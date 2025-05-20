//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define POP3_PORT "110"

int main(int argc, char *argv[]) {
  int sockfd, status;
  struct addrinfo hints, *res;
  char buf[1024], *ptr;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((status = getaddrinfo(argv[1], POP3_PORT, &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    exit(EXIT_FAILURE);
  }

  if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(res);

  if ((ptr = fgets(buf, sizeof(buf), stdin)) == NULL) {
    perror("fgets");
    exit(EXIT_FAILURE);
  }

  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  if ((ptr = fgets(buf, sizeof(buf), stdin)) == NULL) {
    perror("fgets");
    exit(EXIT_FAILURE);
  }

  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  while ((ptr = fgets(buf, sizeof(buf), stdin)) != NULL) {
    if (strncmp(buf, "QUIT", 4) == 0) {
      break;
    }

    if (send(sockfd, buf, strlen(buf), 0) == -1) {
      perror("send");
      exit(EXIT_FAILURE);
    }
  }

  close(sockfd);

  return EXIT_SUCCESS;
}