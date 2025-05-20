//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

int main() {
  int sockfd, client_sockfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[MAX_BUFFER_SIZE];
  int bytes_received, bytes_sent;
  time_t start_time, end_time;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_port = htons(5000);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
  if (client_sockfd < 0) {
    perror("Error accepting client connection");
    exit(1);
  }

  // Start the timer
  start_time = time(NULL);

  // Receive data from the client
  bytes_received = recv(client_sockfd, buffer, MAX_BUFFER_SIZE, 0);
  if (bytes_received < 0) {
    perror("Error receiving data");
    exit(1);
  }

  // Send data to the client
  bytes_sent = send(client_sockfd, buffer, bytes_received, 0);
  if (bytes_sent < 0) {
    perror("Error sending data");
    exit(1);
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the time taken
  int time_taken = end_time - start_time;

  // Print the time taken
  printf("Time taken: %d seconds\n", time_taken);

  // Close the socket
  close(client_sockfd);
  close(sockfd);

  return 0;
}