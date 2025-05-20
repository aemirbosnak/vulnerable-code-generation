//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#include <sys/socket.h>

#define MAX_RESP_LEN 4096

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  const char *host = argv[1];
  const char *port = argv[2];

  struct addrinfo *res;
  if (getaddrinfo(host, port, NULL, &res) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
    return 1;
  }

  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1) {
    fprintf(stderr, "socket: %s\n", strerror(errno));
    freeaddrinfo(res);
    return 1;
  }

  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    fprintf(stderr, "connect: %s\n", strerror(errno));
    freeaddrinfo(res);
    close(sockfd);
    return 1;
  }

  freeaddrinfo(res);

  char buf[MAX_RESP_LEN];
  ssize_t n;

  // Send EHLO command
  strcpy(buf, "EHLO smtp.example.com\r\n");
  if (write(sockfd, buf, strlen(buf)) == -1) {
    fprintf(stderr, "write: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  // Read response
  n = read(sockfd, buf, MAX_RESP_LEN - 1);
  if (n == -1) {
    fprintf(stderr, "read: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send MAIL FROM command
  strcpy(buf, "MAIL FROM: <me@example.com>\r\n");
  if (write(sockfd, buf, strlen(buf)) == -1) {
    fprintf(stderr, "write: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  // Read response
  n = read(sockfd, buf, MAX_RESP_LEN - 1);
  if (n == -1) {
    fprintf(stderr, "read: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send RCPT TO command
  strcpy(buf, "RCPT TO: <you@example.com>\r\n");
  if (write(sockfd, buf, strlen(buf)) == -1) {
    fprintf(stderr, "write: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  // Read response
  n = read(sockfd, buf, MAX_RESP_LEN - 1);
  if (n == -1) {
    fprintf(stderr, "read: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send DATA command
  strcpy(buf, "DATA\r\n");
  if (write(sockfd, buf, strlen(buf)) == -1) {
    fprintf(stderr, "write: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  // Read response
  n = read(sockfd, buf, MAX_RESP_LEN - 1);
  if (n == -1) {
    fprintf(stderr, "read: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send message body
  strcpy(buf, "Hello world!\r\n");
  if (write(sockfd, buf, strlen(buf)) == -1) {
    fprintf(stderr, "write: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  // Send dot to terminate message body
  strcpy(buf, ".\r\n");
  if (write(sockfd, buf, strlen(buf)) == -1) {
    fprintf(stderr, "write: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  // Read response
  n = read(sockfd, buf, MAX_RESP_LEN - 1);
  if (n == -1) {
    fprintf(stderr, "read: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send QUIT command
  strcpy(buf, "QUIT\r\n");
  if (write(sockfd, buf, strlen(buf)) == -1) {
    fprintf(stderr, "write: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }

  // Read response
  n = read(sockfd, buf, MAX_RESP_LEN - 1);
  if (n == -1) {
    fprintf(stderr, "read: %s\n", strerror(errno));
    close(sockfd);
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  close(sockfd);

  return 0;
}