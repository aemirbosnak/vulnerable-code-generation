//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define TIMEOUT_SECONDS 5

int main() {
  int sockfd, client_sockfd, sin_size, bytes_received;
  struct sockaddr_in server_addr, client_addr;
  char packet[MAX_PACKET_SIZE];
  time_t start_time, end_time;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  // Bind the socket to a port
  server_addr.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    return 1;
  }

  // Listen for clients
  sin_size = sizeof(client_addr);
  client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
  if (client_sockfd < 0) {
    perror("Error accepting client connection");
    return 1;
  }

  // Start the timer
  start_time = time(NULL);

  // Receive the packet
  bytes_received = recv(client_sockfd, packet, MAX_PACKET_SIZE, 0);
  if (bytes_received < 0) {
    perror("Error receiving packet");
    return 1;
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the delay
  int delay = end_time - start_time;

  // Print the delay
  printf("The delay is: %d seconds\n", delay);

  // Close the socket
  close(client_sockfd);
  close(sockfd);

  return 0;
}