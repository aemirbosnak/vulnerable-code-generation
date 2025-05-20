//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <proxy_ip> <proxy_port>", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *proxy_ip = argv[1];
  int proxy_port = atoi(argv[2]);

  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr, proxy_addr;
  char buffer[BUFFER_SIZE];
  int bytes_received;

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(proxy_port);

  if (bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, SOMAXCONN) == -1) {
    perror("Error listening to socket");
    exit(EXIT_FAILURE);
  }

  printf("Proxy server started on port %d\n", proxy_port);

  while (1) {
    socklen_t client_addr_len = sizeof(client_addr);
    client_fd = accept(server_fd, (struct sockaddr*) &client_addr, &client_addr_len);

    if (client_fd == -1) {
      perror("Error accepting client connection");
      continue;
    }

    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_port = htons(80);
    if (inet_pton(AF_INET, "www.google.com", &proxy_addr.sin_addr) != 1) {
      perror("Error setting proxy address");
      close(client_fd);
      continue;
    }

    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd == -1) {
      perror("Error creating proxy socket");
      close(client_fd);
      continue;
    }

    if (connect(proxy_fd, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr)) == -1) {
      perror("Error connecting to proxy host");
      close(client_fd);
      close(proxy_fd);
      continue;
    }

    printf("Proxying request from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while ((bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
      if (send(proxy_fd, buffer, bytes_received, 0) == -1) {
        perror("Error sending request to proxy");
        break;
      }
    }

    if (bytes_received == -1) {
      perror("Error receiving client request");
    }

    close(proxy_fd);
    close(client_fd);
  }

  close(server_fd);

  return EXIT_SUCCESS;
}