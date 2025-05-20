//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int sockfd;
  struct sockaddr_in servaddr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  memset(&servaddr, 0, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));

  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buffer[MAX_LENGTH];
  int n;

  // Send USER command
  snprintf(buffer, MAX_LENGTH, "USER %s\r\n", "username");
  if ((n = write(sockfd, buffer, strlen(buffer))) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  // Read response
  memset(buffer, 0, MAX_LENGTH);
  if ((n = read(sockfd, buffer, MAX_LENGTH - 1)) < 0) {
    perror("read");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send PASS command
  snprintf(buffer, MAX_LENGTH, "PASS %s\r\n", "password");
  if ((n = write(sockfd, buffer, strlen(buffer))) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  // Read response
  memset(buffer, 0, MAX_LENGTH);
  if ((n = read(sockfd, buffer, MAX_LENGTH - 1)) < 0) {
    perror("read");
    return EXIT_FAILURE;
  }
  printf("%s", buffer);

  // Send LIST command
  snprintf(buffer, MAX_LENGTH, "LIST\r\n");
  if ((n = write(sockfd, buffer, strlen(buffer))) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  // Read response
  memset(buffer, 0, MAX_LENGTH);
  while ((n = read(sockfd, buffer, MAX_LENGTH - 1)) > 0) {
    printf("%.*s", n, buffer);
    memset(buffer, 0, MAX_LENGTH);
  }

  // Send QUIT command
  snprintf(buffer, MAX_LENGTH, "QUIT\r\n");
  if ((n = write(sockfd, buffer, strlen(buffer))) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  close(sockfd);
  return EXIT_SUCCESS;
}