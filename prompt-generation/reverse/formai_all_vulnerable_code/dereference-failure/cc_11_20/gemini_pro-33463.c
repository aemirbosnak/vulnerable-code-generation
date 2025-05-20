//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#ifndef PORT
#define PORT 8000
#endif

#define BUFFERSIZE 1024

int main() {
  // Create the server socket.
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to the port.
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    exit(1);
  }

  // Start listening for connections.
  if (listen(server_socket, 5) == -1) {
    perror("listen");
    exit(1);
  }

  // Accept a connection from a client.
  int client_socket = accept(server_socket, NULL, NULL);
  if (client_socket == -1) {
    perror("accept");
    exit(1);
  }

  // Read a message from the client.
  char buffer[BUFFERSIZE];
  memset(buffer, 0, sizeof(buffer));
  if (read(client_socket, buffer, BUFFERSIZE) == -1) {
    perror("read");
    exit(1);
  }

  // Verify the message.
  int length = strlen(buffer);
  if (length == 0 || buffer[length - 1] != '\n') {
    printf("Invalid message\n");
    exit(1);
  }

  // Send a response to the client.
  char response[BUFFERSIZE];
  memset(response, 0, sizeof(response));
  sprintf(response, "Hello, %s", buffer);
  if (write(client_socket, response, strlen(response)) == -1) {
    perror("write");
    exit(1);
  }

  // Close the client socket.
  if (close(client_socket) == -1) {
    perror("close");
    exit(1);
  }

  // Close the server socket.
  if (close(server_socket) == -1) {
    perror("close");
    exit(1);
  }

  return 0;
}