//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sock, conn_sock;
  struct sockaddr_in server, client;
  char buffer[MAX_BUFFER_SIZE];
  socklen_t client_len = sizeof(client);

  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    exit(1);
  }

  // Set up the server address
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(atoi(argv[1]));

  // Bind the socket to the server address
  if (bind(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
    perror("bind");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sock, 3) == -1) {
    perror("listen");
    exit(1);
  }

  printf("Server listening on port %s\n", argv[1]);

  // Accept incoming connections
  conn_sock = accept(sock, (struct sockaddr *)&client, &client_len);
  if (conn_sock == -1) {
    perror("accept");
    exit(1);
  }

  // Receive data from the client
  recv(conn_sock, buffer, MAX_BUFFER_SIZE, 0);
  printf("Received message: %s\n", buffer);

  // Send a response to the client
  send(conn_sock, "Hello, client!", strlen("Hello, client!"), 0);

  // Close the connection
  close(conn_sock);
  close(sock);

  return 0;
}