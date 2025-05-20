//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  int sockfd, port, n, i, err, socklen;
  char buf[1024], hostname[256];
  struct sockaddr_in sock_addr;

  printf("Enter the hostname: ");
  scanf("%s", hostname);

  printf("Enter the port number: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(port);
  inet_aton(hostname, &sock_addr.sin_addr);

  socklen = sizeof(sock_addr);
  err = connect(sockfd, (struct sockaddr *)&sock_addr, socklen);
  if (err < 0) {
    perror("Error connecting to socket");
    exit(1);
  }

  printf("Enter your message: ");
  scanf("%s", buf);

  n = write(sockfd, buf, strlen(buf) + 1);
  if (n < 0) {
    perror("Error sending message");
    exit(1);
  }

  n = read(sockfd, buf, 1024);
  if (n < 0) {
    perror("Error receiving message");
    exit(1);
  }

  printf("Received message: %s", buf);

  close(sockfd);
  exit(0);
}