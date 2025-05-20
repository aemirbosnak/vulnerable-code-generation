#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
  int sockfd, n, recv_len;
  char buf[10];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
  connect(sockfd, NULL, NULL);

  recv_len = recv(sockfd, buf, 10, 0);
  n = recv_len;

  if (n > 10) {
    n = 10;
  }

  write(1, buf, n);

  close(sockfd);
  return 0;
}
