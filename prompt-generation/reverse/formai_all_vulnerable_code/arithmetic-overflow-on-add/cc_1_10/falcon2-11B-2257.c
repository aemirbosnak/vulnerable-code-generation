//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <sys/select.h>
#include <sys/time.h>

int main() {
  int listen_fd, conn_fd, n;
  struct sockaddr_in serv_addr, cli_addr;
  int opt = 1;
  fd_set readfds;
  struct timeval tv;

  listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd < 0) {
    perror("listen");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(1234);

  if (bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  if (listen(listen_fd, 5) < 0) {
    perror("listen");
    exit(1);
  }

  FD_ZERO(&readfds);
  FD_SET(listen_fd, &readfds);

  while (1) {
    tv.tv_sec = 0;
    tv.tv_usec = 100000;

    n = select(listen_fd + 1, &readfds, NULL, NULL, &tv);
    if (n < 0) {
      perror("select");
      exit(1);
    }

    if (FD_ISSET(listen_fd, &readfds)) {
      conn_fd = accept(listen_fd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
      if (conn_fd < 0) {
        perror("accept");
        exit(1);
      }

      FD_SET(conn_fd, &readfds);

      while (1) {
        char buffer[256];
        read(conn_fd, buffer, sizeof(buffer));

        if (strcmp(buffer, "quit") == 0) {
          close(conn_fd);
          FD_CLR(conn_fd, &readfds);
          break;
        }

        send(conn_fd, buffer, strlen(buffer), 0);
      }

      close(conn_fd);
    }
  }

  return 0;
}