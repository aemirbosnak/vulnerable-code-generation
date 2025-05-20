//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
// SMTP Client example program in a future-proof style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25

int main(int argc, char *argv[]) {
  // Check command line arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <host> <from> <to> <message>\n", argv[0]);
    return 1;
  }

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  // Resolve hostname
  struct addrinfo hints;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  struct addrinfo *servinfo;
  int ret = getaddrinfo(argv[1], NULL, &hints, &servinfo);
  if (ret != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
    return 1;
  }

  // Connect to server
  int connected = connect(sock, servinfo->ai_addr, servinfo->ai_addrlen);
  if (connected < 0) {
    perror("connect");
    return 1;
  }

  // Send HELO command
  char helo[1024];
  snprintf(helo, sizeof(helo), "HELO %s\r\n", argv[1]);
  if (send(sock, helo, strlen(helo), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send MAIL FROM command
  char mail_from[1024];
  snprintf(mail_from, sizeof(mail_from), "MAIL FROM:<%s>\r\n", argv[2]);
  if (send(sock, mail_from, strlen(mail_from), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send RCPT TO command
  char rcpt_to[1024];
  snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO:<%s>\r\n", argv[3]);
  if (send(sock, rcpt_to, strlen(rcpt_to), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send DATA command
  char data[1024];
  snprintf(data, sizeof(data), "DATA\r\n");
  if (send(sock, data, strlen(data), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send message
  char message[1024];
  snprintf(message, sizeof(message), "%s", argv[4]);
  if (send(sock, message, strlen(message), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send QUIT command
  char quit[1024];
  snprintf(quit, sizeof(quit), "QUIT\r\n");
  if (send(sock, quit, strlen(quit), 0) < 0) {
    perror("send");
    return 1;
  }

  // Close socket
  close(sock);

  return 0;
}