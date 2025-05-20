//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT_MAX 65535

int main() {
  int sockfd;
  struct sockaddr_in servaddr;
  char buf[1024];
  int port;

  printf("Enter the port number: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
  if (sockfd == -1) {
    perror("Error creating socket");
    return 1;
  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("Error connecting to server");
    return 1;
  }

  printf("Connected to port %d.\n", port);

  while (1) {
    printf("Enter a message: ");
    scanf("%s", buf);

    send(sockfd, buf, strlen(buf) + 1, 0);

    recv(sockfd, buf, 1024, 0);

    printf("Received: %s\n", buf);

    if (strcmp(buf, "quit") == 0) {
      break;
    }
  }

  close(sockfd);

  return 0;
}