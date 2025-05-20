//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define PORT 8080

void error(char *msg) {
  perror(msg);
  exit(1);
}

void server() {
  int sockfd, newsockfd, pid;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) error("ERROR opening socket");

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) error("ERROR on binding");
  listen(sockfd, 5);

  while (1) {
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) error("ERROR on accept");

    pid = fork();
    if (pid < 0) error("ERROR on fork");

    if (pid == 0) {
      char buffer[256];
      bzero(buffer, 256);
      int n;

      while ((n = read(newsockfd, buffer, 255)) > 0) {
        printf("Client: %s\n", buffer);
        bzero(buffer, 256);
        n = write(newsockfd, "I got your message", 18);
        if (n < 0) error("ERROR writing to socket");
      }

      if (n < 0) error("ERROR reading from socket");
      close(newsockfd);
      exit(0);
    } else {
      close(newsockfd);
    }
  }

  close(sockfd);
}

void client() {
  int sockfd, n;
  struct sockaddr_in serv_addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) error("ERROR opening socket");

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = htons(PORT);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) error("ERROR connecting");

  char buffer[256];
  while (1) {
    bzero(buffer, 256);
    printf("Client: ");
    fgets(buffer, 255, stdin);

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) error("ERROR reading from socket");
    printf("Server: %s\n", buffer);
  }

  close(sockfd);
}

int main() {
  int choice;

  printf("1. Server\n2. Client\nChoose: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      server();
      break;
    case 2:
      client();
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}