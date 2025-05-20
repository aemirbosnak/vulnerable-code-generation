//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Check if the correct number of arguments is provided
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <document_root>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the port number and document root from the arguments
  int port = atoi(argv[1]);
  char *document_root = argv[2];

  // Create a socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Set up the server address
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);

  // Bind the socket to the server address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    fprintf(stderr, "Error listening for connections: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Main loop
  while (1) {
    // Accept an incoming connection
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
    if (client_socket == -1) {
      fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
      continue;
    }

    // Read the request from the client
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    ssize_t bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
      fprintf(stderr, "Error receiving request: %s\n", strerror(errno));
      close(client_socket);
      continue;
    }

    // Parse the request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *protocol = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (method == NULL || path == NULL || protocol == NULL) {
      fprintf(stderr, "Error parsing request: %s\n", buffer);
      close(client_socket);
      continue;
    }

    // Check if the method is supported
    if (strcmp(method, "GET") != 0) {
      fprintf(stderr, "Error: unsupported method: %s\n", method);
      close(client_socket);
      continue;
    }

    // Check if the path is valid
    if (strcmp(path, "/") == 0) {
      path = "/index.html";
    } else {
      if (path[0] != '/') {
        fprintf(stderr, "Error: invalid path: %s\n", path);
        close(client_socket);
        continue;
      }
    }

    // Check if the file exists
    char filename[MAX_BUFFER_SIZE];
    snprintf(filename, MAX_BUFFER_SIZE, "%s%s", document_root, path);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
      fprintf(stderr, "Error opening file: %s\n", strerror(errno));
      close(client_socket);
      continue;
    }

    // Read the file into a buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *file_buffer = malloc(file_size);
    if (file_buffer == NULL) {
      fprintf(stderr, "Error allocating memory for file buffer: %s\n", strerror(errno));
      close(client_socket);
      continue;
    }
    fread(file_buffer, file_size, 1, file);
    fclose(file);

    // Send the response to the client
    char response[MAX_BUFFER_SIZE];
    snprintf(response, MAX_BUFFER_SIZE, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\n\r\n%s", file_size, file_buffer);
    ssize_t bytes_sent = send(client_socket, response, strlen(response), 0);
    if (bytes_sent == -1) {
      fprintf(stderr, "Error sending response: %s\n", strerror(errno));
      close(client_socket);
      continue;
    }

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return EXIT_SUCCESS;
}