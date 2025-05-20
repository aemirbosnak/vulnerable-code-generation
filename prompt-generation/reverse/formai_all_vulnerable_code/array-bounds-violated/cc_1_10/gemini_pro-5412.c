//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Server program
int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  socklen_t client_address_length;
  char buffer[1024];

  // Create a server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating server socket");
    return EXIT_FAILURE;
  }

  // Set up server address
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(12345);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Bind the server socket to the server address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Error binding server socket to address");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) == -1) {
    perror("Error listening for incoming connections");
    return EXIT_FAILURE;
  }

  // Accept incoming connection
  client_address_length = sizeof(client_address);
  client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
  if (client_socket == -1) {
    perror("Error accepting incoming connection");
    return EXIT_FAILURE;
  }

  // Receive data from the client
  int num_bytes_received;
  do {
    num_bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (num_bytes_received == -1) {
      perror("Error receiving data from client");
      return EXIT_FAILURE;
    }
    buffer[num_bytes_received] = '\0';
    printf("Received from client: %s\n", buffer);
  } while (num_bytes_received > 0);

  // Send data to the client
  char *message = "Hello from server!";
  if (send(client_socket, message, strlen(message), 0) == -1) {
    perror("Error sending data to client");
    return EXIT_FAILURE;
  }

  // Close the client socket
  close(client_socket);

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}