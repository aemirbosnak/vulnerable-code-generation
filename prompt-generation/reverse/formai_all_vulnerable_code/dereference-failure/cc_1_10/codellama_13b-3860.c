//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <host>\n", argv[0]);
    return 1;
  }

  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_NUMERICHOST | AI_NUMERICSERV;

  int err = getaddrinfo(argv[1], NULL, &hints, &res);
  if (err) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
    return 1;
  }

  int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (sock < 0) {
    fprintf(stderr, "socket: %s\n", strerror(errno));
    return 1;
  }

  for (int port = 1; port <= PORT_RANGE; port++) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = ((struct sockaddr_in*)res->ai_addr)->sin_addr;

    err = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    if (err < 0) {
      continue;
    }

    fprintf(stdout, "Port %d is open\n", port);
  }

  close(sock);
  freeaddrinfo(res);

  return 0;
}