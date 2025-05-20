//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
  int sockfd, newsockfd, addrlen;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[BUFFER_SIZE];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  listen(sockfd, 5);
  printf("Server is listening...\n");

  while (1) {
    addrlen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
    if (newsockfd < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }

    printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    while (1) {
      memset(buffer, 0, BUFFER_SIZE);
      if ((recv(newsockfd, buffer, BUFFER_SIZE, 0)) <= 0) {
        if (errno!= EWOULDBLOCK) {
          perror("recv failed");
          exit(EXIT_FAILURE);
        }
        break;
      }
      printf("Received message: %s\n", buffer);
    }

    close(newsockfd);
  }

  close(sockfd);
  return 0;
}