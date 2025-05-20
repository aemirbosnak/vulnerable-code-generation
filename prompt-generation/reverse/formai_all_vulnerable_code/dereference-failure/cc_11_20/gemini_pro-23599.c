//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
  // Check arguments
  if (argc != 3) {
    printf("Usage: %s <port> <server>\n", argv[0]);
    return 1;
  }

  // Initialize variables
  int port = atoi(argv[1]);
  char *server = argv[2];
  int client_socket, server_socket, client_len, server_len;
  struct sockaddr_in client_addr, server_addr;
  char buffer[MAX_BUFFER];

  // Create client socket
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("socket");
    return 1;
  }

  // Initialize client address
  client_addr.sin_family = AF_INET;
  client_addr.sin_addr.s_addr = INADDR_ANY;
  client_addr.sin_port = htons(port);

  // Bind client socket
  if (bind(client_socket, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
    perror("bind");
    return 1;
  }

  // Listen for connections
  listen(client_socket, 5);

  // Accept connections
  while (1) {
    client_len = sizeof(client_addr);
    server_len = sizeof(server_addr);

    // Accept client connection
    server_socket = accept(client_socket, (struct sockaddr *)&server_addr, &server_len);
    if (server_socket < 0) {
      perror("accept");
      continue;
    }

    // Read request from client
    int n = read(server_socket, buffer, MAX_BUFFER);
    if (n < 0) {
      perror("read");
      close(server_socket);
      continue;
    }

    // Parse request
    char *host = strstr(buffer, "Host: ");
    if (host == NULL) {
      close(server_socket);
      continue;
    }
    host += 6;
    char *end = strchr(host, '\n');
    *end = '\0';

    // Connect to server
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
      perror("socket");
      close(server_socket);
      continue;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(80);

    if (connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("connect");
      close(server_socket);
      close(server_sock);
      continue;
    }

    // Send request to server
    write(server_sock, buffer, n);

    // Read response from server
    while (1) {
      n = read(server_sock, buffer, MAX_BUFFER);
      if (n <= 0) {
        break;
      }

      // Send response to client
      write(server_socket, buffer, n);
    }

    // Close connections
    close(server_socket);
    close(server_sock);
  }

  return 0;
}