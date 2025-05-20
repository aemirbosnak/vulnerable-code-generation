//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SMTP_PORT "25"

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: %s hostname recipient sender email\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  char *recipient = argv[2];
  char *sender = argv[3];
  char *email = argv[4];

  struct addrinfo hints, *servinfo, *p;
  int status;
  int sockfd;
  char addr[INET6_ADDRSTRLEN];

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((status = getaddrinfo(hostname, SMTP_PORT, &hints, &servinfo)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return 1;
  }

  for (p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("socket");
      continue;
    }

    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      perror("connect");
      close(sockfd);
      continue;
    }

    break;
  }

  if (p == NULL) {
    fprintf(stderr, "failed to connect\n");
    return 1;
  }

  inet_ntop(p->ai_family, &((struct sockaddr_in *)p->ai_addr)->sin_addr, addr, sizeof addr);
  printf("connected to %s\n", addr);

  freeaddrinfo(servinfo);

  char buffer[1024];
  int bytes_sent, bytes_received;

  memset(buffer, 0, sizeof buffer);
  strcpy(buffer, "EHLO ");
  strcat(buffer, hostname);
  strcat(buffer, "\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return 1;
  }

  memset(buffer, 0, sizeof buffer);
  bytes_received = recv(sockfd, buffer, sizeof buffer, 0);
  if (bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof buffer);
  strcpy(buffer, "MAIL FROM: ");
  strcat(buffer, sender);
  strcat(buffer, "\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return 1;
  }

  memset(buffer, 0, sizeof buffer);
  bytes_received = recv(sockfd, buffer, sizeof buffer, 0);
  if (bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof buffer);
  strcpy(buffer, "RCPT TO: ");
  strcat(buffer, recipient);
  strcat(buffer, "\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return 1;
  }

  memset(buffer, 0, sizeof buffer);
  bytes_received = recv(sockfd, buffer, sizeof buffer, 0);
  if (bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof buffer);
  strcpy(buffer, "DATA\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return 1;
  }

  memset(buffer, 0, sizeof buffer);
  bytes_received = recv(sockfd, buffer, sizeof buffer, 0);
  if (bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof buffer);
  strcpy(buffer, email);
  strcat(buffer, "\r\n.\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return 1;
  }

  memset(buffer, 0, sizeof buffer);
  bytes_received = recv(sockfd, buffer, sizeof buffer, 0);
  if (bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return 1;
  }

  printf("%s", buffer);

  memset(buffer, 0, sizeof buffer);
  strcpy(buffer, "QUIT\r\n");
  bytes_sent = send(sockfd, buffer, strlen(buffer), 0);
  if (bytes_sent == -1) {
    perror("send");
    close(sockfd);
    return 1;
  }

  memset(buffer, 0, sizeof buffer);
  bytes_received = recv(sockfd, buffer, sizeof buffer, 0);
  if (bytes_received == -1) {
    perror("recv");
    close(sockfd);
    return 1;
  }

  printf("%s", buffer);

  close(sockfd);

  return 0;
}