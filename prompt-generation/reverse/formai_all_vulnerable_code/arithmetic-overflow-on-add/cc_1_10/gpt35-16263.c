//FormAI DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <time.h>

#define PING_TIMEOUT 5       // timeout for pinging.
#define ICMP_HDR_SIZE 8      // size of ICMP header.
#define IP_HDR_SIZE 20       // size of IP header.
#define PING_PKT_S 64        // ping request packet size (in bytes).

// function to perform checksum computation for ICMP header.
unsigned short compute_icmp_checksum (const void *buff, int length)
{
  unsigned short *buff_ptr = (unsigned short *) buff;
  unsigned int sum = 0;
  unsigned short icmp_hdr_csum;

  while (length > 1)
  {
    sum += *buff_ptr++;
    length -= 2;
  }

  if (length == 1)
    sum += *((unsigned char *) buff_ptr);

  sum = (sum >> 16) + (sum & 0xFFFF);
  sum += (sum >> 16);
  icmp_hdr_csum = (unsigned short) ~sum;
  return icmp_hdr_csum;
}

// function to send a ping request.
int send_ping_request(int sockfd, struct sockaddr_in *dest_addr, pid_t pid, int seq)
{
  struct icmp icmp_hdr;
  char ping_pkt[PING_PKT_S];

  // prepare ping request packet.
  memset(&icmp_hdr, 0, sizeof(struct icmp));
  icmp_hdr.icmp_type = ICMP_ECHO;
  icmp_hdr.icmp_code = 0;
  icmp_hdr.icmp_id = pid;
  icmp_hdr.icmp_seq = seq;
  memset(ping_pkt, 0, PING_PKT_S);
  memcpy(ping_pkt, &icmp_hdr, sizeof(struct icmp));
  icmp_hdr.icmp_cksum = compute_icmp_checksum((unsigned short *) ping_pkt, PING_PKT_S);
  memcpy(ping_pkt, &icmp_hdr, sizeof(struct icmp));

  // send ping request packet.
  if (sendto(sockfd, ping_pkt, sizeof(ping_pkt), 0, (struct sockaddr *) dest_addr, sizeof(struct sockaddr)) <= 0)
  {
    perror("sendto() failed");
    return -1;
  }

  return 0;
}

// function to receive a ping response.
int recv_ping_response(int sockfd, struct sockaddr_in *src_addr, pid_t pid, int ttl)
{
  char recv_pkt[IP_MAXPACKET];
  struct iphdr *ip_hdr = (struct iphdr *) recv_pkt;
  socklen_t src_addr_len = sizeof(struct sockaddr_in);
  struct icmp *icmp_hdr;
  struct timeval start_time, end_time;
  long double rtt, rtt_ms, sent_time_ms, received_time_ms;
  int pkt_size, bytes_rcvd;

  // receive ping response packet.
  bytes_rcvd = recvfrom(sockfd, recv_pkt, sizeof(recv_pkt), 0, (struct sockaddr *) src_addr, &src_addr_len);
  if (bytes_rcvd <= 0)
  {
    perror("recvfrom() failed");
    return -1;
  }

  // check if the packet is an ICMP packet.
  icmp_hdr = (struct icmp *) (recv_pkt + (ip_hdr->ihl * 4));
  if (icmp_hdr->icmp_type != ICMP_ECHOREPLY || icmp_hdr->icmp_id != pid)
    return 0;

  // calculate round-trip-time and print ping response details.
  gettimeofday(&end_time, NULL);
  start_time.tv_sec = icmp_hdr->icmp_data[0];
  start_time.tv_usec = icmp_hdr->icmp_data[1];
  rtt = (long double) (end_time.tv_sec - start_time.tv_sec) * 1000.0L;
  rtt += (long double) (end_time.tv_usec - start_time.tv_usec) / 1000.0L;
  pkt_size = bytes_rcvd - IP_HDR_SIZE;
  rtt_ms = rtt * 1000000 / CLOCKS_PER_SEC;
  sent_time_ms = *((unsigned int *) (icmp_hdr->icmp_data + 2));
  received_time_ms = (long double) clock() / CLOCKS_PER_SEC * 1000.0L;
  printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.3Lf ms\n",
         pkt_size, inet_ntoa(src_addr->sin_addr), icmp_hdr->icmp_seq, ttl, rtt_ms);
  return 1;
}

// main function to perform network ping test.
int main(int argc, char *argv[])
{
  int sockfd, ttl = 0, seq = 0, bytes_sent = 0, bytes_rcvd = 0, ping_responses = 0;
  unsigned long int ip_addr;
  char *ip_addr_str;
  struct sockaddr_in dest_addr, src_addr;
  struct hostent *host;
  struct timeval tv_timeout;
  fd_set readfds;

  if (argc < 2)
  {
    printf("Usage: %s <ip_address>\n", argv[0]);
    return -1;
  }

  ip_addr_str = argv[1];
  memset(&dest_addr, 0, sizeof(struct sockaddr_in));
  dest_addr.sin_family = AF_INET;
  dest_addr.sin_port = 0;
  if ((ip_addr = inet_addr(ip_addr_str)) == -1)
  {
    host = gethostbyname(ip_addr_str);
    if (!host)
    {
      printf("Could not resolve hostname/ip address.\n");
      return -1;
    }
    memcpy(&dest_addr.sin_addr, host->h_addr, host->h_length);
  }
  else
  {
    dest_addr.sin_addr.s_addr = ip_addr;
  }

  // create a raw socket with ICMP protocol.
  if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) < 0)
  {
    perror ("socket() failed");
    return -1;
  }

  // set the timeout for socket receive.
  tv_timeout.tv_sec = PING_TIMEOUT;
  tv_timeout.tv_usec = 0;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &tv_timeout, sizeof(tv_timeout));

  printf("PING %s (%s):\n", ip_addr_str, inet_ntoa(dest_addr.sin_addr));

  // loop to send and receive ping packets.
  for (seq = 1; seq <= 10; seq++)
  {
    // send ping request packet.
    if (send_ping_request(sockfd, &dest_addr, getpid(), seq) < 0)
      continue;
    bytes_sent += PING_PKT_S;

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    // wait for ping response packet.
    if (select(sockfd + 1, &readfds, NULL, NULL, &tv_timeout) <= 0)
    {
      printf("Request timed out.\n");
      continue;
    }

    // receive ping response packet.
    bytes_rcvd = recv_ping_response(sockfd, &src_addr, getpid(), ttl);
    if (bytes_rcvd < 0)
      break;
    ping_responses++;
    if (ping_responses == 1)
      printf("PING SUCCESSFUL!\n");
  }

  // close the socket and return.
  close(sockfd);
  return 0;
}