//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int main(int argc, char* argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char* host = argv[1];
  char* port = argv[2];

  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(host, port, &hints, &res);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  freeaddrinfo(res);

  char buff[BUFF_SIZE];
  while (1) {
    memset(buff, 0, BUFF_SIZE);
    printf("> ");
    fgets(buff, BUFF_SIZE - 1, stdin);

    if (strcmp(buff, "exit\n") == 0) {
      break;
    }

    int len = strlen(buff);
    buff[len - 1] = '\0';

    if (send(sockfd, buff, len, 0) == -1) {
      perror("send");
      exit(EXIT_FAILURE);
    }

    memset(buff, 0, BUFF_SIZE);
    if (recv(sockfd, buff, BUFF_SIZE - 1, 0) == -1) {
      perror("recv");
      exit(EXIT_FAILURE);
    }

    printf("%s\n", buff);
  }

  close(sockfd);

  return EXIT_SUCCESS;
}