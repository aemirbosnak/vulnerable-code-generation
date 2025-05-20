//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5555
#define IP_ADDRESS "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
  int client_socket, server_socket;
  struct sockaddr_in client_address, server_address;
  char buffer[BUFFER_SIZE];
  int n;

  // Create a TCP socket.
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("Cannot create socket.");
    exit(EXIT_FAILURE);
  }

  // Set the server address.
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = inet_addr(IP_ADDRESS);

  // Connect to the server.
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Cannot connect to server.");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server.
  strcpy(buffer, "Romeo: ");
  n = strlen(buffer);
  send(client_socket, buffer, n, 0);
  printf("%s", buffer);

  // Receive a message from the server.
  n = recv(client_socket, buffer, BUFFER_SIZE, 0);
  if (n > 0) {
    buffer[n] = '\0';
    printf("%s\n", buffer);
  }

  // Close the socket.
  close(client_socket);

  return 0;
}