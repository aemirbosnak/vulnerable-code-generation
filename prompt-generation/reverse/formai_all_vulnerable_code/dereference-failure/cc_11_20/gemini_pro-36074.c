//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server address> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get server address and port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send a login request
  char buffer[MAX_BUFFER_SIZE];
  snprintf(buffer, MAX_BUFFER_SIZE, "USER anonymous\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the login response
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the login was successful
  if (strncmp(buffer, "230", 3) != 0) {
    fprintf(stderr, "Login failed: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send a password request
  snprintf(buffer, MAX_BUFFER_SIZE, "PASS anonymous@\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the password response
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the password was successful
  if (strncmp(buffer, "230", 3) != 0) {
    fprintf(stderr, "Password failed: %s\n", buffer);
    return EXIT_FAILURE;
  }

  // Send a LIST command
  snprintf(buffer, MAX_BUFFER_SIZE, "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the LIST response
  while (1) {
    if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    if (strncmp(buffer, "226", 3) == 0) {
      break;
    }

    // Print the file listing
    printf("%s", buffer);
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}