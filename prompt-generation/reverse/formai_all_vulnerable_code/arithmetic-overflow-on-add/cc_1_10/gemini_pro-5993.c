//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <assert.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10

struct connection {
  int fd;
  struct sockaddr_in addr;
};

struct server {
  int fd;
  struct connection connections[MAX_CONNECTIONS];
  int num_connections;
};

void handle_connection(struct server *server, int fd) {
  char buffer[1024];
  int bytes_read;

  while ((bytes_read = read(fd, buffer, sizeof(buffer)))) {
    if (bytes_read < 0) {
      perror("read");
      close(fd);
      return;
    }

    write(fd, buffer, bytes_read);
  }

  close(fd);
}

void accept_loop(struct server *server) {
  while (1) {
    int fd = accept(server->fd, (struct sockaddr *) &server->connections[server->num_connections].addr, sizeof(server->connections[server->num_connections].addr));
    if (fd < 0) {
      perror("accept");
      continue;
    }

    server->connections[server->num_connections].fd = fd;
    server->num_connections++;

    handle_connection(server, fd);
  }
}

int main(int argc, char *argv[]) {
  struct server server;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  server.fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server.fd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  int optval = 1;
  if (setsockopt(server.fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
    perror("setsockopt");
    close(server.fd);
    return EXIT_FAILURE;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(atoi(argv[1]));

  if (bind(server.fd, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
    perror("bind");
    close(server.fd);
    return EXIT_FAILURE;
  }

  if (listen(server.fd, MAX_CONNECTIONS) < 0) {
    perror("listen");
    close(server.fd);
    return EXIT_FAILURE;
  }

  accept_loop(&server);

  return EXIT_SUCCESS;
}