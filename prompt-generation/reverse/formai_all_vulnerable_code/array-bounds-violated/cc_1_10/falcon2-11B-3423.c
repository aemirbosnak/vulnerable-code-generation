//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: shocked
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
  int sockfd, connfd, n;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  listen(sockfd, 5);

  connfd = accept(sockfd, (struct sockaddr *)&cli_addr, &n);
  if (connfd < 0) {
    perror("ERROR on accept");
    exit(1);
  }

  printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

  while (1) {
    bzero(buffer, 1024);
    n = recv(connfd, buffer, 1024, 0);
    if (n < 0) {
      perror("ERROR reading from socket");
      break;
    }
    buffer[n] = '\0';
    printf("Received: %s\n", buffer);
    if (strcmp(buffer, "quit") == 0)
      break;
    send(connfd, buffer, strlen(buffer), 0);
  }

  close(connfd);
  close(sockfd);
  return 0;
}