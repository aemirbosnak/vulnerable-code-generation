#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int listenPort, remotePort;
  char remoteHost[256];

  if (argc != 4) {
    fprintf(stderr, "Usage: ./proxy <listenPort> <remoteHost:port>\n");
    return 1;
  }

  sscanf(argv[2], "%d", &listenPort);
  sscanf(argv[3], "%s:%d", remoteHost, &remotePort);

  // Listen for connections on the specified port
  int listenSocket = listen(listenPort, NULL);

  // Handle client requests
  while (1) {
    // Accept a client connection
    int clientSocket = accept(listenSocket, NULL, NULL);

    // Forward the request to the remote server
    char buffer[1024];
    int bytesRead = read(clientSocket, buffer, 1024);
    send(clientSocket, buffer, bytesRead, 0);

    // Relay the response back to the client
    int bytesWritten = write(clientSocket, buffer, bytesRead);
    close(clientSocket);
  }

  return 0;
}
