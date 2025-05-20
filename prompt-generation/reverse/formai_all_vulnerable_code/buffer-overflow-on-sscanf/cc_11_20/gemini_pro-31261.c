//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <user>\n", argv[0]);
    exit(1);
  }

  // Get the IP address of the POP3 server
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
    exit(1);
  }

  // Create a socket for connecting to the POP3 server
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Error: Could not create socket");
    exit(1);
  }

  // Connect to the POP3 server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error: Could not connect to POP3 server");
    exit(1);
  }

  // Receive the welcome message from the POP3 server
  char buffer[MAX_LINE];
  if (recv(sock, buffer, MAX_LINE, 0) < 0) {
    perror("Error: Could not receive welcome message");
    exit(1);
  }

  // Send the USER command to the POP3 server
  snprintf(buffer, MAX_LINE, "USER %s\r\n", argv[2]);
  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    perror("Error: Could not send USER command");
    exit(1);
  }

  // Receive the response from the POP3 server
  if (recv(sock, buffer, MAX_LINE, 0) < 0) {
    perror("Error: Could not receive response to USER command");
    exit(1);
  }

  // Send the PASS command to the POP3 server
  snprintf(buffer, MAX_LINE, "PASS %s\r\n", argv[3]);
  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    perror("Error: Could not send PASS command");
    exit(1);
  }

  // Receive the response from the POP3 server
  if (recv(sock, buffer, MAX_LINE, 0) < 0) {
    perror("Error: Could not receive response to PASS command");
    exit(1);
  }

  // Send the STAT command to the POP3 server
  snprintf(buffer, MAX_LINE, "STAT\r\n");
  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    perror("Error: Could not send STAT command");
    exit(1);
  }

  // Receive the response from the POP3 server
  if (recv(sock, buffer, MAX_LINE, 0) < 0) {
    perror("Error: Could not receive response to STAT command");
    exit(1);
  }

  // Parse the response from the POP3 server
  int num_messages;
  int total_size;
  sscanf(buffer, "+OK %d %d", &num_messages, &total_size);

  // Print the number of messages and the total size of the messages
  printf("Number of messages: %d\n", num_messages);
  printf("Total size of messages: %d\n", total_size);

  // Close the socket connection to the POP3 server
  close(sock);

  return 0;
}