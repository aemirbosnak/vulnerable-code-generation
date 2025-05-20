//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
  int listen_socket, client_socket, remote_socket;
  struct sockaddr_in listen_addr, client_addr, remote_addr;
  char buffer[MAX_BUFFER_SIZE];
  int bytes_received, bytes_sent;

  if (argc != 3) {
    printf("Usage: %s <port> <remote_host>\n", argv[0]);
    return 1;
  }

  listen_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_socket == -1) {
    perror("socket");
    return 1;
  }

  memset(&listen_addr, 0, sizeof(listen_addr));
  listen_addr.sin_family = AF_INET;
  listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  listen_addr.sin_port = htons(atoi(argv[1]));

  if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
    perror("bind");
    return 1;
  }

  if (listen(listen_socket, 5) == -1) {
    perror("listen");
    return 1;
  }

  while (1) {
    client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while ((bytes_received = recv(client_socket, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
      remote_socket = socket(AF_INET, SOCK_STREAM, 0);
      if (remote_socket == -1) {
        perror("socket");
        continue;
      }

      memset(&remote_addr, 0, sizeof(remote_addr));
      remote_addr.sin_family = AF_INET;
      remote_addr.sin_addr.s_addr = inet_addr(argv[2]);
      remote_addr.sin_port = htons(80);

      if (connect(remote_socket, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
        perror("connect");
        continue;
      }

      if (send(remote_socket, buffer, bytes_received, 0) == -1) {
        perror("send");
        continue;
      }

      while ((bytes_received = recv(remote_socket, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        if (send(client_socket, buffer, bytes_received, 0) == -1) {
          perror("send");
          continue;
        }
      }

      close(remote_socket);
    }

    close(client_socket);
  }

  close(listen_socket);

  return 0;
}