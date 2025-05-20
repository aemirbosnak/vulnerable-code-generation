//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define MAX_CLIENTS 10

struct Client {
  char name[255];
  int sockfd;
  struct Client *next;
};

void handleClient(struct Client *client) {
  char message[255];
  printf("Client: %s\n", client->name);

  // Send a message to the client
  printf("Enter your message: ");
  scanf("%s", message);
  send(client->sockfd, message, strlen(message), 0);

  // Receive a message from the client
  recv(client->sockfd, message, 255, 0);
  printf("Client: %s says: %s\n", client->name, message);
}

int main() {
  int sockfd, clientsockfd;
  struct Client *clients = NULL;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Listen for clients
  while (1) {
    clientsockfd = accept(sockfd, NULL, NULL);

    // Create a new client structure
    struct Client *client = malloc(sizeof(struct Client));
    client->sockfd = clientsockfd;

    // Get the client's name
    recv(clientsockfd, client->name, 255, 0);

    // Add the client to the list
    client->next = clients;
    clients = client;

    // Handle the client
    handleClient(client);

    // Close the client socket
    close(clientsockfd);

    // Free the client structure
    free(client);
  }

  return 0;
}