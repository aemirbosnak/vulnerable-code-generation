//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
  int sockfd, newsockfd, client_addr_len;
  struct sockaddr_in serv_addr, client_addr;
  char buffer[256];
  int clients[MAX_CLIENTS];
  int num_clients = 0;

  // Create a new socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    return 1;
  }

  // Set up the server address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    return 1;
  }

  // Listen for incoming connections
  if (listen(sockfd, 5) < 0) {
    perror("ERROR on listen");
    return 1;
  }

  // Accept incoming connections
  while (1) {
    client_addr_len = sizeof(client_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      continue;
    }

    // Add the new client to the list of clients
    clients[num_clients] = newsockfd;
    num_clients++;

    // Send a welcome message to the new client
    strcpy(buffer, "Welcome to the chat server!\n");
    send(newsockfd, buffer, strlen(buffer), 0);
  }

  // Close the socket
  close(sockfd);

  return 0;
}