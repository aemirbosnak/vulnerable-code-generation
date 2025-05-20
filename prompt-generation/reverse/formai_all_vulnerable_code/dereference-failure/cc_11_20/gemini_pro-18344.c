//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 4) {
    printf("Usage: %s <smtp_server> <from_address> <to_address>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Resolve the SMTP server's hostname
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    printf("Error: could not resolve hostname '%s'\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Create a socket for connecting to the SMTP server
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Error: could not create socket\n");
    return EXIT_FAILURE;
  }

  // Connect to the SMTP server
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(25);
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    printf("Error: could not connect to SMTP server\n");
    return EXIT_FAILURE;
  }

  // Send the EHLO message
  char buf[512];
  snprintf(buf, sizeof(buf), "EHLO %s\r\n", argv[0]);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    printf("Error: could not send EHLO message\n");
    return EXIT_FAILURE;
  }

  // Receive the server's response
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    printf("Error: could not receive server's response\n");
    return EXIT_FAILURE;
  }

  // Send the MAIL FROM message
  snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", argv[2]);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    printf("Error: could not send MAIL FROM message\n");
    return EXIT_FAILURE;
  }

  // Receive the server's response
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    printf("Error: could not receive server's response\n");
    return EXIT_FAILURE;
  }

  // Send the RCPT TO message
  snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", argv[3]);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    printf("Error: could not send RCPT TO message\n");
    return EXIT_FAILURE;
  }

  // Receive the server's response
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    printf("Error: could not receive server's response\n");
    return EXIT_FAILURE;
  }

  // Send the DATA message
  snprintf(buf, sizeof(buf), "DATA\r\n");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    printf("Error: could not send DATA message\n");
    return EXIT_FAILURE;
  }

  // Receive the server's response
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    printf("Error: could not receive server's response\n");
    return EXIT_FAILURE;
  }

  // Send the email message
  snprintf(buf, sizeof(buf),
           "From: <%s>\r\n"
           "To: <%s>\r\n"
           "Subject: Test Email\r\n"
           "\r\n"
           "This is a test email.\r\n"
           "\r\n"
           ".\r\n",
           argv[2], argv[3]);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    printf("Error: could not send email message\n");
    return EXIT_FAILURE;
  }

  // Receive the server's response
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    printf("Error: could not receive server's response\n");
    return EXIT_FAILURE;
  }

  // Send the QUIT message
  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    printf("Error: could not send QUIT message\n");
    return EXIT_FAILURE;
  }

  // Receive the server's response
  if (recv(sock, buf, sizeof(buf), 0) == -1) {
    printf("Error: could not receive server's response\n");
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sock);

  return EXIT_SUCCESS;
}