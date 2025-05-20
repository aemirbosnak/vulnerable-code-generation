//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  int port = atoi(argv[1]);
  int server_fd, new_socket;
  struct sockaddr_in server_addr, client_addr;
  int addrlen = sizeof(client_addr);

  if (port <= 0 || port >= 65536) {
    fprintf(stderr, "Invalid port number\n");
    exit(1);
  }

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    fprintf(stderr, "Failed to create socket\n");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(port);

  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    fprintf(stderr, "Failed to bind socket\n");
    exit(1);
  }

  if (listen(server_fd, 5) < 0) {
    fprintf(stderr, "Failed to listen on socket\n");
    exit(1);
  }

  while (1) {
    new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
    if (new_socket < 0) {
      fprintf(stderr, "Failed to accept connection\n");
      continue;
    }

    char buffer[1024];
    int n = read(new_socket, buffer, sizeof(buffer));
    if (n < 0) {
      fprintf(stderr, "Failed to read from socket\n");
      continue;
    }

    printf("Received: %s\n", buffer);
    if (strstr(buffer, "GET /")!= NULL) {
      char response[1024];
      sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Welcome to the Ada Lovelace Web Server!</h1>");
      write(new_socket, response, strlen(response));
    }

    close(new_socket);
  }

  return 0;
}