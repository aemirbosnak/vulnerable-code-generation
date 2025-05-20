//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  struct sockaddr_in server;
  int sockfd, bytes;
  char buffer[1024];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve the hostname
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    herror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Set the server address
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  memcpy(&server.sin_addr, host->h_addr, host->h_length);
  server.sin_port = htons(POP3_PORT);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Receive the welcome message
  bytes = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send the USER command
  sprintf(buffer, "USER %s\r\n", argv[2]);
  bytes = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  bytes = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send the PASS command
  sprintf(buffer, "PASS %s\r\n", argv[3]);
  bytes = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  bytes = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Send the LIST command
  strcpy(buffer, "LIST\r\n");
  bytes = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response
  bytes = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the list of messages
  printf("%s\n", buffer);

  // Send the QUIT command
  strcpy(buffer, "QUIT\r\n");
  bytes = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}