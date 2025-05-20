#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd, connfd, nread, i, j, k;
  char buf[1024], filename[256], data[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(21));
  connfd = accept(sockfd, NULL, NULL);

  printf("Enter filename: ");
  scanf("%s", filename);

  nread = read(connfd, buf, 1024);
  if (nread > 0) {
    for (i = 0; i < nread; i++) {
      for (j = 0; j < 1024; j++) {
        if (buf[i] != '\0') {
          data[j] = buf[i];
          j++;
        }
      }
    }
  }

  write(1, data, j);

  close(connfd);
  close(sockfd);

  return 0;
}
