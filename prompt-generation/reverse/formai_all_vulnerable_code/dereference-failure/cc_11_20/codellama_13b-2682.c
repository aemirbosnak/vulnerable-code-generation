//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  struct addrinfo *result, *rp;
  if (getaddrinfo(argv[1], argv[2], &hints, &result) != 0) {
    fprintf(stderr, "getaddrinfo() failed: %s\n", gai_strerror(errno));
    return 1;
  }

  int sock = -1;
  for (rp = result; rp != NULL; rp = rp->ai_next) {
    sock = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    if (sock == -1) {
      continue;
    }

    if (connect(sock, rp->ai_addr, rp->ai_addrlen) == 0) {
      break;
    }

    close(sock);
    sock = -1;
  }

  if (sock == -1) {
    fprintf(stderr, "connect() failed\n");
    return 1;
  }

  char buf[MAX_LINE_LEN];
  char cmd[MAX_LINE_LEN];
  while (fgets(cmd, MAX_LINE_LEN, stdin) != NULL) {
    if (strcmp(cmd, "CLOSE\n") == 0) {
      close(sock);
      break;
    }

    if (send(sock, cmd, strlen(cmd), 0) < 0) {
      fprintf(stderr, "send() failed\n");
      return 1;
    }

    int n = recv(sock, buf, MAX_LINE_LEN, 0);
    if (n < 0) {
      fprintf(stderr, "recv() failed\n");
      return 1;
    }

    printf("%.*s", n, buf);
  }

  freeaddrinfo(result);
  return 0;
}