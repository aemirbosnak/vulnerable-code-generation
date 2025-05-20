//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: puzzling
// TCP/IP Programming Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  int sockfd, new_fd;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t clilen;
  char buffer[MAX_LINE];

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  // Initialize server address
  memset((char *)&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind socket to port
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sockfd, 3) < 0) {
    perror("Error listening on socket");
    exit(1);
  }

  // Accept incoming connection
  clilen = sizeof(cli_addr);
  new_fd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  if (new_fd < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  // Read message from client
  bzero(buffer, MAX_LINE);
  if (read(new_fd, buffer, MAX_LINE) < 0) {
    perror("Error reading from socket");
    exit(1);
  }

  // Print received message
  printf("Received message: %s\n", buffer);

  // Write message to client
  bzero(buffer, MAX_LINE);
  sprintf(buffer, "Hello, client!");
  if (write(new_fd, buffer, strlen(buffer)) < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Close socket
  close(new_fd);
  close(sockfd);

  return 0;
}