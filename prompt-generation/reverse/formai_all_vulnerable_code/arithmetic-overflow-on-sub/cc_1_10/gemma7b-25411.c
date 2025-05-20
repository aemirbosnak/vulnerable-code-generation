//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

int main() {
  int sockfd, client_sockfd, sin_size, bytes_read;
  struct sockaddr_in server_addr, client_addr;
  char buffer[MAX_PACKET_SIZE];
  time_t start_time, end_time;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  sin_size = sizeof(client_addr);
  client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
  if (client_sockfd < 0) {
    perror("Error accepting client connection");
    exit(1);
  }

  // Start the timer
  start_time = time(NULL);

  // Read data from the client
  bytes_read = read(client_sockfd, buffer, MAX_PACKET_SIZE);
  if (bytes_read < 0) {
    perror("Error reading data");
    exit(1);
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the time taken to read the data
  int time_taken = end_time - start_time;

  // Print the time taken
  printf("Time taken to read data: %d seconds\n", time_taken);

  // Close the client socket
  close(client_sockfd);

  // Close the server socket
  close(sockfd);

  return 0;
}