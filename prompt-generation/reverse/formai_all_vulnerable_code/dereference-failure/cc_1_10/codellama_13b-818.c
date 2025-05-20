//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: complex
// TCP/IP Programming Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Check for command-line arguments
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Set up address structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[1]));
  addr.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket
  if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind() failed");
    return 1;
  }

  // Listen for incoming connections
  if (listen(sock, 5) < 0) {
    perror("listen() failed");
    return 1;
  }

  printf("Waiting for incoming connections...\n");

  // Accept incoming connections
  int client_sock;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  while (1) {
    client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
      perror("accept() failed");
      return 1;
    }

    printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive data from the client
    char buf[1024];
    int bytes_received = recv(client_sock, buf, sizeof(buf), 0);
    if (bytes_received < 0) {
      perror("recv() failed");
      return 1;
    }

    // Send data back to the client
    int bytes_sent = send(client_sock, buf, bytes_received, 0);
    if (bytes_sent < 0) {
      perror("send() failed");
      return 1;
    }

    // Close the client connection
    close(client_sock);
  }

  // Close the server socket
  close(sock);

  return 0;
}