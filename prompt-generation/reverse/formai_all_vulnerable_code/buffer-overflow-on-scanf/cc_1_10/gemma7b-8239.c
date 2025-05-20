//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define PORT_MIN 0
#define PORT_MAX 65535

int main() {
  int sockfd, port, n, i, host_port;
  char hostname[256];
  struct sockaddr_in srv_addr;

  printf("Enter hostname: ");
  scanf("%s", hostname);

  printf("Enter target port: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  srv_addr.sin_family = AF_INET;
  srv_addr.sin_port = htons(port);
  inet_aton(hostname, &srv_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) < 0) {
    perror("Error connecting to server");
    close(sockfd);
    exit(1);
  }

  printf("Connection established.\n");

  for (i = 0; i < 10; i++) {
    printf("Sending data: ");
    scanf("%d", &n);
    send(sockfd, &n, sizeof(int), 0);

    printf("Received data: ");
    recv(sockfd, &n, sizeof(int), 0);
    printf("%d\n", n);
  }

  close(sockfd);
  return 0;
}