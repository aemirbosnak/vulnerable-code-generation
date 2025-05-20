#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
  int listenPort, remotePort;
  char remoteHost[1024];

  if (argc < 4) {
    fprintf(stderr, "Usage: ./proxy listenPort remoteHost:port\n");
    exit(1);
  }

  sscanf(argv[2], "%d", &listenPort);
  sscanf(argv[3], "%s", remoteHost);
  sscanf(argv[3] + strlen(remoteHost) + 1, "%d", &remotePort);

  // ... Implement the proxy logic here ...

  return 0;
}
