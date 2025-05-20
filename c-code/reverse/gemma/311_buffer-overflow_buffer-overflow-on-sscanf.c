#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int listenPort, remoteHostPort;
  char remoteHost[256];

  if (argc != 3) {
    fprintf(stderr, "Usage: ./proxy <listenPort> <remoteHost:port>\n");
    return 1;
  }

  sscanf(argv[1], "%d", &listenPort);
  sscanf(argv[2], "%s:%d", remoteHost, &remoteHostPort);

  int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
  bind(listenSocket, NULL, 0);

  for (;;) {
    int clientSocket = accept(listenSocket, NULL, NULL);
    fork();

    char buffer[1024];
    int bytesRead = read(clientSocket, buffer, 1024);
    write(clientSocket, buffer, bytesRead);

    close(clientSocket);
  }

  return 0;
}
