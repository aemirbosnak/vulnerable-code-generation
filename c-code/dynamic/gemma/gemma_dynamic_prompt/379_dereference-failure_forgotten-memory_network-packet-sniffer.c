#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

int main() {
  int sockfd, err, len;
  char *buf, *ptr;

  sockfd = socket(AF_INET, SOCK_RAW, htons(3));
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  err = bind(sockfd, NULL, 0);
  if (err < 0) {
    perror("bind");
    exit(1);
  }

  len = 1024;
  buf = malloc(len);

  while (1) {
    err = recvfrom(sockfd, buf, len, NULL, NULL, NULL);
    if (err < 0) {
      perror("recvfrom");
      exit(1);
    }

    ptr = buf;
    // Deference failure: Accessing a memory location beyond the buffer
    *(ptr + len) = 0;

    printf("Received packet: %s\n", buf);
  }

  free(buf);
  close(sockfd);

  return 0;
}
