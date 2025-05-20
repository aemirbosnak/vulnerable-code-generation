//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define POP3_PORT "110"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <server>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *hostname = argv[1];

  struct addrinfo *result;
  if (getaddrinfo(hostname, POP3_PORT, NULL, &result) != 0) {
    perror("getaddrinfo");
    return EXIT_FAILURE;
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd < 0) {
    perror("socket");
    freeaddrinfo(result);
    return EXIT_FAILURE;
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) < 0) {
    perror("connect");
    freeaddrinfo(result);
    close(sockfd);
    return EXIT_FAILURE;
  }

  freeaddrinfo(result);

  char buffer[1024];
  int bytes_received;

  // Receive the welcome message
  bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);

  // Send the username
  char username[] = "username\r\n";
  if (send(sockfd, username, strlen(username), 0) < 0) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response
  bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);

  // Send the password
  char password[] = "password\r\n";
  if (send(sockfd, password, strlen(password), 0) < 0) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response
  bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);

  // List the messages
  char list_command[] = "LIST\r\n";
  if (send(sockfd, list_command, strlen(list_command), 0) < 0) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response
  bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);

  // Retrieve the first message
  char retr_command[16];
  snprintf(retr_command, sizeof(retr_command), "RETR 1\r\n");
  if (send(sockfd, retr_command, strlen(retr_command), 0) < 0) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response
  bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);

  // Quit the POP3 session
  char quit_command[] = "QUIT\r\n";
  if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response
  bytes_received = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);

  close(sockfd);

  return EXIT_SUCCESS;
}