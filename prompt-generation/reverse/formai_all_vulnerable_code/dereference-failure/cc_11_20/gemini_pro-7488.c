//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  // Check if the user has provided the server hostname
  if (argc < 2) {
    fprintf(stderr, "Usage: %s hostname\n", argv[0]);
    exit(1);
  }

  // Get the server hostname
  char *hostname = argv[1];

  // Get the server's IP address
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
    exit(1);
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Error: could not create socket");
    exit(1);
  }

  // Connect to the server
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(POP3_PORT);
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("Error: could not connect to server");
    exit(1);
  }

  // Receive the welcome message
  char buf[MAX_LINE];
  if (recv(sock, buf, MAX_LINE, 0) == -1) {
    perror("Error: could not receive welcome message");
    exit(1);
  }

  // Print the welcome message
  printf("%s", buf);

  // Send the USER command
  memset(buf, 0, MAX_LINE);
  sprintf(buf, "USER %s\r\n", "username");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("Error: could not send USER command");
    exit(1);
  }

  // Receive the USER command response
  if (recv(sock, buf, MAX_LINE, 0) == -1) {
    perror("Error: could not receive USER command response");
    exit(1);
  }

  // Print the USER command response
  printf("%s", buf);

  // Send the PASS command
  memset(buf, 0, MAX_LINE);
  sprintf(buf, "PASS %s\r\n", "password");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("Error: could not send PASS command");
    exit(1);
  }

  // Receive the PASS command response
  if (recv(sock, buf, MAX_LINE, 0) == -1) {
    perror("Error: could not receive PASS command response");
    exit(1);
  }

  // Print the PASS command response
  printf("%s", buf);

  // Send the LIST command
  memset(buf, 0, MAX_LINE);
  sprintf(buf, "LIST\r\n");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("Error: could not send LIST command");
    exit(1);
  }

  // Receive the LIST command response
  while (1) {
    if (recv(sock, buf, MAX_LINE, 0) == -1) {
      perror("Error: could not receive LIST command response");
      exit(1);
    }

    // Print the LIST command response
    printf("%s", buf);

    // Check if the response is the end of the list
    if (strcmp(buf, ".\r\n") == 0) {
      break;
    }
  }

  // Send the QUIT command
  memset(buf, 0, MAX_LINE);
  sprintf(buf, "QUIT\r\n");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("Error: could not send QUIT command");
    exit(1);
  }

  // Close the socket
  close(sock);

  return 0;
}