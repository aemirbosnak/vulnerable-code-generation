//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: rigorous
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define MAX_PACKET_SIZE 1024

int main() {
  int sockfd, n, port = SERVER_PORT, retries = 3;
  struct sockaddr_in srv_addr;
  char packet[MAX_PACKET_SIZE];

  // Socket setup
  sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Server address setup
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_port = htons(port);
  srv_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

  // Sending ping packet
  time_t start_time = time(NULL);
  n = sendto(sockfd, packet, MAX_PACKET_SIZE, 0, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
  if (n < 0) {
    perror("Error sending packet");
    exit(1);
  }

  // Receiving ping response
  n = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, (struct sockaddr *)&srv_addr, NULL);
  if (n < 0) {
    perror("Error receiving response");
    exit(1);
  }

  // Calculate ping time
  time_t end_time = time(NULL);
  long ping_time = end_time - start_time;

  // Print ping time
  printf("Ping time: %ld ms\n", ping_time);

  // Close socket
  close(sockfd);

  return 0;
}