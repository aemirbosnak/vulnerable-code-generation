//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd, port;
  struct sockaddr_in servaddr;
  char *hostname, *user, *pass, buf[1024];

  printf("Enter hostname: ");
  scanf("%s", hostname);
  printf("Enter port number: ");
  scanf("%d", &port);
  printf("Enter username: ");
  scanf("%s", user);
  printf("Enter password: ");
  scanf("%s", pass);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  // POP3 conversation
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  snprintf(buf, sizeof(buf), "USER %s\r\n", user);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  snprintf(buf, sizeof(buf), "PASS %s\r\n", pass);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  snprintf(buf, sizeof(buf), "LIST\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  snprintf(buf, sizeof(buf), "RETR 1\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    exit(1);
  }
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  close(sockfd);
  return 0;
}