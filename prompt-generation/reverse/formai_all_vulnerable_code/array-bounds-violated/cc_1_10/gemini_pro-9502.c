//GEMINI-pro DATASET v1.0 Category: Networking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 8080

char buffer[BUFFER_SIZE];
int main()
{
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1)
  {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to a port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(PORT);
  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1)
  {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for connections
  if (listen(sock, 10) == -1)
  {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept a connection
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_sock == -1)
  {
    perror("accept");
    return EXIT_FAILURE;
  }

  // Send a message to the client
  char *message = "Hello, world!";
  if (send(client_sock, message, strlen(message), 0) == -1)
  {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive a message from the client
  int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);
  if (bytes_received == -1)
  {
    perror("recv");
    return EXIT_FAILURE;
  }
  buffer[bytes_received] = '\0';

  // Print the message from the client
  printf("Received from client: %s\n", buffer);

  // Close the client socket
  close(client_sock);

  // Close the server socket
  close(sock);

  return EXIT_SUCCESS;
}