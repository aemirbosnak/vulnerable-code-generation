//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
  // Check if arguments are valid
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Get the port number
  int port = atoi(argv[1]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  // Set up the socket address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections
  if (listen(sock, 3) == -1) {
    perror("listen");
    return 1;
  }

  // Accept incoming connections
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
  if (client_sock == -1) {
    perror("accept");
    return 1;
  }

  // Read from the client
  char buffer[256];
  int bytes_read = read(client_sock, buffer, sizeof(buffer));
  if (bytes_read == -1) {
    perror("read");
    return 1;
  }

  // Send a response to the client
  char response[256];
  sprintf(response, "Hello, client! You sent: %s", buffer);
  bytes_read = write(client_sock, response, strlen(response));
  if (bytes_read == -1) {
    perror("write");
    return 1;
  }

  // Close the socket
  close(sock);
  close(client_sock);

  return 0;
}