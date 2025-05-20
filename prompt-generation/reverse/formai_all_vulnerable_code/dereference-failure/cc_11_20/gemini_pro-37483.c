//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <SMTP server IP> <port> <email address>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse command line arguments
  char *smtp_server_ip = argv[1];
  int port = atoi(argv[2]);
  char *email_address = argv[3];

  // Create a socket for connecting to the SMTP server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return EXIT_FAILURE;
  }

  // Connect to the SMTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(smtp_server_ip);
  int connect_status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connect_status < 0) {
    perror("Error connecting to SMTP server");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the SMTP server's greeting
  char buf[MAX_BUF_SIZE];
  int recv_status = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (recv_status < 0) {
    perror("Error receiving greeting from SMTP server");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send the HELO command
  memset(buf, 0, MAX_BUF_SIZE);
  sprintf(buf, "HELO smtp.example.com\r\n");
  int send_status = send(sockfd, buf, strlen(buf), 0);
  if (send_status < 0) {
    perror("Error sending HELO command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server's response to the HELO command
  memset(buf, 0, MAX_BUF_SIZE);
  recv_status = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (recv_status < 0) {
    perror("Error receiving response to HELO command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send the MAIL FROM command
  memset(buf, 0, MAX_BUF_SIZE);
  sprintf(buf, "MAIL FROM: %s\r\n", email_address);
  send_status = send(sockfd, buf, strlen(buf), 0);
  if (send_status < 0) {
    perror("Error sending MAIL FROM command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server's response to the MAIL FROM command
  memset(buf, 0, MAX_BUF_SIZE);
  recv_status = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (recv_status < 0) {
    perror("Error receiving response to MAIL FROM command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send the RCPT TO command
  memset(buf, 0, MAX_BUF_SIZE);
  sprintf(buf, "RCPT TO: %s\r\n", email_address);
  send_status = send(sockfd, buf, strlen(buf), 0);
  if (send_status < 0) {
    perror("Error sending RCPT TO command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server's response to the RCPT TO command
  memset(buf, 0, MAX_BUF_SIZE);
  recv_status = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (recv_status < 0) {
    perror("Error receiving response to RCPT TO command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send the DATA command
  memset(buf, 0, MAX_BUF_SIZE);
  sprintf(buf, "DATA\r\n");
  send_status = send(sockfd, buf, strlen(buf), 0);
  if (send_status < 0) {
    perror("Error sending DATA command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server's response to the DATA command
  memset(buf, 0, MAX_BUF_SIZE);
  recv_status = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (recv_status < 0) {
    perror("Error receiving response to DATA command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send the email message
  memset(buf, 0, MAX_BUF_SIZE);
  sprintf(buf, "From: %s\r\nTo: %s\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n", email_address, email_address);
  send_status = send(sockfd, buf, strlen(buf), 0);
  if (send_status < 0) {
    perror("Error sending email message");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server's response to the email message
  memset(buf, 0, MAX_BUF_SIZE);
  recv_status = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (recv_status < 0) {
    perror("Error receiving response to email message");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send the QUIT command
  memset(buf, 0, MAX_BUF_SIZE);
  sprintf(buf, "QUIT\r\n");
  send_status = send(sockfd, buf, strlen(buf), 0);
  if (send_status < 0) {
    perror("Error sending QUIT command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server's response to the QUIT command
  memset(buf, 0, MAX_BUF_SIZE);
  recv_status = recv(sockfd, buf, MAX_BUF_SIZE, 0);
  if (recv_status < 0) {
    perror("Error receiving response to QUIT command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}