#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  char port_range[1024];
  scanf("%s", port_range);

  char *port_start = strchr(port_range, '-') ? strchr(port_range, '-') + 1 : port_range;
  char *port_end = strchr(port_range, '-') ? strchr(port_range, '-') : port_range;

  int port_start_int = atoi(port_start);
  int port_end_int = atoi(port_end);

  for (int port = port_start_int; port <= port_end_int; port++) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd == -1) {
      perror("Error creating socket");
      exit(1);
    }

    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1) {
      perror("Error connecting to socket");
      close(sockfd);
    } else {
      close(sockfd);
    }
  }

  return 0;
}
