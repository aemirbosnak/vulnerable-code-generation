//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 1024

int main() {
  int sockfd, newsockfd, client_len;
  struct sockaddr_in client_addr;
  char buffer[MAX_PACKET_SIZE];
  int packet_size, received_bytes, start_time, end_time, delay;
  float avg_delay = 0.0f;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Listen for clients
  client_len = sizeof(client_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
  if (newsockfd < 0) {
    perror("Error accepting client");
    exit(1);
  }

  // Receive packet size
  packet_size = recv(newsockfd, buffer, sizeof(packet_size), 0);
  if (packet_size < 0) {
    perror("Error receiving packet size");
    exit(1);
  }

  // Start timer
  start_time = time(NULL);

  // Receive packet
  received_bytes = recv(newsockfd, buffer, packet_size, 0);
  if (received_bytes < 0) {
    perror("Error receiving packet");
    exit(1);
  }

  // End timer
  end_time = time(NULL);

  // Calculate delay
  delay = end_time - start_time;

  // Add delay to average delay
  avg_delay += (float)delay;

  // Send confirmation
  send(newsockfd, "Packet received", 16, 0);

  // Close connection
  close(newsockfd);

  // Print average delay
  printf("Average delay: %.2f milliseconds\n", avg_delay / (float)client_len);

  return 0;
}