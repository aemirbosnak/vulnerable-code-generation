//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the IP address of the POP3 server
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_CANONNAME;
  int err = getaddrinfo(argv[1], argv[2], &hints, &res);
  if (err) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
    return EXIT_FAILURE;
  }

  // Create a socket to connect to the POP3 server
  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    freeaddrinfo(res);
    return EXIT_FAILURE;
  }

  // Connect to the POP3 server
  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    perror("connect");
    freeaddrinfo(res);
    close(sockfd);
    return EXIT_FAILURE;
  }

  freeaddrinfo(res);

  // Read the welcome message from the POP3 server
  char buffer[BUFFER_SIZE];
  int bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (bytes_read == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("Welcome message: %s\n", buffer);

  // Send the USER command to the POP3 server
  const char *user = "username";
  int user_len = strlen(user);
  char user_cmd[user_len + 6];
  sprintf(user_cmd, "USER %s\r\n", user);
  int bytes_sent = send(sockfd, user_cmd, user_len + 5, 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Read the response from the POP3 server
  bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (bytes_read == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("Response to USER command: %s\n", buffer);

  // Send the PASS command to the POP3 server
  const char *password = "password";
  int password_len = strlen(password);
  char password_cmd[password_len + 6];
  sprintf(password_cmd, "PASS %s\r\n", password);
  bytes_sent = send(sockfd, password_cmd, password_len + 5, 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Read the response from the POP3 server
  bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (bytes_read == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("Response to PASS command: %s\n", buffer);

  // Send the LIST command to the POP3 server
  const char *list_cmd = "LIST\r\n";
  bytes_sent = send(sockfd, list_cmd, strlen(list_cmd), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Read the response from the POP3 server
  bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (bytes_read == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("Response to LIST command: %s\n", buffer);

  // Send the RETR command to the POP3 server
  const char *retr_cmd = "RETR 1\r\n";
  bytes_sent = send(sockfd, retr_cmd, strlen(retr_cmd), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Read the response from the POP3 server
  bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (bytes_read == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("Response to RETR command: %s\n", buffer);

  // Send the QUIT command to the POP3 server
  const char *quit_cmd = "QUIT\r\n";
  bytes_sent = send(sockfd, quit_cmd, strlen(quit_cmd), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Read the response from the POP3 server
  bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);
  if (bytes_read == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  printf("Response to QUIT command: %s\n", buffer);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}