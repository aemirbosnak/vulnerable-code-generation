//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in servaddr;
  char buffer[1024];

  if (argc != 5) {
    fprintf(stderr, "Usage: %s <server IP> <server port> <sender> <recipient>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  snprintf(buffer, sizeof(buffer), "HELO %s\r\n", argv[0]);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    exit(1);
  }

  snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    exit(1);
  }

  snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", argv[4]);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    exit(1);
  }

  snprintf(buffer, sizeof(buffer), "DATA\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    exit(1);
  }

  snprintf(buffer, sizeof(buffer), "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    exit(1);
  }

  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(1);
  }

  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    exit(1);
  }

  close(sockfd);

  return 0;
}