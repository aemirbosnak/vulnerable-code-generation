//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define MAX_LINE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
  int listen_sock, client_sock, bytes_read;
  struct sockaddr_in server_addr, client_addr;
  char buffer[MAX_LINE];

  listen_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_sock == -1) {
    perror("socket");
    exit(errno);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    exit(errno);
  }

  if (listen(listen_sock, 5) == -1) {
    perror("listen");
    exit(errno);
  }

  while (1) {
    client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
    if (client_sock == -1) {
      perror("accept");
      exit(errno);
    }

    printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
      bytes_read = recv(client_sock, buffer, MAX_LINE, 0);
      if (bytes_read <= 0) {
        if (bytes_read == 0) {
          printf("Client disconnected\n");
        } else {
          perror("recv");
          exit(errno);
        }
        break;
      }

      buffer[bytes_read] = '\0';
      printf("Received: %s", buffer);

      send(client_sock, buffer, strlen(buffer), 0);
    }

    close(client_sock);
  }

  close(listen_sock);
  return 0;
}