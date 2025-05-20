//Gemma-7B DATASET v1.0 Category: Chat server ; Style: retro
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 8888
#define MAX_CLIENTS 10

// Global client list
int client_list[MAX_CLIENTS] = { -1 };

void handle_client(int client_sock) {
  char message[1024];

  // Receive message from client
  recv(client_sock, message, 1024, 0);

  // Broadcast message to other clients
  for (int i = 0; i < MAX_CLIENTS; i++) {
    if (client_list[i] != -1 && client_sock != client_list[i]) {
      send(client_list[i], message, strlen(message), 0);
    }
  }

  // Close client connection
  close(client_sock);
}

int main() {
  int server_sock, client_sock;
  struct sockaddr_in server_addr, client_addr;
  int client_count = 0;

  // Create server socket
  server_sock = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (server_sock < 0) {
    return -1;
  }

  // Bind server socket to port
  server_addr.sin_port = htons(SERVER_PORT);
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    return -1;
  }

  // Listen for clients
  while (1) {
    // Accept client connection
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, NULL);

    // Add client to list
    client_list[client_count++] = client_sock;

    // Handle client
    handle_client(client_sock);
  }

  return 0;
}