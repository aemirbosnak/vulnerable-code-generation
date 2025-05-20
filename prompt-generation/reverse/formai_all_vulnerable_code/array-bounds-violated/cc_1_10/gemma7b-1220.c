//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

int main() {
  int sockfd, newsockfd, clientfd[MAX_CLIENTS], i;
  char buffer[BUFFER_SIZE];

  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  for (i = 0; i < MAX_CLIENTS; i++) {
    clientfd[i] = -1;
  }

  while (1) {
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    for (i = 0; i < MAX_CLIENTS; i++) {
      if (clientfd[i] == -1) {
        clientfd[i] = newsockfd;
        break;
      }
    }

    printf("Client connected: %d\n", clientfd[i]);

    memset(buffer, 0, BUFFER_SIZE);
    recv(clientfd[i], buffer, BUFFER_SIZE, 0);
    printf("Received: %s\n", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "Hello, client %d!", clientfd[i]);
    send(clientfd[i], buffer, BUFFER_SIZE, 0);

    close(clientfd[i]);
  }

  return 0;
}