//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080

int main() {
  int sockfd;
  struct sockaddr_in servaddr;
  char buf[1024];
  time_t start, end;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  servaddr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for connections
  listen(sockfd, 1);

  // Accept a connection
  int connfd = accept(sockfd, NULL, NULL);
  if (connfd < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  // Start the timer
  start = time(NULL);

  // Send a message to the client
  write(connfd, "Hello, world!", 13);

  // Receive a message from the client
  read(connfd, buf, 1024);

  // End the timer
  end = time(NULL);

  // Calculate the time taken
  int time_taken = end - start;

  // Print the time taken
  printf("Time taken: %d seconds\n", time_taken);

  // Close the connection
  close(connfd);

  // Close the socket
  close(sockfd);

  return 0;
}