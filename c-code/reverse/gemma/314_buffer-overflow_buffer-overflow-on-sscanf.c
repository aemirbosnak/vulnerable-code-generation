#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>

#define BUFFER_SIZE 16

int main() {
  char buffer[BUFFER_SIZE];
  char *url = NULL;
  int listenfd = socket(AF_INET, SOCK_STREAM, htons(80));
  bind(listenfd, NULL, 0);

  while (1) {
    int connfd = accept(listenfd, NULL, NULL);
    read(connfd, buffer, BUFFER_SIZE);
    url = malloc(BUFFER_SIZE);
    sscanf(buffer, "GET %s", url);
    write(connfd, url, strlen(url));
    free(url);
    close(connfd);
  }
}
