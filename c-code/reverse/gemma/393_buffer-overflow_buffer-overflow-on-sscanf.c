#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int port_start, port_end, port, sockfd, is_open = 1;
  char host[256];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port_range>\n", argv[0]);
    return 1;
  }

  scanf("%s", host);
  sscanf(argv[2], "%d-%d", &port_start, &port_end);

  for (port = port_start; port <= port_end; port++) {
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
      perror("Error creating socket");
      return 1;
    }

    if (connect(sockfd, (struct sockaddr *)host, sizeof(host)) == 0) {
      printf("%d is open\n", port);
      is_open = 0;
    }

    close(sockfd);
  }

  if (is_open) {
    printf("No ports are open\n");
  }

  return 0;
}
