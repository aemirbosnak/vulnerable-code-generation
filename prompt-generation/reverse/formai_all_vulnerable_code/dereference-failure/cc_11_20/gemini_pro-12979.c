//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  socklen_t client_address_length;
  char buffer[BUFFER_SIZE];
  int bytes_received, bytes_sent;

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the server address
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Bind the server socket to the server address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  while (1) {
    client_address_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Read the request from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
      perror("recv");
      continue;
    }

    // Parse the request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0 || strcmp(http_version, "HTTP/1.1") != 0) {
      bytes_sent = send(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", 32, 0);
      if (bytes_sent == -1) {
        perror("send");
      }
      continue;
    }

    // Get the hostname from the path
    char *hostname = strtok(path, "/");

    // Get the port number from the path
    char *port = strtok(NULL, "/");
    if (port == NULL) {
      port = "80";
    }

    // Create the client socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
      perror("socket");
      continue;
    }

    // Set the client address
    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_port = htons(atoi(port));
    client_address.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&client_address, sizeof(client_address)) == -1) {
      perror("connect");
      continue;
    }

    // Send the request to the server
    bytes_sent = send(client_socket, buffer, bytes_received, 0);
    if (bytes_sent == -1) {
      perror("send");
      continue;
    }

    // Receive the response from the server
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
      perror("recv");
      continue;
    }

    // Send the response to the client
    bytes_sent = send(client_socket, buffer, bytes_received, 0);
    if (bytes_sent == -1) {
      perror("send");
      continue;
    }

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}