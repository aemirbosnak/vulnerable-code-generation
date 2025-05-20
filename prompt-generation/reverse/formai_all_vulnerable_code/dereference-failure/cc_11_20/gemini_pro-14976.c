//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: intelligent
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  char buffer[BUFFER_SIZE];
  int bytes_received, bytes_sent;

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return 1;
  }

  // Set the server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Bind the server socket to the address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_socket, 5) == -1) {
    perror("listen");
    return 1;
  }

  // Accept incoming connections
  while (1) {
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&client_address);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Receive the request from the client
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
      perror("recv");
      close(client_socket);
      continue;
    }

    // Parse the request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the method is GET
    if (strcmp(method, "GET") != 0) {
      // Send an error response
      bytes_sent = send(client_socket, "HTTP/1.1 405 Method Not Allowed\r\n\r\n", strlen("HTTP/1.1 405 Method Not Allowed\r\n\r\n"), 0);
      if (bytes_sent == -1) {
        perror("send");
      }
      close(client_socket);
      continue;
    }

    // Check if the path is valid
    if (strcmp(path, "/") != 0) {
      // Send an error response
      bytes_sent = send(client_socket, "HTTP/1.1 404 Not Found\r\n\r\n", strlen("HTTP/1.1 404 Not Found\r\n\r\n"), 0);
      if (bytes_sent == -1) {
        perror("send");
      }
      close(client_socket);
      continue;
    }

    // Send the response to the client
    bytes_sent = send(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, world!"), 0);
    if (bytes_sent == -1) {
      perror("send");
    }

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}