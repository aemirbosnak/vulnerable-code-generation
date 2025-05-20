//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the port number for the server
#define PORT 8080

// Define the maximum number of bytes to receive from the client
#define MAX_BYTES 1024

// Define the function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the port
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(sockfd, 5) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accept a connection from a client
  struct sockaddr_in cliaddr;
  socklen_t clilen = sizeof(cliaddr);
  int connfd = accept(sockfd, (struct sockaddr *) &cliaddr, &clilen);
  if (connfd < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // Receive the number from the client
  char buffer[MAX_BYTES];
  int nbytes = recv(connfd, buffer, MAX_BYTES, 0);
  if (nbytes < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Calculate the factorial of the number
  int number = atoi(buffer);
  int factorial_result = factorial(number);

  // Send the factorial result back to the client
  char result_buffer[MAX_BYTES];
  sprintf(result_buffer, "%d", factorial_result);
  int nbytes_sent = send(connfd, result_buffer, strlen(result_buffer), 0);
  if (nbytes_sent < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Close the connection with the client
  close(connfd);

  // Close the socket
  close(sockfd);

  return 0;
}