//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Set the socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
    perror("Error setting socket options");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the port
  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(sockfd, 5) < 0) {
    perror("Error listening for connections");
    exit(EXIT_FAILURE);
  }

  // Accept a connection
  int connfd = accept(sockfd, (struct sockaddr *)NULL, NULL);
  if (connfd < 0) {
    perror("Error accepting connection");
    exit(EXIT_FAILURE);
  }

  // Read the data from the client
  char buffer[BUFFER_SIZE];
  int nbytes = read(connfd, buffer, BUFFER_SIZE);
  if (nbytes < 0) {
    perror("Error reading data from client");
    exit(EXIT_FAILURE);
  }

  // Get the current time of day
  struct timeval start, end;
  if (gettimeofday(&start, NULL) < 0) {
    perror("Error getting time of day");
    exit(EXIT_FAILURE);
  }

  // Write the data to the client
  if (write(connfd, buffer, nbytes) < 0) {
    perror("Error writing data to client");
    exit(EXIT_FAILURE);
  }

  // Get the current time of day
  if (gettimeofday(&end, NULL) < 0) {
    perror("Error getting time of day");
    exit(EXIT_FAILURE);
  }

  // Calculate the elapsed time
  long elapsed_us = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

  // Calculate the download speed
  double download_speed = (double)nbytes * 8 / elapsed_us;

  // Print the download speed
  printf("Download speed: %.2f Mbps\n", download_speed);

  // Close the connection
  if (close(connfd) < 0) {
    perror("Error closing connection");
    exit(EXIT_FAILURE);
  }

  // Close the socket
  if (close(sockfd) < 0) {
    perror("Error closing socket");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}