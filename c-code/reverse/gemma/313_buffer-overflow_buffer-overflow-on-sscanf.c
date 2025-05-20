#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int port, listenfd, connfd, remotefd;
  char host[256], buf[4096], remote_host[256], remote_port;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <port> <remote_host:port>\n", argv[0]);
    return 1;
  }

  sscanf(argv[1], "%d", &port);
  sscanf(argv[2], "%s:%d", remote_host, &remote_port);

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  bind(listenfd, NULL, 0);

  while (1) {
    connfd = accept(listenfd, NULL, NULL);
    if (connfd < 0) {
      perror("accept");
      continue;
    }

    remotefd = socket(AF_INET, SOCK_STREAM, 0);
    connect(remotefd, remote_host, remote_port);

    char data[4096];
    int bytes_read, bytes_written;

    while ((bytes_read = read(connfd, data, 4096)) > 0) {
      bytes_written = write(remotefd, data, bytes_read);
      if (bytes_written < 0) {
        perror("write");
        break;
      }
    }

    close(remotefd);
    close(connfd);
  }

  return 0;
}
