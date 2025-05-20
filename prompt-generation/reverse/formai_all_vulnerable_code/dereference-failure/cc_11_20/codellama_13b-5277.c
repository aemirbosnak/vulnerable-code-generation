//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
  int sock, client_sock, port, n, i;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len = sizeof(client_addr);

  if (argc < 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[1]);

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    exit(1);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind() failed");
    exit(1);
  }

  if (listen(sock, MAX_CLIENTS) < 0) {
    perror("listen() failed");
    exit(1);
  }

  printf("Server started and listening on port %d\n", port);

  while (1) {
    client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock < 0) {
      perror("accept() failed");
      exit(1);
    }

    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
      memset(buffer, 0, BUFFER_SIZE);
      n = recv(client_sock, buffer, BUFFER_SIZE, 0);
      if (n < 0) {
        perror("recv() failed");
        exit(1);
      } else if (n == 0) {
        printf("Client disconnected\n");
        break;
      }

      printf("Client message: %s\n", buffer);

      n = send(client_sock, buffer, n, 0);
      if (n < 0) {
        perror("send() failed");
        exit(1);
      }
    }

    close(client_sock);
  }

  close(sock);

  return 0;
}