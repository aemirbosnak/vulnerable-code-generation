//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: active
/*
 * Building a FTP Client in Active Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define FTP_PORT 21
#define FTP_TIMEOUT 10

int main(int argc, char *argv[]) {
  // Check command-line arguments
  if (argc < 3) {
    printf("Usage: %s <host> <filename>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set up the address structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(FTP_PORT);
  if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  // Connect to the FTP server
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the username and password
  char *username = "anonymous";
  char *password = "guest";
  char *command = "USER";
  send(sock, command, strlen(command), 0);
  send(sock, username, strlen(username), 0);
  command = "PASS";
  send(sock, command, strlen(command), 0);
  send(sock, password, strlen(password), 0);

  // Send the file name
  char *filename = argv[2];
  command = "RETR";
  send(sock, command, strlen(command), 0);
  send(sock, filename, strlen(filename), 0);

  // Receive the file data
  char buffer[1024];
  int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
  while (bytes_received > 0) {
    write(STDOUT_FILENO, buffer, bytes_received);
    bytes_received = recv(sock, buffer, sizeof(buffer), 0);
  }

  // Close the socket
  close(sock);

  return 0;
}