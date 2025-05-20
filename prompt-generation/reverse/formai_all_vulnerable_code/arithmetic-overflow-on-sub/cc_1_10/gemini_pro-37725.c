//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>

// A lively QoS monitor
int main() {
  // Our trusty network socket
  int sockfd;

  // Welcome our QoS monitor to the world
  printf("Howdy, folks! I'm your friendly neighborhood QoS monitor!\n");

  // Create a socket to listen for network traffic
  sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set up the socket address structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(5000);
  addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the address
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Receive data from the socket
  char buf[1024];
  socklen_t len = sizeof(addr);
  while (1) {
    int n = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &len);
    if (n == -1) {
      perror("recvfrom");
      exit(EXIT_FAILURE);
    }

    // Calculate the round-trip time (RTT)
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long long t1 = tv.tv_sec * 1000000 + tv.tv_usec;
    long long t2 = ntohl(*(long long *)buf);
    long long rtt = t1 - t2;

    // Print the RTT
    printf("RTT: %lld us\n", rtt);
  }

  // Close the socket
  close(sockfd);

  // Say goodbye
  printf("Welp, that's all, folks! Thanks for watching!\n");

  return 0;
}