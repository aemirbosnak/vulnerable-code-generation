//Gemma-7B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 10

int main() {
  int sockfd, clientfd, newsockfd;
  char buffer[1024];
  int client_list[MAX_CLIENTS] = { -1 };
  int client_count = 0;

  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }

  listen(sockfd, MAX_CLIENTS);

  while (1) {
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    for (int i = 0; i < client_count; i++) {
      if (client_list[i] == -1) {
        client_list[i] = newsockfd;
        client_count++;
        break;
      }
    }

    printf("Client connected: %d\n", client_count);

    while (1) {
      int recv_size = recv(clientfd, buffer, 1024, 0);
      if (recv_size > 0) {
        printf("Client: %s\n", buffer);
      } else if (recv_size == 0) {
        printf("Client disconnected: %d\n", client_count);
        client_list[client_count - 1] = -1;
        break;
      } else {
        perror("Error receiving data");
      }
    }
  }

  return 0;
}