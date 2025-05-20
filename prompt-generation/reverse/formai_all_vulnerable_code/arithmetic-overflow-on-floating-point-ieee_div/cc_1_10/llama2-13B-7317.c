//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int server_fd, client_fd;
  socklen_t client_len = sizeof(struct sockaddr_in);
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];
  int bytes_sent, bytes_received;
  float avg_message_length = 0;
  int num_messages = 0;

  // Create the server socket
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set address and port number for the server
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(8080);

  // Bind the server socket to the address and port
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Binding failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("Listening failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d...\n", server_addr.sin_port);

  while (1) {
    // Accept an incoming connection
    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
      perror("Accept failed");
      continue;
    }

    printf("Connection accepted from client IP address %s and port %d...\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    while (1) {
      // Receive a message from the client
      bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
      if (bytes_received < 0) {
        perror("Recv failed");
        break;
      }

      // Calculate the average message length
      avg_message_length = (float)bytes_received / num_messages;
      num_messages++;

      // Print the received message and the average message length
      printf("Received message: %s\n", buffer);
      printf("Average message length: %.2f bytes\n", avg_message_length);

      // Send a response back to the client
      bytes_sent = send(client_fd, "Hello, client!", 13, 0);
      if (bytes_sent < 0) {
        perror("Send failed");
        break;
      }
    }

    // Close the client socket
    close(client_fd);
  }

  // Close the server socket
  close(server_fd);

  return 0;
}