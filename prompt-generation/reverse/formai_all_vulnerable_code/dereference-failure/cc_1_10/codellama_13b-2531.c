//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: recursive
/*
 * Recursive Socket Programming Example
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 5
#define BUF_SIZE 1024

void client_handler(int sock) {
  char buf[BUF_SIZE];
  memset(buf, 0, BUF_SIZE);
  recv(sock, buf, BUF_SIZE, 0);
  printf("Received: %s\n", buf);
  close(sock);
}

void server_handler(int sock) {
  int new_sock;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buf[BUF_SIZE];
  memset(buf, 0, BUF_SIZE);

  for (int i = 0; i < MAX_CLIENTS; i++) {
    new_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (new_sock < 0) {
      perror("accept");
      continue;
    }
    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    client_handler(new_sock);
  }
}

int main(int argc, char *argv[]) {
  int sock, new_sock;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buf[BUF_SIZE];
  memset(buf, 0, BUF_SIZE);

  if (argc < 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[1]));
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(sock, 5) < 0) {
    perror("listen");
    return 1;
  }

  printf("Server listening on port %d\n", ntohs(server_addr.sin_port));

  server_handler(sock);

  return 0;
}