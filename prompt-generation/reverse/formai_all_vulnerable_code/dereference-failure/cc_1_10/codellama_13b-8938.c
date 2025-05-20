//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
/*
 * SMTP Client Example Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MSG_SIZE 1024
#define MAX_RECIPIENTS 5

int main(int argc, char *argv[]) {
  // Check command line arguments
  if (argc != 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  // Get host and port from command line arguments
  char *host = argv[1];
  int port = atoi(argv[2]);

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Set up address structure
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send EHLO message
  char msg[MAX_MSG_SIZE];
  sprintf(msg, "EHLO %s\r\n", host);
  send(sock, msg, strlen(msg), 0);

  // Send MAIL FROM message
  sprintf(msg, "MAIL FROM:<%s>\r\n", host);
  send(sock, msg, strlen(msg), 0);

  // Send RCPT TO message
  char recipients[MAX_RECIPIENTS][MAX_MSG_SIZE];
  for (int i = 0; i < MAX_RECIPIENTS; i++) {
    sprintf(recipients[i], "RCPT TO:<%s>\r\n", argv[i + 3]);
    send(sock, recipients[i], strlen(recipients[i]), 0);
  }

  // Send DATA message
  sprintf(msg, "DATA\r\n");
  send(sock, msg, strlen(msg), 0);

  // Send email message
  char message[MAX_MSG_SIZE];
  while (fgets(message, sizeof(message), stdin) != NULL) {
    send(sock, message, strlen(message), 0);
  }

  // Send QUIT message
  sprintf(msg, "QUIT\r\n");
  send(sock, msg, strlen(msg), 0);

  // Close socket
  close(sock);

  return 0;
}