//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
  // Check arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server> <sender> <recipient>\n", argv[0]);
    exit(1);
  }

  // Get server address
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Error: Could not resolve host %s\n", argv[1]);
    exit(1);
  }

  // Create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Error: Could not create socket");
    exit(1);
  }

  // Connect to server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(SMTP_PORT);
  addr.sin_addr = *(struct in_addr *)host->h_addr;
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("Error: Could not connect to server");
    exit(1);
  }

  // Send HELO command
  char buf[512];
  sprintf(buf, "HELO %s\r\n", argv[1]);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("Error: Could not send HELO command");
    exit(1);
  }

  // Receive server response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("Error: Could not receive server response");
    exit(1);
  }

  // Send MAIL FROM command
  sprintf(buf, "MAIL FROM: <%s>\r\n", argv[2]);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("Error: Could not send MAIL FROM command");
    exit(1);
  }

  // Receive server response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("Error: Could not receive server response");
    exit(1);
  }

  // Send RCPT TO command
  sprintf(buf, "RCPT TO: <%s>\r\n", argv[3]);
  if (send(sock, buf, strlen(buf), 0) < 0) {
    perror("Error: Could not send RCPT TO command");
    exit(1);
  }

  // Receive server response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("Error: Could not receive server response");
    exit(1);
  }

  // Send DATA command
  if (send(sock, "DATA\r\n", 5, 0) < 0) {
    perror("Error: Could not send DATA command");
    exit(1);
  }

  // Receive server response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("Error: Could not receive server response");
    exit(1);
  }

  // Send email body
  char *body = "This is a test email.\n";
  if (send(sock, body, strlen(body), 0) < 0) {
    perror("Error: Could not send email body");
    exit(1);
  }

  // Send dot to indicate end of email
  if (send(sock, ".\r\n", 3, 0) < 0) {
    perror("Error: Could not send end of email");
    exit(1);
  }

  // Receive server response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("Error: Could not receive server response");
    exit(1);
  }

  // Send QUIT command
  if (send(sock, "QUIT\r\n", 6, 0) < 0) {
    perror("Error: Could not send QUIT command");
    exit(1);
  }

  // Receive server response
  if (recv(sock, buf, sizeof(buf), 0) < 0) {
    perror("Error: Could not receive server response");
    exit(1);
  }

  // Close socket
  close(sock);

  return 0;
}