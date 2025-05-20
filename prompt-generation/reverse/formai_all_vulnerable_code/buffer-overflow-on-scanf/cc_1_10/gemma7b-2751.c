//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10

int main() {
  int server_fd, client_fd[MAX_CLIENTS], num_clients = 0, i;
  char buf[1024], client_name[256];

  // Create a socket
  server_fd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (server_fd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  listen(server_fd, MAX_CLIENTS);

  // Accept clients
  while (num_clients < MAX_CLIENTS) {
    client_fd[num_clients] = accept(server_fd, NULL, NULL);
    if (client_fd[num_clients] < 0) {
      perror("Error accepting client");
      continue;
    }

    // Get the client's name
    recv(client_fd[num_clients], client_name, 256, 0);

    // Welcome the client
    printf("Client %s has connected.\n", client_name);

    // Have the client send a message
    printf("Enter a message: ");
    scanf("%s", buf);

    // Send the message to the client
    send(client_fd[num_clients], buf, strlen(buf) + 1, 0);

    // Close the client connection
    close(client_fd[num_clients]);

    // Increment the number of clients
    num_clients++;
  }

  // Close the server socket
  close(server_fd);

  return 0;
}