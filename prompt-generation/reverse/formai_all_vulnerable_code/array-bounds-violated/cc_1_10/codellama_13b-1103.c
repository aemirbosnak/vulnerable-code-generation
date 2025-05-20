//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[1]);
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);

  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(sock, 1) < 0) {
    perror("listen");
    return 1;
  }

  printf("Listening on port %d\n", port);

  while (1) {
    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);

    int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
      perror("accept");
      return 1;
    }

    char buffer[BUFFER_SIZE];
    int n = recv(client_sock, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
      perror("recv");
      return 1;
    }

    buffer[n] = '\0';
    printf("Received request: %s\n", buffer);

    char response[] = "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n";
    send(client_sock, response, sizeof(response), 0);

    close(client_sock);
  }

  close(sock);
  return 0;
}