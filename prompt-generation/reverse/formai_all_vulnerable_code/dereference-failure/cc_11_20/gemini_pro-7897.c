//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// The port number to listen on
#define PORT 8080

// The maximum number of clients that can be connected at once
#define MAX_CLIENTS 10

// The maximum size of a request
#define MAX_REQUEST_SIZE 1024

// The maximum size of a response
#define MAX_RESPONSE_SIZE 1024

// The directory containing the static files to serve
#define STATIC_DIR "static"

// The main function
int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Set the socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
    perror("setsockopt");
    return 1;
  }

  // Bind the socket to the port
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return 1;
  }

  // Listen for connections
  if (listen(sockfd, MAX_CLIENTS) < 0) {
    perror("listen");
    return 1;
  }

  // Accept connections and handle them in a loop
  while (1) {
    // Accept a connection
    int clientfd = accept(sockfd, NULL, NULL);
    if (clientfd < 0) {
      perror("accept");
      continue;
    }

    // Read the request
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, MAX_REQUEST_SIZE);
    int request_size = recv(clientfd, request, MAX_REQUEST_SIZE - 1, 0);
    if (request_size < 0) {
      perror("recv");
      close(clientfd);
      continue;
    }

    // Parse the request
    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");
    char *protocol = strtok(NULL, "\r\n");

    // Check if the method is valid
    if (strcmp(method, "GET") != 0) {
      // Send a 405 Method Not Allowed response
      char response[MAX_RESPONSE_SIZE];
      memset(response, 0, MAX_RESPONSE_SIZE);
      sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\n\r\n");
      int response_size = strlen(response);
      send(clientfd, response, response_size, 0);
      close(clientfd);
      continue;
    }

    // Check if the path is valid
    if (strcmp(path, "/") == 0) {
      path = "/index.html";
    }

    char filepath[MAX_REQUEST_SIZE];
    memset(filepath, 0, MAX_REQUEST_SIZE);
    sprintf(filepath, "%s%s", STATIC_DIR, path);

    FILE *file = fopen(filepath, "r");
    if (file == NULL) {
      // Send a 404 Not Found response
      char response[MAX_RESPONSE_SIZE];
      memset(response, 0, MAX_RESPONSE_SIZE);
      sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\n");
      int response_size = strlen(response);
      send(clientfd, response, response_size, 0);
      close(clientfd);
      continue;
    }

    // Send a 200 OK response
    char response[MAX_RESPONSE_SIZE];
    memset(response, 0, MAX_RESPONSE_SIZE);
    sprintf(response, "HTTP/1.1 200 OK\r\n\r\n");
    int response_size = strlen(response);
    send(clientfd, response, response_size, 0);

    // Send the file contents
    char buffer[MAX_REQUEST_SIZE];
    memset(buffer, 0, MAX_REQUEST_SIZE);
    while (fread(buffer, 1, MAX_REQUEST_SIZE - 1, file) > 0) {
      send(clientfd, buffer, strlen(buffer), 0);
    }

    // Close the file
    fclose(file);

    // Close the connection
    close(clientfd);
  }

  return 0;
}