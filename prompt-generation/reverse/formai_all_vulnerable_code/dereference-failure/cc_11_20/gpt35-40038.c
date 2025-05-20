//FormAI DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

#define IP_ADDRESS "8.8.8.8" // Default IP address to ping
#define PACKETSIZE 64 // Default packet size
#define PORT 7 // Echo port

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in addr_ping, addr_pong;
  struct hostent *host;
  struct timeval start, end;
  double time_taken, rtt_min, rtt_max, rtt_total;

  // Check if user has provided custom IP address
  if (argc > 1) {
    if (inet_pton(AF_INET, argv[1], &addr_ping.sin_addr) != 1) {
      printf("Invalid IP address: %s\n", argv[1]);
      return 1;
    }
  } else {
    // Use default IP address
    if (inet_pton(AF_INET, IP_ADDRESS, &addr_ping.sin_addr) != 1) {
      printf("Invalid IP address: %s\n", IP_ADDRESS);
      return 1;
    }
  }

  // Create socket
  sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Set timeout for socket receive function
  struct timeval tv;
  tv.tv_sec = 1;
  tv.tv_usec = 0;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

  // Fill in ping address
  addr_ping.sin_family = AF_INET;
  addr_ping.sin_port = htons(PORT);

  // Get host information if applicable
  if ((host = gethostbyname(addr_ping.sin_addr.s_addr != INADDR_NONE ? inet_ntoa(addr_ping.sin_addr) : IP_ADDRESS)) == NULL) {
    perror("gethostbyname");
    return 1;
  }

  memcpy(&addr_ping.sin_addr, host->h_addr, host->h_length);

  // Print IP address and hostname
  printf("Pinging %s (%s) with %d bytes of data:\n\n", host->h_name, inet_ntoa(addr_ping.sin_addr), PACKETSIZE);

  // Prepare buffer for sending
  char buffer[PACKETSIZE];
  memset(buffer, 'a', sizeof buffer);

  // Start ping loop
  int i, count_success = 0, count_total = 0;
  rtt_min = 1000000, rtt_max = 0, rtt_total = 0;
  for (i = 0; i < 4; i++) {
    // Record start time
    gettimeofday(&start, NULL);

    // Send packet
    if (sendto(sockfd, buffer, PACKETSIZE, 0, (struct sockaddr*)&addr_ping, sizeof addr_ping) < 0) {
      perror("sendto");
      continue;
    }

    // Receive pong
    socklen_t len = sizeof addr_pong;
    ssize_t n = recvfrom(sockfd, buffer, sizeof buffer, 0, (struct sockaddr*)&addr_pong, &len);
    if (n < 0) {
      printf("Request timed out.\n\n");
      continue;
    }

    // Record end time
    gettimeofday(&end, NULL);

    // Compute round-trip time
    time_taken = (double)(end.tv_sec - start.tv_sec) * 1000.0 + (double)(end.tv_usec - start.tv_usec) / 1000.0;
    rtt_total += time_taken;
    if (time_taken < rtt_min) rtt_min = time_taken;
    if (time_taken > rtt_max) rtt_max = time_taken;

    // Print pong information
    char sender_ip[INET_ADDRSTRLEN];
    printf("Reply from %s (%s): bytes=%d time=%.2fms TTL=%d\n\n",
      inet_ntop(AF_INET, &addr_pong.sin_addr, sender_ip, sizeof sender_ip),
      host->h_name, n, time_taken, 128);
    
    count_success++;
    count_total++;
  }

  // Compute and print summary statistics
  printf("--- %s ping statistics ---\n", host->h_name);
  printf("%d packets transmitted, %d received, %.0f%% packet loss, time %.0fms\n",
    count_total, count_success, 100.0 * (double)(count_total - count_success) / (double)count_total,
    rtt_total);
  printf("rtt min/avg/max = %.2f/%.2f/%.2f ms\n",
    rtt_min, rtt_total / (double)count_success, rtt_max);

  // Close socket
  close(sockfd);

  return 0;
}