//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main() {
  char hostname[256];
  int port;
  int sockfd;
  struct sockaddr_in servaddr;
  char buffer[1024];

  printf("Enter hostname: ");
  scanf("%s", hostname);

  printf("Enter port: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  inet_pton(AF_INET, hostname, &servaddr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  printf("Connected to server.\n");

  // Send and receive messages
  while (1) {
    printf("Enter message: ");
    scanf("%s", buffer);

    send(sockfd, buffer, strlen(buffer) + 1, 0);

    recv(sockfd, buffer, 1024, 0);

    printf("Received message: %s\n", buffer);

    if (strcmp(buffer, "quit") == 0) {
      break;
    }
  }

  close(sockfd);
  exit(0);
}