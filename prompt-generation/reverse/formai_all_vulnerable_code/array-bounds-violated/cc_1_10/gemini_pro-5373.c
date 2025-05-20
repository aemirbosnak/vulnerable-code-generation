//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  char request[4096], response[4096];
  int request_len, response_len;

  // Create the server socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket() failed");
    return EXIT_FAILURE;
  }

  // Set up the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind() failed");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(server_fd, MAX_CLIENTS) < 0) {
    perror("listen() failed");
    return EXIT_FAILURE;
  }

  while (1) {
    // Accept a client connection
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr);
    if (client_fd < 0) {
      perror("accept() failed");
      continue;
    }

    // Read the request from the client
    request_len = recv(client_fd, request, sizeof(request) - 1, 0);
    if (request_len < 0) {
      perror("recv() failed");
      close(client_fd);
      continue;
    }

    request[request_len] = '\0';

    // Print the request to the console for fun
    printf("Request:\n%s\n", request);

    // Send a fake response to the client
    response_len = sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>\r\n");

    // Send the response to the client
    if (send(client_fd, response, response_len, 0) < 0) {
      perror("send() failed");
      close(client_fd);
      continue;
    }

    // Close the client connection
    close(client_fd);
  }

  // Close the server socket
  close(server_fd);

  return EXIT_SUCCESS;
}