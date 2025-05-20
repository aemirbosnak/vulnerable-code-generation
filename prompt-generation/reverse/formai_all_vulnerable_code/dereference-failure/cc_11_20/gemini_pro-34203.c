//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// SMTP commands
#define HELO "HELO"
#define MAIL "MAIL FROM:"
#define RCPT "RCPT TO:"
#define DATA "DATA"
#define QUIT "QUIT"

// SMTP response codes
#define OK "250"
#define QUIT_OK "221"

// SMTP port
#define SMTP_PORT 25

// Maximum line length
#define MAX_LINE_LENGTH 1024

// Main function
int main(int argc, char **argv) {
  // Check arguments
  if (argc != 4) {
    printf("Usage: %s <sender> <recipient> <message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get sender, recipient, and message
  char *sender = argv[1];
  char *recipient = argv[2];
  char *message = argv[3];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the SMTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SMTP_PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Receive the welcome message
  char line[MAX_LINE_LENGTH];
  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", line);

  // Send the HELO command
  if (send(sockfd, HELO, strlen(HELO), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the HELO response
  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", line);

  // Send the MAIL FROM command
  char mail_from[MAX_LINE_LENGTH];
  snprintf(mail_from, sizeof(mail_from), "%s %s", MAIL, sender);
  if (send(sockfd, mail_from, strlen(mail_from), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the MAIL FROM response
  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", line);

  // Send the RCPT TO command
  char rcpt_to[MAX_LINE_LENGTH];
  snprintf(rcpt_to, sizeof(rcpt_to), "%s %s", RCPT, recipient);
  if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the RCPT TO response
  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", line);

  // Send the DATA command
  if (send(sockfd, DATA, strlen(DATA), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the DATA response
  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", line);

  // Send the message
  if (send(sockfd, message, strlen(message), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send the CRLF
  if (send(sockfd, "\r\n", 2, 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send the QUIT command
  if (send(sockfd, QUIT, strlen(QUIT), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the QUIT response
  if (recv(sockfd, line, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s", line);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}