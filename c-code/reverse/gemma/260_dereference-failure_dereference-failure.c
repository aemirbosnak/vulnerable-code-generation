#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, htons(21));
  connect(sockfd, NULL, NULL);

  char buf[1024];
  int len = recv(sockfd, buf, 1024, NULL);

  write(1, buf, len);

  close(sockfd);
  return 0;
}
