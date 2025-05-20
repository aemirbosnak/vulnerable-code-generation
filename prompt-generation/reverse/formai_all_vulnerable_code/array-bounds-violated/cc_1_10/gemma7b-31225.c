//Gemma-7B DATASET v1.0 Category: Chat server ; Style: Alan Turing
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

int main() {
  int sockfd, newsockfd, clientfd[MAX_CLIENTS], i, j, recvlen;
  char msg[1024], username[256], server_message[1024];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));

  // Bind the socket to a port
  bind(sockfd, NULL, 0);

  // Listen for clients
  while (1) {
    // Accept a client connection
    newsockfd = accept(sockfd, NULL, NULL);

    // Get the client's username
    recvlen = recv(newsockfd, username, 256, 0);
    username[recvlen] = '\0';

    // Send a welcome message to the client
    sprintf(server_message, "Welcome, %s!", username);
    send(newsockfd, server_message, strlen(server_message), 0);

    // Create a loop to handle client messages
    while (1) {
      // Get the client's message
      recvlen = recv(newsockfd, msg, 1024, 0);
      msg[recvlen] = '\0';

      // Broadcast the message to other clients
      for (i = 0; i < MAX_CLIENTS; i++) {
        if (clientfd[i] != newsockfd) {
          send(clientfd[i], msg, strlen(msg), 0);
        }
      }

      // Check if the client has disconnected
      if (recvlen == 0) {
        break;
      }
    }

    // Close the client connection
    close(newsockfd);
  }

  return 0;
}