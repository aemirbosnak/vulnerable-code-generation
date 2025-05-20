//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <winsock2.h>
#else
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#endif

#ifndef INADDR_NONE
#define INADDR_NONE -1
#endif

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <host>\n", argv[0]);
    return 1;
  }

  char *host = argv[1];
  char *port = "80";

  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(host, port, &hints, &res);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return 1;
  }

  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sockfd < 0) {
    perror("socket");
    freeaddrinfo(res);
    return 1;
  }

  if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
    perror("connect");
    freeaddrinfo(res);
    return 1;
  }

  freeaddrinfo(res);

  char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";

  int len = asprintf(&request, request, host);
  if (len < 0) {
    perror("asprintf");
    close(sockfd);
    return 1;
  }

  if (send(sockfd, request, len, 0) < 0) {
    perror("send");
    free(request);
    close(sockfd);
    return 1;
  }

  free(request);

  char buffer[1024];
  while (1) {
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
      perror("recv");
      close(sockfd);
      return 1;
    } else if (n == 0) {
      break;
    }

    if (fwrite(buffer, 1, n, stdout) < n) {
      perror("fwrite");
      close(sockfd);
      return 1;
    }
  }

  close(sockfd);

  return 0;
}