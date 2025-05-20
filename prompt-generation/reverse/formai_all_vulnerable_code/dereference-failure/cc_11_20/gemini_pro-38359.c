//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char **argv) {
  assert(argc == 3);

  const char *hostname = argv[1];
  const char *port = argv[2];

  struct addrinfo hints = {
    .ai_family = AF_INET,
    .ai_socktype = SOCK_STREAM,
    .ai_protocol = IPPROTO_TCP,
  };
  struct addrinfo *result;
  int err = getaddrinfo(hostname, port, &hints, &result);
  if (err != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
    return EXIT_FAILURE;
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  freeaddrinfo(result);

  char buf[MAX_LINE];

  while (1) {
    printf("ftp> ");
    fflush(stdout);

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
      break;
    }

    int len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
      buf[len - 1] = '\0';
    }

    if (strcmp(buf, "quit") == 0) {
      break;
    }

    if (write(sockfd, buf, len) == -1) {
      perror("write");
      return EXIT_FAILURE;
    }

    while (1) {
      int n = read(sockfd, buf, sizeof(buf));
      if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
      } else if (n == 0) {
        break;
      }

      fwrite(buf, 1, n, stdout);
    }
  }

  close(sockfd);

  return EXIT_SUCCESS;
}