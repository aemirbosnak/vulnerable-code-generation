//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_REQUEST_SIZE 1024

int main(int argc, char** argv) {
  // Check if we have the right number of arguments
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Get the port number from the command line
  int port = atoi(argv[1]);

  // Create a socket for listening on
  int listening_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (listening_socket == -1) {
    perror("socket");
    return 1;
  }

  // Set the socket to be non-blocking
  if (fcntl(listening_socket, F_SETFL, O_NONBLOCK) == -1) {
    perror("fcntl");
    return 1;
  }

  // Bind the socket to the port
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);
  if (bind(listening_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return 1;
  }

  // Start listening on the socket
  if (listen(listening_socket, 5) == -1) {
    perror("listen");
    return 1;
  }

  // Loop forever, accepting new connections and serving requests
  while (1) {
    // Accept a new connection
    int client_socket = accept(listening_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Set the client socket to be non-blocking
    if (fcntl(client_socket, F_SETFL, O_NONBLOCK) == -1) {
      perror("fcntl");
      continue;
    }

    // Read the request from the client
    char request[MAX_REQUEST_SIZE];
    int request_length = read(client_socket, request, MAX_REQUEST_SIZE);
    if (request_length == -1) {
      perror("read");
      continue;
    }

    // Check if the request is valid
    if (request_length == 0 || strncmp(request, "GET /", 5) != 0) {
      write(client_socket, "HTTP/1.1 400 Bad Request\n\n", 28);
      continue;
    }

    // Get the filename from the request
    char filename[1024];
    sscanf(request, "GET /%s HTTP/1.1", filename);

    // Open the file
    int file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1) {
      write(client_socket, "HTTP/1.1 404 Not Found\n\n", 26);
      continue;
    }

    // Get the file size
    struct stat file_stat;
    fstat(file_descriptor, &file_stat);
    int file_size = file_stat.st_size;

    // Send the response to the client
    char response[MAX_REQUEST_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\nContent-Length: %d\n\n", file_size);
    write(client_socket, response, strlen(response));

    // Send the file contents to the client
    char buffer[1024];
    while (file_size > 0) {
      int bytes_read = read(file_descriptor, buffer, 1024);
      if (bytes_read == -1) {
        perror("read");
        break;
      }
      if (bytes_read == 0) {
        break;
      }
      write(client_socket, buffer, bytes_read);
      file_size -= bytes_read;
    }

    // Close the file
    close(file_descriptor);

    // Close the client socket
    close(client_socket);
  }

  // Close the listening socket
  close(listening_socket);

  return 0;
}