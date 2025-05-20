//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

int main() {
  int server_socket, client_socket[MAX_CLIENTS], max_clients, max_sd;
  struct sockaddr_in server, client;
  int opt = 1;
  fd_set readfds;

  // Create the server socket
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Set the socket options
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }

  // Set the server address
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8080);

  // Bind the socket to the address
  if (bind(server_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CLIENTS) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  // Initialize the client sockets
  memset(client_socket, 0, sizeof(client_socket));
  max_clients = 0;
  max_sd = server_socket;

  // Main loop
  while(1) {
    // Clear the readfds set
    FD_ZERO(&readfds);

    // Add the server socket to the readfds set
    FD_SET(server_socket, &readfds);

    // Add the client sockets to the readfds set
    for (int i = 0; i < max_clients; i++) {
      if (client_socket[i] > 0) {
        FD_SET(client_socket[i], &readfds);
      }
    }

    // Wait for activity on any of the sockets
    int activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
    if (activity < 0) {
      perror("select failed");
      exit(EXIT_FAILURE);
    }

    // If activity on the server socket, a new client has connected
    if (FD_ISSET(server_socket, &readfds)) {
      int new_client_socket;
      int addrlen = sizeof(client);

      // Accept the new connection
      if ((new_client_socket = accept(server_socket, (struct sockaddr *)&client, &addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
      }

      // Add the new client socket to the array of client sockets
      for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_socket[i] == 0) {
          client_socket[i] = new_client_socket;
          break;
        }
      }

      // If the new client socket is the highest, update the max_clients and max_sd variables
      if (new_client_socket > max_clients) {
        max_clients = new_client_socket;
        max_sd = max_clients;
      }

      // Send a welcome message to the new client
      char *welcome_msg = "Welcome to the chat server!\n";
      if (send(new_client_socket, welcome_msg, strlen(welcome_msg), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
      }
    }

    // Check for activity on any of the client sockets
    for (int i = 0; i < max_clients; i++) {
      if (FD_ISSET(client_socket[i], &readfds)) {
        char msg[MAX_MSG_LEN];

        // Receive the message from the client
        int recv_len = recv(client_socket[i], msg, MAX_MSG_LEN, 0);
        if (recv_len == 0) {
          // Client has disconnected
          close(client_socket[i]);
          client_socket[i] = 0;
        } else if (recv_len < 0) {
          // Error receiving message
          perror("recv failed");
          exit(EXIT_FAILURE);
        } else {
          // Send the message to all other clients
          for (int j = 0; j < max_clients; j++) {
            if (client_socket[j] != client_socket[i] && client_socket[j] > 0) {
              if (send(client_socket[j], msg, recv_len, 0) < 0) {
                perror("send failed");
                exit(EXIT_FAILURE);
              }
            }
          }
        }
      }
    }
  }

  // Close the server socket
  close(server_socket);

  return 0;
}