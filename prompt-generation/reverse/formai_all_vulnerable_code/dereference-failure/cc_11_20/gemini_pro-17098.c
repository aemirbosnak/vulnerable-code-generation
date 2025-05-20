//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int proxyPort;
  int clientSocket, serverSocket;
  struct sockaddr_in clientAddr, serverAddr;
  socklen_t clientAddrLen, serverAddrLen;
  char buf[BUFSIZE];
  int n;

  if (argc != 3) {
    printf("Usage: %s <proxy port> <destination address>\n", argv[0]);
    return 1;
  }

  proxyPort = atoi(argv[1]);

  // Create a TCP socket for the proxy
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket == -1) {
    perror("Could not create client socket");
    return 1;
  }

  // Bind the proxy socket to the specified port
  clientAddr.sin_family = AF_INET;
  clientAddr.sin_addr.s_addr = INADDR_ANY;
  clientAddr.sin_port = htons(proxyPort);
  if (bind(clientSocket, (struct sockaddr *)&clientAddr, sizeof(clientAddr)) == -1) {
    perror("Could not bind client socket");
    return 1;
  }

  // Listen for incoming connections on the proxy socket
  if (listen(clientSocket, 5) == -1) {
    perror("Could not listen on client socket");
    return 1;
  }

  while (1) {
    // Accept an incoming connection from a client
    clientAddrLen = sizeof(clientAddr);
    serverSocket = accept(clientSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
    if (serverSocket == -1) {
      perror("Could not accept client connection");
      continue;
    }

    // Read the HTTP request from the client
    n = read(serverSocket, buf, BUFSIZE);
    if (n == -1) {
      perror("Could not read HTTP request from client");
      close(serverSocket);
      continue;
    }

    // Determine the destination address and port from the HTTP request
    char *host = strstr(buf, "Host: ");
    if (host == NULL) {
      printf("Could not find Host header in HTTP request\n");
      close(serverSocket);
      continue;
    }

    host += strlen("Host: ");
    char *port = strchr(host, ':');
    if (port == NULL) {
      port = "80";
    } else {
      *port++ = '\0';
    }

    char *address = strtok(host, "\r\n");

    // Create a TCP socket for the connection to the destination server
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
      perror("Could not create server socket");
      close(serverSocket);
      continue;
    }

    // Resolve the destination address and port
    struct hostent *he = gethostbyname(address);
    if (he == NULL) {
      printf("Could not resolve destination address: %s\n", address);
      close(serverSocket);
      continue;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = ((struct in_addr *)he->h_addr)->s_addr;
    serverAddr.sin_port = htons(atoi(port));

    // Connect to the destination server
    if (connect(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
      perror("Could not connect to destination server");
      close(serverSocket);
      continue;
    }

    // Forward the HTTP request to the destination server
    if (write(serverSocket, buf, n) == -1) {
      perror("Could not write HTTP request to destination server");
      close(serverSocket);
      continue;
    }

    // Read the HTTP response from the destination server
    n = read(serverSocket, buf, BUFSIZE);
    if (n == -1) {
      perror("Could not read HTTP response from destination server");
      close(serverSocket);
      continue;
    }

    // Forward the HTTP response to the client
    if (write(clientSocket, buf, n) == -1) {
      perror("Could not write HTTP response to client");
      close(serverSocket);
      continue;
    }

    // Close the connections
    close(clientSocket);
    close(serverSocket);
  }

  return 0;
}