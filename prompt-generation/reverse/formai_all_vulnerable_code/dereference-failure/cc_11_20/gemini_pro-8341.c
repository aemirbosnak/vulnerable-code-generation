//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  // Check arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <hostname> <port> <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Resolve hostname
  struct hostent *host = gethostbyname(argv[1]);
  if (!host) {
    fprintf(stderr, "Error resolving hostname: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Connect to server
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr = *(struct in_addr *)host->h_addr;
  addr.sin_port = htons(atoi(argv[2]));
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Send greeting
  char greeting[1024];
  sprintf(greeting, "A01 CAPABILITY\r\n");
  if (send(sock, greeting, strlen(greeting), 0) == -1) {
    fprintf(stderr, "Error sending greeting: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Receive capabilities
  char capabilities[1024];
  size_t capabilities_len = recv(sock, capabilities, sizeof(capabilities), 0);
  if (capabilities_len == -1) {
    fprintf(stderr, "Error receiving capabilities: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Check for AUTH=PLAIN capability
  if (strstr(capabilities, "AUTH=PLAIN") == NULL) {
    fprintf(stderr, "Server does not support AUTH=PLAIN\n");
    return EXIT_FAILURE;
  }

  // Send authentication command
  char auth_command[1024];
  sprintf(auth_command, "A01 AUTHENTICATE PLAIN\r\n%s\r\n\r\n", argv[3]);
  if (send(sock, auth_command, strlen(auth_command), 0) == -1) {
    fprintf(stderr, "Error sending authentication command: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Receive authentication result
  char auth_result[1024];
  size_t auth_result_len = recv(sock, auth_result, sizeof(auth_result), 0);
  if (auth_result_len == -1) {
    fprintf(stderr, "Error receiving authentication result: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Check for authentication success
  if (strncmp(auth_result, "+OK", 3) != 0) {
    fprintf(stderr, "Authentication failed: %s\n", auth_result);
    return EXIT_FAILURE;
  }

  // Send SELECT command
  char select_command[1024];
  sprintf(select_command, "A01 SELECT INBOX\r\n");
  if (send(sock, select_command, strlen(select_command), 0) == -1) {
    fprintf(stderr, "Error sending SELECT command: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Receive SELECT result
  char select_result[1024];
  size_t select_result_len = recv(sock, select_result, sizeof(select_result), 0);
  if (select_result_len == -1) {
    fprintf(stderr, "Error receiving SELECT result: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Check for SELECT success
  if (strncmp(select_result, "+OK", 3) != 0) {
    fprintf(stderr, "SELECT failed: %s\n", select_result);
    return EXIT_FAILURE;
  }

  // Send FETCH command
  char fetch_command[1024];
  sprintf(fetch_command, "A01 FETCH 1 BODY[TEXT]\r\n");
  if (send(sock, fetch_command, strlen(fetch_command), 0) == -1) {
    fprintf(stderr, "Error sending FETCH command: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Receive FETCH result
  char fetch_result[1024];
  size_t fetch_result_len = recv(sock, fetch_result, sizeof(fetch_result), 0);
  if (fetch_result_len == -1) {
    fprintf(stderr, "Error receiving FETCH result: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  // Check for FETCH success
  if (strncmp(fetch_result, "+OK", 3) != 0) {
    fprintf(stderr, "FETCH failed: %s\n", fetch_result);
    return EXIT_FAILURE;
  }

  // Print email body
  printf("%s", fetch_result + 5);

  // Close socket
  close(sock);

  return EXIT_SUCCESS;
}