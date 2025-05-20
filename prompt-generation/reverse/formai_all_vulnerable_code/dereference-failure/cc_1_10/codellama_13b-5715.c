//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_COMMAND 100

int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_in server_addr;
  char buffer[MAX_LINE];
  char command[MAX_COMMAND];
  char response[MAX_LINE];
  int n;

  // Check arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s host port\n", argv[0]);
    return 1;
  }

  // Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  // Set up address structure
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Get command from user
  printf("Enter command: ");
  fgets(command, MAX_COMMAND, stdin);

  // Send command to server
  n = write(sock, command, strlen(command));
  if (n < 0) {
    perror("write");
    return 1;
  }

  // Read response from server
  n = read(sock, response, MAX_LINE);
  if (n < 0) {
    perror("read");
    return 1;
  }

  // Print response
  printf("%s\n", response);

  // Close socket
  close(sock);

  return 0;
}