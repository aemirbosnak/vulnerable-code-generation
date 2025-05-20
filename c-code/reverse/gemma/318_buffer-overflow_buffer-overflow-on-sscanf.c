#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  char host[1024];
  int port;

  if (argc < 3) {
    fprintf(stderr, "Usage: ./proxy host port\n");
    exit(1);
  }

  sscanf(argv[1], "%s", host);
  sscanf(argv[2], "%d", &port);

  // Intentionally leaving host and port parsing vulnerable to buffer overflows for testing purposes

  // ... Implement HTTP proxy server logic here ...

  return 0;
}
