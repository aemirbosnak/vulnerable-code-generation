//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: happy
// Building a SMTP Client in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s <hostname> <port> <message>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    perror("inet_pton() failed");
    return 1;
  }

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  // Send the message to the server
  char buffer[BUFFER_SIZE];
  sprintf(buffer, "%s", argv[3]);
  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    perror("send() failed");
    return 1;
  }

  // Receive the response from the server
  if (recv(sock, buffer, BUFFER_SIZE, 0) < 0) {
    perror("recv() failed");
    return 1;
  }
  printf("Received response: %s\n", buffer);

  // Close the socket
  close(sock);
  return 0;
}