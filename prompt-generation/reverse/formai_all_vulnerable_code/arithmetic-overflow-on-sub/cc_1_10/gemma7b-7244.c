//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#define QoS_PORT 5000

struct QoS_packet {
  int seq_num;
  char data[1024];
  time_t timestamp;
} QoS_packet_t;

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in sock_addr, client_addr;
  struct QoS_packet packet;
  int bytes_read, i, j, k;
  time_t start_time, end_time;
  char command;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(QoS_PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket
  sock_addr.sin_port = htons(QoS_PORT);
  if (bind(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for connections
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
  if (newsockfd < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  // Receive the packet
  bytes_read = recv(newsockfd, &packet, sizeof(packet), 0);
  if (bytes_read < 0) {
    perror("Error receiving packet");
    exit(1);
  }

  // Calculate the packet's delay
  start_time = packet.timestamp;
  end_time = time(NULL);
  k = end_time - start_time;
  printf("Packet sequence number: %d\n", packet.seq_num);
  printf("Packet data: %s\n", packet.data);
  printf("Packet delay: %d seconds\n", k);

  // Send a response
  write(newsockfd, "ACK", 3);
  close(newsockfd);

  return 0;
}