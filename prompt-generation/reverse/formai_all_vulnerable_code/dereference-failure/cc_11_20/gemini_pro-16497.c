//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024


int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(hostname);
  server_addr.sin_port = htons(port);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  char buf[MAX_LINE];
  memset(buf, 0, MAX_LINE);

  if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  printf("%s", buf);

  memset(buf, 0, MAX_LINE);
  strcpy(buf, "USER username\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  memset(buf, 0, MAX_LINE);
  if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  printf("%s", buf);

  memset(buf, 0, MAX_LINE);
  strcpy(buf, "PASS password\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  memset(buf, 0, MAX_LINE);
  if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  printf("%s", buf);

  memset(buf, 0, MAX_LINE);
  strcpy(buf, "LIST\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  memset(buf, 0, MAX_LINE);
  if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(1);
  }

  printf("%s", buf);

  memset(buf, 0, MAX_LINE);
  strcpy(buf, "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }

  close(sockfd);

  return 0;
}