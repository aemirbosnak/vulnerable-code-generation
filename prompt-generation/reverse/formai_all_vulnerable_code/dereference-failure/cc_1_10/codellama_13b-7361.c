//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 256
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
  int sock_fd, client_fd, portno, n;
  struct sockaddr_in server, client;
  char message[MAX_MSG_SIZE];
  socklen_t client_len = sizeof(client);

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }
  portno = atoi(argv[1]);

  sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("socket failed");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(portno);

  if (bind(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind failed");
    exit(1);
  }

  if (listen(sock_fd, MAX_CLIENTS) < 0) {
    perror("listen failed");
    exit(1);
  }

  printf("Server started on port %d\n", portno);

  while (1) {
    client_fd = accept(sock_fd, (struct sockaddr *)&client, &client_len);
    if (client_fd < 0) {
      perror("accept failed");
      exit(1);
    }

    printf("Client connected: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    while (1) {
      n = recv(client_fd, message, MAX_MSG_SIZE, 0);
      if (n < 0) {
        perror("recv failed");
        break;
      }

      if (n == 0) {
        printf("Client disconnected\n");
        break;
      }

      printf("Received message: %s\n", message);

      send(client_fd, message, n, 0);
    }

    close(client_fd);
  }

  return 0;
}