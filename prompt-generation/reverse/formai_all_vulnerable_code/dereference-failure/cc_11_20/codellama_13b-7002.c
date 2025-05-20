//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Donald Knuth
// Simple HTTP Proxy Program in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[1]);
  if (port <= 0) {
    fprintf(stderr, "Invalid port: %s\n", argv[1]);
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server;
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = INADDR_ANY;

  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(sock, 10) < 0) {
    perror("listen");
    return 1;
  }

  printf("Listening on port %d...\n", port);

  while (1) {
    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
      perror("accept");
      continue;
    }

    printf("New connection from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    char request[1024];
    if (read(client_sock, request, 1024) < 0) {
      perror("read");
      close(client_sock);
      continue;
    }

    printf("Request: %s\n", request);

    char *method = strtok(request, " ");
    char *url = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    if (strcmp(method, "GET") != 0) {
      printf("Invalid request method: %s\n", method);
      close(client_sock);
      continue;
    }

    char response[1024];
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: 1024\r\n\r\nHello, world!");

    if (write(client_sock, response, strlen(response)) < 0) {
      perror("write");
      close(client_sock);
      continue;
    }

    close(client_sock);
  }

  return 0;
}