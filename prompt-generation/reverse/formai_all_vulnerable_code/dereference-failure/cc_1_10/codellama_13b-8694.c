//Code Llama-13B DATASET v1.0 Category: Networking ; Style: synchronous
/*
 *  Synchronous networking example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  int sock, n, i;
  struct sockaddr_in server_addr;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  char buf[BUF_SIZE];

  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Error creating socket\n");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(atoi(argv[1]));

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error binding to port\n");
    exit(1);
  }

  if (listen(sock, 3) < 0) {
    printf("Error listening on socket\n");
    exit(1);
  }

  printf("Server listening on port %s\n", argv[1]);

  while (1) {
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
      printf("Error accepting connection\n");
      continue;
    }

    n = read(client_sock, buf, BUF_SIZE);
    if (n < 0) {
      printf("Error reading from client\n");
      close(client_sock);
      continue;
    }

    printf("Received message from client: %s\n", buf);

    n = write(client_sock, "Hello, client!", 13);
    if (n < 0) {
      printf("Error writing to client\n");
      close(client_sock);
      continue;
    }

    close(client_sock);
  }

  close(sock);
  return 0;
}