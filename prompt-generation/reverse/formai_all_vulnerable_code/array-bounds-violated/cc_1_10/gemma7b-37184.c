//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_CLIENTS 10

int main() {
  int sockfd, newsockfd, clientfd[MAX_CLIENTS], pid;
  char buf[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  bind(sockfd, NULL, 0);

  for (;;) {
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    clientfd[newsockfd] = newsockfd;

    pid = fork();

    if (pid < 0) {
      perror("Error forking");
      close(newsockfd);
      continue;
    }

    if (pid == 0) {
      close(sockfd);

      while (1) {
        memset(buf, 0, 1024);

        read(clientfd[newsockfd], buf, 1024);

        if (strcmp(buf, "quit") == 0) {
          break;
        }

        write(clientfd[newsockfd], buf, strlen(buf) + 1);
      }

      close(clientfd[newsockfd]);
      exit(0);
    }

    close(newsockfd);
  }

  return 0;
}