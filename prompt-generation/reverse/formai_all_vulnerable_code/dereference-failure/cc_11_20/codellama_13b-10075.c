//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: shocked
// TCP/IP Programming Example Program in a Shocked Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_in server_addr;
  char buffer[1024];
  int n;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    exit(1);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[1]));
  server_addr.sin_addr.s_addr = INADDR_ANY;
  memset(server_addr.sin_zero, '\0', sizeof(server_addr.sin_zero));

  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind() failed");
    exit(1);
  }

  if (listen(sock, 3) < 0) {
    perror("listen() failed");
    exit(1);
  }

  printf("Server listening on port %d...\n", atoi(argv[1]));

  while (1) {
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
      perror("accept() failed");
      exit(1);
    }

    printf("Client connected...\n");

    while (1) {
      n = recv(client_sock, buffer, sizeof(buffer), 0);
      if (n < 0) {
        perror("recv() failed");
        exit(1);
      } else if (n == 0) {
        break;
      }

      printf("Received: %s\n", buffer);

      n = send(client_sock, buffer, n, 0);
      if (n < 0) {
        perror("send() failed");
        exit(1);
      }
    }

    printf("Client disconnected...\n");

    close(client_sock);
  }

  close(sock);

  return 0;
}