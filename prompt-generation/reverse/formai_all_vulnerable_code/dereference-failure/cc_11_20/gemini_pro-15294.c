//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define IMAP_PORT 143
#define IMAP_BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *server = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(server);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  char buffer[IMAP_BUFFER_SIZE];
  memset(buffer, 0, IMAP_BUFFER_SIZE);
  if (recv(sockfd, buffer, IMAP_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  memset(buffer, 0, IMAP_BUFFER_SIZE);
  sprintf(buffer, "A1 LOGIN username password\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  memset(buffer, 0, IMAP_BUFFER_SIZE);
  if (recv(sockfd, buffer, IMAP_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  memset(buffer, 0, IMAP_BUFFER_SIZE);
  sprintf(buffer, "A2 SELECT inbox\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  memset(buffer, 0, IMAP_BUFFER_SIZE);
  if (recv(sockfd, buffer, IMAP_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  memset(buffer, 0, IMAP_BUFFER_SIZE);
  sprintf(buffer, "A3 FETCH 1:10 (RFC822)\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  memset(buffer, 0, IMAP_BUFFER_SIZE);
  if (recv(sockfd, buffer, IMAP_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  memset(buffer, 0, IMAP_BUFFER_SIZE);
  sprintf(buffer, "A4 LOGOUT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  memset(buffer, 0, IMAP_BUFFER_SIZE);
  if (recv(sockfd, buffer, IMAP_BUFFER_SIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buffer);

  close(sockfd);

  return 0;
}