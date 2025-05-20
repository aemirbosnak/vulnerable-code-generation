//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void) {

  // Set up socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Could not create socket\n");
    return 1;
  }

  // Set up server address
  struct sockaddr_in serveraddr;
  memset((char*) &serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(5000);
  serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Bind socket to port
  if (bind(sockfd, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0) {
    fprintf(stderr, "Could not bind to port\n");
    return 1;
  }

  // Monitor QoS
  int total_packets_received = 0;
  int total_bytes_received = 0;
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  int bytes_received;
  while (1) {
    struct sockaddr_in clientaddr;
    socklen_t clientlen = sizeof(clientaddr);
    bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr*) &clientaddr, &clientlen);
    if (bytes_received < 0) {
      fprintf(stderr, "Could not receive packet\n");
    } else {
      total_packets_received++;
      total_bytes_received += bytes_received;
    }
    time_t current_time = time(NULL);
    printf("QoS report: received %d packets, %d bytes at %s", total_packets_received, total_bytes_received, ctime(&current_time));
  }

  // Close socket and exit program
  close(sockfd);
  return 0;
}