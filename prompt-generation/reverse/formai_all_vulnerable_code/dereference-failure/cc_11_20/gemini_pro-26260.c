//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
  // Check arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <proxy_port> <target_host>\n", argv[0]);
    return 1;
  }

  // Get proxy port and target host
  int proxy_port = atoi(argv[1]);
  char *target_host = argv[2];

  // Create proxy socket
  int proxy_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (proxy_sock < 0) {
    perror("socket");
    return 1;
  }

  // Bind proxy socket to address
  struct sockaddr_in proxy_addr;
  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_port = htons(proxy_port);
  proxy_addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(proxy_sock, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
    perror("bind");
    return 1;
  }

  // Listen on proxy socket
  if (listen(proxy_sock, 5) < 0) {
    perror("listen");
    return 1;
  }

  // Main loop
  while (1) {
    // Accept client connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(proxy_sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock < 0) {
      perror("accept");
      continue;
    }

    // Fork child process to handle client request
    pid_t pid = fork();
    if (pid < 0) {
      perror("fork");
      close(client_sock);
      continue;
    } else if (pid == 0) {
      // Child process

      // Send HTTP request to target host
      int target_sock = socket(AF_INET, SOCK_STREAM, 0);
      if (target_sock < 0) {
        perror("socket");
        exit(1);
      }
      struct sockaddr_in target_addr;
      target_addr.sin_family = AF_INET;
      target_addr.sin_port = htons(80);
      target_addr.sin_addr.s_addr = inet_addr(target_host);
      if (connect(target_sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        perror("connect");
        exit(1);
      }

      // Read request from client
      char buf[MAX_BUF_SIZE];
      int bytes_read = read(client_sock, buf, MAX_BUF_SIZE - 1);
      if (bytes_read < 0) {
        perror("read");
        exit(1);
      }
      buf[bytes_read] = '\0';

      // Send request to target host
      if (write(target_sock, buf, bytes_read) < 0) {
        perror("write");
        exit(1);
      }

      // Read response from target host
      bytes_read = read(target_sock, buf, MAX_BUF_SIZE - 1);
      if (bytes_read < 0) {
        perror("read");
        exit(1);
      }
      buf[bytes_read] = '\0';

      // Send response to client
      if (write(client_sock, buf, bytes_read) < 0) {
        perror("write");
        exit(1);
      }

      // Close client and target sockets
      close(client_sock);
      close(target_sock);

      // Exit child process
      exit(0);
    } else {
      // Parent process

      // Close client socket
      close(client_sock);
    }
  }

  // Close proxy socket
  close(proxy_sock);

  return 0;
}