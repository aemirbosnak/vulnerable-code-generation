//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

int main() {
  int sock, client_sock, port;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;
  char buffer[256];

  // Get port number from user.
  printf("Enter port number: ");
  scanf("%d", &port);

  // Create a TCP socket.
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the server address.
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Bind the socket to the server address.
  if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections.
  if (listen(sock, 5) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accept an incoming connection.
  client_addr_len = sizeof(client_addr);
  client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_sock < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // Receive data from the client.
  while (1) {
    if (recv(client_sock, buffer, sizeof(buffer), 0) < 0) {
      perror("recv");
      exit(EXIT_FAILURE);
    }

    // Print the data received from the client.
    printf("Received: %s", buffer);

    // Send data back to the client.
    if (send(client_sock, buffer, strlen(buffer), 0) < 0) {
      perror("send");
      exit(EXIT_FAILURE);
    }
  }

  // Close the socket.
  close(sock);
  close(client_sock);

  return EXIT_SUCCESS;
}