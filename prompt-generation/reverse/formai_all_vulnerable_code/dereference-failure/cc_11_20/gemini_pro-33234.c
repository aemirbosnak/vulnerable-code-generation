//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// HTTP response codes
#define HTTP_OK 200
#define HTTP_NOT_FOUND 404
#define HTTP_BAD_REQUEST 400

// HTTP headers
#define HEADER_CONTENT_TYPE "Content-Type: text/html\r\n"
#define HEADER_CONTENT_LENGTH "Content-Length: "
#define HEADER_CONNECTION "Connection: close\r\n"

// Maximum buffer size
#define BUFFER_SIZE 1024

// Main function
int main(int argc, char **argv) {
  // Check if the correct number of arguments was provided
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the port number
  int port = atoi(argv[1]);

  // Create a socket
  int listener = socket(AF_INET, SOCK_STREAM, 0);
  if (listener < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set the socket options
  int reuseaddr = 1;
  if (setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(int)) < 0) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }

  // Bind the socket to the port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(port);
  if (bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for incoming connections
  if (listen(listener, 5) < 0) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept incoming connections
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  while (1) {
    int client = accept(listener, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client < 0) {
      perror("accept");
      continue;
    }

    // Read the HTTP request
    char buffer[BUFFER_SIZE];
    int bytes_read = read(client, buffer, BUFFER_SIZE - 1);
    if (bytes_read < 0) {
      perror("read");
      close(client);
      continue;
    }
    buffer[bytes_read] = '\0';

    // Parse the HTTP request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check if the request is valid
    if (strcmp(method, "GET") != 0) {
      // Send a 400 Bad Request response
      char response[] = "HTTP/1.1 400 Bad Request\r\n"
                        HEADER_CONTENT_TYPE
                        HEADER_CONTENT_LENGTH "0\r\n"
                        HEADER_CONNECTION
                        "\r\n";
      write(client, response, strlen(response));
      close(client);
      continue;
    }

    // Check if the path is valid
    if (strcmp(path, "/") != 0) {
      // Send a 404 Not Found response
      char response[] = "HTTP/1.1 404 Not Found\r\n"
                        HEADER_CONTENT_TYPE
                        HEADER_CONTENT_LENGTH "0\r\n"
                        HEADER_CONNECTION
                        "\r\n";
      write(client, response, strlen(response));
      close(client);
      continue;
    }

    // Send a 200 OK response
    char response[] = "HTTP/1.1 200 OK\r\n"
                      HEADER_CONTENT_TYPE
                      HEADER_CONTENT_LENGTH "11\r\n"
                      HEADER_CONNECTION
                      "\r\n"
                      "Hello World!";
    write(client, response, strlen(response));

    // Close the client connection
    close(client);
  }

  // Close the listening socket
  close(listener);

  return EXIT_SUCCESS;
}