//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <port> <remote_host>\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[1]);
  char *remote_host = argv[2];

  // Create a socket for listening for incoming connections.
  int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_socket == -1) {
    perror("socket");
    return 1;
  }

  // Bind the socket to the specified port.
  struct sockaddr_in listen_addr;
  memset(&listen_addr, 0, sizeof(listen_addr));
  listen_addr.sin_family = AF_INET;
  listen_addr.sin_addr.s_addr = INADDR_ANY;
  listen_addr.sin_port = htons(port);
  if (bind(listen_socket, (struct sockaddr *) &listen_addr, sizeof(listen_addr)) ==
      -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections.
  if (listen(listen_socket, 10) == -1) {
    perror("listen");
    return 1;
  }

  // Accept incoming connections.
  while (1) {
    int client_socket = accept(listen_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Read the HTTP request from the client.
    char buffer[BUFFER_SIZE];
    int bytes_read = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_read == -1) {
      perror("read");
      close(client_socket);
      continue;
    }
    buffer[bytes_read] = '\0';

    // Parse the HTTP request.
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    // Connect to the remote host.
    int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_socket == -1) {
      perror("socket");
      close(client_socket);
      continue;
    }

    struct sockaddr_in remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(remote_host);
    remote_addr.sin_port = htons(80);
    if (connect(remote_socket, (struct sockaddr *) &remote_addr,
                sizeof(remote_addr)) == -1) {
      perror("connect");
      close(client_socket);
      close(remote_socket);
      continue;
    }

    // Forward the HTTP request to the remote host.
    if (write(remote_socket, buffer, bytes_read) == -1) {
      perror("write");
      close(client_socket);
      close(remote_socket);
      continue;
    }

    // Read the HTTP response from the remote host.
    char response[BUFFER_SIZE];
    int response_bytes_read = read(remote_socket, response, BUFFER_SIZE - 1);
    if (response_bytes_read == -1) {
      perror("read");
      close(client_socket);
      close(remote_socket);
      continue;
    }
    response[response_bytes_read] = '\0';

    // Forward the HTTP response to the client.
    if (write(client_socket, response, response_bytes_read) == -1) {
      perror("write");
      close(client_socket);
      close(remote_socket);
      continue;
    }

    // Close the client socket.
    close(client_socket);

    // Close the remote socket.
    close(remote_socket);
  }

  // Close the listening socket.
  close(listen_socket);

  return 0;
}