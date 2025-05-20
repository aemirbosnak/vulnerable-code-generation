//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110

int main(int argc, char *argv[])
{
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *server = argv[1];
  char *username = argv[2];

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(POP3_PORT);
  serv_addr.sin_addr.s_addr = inet_addr(server);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buf[1024];
  int n;

  n = read(sockfd, buf, sizeof(buf));
  if (n < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "USER %s\r\n", username);
  n = write(sockfd, buf, strlen(buf));
  if (n < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  n = read(sockfd, buf, sizeof(buf));
  if (n < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "PASS %s\r\n", getenv("PASS"));
  n = write(sockfd, buf, strlen(buf));
  if (n < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  n = read(sockfd, buf, sizeof(buf));
  if (n < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "STAT\r\n");
  n = write(sockfd, buf, strlen(buf));
  if (n < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  n = read(sockfd, buf, sizeof(buf));
  if (n < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "LIST\r\n");
  n = write(sockfd, buf, strlen(buf));
  if (n < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  n = read(sockfd, buf, sizeof(buf));
  if (n < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "RETR 1\r\n");
  n = write(sockfd, buf, strlen(buf));
  if (n < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  n = read(sockfd, buf, sizeof(buf));
  if (n < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  snprintf(buf, sizeof(buf), "QUIT\r\n");
  n = write(sockfd, buf, strlen(buf));
  if (n < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  n = read(sockfd, buf, sizeof(buf));
  if (n < 0) {
    perror("read");
    return EXIT_FAILURE;
  }

  printf("%s", buf);

  close(sockfd);

  return EXIT_SUCCESS;
}