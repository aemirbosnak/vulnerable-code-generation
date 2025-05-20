#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {
  int port_start, port_end, sockfd, err, i, buf_size = 1024;
  char *buf = malloc(buf_size);

  printf("Enter port range (start-end): ");
  scanf("%d-%d", &port_start, &port_end);

  for (i = port_start; i <= port_end; i++) {
    sockfd = socket(AF_INET, SOCK_STREAM, htons(i));
    if (sockfd < 0) {
      perror("Error creating socket");
      continue;
    }

    if (connect(sockfd, NULL, 0) < 0) {
      perror("Error connecting to port");
      close(sockfd);
      continue;
    }

    read(sockfd, buf, buf_size);
    printf("Port %d: Response: %s\n", i, buf);

    close(sockfd);
  }

  free(buf);
  return 0;
}
