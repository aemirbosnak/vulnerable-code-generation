//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: genius
// Simple HTTP Proxy Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
  if (argc < 3) {
    printf("Usage: %s <listen_port> <upstream_host> <upstream_port>\n", argv[0]);
    return 1;
  }

  // Parse command-line arguments
  int listen_port = atoi(argv[1]);
  char *upstream_host = argv[2];
  int upstream_port = atoi(argv[3]);

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Bind socket to listen port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(listen_port);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind() failed");
    return 1;
  }

  // Listen for incoming connections
  if (listen(sock, 5) < 0) {
    perror("listen() failed");
    return 1;
  }

  printf("Listening on port %d...\n", listen_port);

  // Accept incoming connection
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
  if (client_sock < 0) {
    perror("accept() failed");
    return 1;
  }

  printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  // Connect to upstream server
  int upstream_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (upstream_sock < 0) {
    perror("socket() failed");
    return 1;
  }

  struct sockaddr_in upstream_addr;
  memset(&upstream_addr, 0, sizeof(upstream_addr));
  upstream_addr.sin_family = AF_INET;
  upstream_addr.sin_port = htons(upstream_port);
  upstream_addr.sin_addr.s_addr = inet_addr(upstream_host);
  if (connect(upstream_sock, (struct sockaddr *)&upstream_addr, sizeof(upstream_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  printf("Connected to upstream server: %s:%d\n", upstream_host, upstream_port);

  // Relay data between client and upstream server
  char buf[MAX_BUF_SIZE];
  int n;
  while ((n = recv(client_sock, buf, MAX_BUF_SIZE, 0)) > 0) {
    if (send(upstream_sock, buf, n, 0) < 0) {
      perror("send() failed");
      break;
    }
  }

  // Close sockets
  close(client_sock);
  close(upstream_sock);
  close(sock);

  return 0;
}