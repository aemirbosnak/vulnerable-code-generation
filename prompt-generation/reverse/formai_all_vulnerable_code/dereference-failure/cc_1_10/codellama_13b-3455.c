//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: grateful
/*
 * Building a HTTP Client example program in a grateful style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <host> <port> <message>\n", argv[0]);
    return 1;
  }

  // Get the host and port from the command line
  char *host = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  // Send a message to the server
  char *message = argv[3];
  int message_len = strlen(message);
  if (send(sock, message, message_len, 0) != message_len) {
    perror("send() failed");
    return 1;
  }

  // Receive the response from the server
  char buffer[1024];
  int bytes_received = recv(sock, buffer, 1024, 0);
  if (bytes_received < 0) {
    perror("recv() failed");
    return 1;
  }

  // Print the response
  printf("Received response: %s\n", buffer);

  // Close the socket
  close(sock);

  return 0;
}