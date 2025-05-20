//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <destination IP address>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a raw socket for ICMP packets.
  int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket options.
  int on = 1;
  if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) < 0) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Set the destination IP address.
  struct sockaddr_in dest_addr;
  memset(&dest_addr, 0, sizeof(dest_addr));
  dest_addr.sin_family = AF_INET;
  dest_addr.sin_addr.s_addr = inet_addr(argv[1]);

  // Send ICMP echo requests.
  char buf[1024];
  struct icmphdr *icmp = (struct icmphdr *)buf;
  icmp->type = ICMP_ECHO;
  icmp->code = 0;
  icmp->checksum = 0;
  icmp->un.echo.id = getpid();
  icmp->un.echo.sequence = 0;

  struct timeval start_time;
  struct timeval end_time;
  struct timeval elapsed_time;
  double rtt = 0;

  while (1) {
    // Send the ICMP echo request.
    if (sendto(sockfd, buf, sizeof(buf), 0, (const struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
      perror("sendto");
      return EXIT_FAILURE;
    }

    // Get the current time.
    gettimeofday(&start_time, NULL);

    // Wait for an ICMP echo reply.
    socklen_t addrlen = sizeof(dest_addr);
    if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&dest_addr, &addrlen) < 0) {
      perror("recvfrom");
      return EXIT_FAILURE;
    }

    // Get the current time.
    gettimeofday(&end_time, NULL);

    // Calculate the round-trip time.
    elapsed_time.tv_sec = end_time.tv_sec - start_time.tv_sec;
    elapsed_time.tv_usec = end_time.tv_usec - start_time.tv_usec;
    rtt = (double)elapsed_time.tv_sec + (double)elapsed_time.tv_usec / 1000000;

    // Print the round-trip time.
    printf("Round-trip time: %.3f ms\n", rtt * 1000);

    // Sleep for 1 second.
    sleep(1);
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}