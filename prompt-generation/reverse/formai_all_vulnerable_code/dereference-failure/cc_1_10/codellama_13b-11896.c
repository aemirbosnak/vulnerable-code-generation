//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buffer[MAX_BUFFER_SIZE];
  int n;

  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("socket");
    return 1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(atoi(argv[1]));

  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(server_fd, MAX_CLIENTS) < 0) {
    perror("listen");
    return 1;
  }

  printf("Server listening on port %d\n", atoi(argv[1]));

  while (1) {
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
    if (client_fd < 0) {
      perror("accept");
      return 1;
    }

    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
      n = read(client_fd, buffer, MAX_BUFFER_SIZE);
      if (n < 0) {
        perror("read");
        break;
      }

      printf("Received: %s\n", buffer);

      n = write(client_fd, buffer, n);
      if (n < 0) {
        perror("write");
        break;
      }
    }

    close(client_fd);
  }

  close(server_fd);
  return 0;
}