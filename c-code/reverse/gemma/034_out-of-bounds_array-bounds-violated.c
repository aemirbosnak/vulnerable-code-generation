#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  char buffer[1024];
  int port_start, port_end, i;

  printf("Enter port range (e.g. 1234-5678): ");
  scanf("%d-%d", &port_start, &port_end);

  for (i = port_start; i <= port_end; i++) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(i));
    if (sockfd < 0) {
      perror("Error creating socket");
      continue;
    }

    if (connect(sockfd, NULL, 0) == 0) {
      read(sockfd, buffer, 1024);
      printf("Port %d: Received data: %s\n", i, buffer);
    } else {
      perror("Error connecting to port");
    }

    close(sockfd);
  }

  return 0;
}
