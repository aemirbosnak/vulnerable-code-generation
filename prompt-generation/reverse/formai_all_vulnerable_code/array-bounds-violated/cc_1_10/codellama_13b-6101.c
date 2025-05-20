//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: energetic
// Chat Server Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

int main() {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Set up address structure
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Bind the socket to the address structure
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sock, MAX_CLIENTS) < 0) {
    perror("Error listening on socket");
    exit(1);
  }

  // Accept incoming connections
  int client_sock;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  while (1) {
    client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
      perror("Error accepting connection");
      exit(1);
    }

    // Receive messages from the client
    char msg[MAX_MSG_SIZE];
    int bytes_read;
    while ((bytes_read = recv(client_sock, msg, MAX_MSG_SIZE, 0)) > 0) {
      msg[bytes_read] = '\0';
      printf("Received message: %s\n", msg);

      // Echo the message back to the client
      send(client_sock, msg, bytes_read, 0);
    }

    // Close the client socket
    close(client_sock);
  }

  // Close the server socket
  close(sock);

  return 0;
}