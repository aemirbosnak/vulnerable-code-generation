//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: mathematical
// chat_server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_MSG_LEN 1024
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
  // Check command-line arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Set up server socket
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("socket");
    return 1;
  }

  // Set up server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[1]));
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind server socket to address
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_sock, MAX_CLIENTS) < 0) {
    perror("listen");
    return 1;
  }

  // Accept incoming connections
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_sock < 0) {
    perror("accept");
    return 1;
  }

  // Read from client socket
  char client_msg[MAX_MSG_LEN];
  int read_bytes = read(client_sock, client_msg, MAX_MSG_LEN);
  if (read_bytes < 0) {
    perror("read");
    return 1;
  }

  // Print message from client
  printf("Received message from client: %s\n", client_msg);

  // Send response to client
  char server_msg[] = "Hello, client!";
  if (write(client_sock, server_msg, sizeof(server_msg)) < 0) {
    perror("write");
    return 1;
  }

  // Close client socket
  close(client_sock);

  return 0;
}