//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {

  printf("Whoa! Can you believe we're going to create a TCP/IP server?!\n");

  int socket_desc, client_sock, c, read_size;
  struct sockaddr_in server, client;
  char client_message[2000], response_message[2000];

  // Create TCP socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Oh no, could not create socket!\n");
    return 1;
  }

  printf("Socket created, let's set some settings!\n");

  // Prepare the sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(1337); // Listen on port 1337

  // Bind
  if (bind(socket_desc, (struct sockaddr*) &server, sizeof(server)) < 0) {
    printf("Uh oh, failed to bind socket to port 1337...\n");
    return 1;
  }

  printf("Socket bound to port 1337, now let's start listening for incoming connections...\n");

  // Listen
  listen(socket_desc, 3);

  // Accept incoming connections
  c = sizeof(struct sockaddr_in);
  client_sock = accept(socket_desc, (struct sockaddr*) &client, (socklen_t*) &c);
  if (client_sock < 0) {
    printf("Oops, failed to accept incoming connection...\n");
    return 1;
  }

  printf("Connection accepted, let's receive some data...\n");

  // Receive incoming data
  while ((read_size = recv(client_sock, client_message, 2000, 0)) > 0) {

    // Add null terminator to message
    client_message[read_size] = '\0';

    printf("Received: %s", client_message);

    // Prepare response message
    sprintf(response_message, "You sent: %s", client_message);

    // Send response back to client
    write(client_sock, response_message, strlen(response_message));
  }

  if (read_size == 0) {
    printf("Client disconnected! Unbelievable...\n");
  } else if (read_size == -1) {
    printf("Something went wrong trying to receive data from client. Who would have thought?!\n");
  }

  return 0;
}