//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: distributed
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

#define PORT_RANGE 1024

int main() {
  int port, sockfd, err, n, host_port;
  char host[256];
  struct sockaddr_in server_addr;

  printf("Enter host name: ");
  scanf("%s", host);

  printf("Enter port range (separated by commas): ");
  scanf("%d, %d", &port, &host_port);

  for (port = port; port <= host_port; port++) {
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
      perror("Error creating socket");
      continue;
    }

    server_addr.sin_port = htons(port);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Error connecting to server");
      close(sockfd);
      continue;
    }

    n = write(sockfd, "Hello, world!", 13);
    if (n < 0) {
      perror("Error writing to socket");
    }

    n = read(sockfd, host, 256);
    if (n < 0) {
      perror("Error reading from socket");
    }

    printf("Response from port %d: %s\n", port, host);

    close(sockfd);
  }

  return 0;
}