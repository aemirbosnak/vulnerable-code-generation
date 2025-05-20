//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
/*
 * SMTP Client
 *
 * This program sends an email using the Simple Mail Transfer Protocol (SMTP).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Check command-line arguments
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <host> <port> <from> <to> <message>\n", argv[0]);
    return 1;
  }

  // Get command-line arguments
  char *host = argv[1];
  char *port = argv[2];
  char *from = argv[3];
  char *to = argv[4];
  char *message = argv[5];

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Setup socket address structure
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(port));
  addr.sin_addr.s_addr = inet_addr(host);

  // Connect to SMTP server
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send HELO command
  char helo[1024];
  sprintf(helo, "HELO %s\r\n", host);
  if (send(sock, helo, strlen(helo), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send MAIL FROM command
  char mail_from[1024];
  sprintf(mail_from, "MAIL FROM:<%s>\r\n", from);
  if (send(sock, mail_from, strlen(mail_from), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send RCPT TO command
  char rcpt_to[1024];
  sprintf(rcpt_to, "RCPT TO:<%s>\r\n", to);
  if (send(sock, rcpt_to, strlen(rcpt_to), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send DATA command
  if (send(sock, "DATA\r\n", 5, 0) < 0) {
    perror("send");
    return 1;
  }

  // Send message
  if (send(sock, message, strlen(message), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send QUIT command
  if (send(sock, "QUIT\r\n", 5, 0) < 0) {
    perror("send");
    return 1;
  }

  // Close socket
  close(sock);

  return 0;
}