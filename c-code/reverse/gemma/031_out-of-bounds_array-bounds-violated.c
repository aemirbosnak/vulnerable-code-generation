#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>

int main() {
  char ip[20];
  int startPort, endPort;
  int sockfd, port;
  struct sockaddr_in servaddr;

  printf("Enter IP address: ");
  scanf("%s", ip);

  printf("Enter start port: ");
  scanf("%d", &startPort);

  printf("Enter end port: ");
  scanf("%d", &endPort);

  for (port = startPort; port <= endPort; port++) {
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0) {
      perror("Error creating socket");
      continue;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
      perror("Error connecting to port");
      close(sockfd);
      continue;
    }

    char buf[1024];
    int bytesRead = read(sockfd, buf, 1024);

    if (bytesRead > 0) {
      printf("Port %d: Received data: %s\n", port, buf);
    } else {
      printf("Port %d: No data received.\n", port);
    }

    close(sockfd);
  }

  return 0;
}
