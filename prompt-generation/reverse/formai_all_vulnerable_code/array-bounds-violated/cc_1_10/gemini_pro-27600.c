//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 1024

struct client {
  int socket;
  struct sockaddr_in address;
  char *username;
};

struct client clients[MAX_CLIENTS];
int client_count = 0;

void handle_client(struct client *client) {
  char buffer[MAX_BUFFER_SIZE];
  int n;

  while ((n = recv(client->socket, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
    buffer[n] = '\0';

    if (strcmp(buffer, "login") == 0) {
      // Handle login request
      char username[MAX_BUFFER_SIZE];
      n = recv(client->socket, username, MAX_BUFFER_SIZE, 0);
      username[n] = '\0';

      client->username = strdup(username);
      send(client->socket, "Login successful", strlen("Login successful"), 0);
    } else if (strcmp(buffer, "logout") == 0) {
      // Handle logout request
      send(client->socket, "Logout successful", strlen("Logout successful"), 0);
      close(client->socket);
      free(client->username);
      client_count--;
    } else if (strcmp(buffer, "message") == 0) {
      // Handle message request
      char message[MAX_BUFFER_SIZE];
      n = recv(client->socket, message, MAX_BUFFER_SIZE, 0);
      message[n] = '\0';

      // Broadcast message to all other clients
      for (int i = 0; i < client_count; i++) {
        if (clients[i].socket != client->socket) {
          send(clients[i].socket, message, strlen(message), 0);
        }
      }
    } else {
      // Handle unknown command
      send(client->socket, "Unknown command", strlen("Unknown command"), 0);
    }
  }

  close(client->socket);
  free(client->username);
  client_count--;
}

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  int addrlen = sizeof(client_address);

  // Create server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return 1;
  }

  // Set server address
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  // Bind server socket to address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("listen");
    return 1;
  }

  // Accept incoming connections
  while (1) {
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &addrlen);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Add client to list of clients
    clients[client_count].socket = client_socket;
    clients[client_count].address = client_address;
    clients[client_count].username = NULL;
    client_count++;

    // Create thread to handle client
    pthread_t thread;
    pthread_create(&thread, NULL, (void *)handle_client, &clients[client_count - 1]);
  }

  // Close server socket
  close(server_socket);

  return 0;
}