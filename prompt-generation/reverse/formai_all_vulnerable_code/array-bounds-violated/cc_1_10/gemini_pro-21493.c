//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000
#define MAX_CONNECTIONS 5
#define MAX_BUFFER_SIZE 1024

int main() {
  int server_socket, client_socket, addr_len, bytes_received, bytes_sent;
  char buffer[MAX_BUFFER_SIZE];
  struct sockaddr_in server_address, client_address;

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Error creating server socket");
    exit(1);
  }

  // Set up the server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  // Bind the server socket to the server address
  if (bind(server_socket, (struct sockaddr *) &server_address,
           sizeof(server_address)) < 0) {
    perror("Error binding server socket");
    exit(1);
  }

  // Listen for connections on the server socket
  if (listen(server_socket, MAX_CONNECTIONS) < 0) {
    perror("Error listening on server socket");
    exit(1);
  }

  // Accept connections from clients
  while (1) {
    addr_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &addr_len);
    if (client_socket < 0) {
      perror("Error accepting client connection");
      continue;
    }

    // Read the message from the client
    bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received < 0) {
      perror("Error receiving message from client");
      close(client_socket);
      continue;
    }

    // Process the message from the client
    buffer[bytes_received] = '\0';
    printf("Received message from client: %s\n", buffer);

    // Send a response to the client
    bytes_sent = send(client_socket, buffer, bytes_received, 0);
    if (bytes_sent < 0) {
      perror("Error sending message to client");
      close(client_socket);
      continue;
    }

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}