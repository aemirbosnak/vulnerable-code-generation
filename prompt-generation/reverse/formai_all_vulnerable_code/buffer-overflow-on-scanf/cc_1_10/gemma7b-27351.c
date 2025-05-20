//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10

typedef struct Client {
  char name[20];
  int speed;
  struct Client* next;
} Client;

Client* head = NULL;

void addClient(char* name, int speed) {
  Client* newClient = malloc(sizeof(Client));
  strcpy(newClient->name, name);
  newClient->speed = speed;
  newClient->next = head;
  head = newClient;
}

int main() {
  int port = SERVER_PORT;
  int clients = 0;
  Client* currentClient = NULL;

  // Create a server socket
  // Listen for clients
  // Accept clients

  // For each client, get their name and speed
  // Add the client to the list

  while (clients < MAX_CLIENTS) {
    char name[20];
    int speed;

    // Get the client's name and speed
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your speed: ");
    scanf("%d", &speed);

    addClient(name, speed);
    clients++;
  }

  // Print the list of clients
  for (currentClient = head; currentClient; currentClient = currentClient->next) {
    printf("%s: %d\n", currentClient->name, currentClient->speed);
  }

  return 0;
}