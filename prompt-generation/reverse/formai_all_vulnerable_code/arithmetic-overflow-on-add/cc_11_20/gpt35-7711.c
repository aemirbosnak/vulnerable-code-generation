//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
  int socket_fd;
  struct sockaddr_in server_address, client_address;
  char buffer[BUFFER_SIZE];
  fd_set read_fds;
  int max_fd, activity;

  // Create socket
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Set server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  // Bind socket to address
  if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Error binding socket to address");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(socket_fd, 3) < 0) {
    perror("Error listening for incoming connections");
    exit(EXIT_FAILURE);
  }

  // Accept incoming connections
  int client_fd, client_address_len = sizeof(client_address);
  if ((client_fd = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t *)&client_address_len)) < 0) {
    perror("Error accepting incoming connection");
    exit(EXIT_FAILURE);
  }

  // Initialize file descriptors for select
  FD_ZERO(&read_fds);
  FD_SET(client_fd, &read_fds);
  max_fd = client_fd;

  while (1) {
    // Wait for activity on file descriptors using select
    activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

    if (activity < 0) {
      perror("Error waiting for activity on file descriptors");
      exit(EXIT_FAILURE);
    }

    if (activity == 0) {
      printf("No activity\n");
    }

    int byte_count;

    if (FD_ISSET(client_fd, &read_fds)) {
      // Read data from client
      memset(buffer, 0, BUFFER_SIZE);
      byte_count = read(client_fd, buffer, BUFFER_SIZE);

      if (byte_count < 0) {
        perror("Error reading data from client");
        exit(EXIT_FAILURE);
      }

      if (byte_count == 0) {
        // Connection closed by client
        printf("Connection closed by client\n");
        break;
      }

      // Write data back to client
      byte_count = write(client_fd, buffer, strlen(buffer));

      if (byte_count < 0) {
        perror("Error writing data back to client");
        exit(EXIT_FAILURE);
      }

      // Print received data
      printf("Received data: %s\n", buffer);
    }
  }

  return 0;
}