//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

// The server's IP address and port
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

// The client's IP address and port
#define CLIENT_IP "127.0.0.1"
#define CLIENT_PORT 8081

// The maximum size of the message that can be sent
#define BUFFER_SIZE 1024

// The main function
int main() {
  // Get a socket descriptor
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Set up the server address
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(SERVER_PORT);
  server_address.sin_addr.s_addr = inet_addr(SERVER_IP);

  // Connect to the server
  if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Get the user's input
  char message[BUFFER_SIZE];
  printf("Enter a message to send to the server: ");
  scanf("%s", message);

  // Send the message to the server
  if (send(client_socket, message, strlen(message), 0) < 0) {
    perror("Error sending message");
    exit(1);
  }

  // Receive the server's response
  char response[BUFFER_SIZE];
  if (recv(client_socket, response, BUFFER_SIZE, 0) < 0) {
    perror("Error receiving response");
    exit(1);
  }

  // Print the server's response
  printf("Received from server: %s\n", response);

  // Close the socket
  close(client_socket);

  return 0;
}