//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <target>\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[1]);
  char *target = argv[2];

  int listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd == -1) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in listenaddr;
  memset(&listenaddr, 0, sizeof(listenaddr));
  listenaddr.sin_family = AF_INET;
  listenaddr.sin_addr.s_addr = INADDR_ANY;
  listenaddr.sin_port = htons(port);

  if (bind(listenfd, (struct sockaddr *)&listenaddr, sizeof(listenaddr)) == -1) {
    perror("bind");
    return 1;
  }

  if (listen(listenfd, 10) == -1) {
    perror("listen");
    return 1;
  }

  while (1) {
    struct sockaddr_in clientaddr;
    socklen_t clientaddrlen = sizeof(clientaddr);

    int clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientaddrlen);
    if (clientfd == -1) {
      perror("accept");
      continue;
    }

    char buffer[BUFFER_SIZE];
    ssize_t nread = recv(clientfd, buffer, sizeof(buffer), 0);
    if (nread == -1) {
      perror("recv");
      close(clientfd);
      continue;
    }

    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    if (strcmp(method, "GET") != 0) {
      fprintf(clientfd, "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n");
      close(clientfd);
      continue;
    }

    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "%s %s %s\r\nHost: %s\r\n\r\n", method, path, http_version, target);

    int targetfd = socket(AF_INET, SOCK_STREAM, 0);
    if (targetfd == -1) {
      perror("socket");
      close(clientfd);
      continue;
    }

    struct hostent *host = gethostbyname(target);
    if (host == NULL) {
      fprintf(clientfd, "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n");
      close(targetfd);
      close(clientfd);
      continue;
    }

    struct sockaddr_in targetaddr;
    memset(&targetaddr, 0, sizeof(targetaddr));
    targetaddr.sin_family = AF_INET;
    targetaddr.sin_addr.s_addr = ((struct in_addr *)host->h_addr_list[0])->s_addr;
    targetaddr.sin_port = htons(80);

    if (connect(targetfd, (struct sockaddr *)&targetaddr, sizeof(targetaddr)) == -1) {
      perror("connect");
      close(targetfd);
      close(clientfd);
      continue;
    }

    if (send(targetfd, request, strlen(request), 0) == -1) {
      perror("send");
      close(targetfd);
      close(clientfd);
      continue;
    }

    char target_buffer[BUFFER_SIZE];
    while (1) {
      ssize_t nread = recv(targetfd, target_buffer, sizeof(target_buffer), 0);
      if (nread == -1) {
        perror("recv");
        break;
      }
      if (nread == 0) {
        break;
      }

      if (send(clientfd, target_buffer, nread, 0) == -1) {
        perror("send");
        break;
      }
    }

    close(targetfd);
    close(clientfd);
  }

  close(listenfd);

  return 0;
}