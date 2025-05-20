//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define EMAIL_MAX_SIZE 1024

int main(int argc, char *argv[]) {
  // Check if all the required arguments are provided
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <SMTP server> <from email> <to email>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the SMTP server address and port
  char *smtp_server = argv[1];
  int smtp_port = 25;

  // Get the sender and receiver email addresses
  char *from_email = argv[2];
  char *to_email = argv[3];

  // Create a socket for connecting to the SMTP server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve the SMTP server's address
  struct hostent *host = gethostbyname(smtp_server);
  if (host == NULL) {
    herror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Connect to the SMTP server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
  serv_addr.sin_port = htons(smtp_port);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Receive the SMTP server's welcome message
  char *response = malloc(EMAIL_MAX_SIZE);
  int response_len = recv(sockfd, response, EMAIL_MAX_SIZE, 0);
  if (response_len < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the SMTP server's welcome message
  printf("SMTP server welcome message:\n%s\n", response);

  // Send the HELO command to the SMTP server
  char *helo_command = "HELO example.com\r\n";
  if (send(sockfd, helo_command, strlen(helo_command), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the SMTP server's response to the HELO command
  response_len = recv(sockfd, response, EMAIL_MAX_SIZE, 0);
  if (response_len < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the SMTP server's response to the HELO command
  printf("SMTP server response to HELO command:\n%s\n", response);

  // Send the MAIL FROM command to the SMTP server
  char *mail_from_command = "MAIL FROM: %s\r\n";
  asprintf(&mail_from_command, mail_from_command, from_email);
  if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the SMTP server's response to the MAIL FROM command
  response_len = recv(sockfd, response, EMAIL_MAX_SIZE, 0);
  if (response_len < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the SMTP server's response to the MAIL FROM command
  printf("SMTP server response to MAIL FROM command:\n%s\n", response);

  // Send the RCPT TO command to the SMTP server
  char *rcpt_to_command = "RCPT TO: %s\r\n";
  asprintf(&rcpt_to_command, rcpt_to_command, to_email);
  if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the SMTP server's response to the RCPT TO command
  response_len = recv(sockfd, response, EMAIL_MAX_SIZE, 0);
  if (response_len < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the SMTP server's response to the RCPT TO command
  printf("SMTP server response to RCPT TO command:\n%s\n", response);

  // Send the DATA command to the SMTP server
  char *data_command = "DATA\r\n";
  if (send(sockfd, data_command, strlen(data_command), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the SMTP server's response to the DATA command
  response_len = recv(sockfd, response, EMAIL_MAX_SIZE, 0);
  if (response_len < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the SMTP server's response to the DATA command
  printf("SMTP server response to DATA command:\n%s\n", response);

  // Send the email message to the SMTP server
  char *email_message = "Subject: Example email\r\n\r\nThis is an example email.\r\n";
  if (send(sockfd, email_message, strlen(email_message), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send the end of the email message to the SMTP server
  char *email_end = ".\r\n";
  if (send(sockfd, email_end, strlen(email_end), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the SMTP server's response to the email message
  response_len = recv(sockfd, response, EMAIL_MAX_SIZE, 0);
  if (response_len < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the SMTP server's response to the email message
  printf("SMTP server response to email message:\n%s\n", response);

  // Send the QUIT command to the SMTP server
  char *quit_command = "QUIT\r\n";
  if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the SMTP server's response to the QUIT command
  response_len = recv(sockfd, response, EMAIL_MAX_SIZE, 0);
  if (response_len < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Print the SMTP server's response to the QUIT command
  printf("SMTP server response to QUIT command:\n%s\n", response);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}