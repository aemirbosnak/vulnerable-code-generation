//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: introspective
/*
 * A simple web server in C
 *
 * Usage:
 * ./web_server [port]
 *
 * The server listens on the specified port for incoming requests, and responds
 * with a simple HTML page.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buffer[BUFSIZE];
  char html[] =
    "<html>\n"
    "<head>\n"
    "<title>Simple Web Server</title>\n"
    "</head>\n"
    "<body>\n"
    "<h1>Hello, World!</h1>\n"
    "</body>\n"
    "</html>\n";

  // Create a socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket");
    exit(1);
  }

  // Set the port and IP address of the server
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[1]));
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the port and IP address
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_fd, 5) < 0) {
    perror("listen");
    exit(1);
  }

  printf("Listening on port %d\n", ntohs(server_addr.sin_port));

  // Accept incoming connections
  client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
  if (client_fd < 0) {
    perror("accept");
    exit(1);
  }

  // Read data from the client
  read(client_fd, buffer, BUFSIZE);
  printf("Received data: %s\n", buffer);

  // Send a response back to the client
  write(client_fd, html, strlen(html));
  close(client_fd);

  return 0;
}