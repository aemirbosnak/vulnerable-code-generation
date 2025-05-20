//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define POP3_PORT 110

int main(int argc, char **argv) {
  int sockfd;
  char buffer[1024];
  char hostname[1024];
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc < 3) {
    printf("Usage: %s <hostname> <username>\n", argv[0]);
    return 1;
  }

  strcpy(hostname, argv[1]);
  server = gethostbyname(hostname);
  if (server == NULL) {
    perror("gethostbyname");
    return 1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(POP3_PORT);
  serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return 1;
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "USER %s\r\n", argv[2]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof(buffer));
  sprintf(buffer, "PASS %s\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "STAT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "RETR 1\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof(buffer));
  strcpy(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  close(sockfd);
  return 0;
}