//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

// A simple smart home automation program in a Dennis Ritchie style

// Define the port number
#define PORT 5000

// Define the maximum number of clients
#define MAX_CLIENTS 10

// Define the maximum size of a message
#define MAX_MESSAGE_SIZE 1024

// Define the structure of a client
typedef struct {
  int socket;
  char name[MAX_MESSAGE_SIZE];
} client_t;

// Define the global variables
int server_socket;
client_t clients[MAX_CLIENTS];

// Function to handle a new client
void handle_new_client(int client_socket) {
  // Get the client's name
  char name[MAX_MESSAGE_SIZE];
  recv(client_socket, name, sizeof(name), 0);

  // Add the client to the list of clients
  int i;
  for (i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i].socket == 0) {
      clients[i].socket = client_socket;
      strcpy(clients[i].name, name);
      break;
    }
  }

  // Send a welcome message to the client
  char welcome_message[] = "Welcome to the smart home automation system!";
  send(client_socket, welcome_message, sizeof(welcome_message), 0);
}

// Function to handle a message from a client
void handle_message(int client_socket, char *message) {
  // Parse the message
  char command[MAX_MESSAGE_SIZE];
  char argument[MAX_MESSAGE_SIZE];
  sscanf(message, "%s %s", command, argument);

  // Execute the command
  if (strcmp(command, "turn on") == 0) {
    // Turn on the specified device
    char response[] = "OK";
    send(client_socket, response, sizeof(response), 0);
  } else if (strcmp(command, "turn off") == 0) {
    // Turn off the specified device
    char response[] = "OK";
    send(client_socket, response, sizeof(response), 0);
  } else if (strcmp(command, "get status") == 0) {
    // Get the status of the specified device
    char response[] = "OK";
    send(client_socket, response, sizeof(response), 0);
  } else {
    // Send an error message to the client
    char error_message[] = "Invalid command";
    send(client_socket, error_message, sizeof(error_message), 0);
  }
}

// Function to handle a client disconnect
void handle_disconnect(int client_socket) {
  // Remove the client from the list of clients
  int i;
  for (i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i].socket == client_socket) {
      clients[i].socket = 0;
      strcpy(clients[i].name, "");
      break;
    }
  }

  // Send a disconnect message to the client
  char disconnect_message[] = "Goodbye!";
  send(client_socket, disconnect_message, sizeof(disconnect_message), 0);
}

// Main function
int main() {
  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    exit(1);
  }

  // Bind the server socket to the port
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("listen");
    exit(1);
  }

  // Main loop
  while (1) {
    // Accept a new connection
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Handle the new client
    handle_new_client(client_socket);

    // Receive messages from the client
    while (1) {
      // Receive a message from the client
      char message[MAX_MESSAGE_SIZE];
      int message_size = recv(client_socket, message, sizeof(message), 0);
      if (message_size == -1) {
        perror("recv");
        break;
      } else if (message_size == 0) {
        // Client disconnected
        handle_disconnect(client_socket);
        break;
      }

      // Handle the message
      handle_message(client_socket, message);
    }

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}