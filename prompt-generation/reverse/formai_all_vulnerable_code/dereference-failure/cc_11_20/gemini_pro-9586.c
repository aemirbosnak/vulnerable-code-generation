//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char buf[BUF_SIZE];
  char *host, *user, *pass;

  if (argc != 4) {
    fprintf(stderr, "Usage: %s <host> <user> <pass>\n", argv[0]);
    exit(1);
  }

  host = argv[1];
  user = argv[2];
  pass = argv[3];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  struct hostent *h = gethostbyname(host);
  if (h == NULL) {
    fprintf(stderr, "Could not resolve hostname %s\n", host);
    exit(1);
  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(110);
  memcpy(&servaddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Receive the greeting message from the server
  n = recv(sockfd, buf, BUF_SIZE, 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  // Send the USER command
  snprintf(buf, BUF_SIZE, "USER %s\r\n", user);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    exit(1);
  }

  // Receive the response to the USER command
  n = recv(sockfd, buf, BUF_SIZE, 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  // Send the PASS command
  snprintf(buf, BUF_SIZE, "PASS %s\r\n", pass);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    exit(1);
  }

  // Receive the response to the PASS command
  n = recv(sockfd, buf, BUF_SIZE, 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  // Send the LIST command
  snprintf(buf, BUF_SIZE, "LIST\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    exit(1);
  }

  // Receive the response to the LIST command
  while ((n = recv(sockfd, buf, BUF_SIZE, 0)) > 0) {
    printf("%s", buf);
  }
  if (n < 0) {
    perror("recv");
    exit(1);
  }

  // Send the QUIT command
  snprintf(buf, BUF_SIZE, "QUIT\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("send");
    exit(1);
  }

  // Receive the response to the QUIT command
  n = recv(sockfd, buf, BUF_SIZE, 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }
  printf("%s", buf);

  close(sockfd);
  return 0;
}