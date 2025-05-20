//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd;
  struct sockaddr_in server_addr;
  struct hostent *he;
  char *email_from = "sender@example.com";
  char *email_to = "receiver@example.com";
  char *email_subject = "Testing SMTP Client";
  char *email_body = "This is a test email from my SMTP client.";
  char buffer[1024];
  int bytes_sent;
  char *smtp_server = "smtp.example.com";

  /* Create socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  /* Get the IP address of the SMTP server */
  if ((he = gethostbyname(smtp_server)) == NULL) {
    perror("Error in gethostbyname");
    exit(1);
  }

  /* Fill in the server's address */
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(25);
  memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

  /* Connect to the SMTP server */
  if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  /* Receive the server's greeting message */
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error receiving greeting");
    exit(1);
  }
  printf("%s\n", buffer);

  /* Send the HELO command */
  bytes_sent = sprintf(buffer, "HELO %s\r\n", smtp_server);
  if (send(sockfd, buffer, bytes_sent, 0) < 0) {
    perror("Error sending HELO command");
    exit(1);
  }

  /* Receive the server's response to HELO */
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error receiving HELO response");
    exit(1);
  }
  printf("%s\n", buffer);

  /* Send the MAIL FROM command */
  bytes_sent = sprintf(buffer, "MAIL FROM:<%s>\r\n", email_from);
  if (send(sockfd, buffer, bytes_sent, 0) < 0) {
    perror("Error sending MAIL FROM command");
    exit(1);
  }

  /* Receive the server's response to MAIL FROM */
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error receiving MAIL FROM response");
    exit(1);
  }
  printf("%s\n", buffer);

  /* Send the RCPT TO command */
  bytes_sent = sprintf(buffer, "RCPT TO:<%s>\r\n", email_to);
  if (send(sockfd, buffer, bytes_sent, 0) < 0) {
    perror("Error sending RCPT TO command");
    exit(1);
  }

  /* Receive the server's response to RCPT TO */
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error receiving RCPT TO response");
    exit(1);
  }
  printf("%s\n", buffer);

  /* Send the DATA command */
  bytes_sent = sprintf(buffer, "DATA\r\n");
  if (send(sockfd, buffer, bytes_sent, 0) < 0) {
    perror("Error sending DATA command");
    exit(1);
  }

  /* Receive the server's response to DATA */
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error receiving DATA response");
    exit(1);
  }
  printf("%s\n", buffer);

  /* Send the email headers */
  bytes_sent = sprintf(buffer, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n", email_from, email_to, email_subject);
  if (send(sockfd, buffer, bytes_sent, 0) < 0) {
    perror("Error sending email headers");
    exit(1);
  }

  /* Send the email body */
  bytes_sent = sprintf(buffer, "%s\r\n.\r\n", email_body);
  if (send(sockfd, buffer, bytes_sent, 0) < 0) {
    perror("Error sending email body");
    exit(1);
  }

  /* Receive the server's response to the email */
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error receiving email response");
    exit(1);
  }
  printf("%s\n", buffer);

  /* Send the QUIT command */
  bytes_sent = sprintf(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, bytes_sent, 0) < 0) {
    perror("Error sending QUIT command");
    exit(1);
  }

  /* Receive the server's response to QUIT */
  memset(buffer, 0, sizeof(buffer));
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error receiving QUIT response");
    exit(1);
  }
  printf("%s\n", buffer);

  /* Close the connection */
  close(sockfd);
  return 0;
}