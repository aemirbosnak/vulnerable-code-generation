//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5000
#define MAX_CLIENTS 100

typedef struct {
  int socket;
  char name[100];
} Client;

Client clients[MAX_CLIENTS];
int num_clients = 0;

void send_message(char *message, int client_index) {
  for (int i = 0; i < num_clients; i++) {
    if (i != client_index) {
      send(clients[i].socket, message, strlen(message), 0);
    }
  }
}

void *handle_client(void *arg) {
  int client_index = *(int *)arg;
  char buffer[1024];

  while (1) {
    int bytes_received = recv(clients[client_index].socket, buffer, 1024, 0);
    if (bytes_received <= 0) {
      break;
    }

    printf("%s: %s", clients[client_index].name, buffer);
    send_message(buffer, client_index);
  }

  close(clients[client_index].socket);
  num_clients--;

  return NULL;
}

int main() {
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  while (1) {
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);

    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    if (num_clients >= MAX_CLIENTS) {
      send(client_socket, "Server is full", strlen("Server is full"), 0);
      close(client_socket);
      continue;
    }

    clients[num_clients].socket = client_socket;
    recv(client_socket, clients[num_clients].name, 100, 0);
    num_clients++;

    printf("%s has joined the chat\n", clients[num_clients - 1].name);
    send_message(clients[num_clients - 1].name, num_clients - 1);

    pthread_t thread;
    pthread_create(&thread, NULL, handle_client, &num_clients);
  }

  close(server_socket);
  return EXIT_SUCCESS;
}