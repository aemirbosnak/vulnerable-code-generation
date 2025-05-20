//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define MAX_CLIENTS 10

int main() {
  int sockfd, newsockfd, clientfd[MAX_CLIENTS], pid, i;
  char buffer[1024], username[256], message[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  bind(sockfd, NULL, 0);

  printf("Chat server running...\n");

  while (1) {
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    clientfd[i++] = newsockfd;

    printf("Client connected: %d\n", clientfd[i - 1]);

    pid = fork();

    if (pid < 0) {
      perror("Error forking process");
      close(newsockfd);
      continue;
    }

    if (pid == 0) {
      printf("Enter your username: ");
      scanf("%s", username);

      printf("Enter your message: ");
      scanf("%s", message);

      send(clientfd[i - 1], message, strlen(message) + 1, 0);

      close(clientfd[i - 1]);
      exit(0);
    }

    wait(NULL);

    close(newsockfd);
  }

  return 0;
}