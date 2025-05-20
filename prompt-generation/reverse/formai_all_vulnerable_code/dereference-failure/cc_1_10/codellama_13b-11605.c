//Code Llama-13B DATASET v1.0 Category: Client Server Application ; Style: funny
// C Client-Server Program - Funny Style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define constants
#define PORT 8080
#define MAX_LINE 1024
#define MAX_MSG 1024

// Function declarations
void error(const char *msg);
void handle_client(int client_sock);

// Main function
int main(int argc, char *argv[]) {
  // Check arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Create socket
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    error("socket() failed");
  }

  // Set socket options
  int enable = 1;
  if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
    error("setsockopt() failed");
  }

  // Bind socket to port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(atoi(argv[1]));
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    error("bind() failed");
  }

  // Listen for incoming connections
  if (listen(server_sock, 3) < 0) {
    error("listen() failed");
  }

  printf("Server listening on port %s\n", argv[1]);

  // Accept incoming connections
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
  if (client_sock < 0) {
    error("accept() failed");
  }

  printf("Client connected\n");

  // Handle client connection
  handle_client(client_sock);

  // Close client socket
  close(client_sock);

  // Close server socket
  close(server_sock);

  return 0;
}

// Function definitions
void error(const char *msg) {
  perror(msg);
  exit(1);
}

void handle_client(int client_sock) {
  // Read message from client
  char msg[MAX_MSG];
  if (recv(client_sock, msg, MAX_MSG, 0) < 0) {
    error("recv() failed");
  }
  printf("Client message: %s\n", msg);

  // Send response to client
  char response[] = "Hello, client!";
  if (send(client_sock, response, strlen(response), 0) < 0) {
    error("send() failed");
  }
  printf("Response sent to client\n");
}