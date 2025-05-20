//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main() {
  int sockfd, port, n, i, srcaddrlen;
  char buf[1024], hostname[256];
  struct sockaddr_in srvaddr;

  printf("Enter hostname: ");
  scanf("%s", hostname);

  printf("Enter port number: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  srvaddr.sin_family = AF_INET;
  srvaddr.sin_port = htons(port);
  srvaddr.sin_addr.s_addr = inet_addr(hostname);

  n = connect(sockfd, (struct sockaddr *)&srvaddr, sizeof(srvaddr));
  if (n < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  printf("Connected to server.\n");

  // Send and receive data
  for (i = 0; i < 10; i++) {
    printf("Enter message: ");
    scanf("%s", buf);

    n = send(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
      perror("Error sending message");
      exit(1);
    }

    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
      perror("Error receiving message");
      exit(1);
    }

    printf("Received message: %s\n", buf);
  }

  close(sockfd);
  return 0;
}