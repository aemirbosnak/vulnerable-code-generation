//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
  // Check if the number of arguments is correct
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <smtp_server> <sender_email> <recipient_email>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the SMTP server address
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Unable to resolve hostname: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Create a socket for the SMTP connection
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Unable to create socket");
    return EXIT_FAILURE;
  }

  // Connect to the SMTP server
  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SMTP_PORT);
  servaddr.sin_addr = *(struct in_addr *)host->h_addr;
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Unable to connect to SMTP server");
    return EXIT_FAILURE;
  }

  // Read the SMTP server's welcome message
  char buf[1024];
  if (read(sockfd, buf, sizeof(buf)) < 0) {
    perror("Unable to read SMTP server's welcome message");
    return EXIT_FAILURE;
  }

  // Send the HELO command
  sprintf(buf, "HELO %s\r\n", "your.domain.tld");
  if (write(sockfd, buf, strlen(buf)) < 0) {
    perror("Unable to send HELO command");
    return EXIT_FAILURE;
  }

  // Read the SMTP server's response
  if (read(sockfd, buf, sizeof(buf)) < 0) {
    perror("Unable to read SMTP server's response");
    return EXIT_FAILURE;
  }

  // Send the MAIL FROM command
  sprintf(buf, "MAIL FROM:<%s>\r\n", argv[2]);
  if (write(sockfd, buf, strlen(buf)) < 0) {
    perror("Unable to send MAIL FROM command");
    return EXIT_FAILURE;
  }

  // Read the SMTP server's response
  if (read(sockfd, buf, sizeof(buf)) < 0) {
    perror("Unable to read SMTP server's response");
    return EXIT_FAILURE;
  }

  // Send the RCPT TO command
  sprintf(buf, "RCPT TO:<%s>\r\n", argv[3]);
  if (write(sockfd, buf, strlen(buf)) < 0) {
    perror("Unable to send RCPT TO command");
    return EXIT_FAILURE;
  }

  // Read the SMTP server's response
  if (read(sockfd, buf, sizeof(buf)) < 0) {
    perror("Unable to read SMTP server's response");
    return EXIT_FAILURE;
  }

  // Send the DATA command
  sprintf(buf, "DATA\r\n");
  if (write(sockfd, buf, strlen(buf)) < 0) {
    perror("Unable to send DATA command");
    return EXIT_FAILURE;
  }

  // Read the SMTP server's response
  if (read(sockfd, buf, sizeof(buf)) < 0) {
    perror("Unable to read SMTP server's response");
    return EXIT_FAILURE;
  }

  // Send the email message
  sprintf(buf, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", argv[2], argv[3], "Test email", "This is a test email.");
  if (write(sockfd, buf, strlen(buf)) < 0) {
    perror("Unable to send email message");
    return EXIT_FAILURE;
  }

  // Read the SMTP server's response
  if (read(sockfd, buf, sizeof(buf)) < 0) {
    perror("Unable to read SMTP server's response");
    return EXIT_FAILURE;
  }

  // Send the QUIT command
  sprintf(buf, "QUIT\r\n");
  if (write(sockfd, buf, strlen(buf)) < 0) {
    perror("Unable to send QUIT command");
    return EXIT_FAILURE;
  }

  // Read the SMTP server's response
  if (read(sockfd, buf, sizeof(buf)) < 0) {
    perror("Unable to read SMTP server's response");
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}