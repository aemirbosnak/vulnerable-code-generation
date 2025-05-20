//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
/*
 * Building a SMTP Client in a paranoid style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    return 1;
  }

  char *server = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, server, &server_addr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid server address\n");
    return 1;
  }

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the message
  char message[] = "Hello, World!";
  if (send(sock, message, strlen(message), 0) < 0) {
    perror("send");
    return 1;
  }

  // Close the socket
  close(sock);

  return 0;
}