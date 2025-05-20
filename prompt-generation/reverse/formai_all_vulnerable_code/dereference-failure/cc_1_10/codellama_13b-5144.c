//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
// smtp_client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_PORT 25
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_in server_addr;
  char *server_host;
  char *message;
  char buffer[MAX_BUFFER_SIZE];
  int n;

  if (argc != 3) {
    printf("Usage: %s <server_host> <message>\n", argv[0]);
    return 1;
  }

  server_host = argv[1];
  message = argv[2];

  // Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Initialize server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  inet_pton(AF_INET, server_host, &server_addr.sin_addr);

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send message
  n = send(sock, message, strlen(message), 0);
  if (n < 0) {
    perror("send");
    return 1;
  }

  // Receive response
  n = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
  if (n < 0) {
    perror("recv");
    return 1;
  }

  // Print response
  printf("Response: %s\n", buffer);

  // Close socket
  close(sock);

  return 0;
}