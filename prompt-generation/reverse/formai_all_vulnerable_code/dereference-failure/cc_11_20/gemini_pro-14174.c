//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s <to> <from> <message>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a socket for the SMTP connection.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Resolve the hostname of the SMTP server.
  struct hostent *hostent = gethostbyname(argv[1]);
  if (hostent == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }

  // Fill in the sockaddr_in structure with the SMTP server's address and port.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SMTP_PORT);
  memcpy(&server_addr.sin_addr, hostent->h_addr, sizeof(server_addr.sin_addr));

  // Connect to the SMTP server.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's greeting.
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  int bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the HELO command.
  char helo_command[1024];
  snprintf(helo_command, sizeof(helo_command), "HELO %s\r\n", "localhost");
  if (send(sockfd, helo_command, strlen(helo_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response to the HELO command.
  memset(buffer, 0, sizeof(buffer));
  bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the MAIL FROM command.
  char mail_from_command[1024];
  snprintf(mail_from_command, sizeof(mail_from_command), "MAIL FROM: <%s>\r\n", argv[2]);
  if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response to the MAIL FROM command.
  memset(buffer, 0, sizeof(buffer));
  bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the RCPT TO command.
  char rcpt_to_command[1024];
  snprintf(rcpt_to_command, sizeof(rcpt_to_command), "RCPT TO: <%s>\r\n", argv[3]);
  if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response to the RCPT TO command.
  memset(buffer, 0, sizeof(buffer));
  bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the DATA command.
  char data_command[1024];
  snprintf(data_command, sizeof(data_command), "DATA\r\n");
  if (send(sockfd, data_command, strlen(data_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response to the DATA command.
  memset(buffer, 0, sizeof(buffer));
  bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the message.
  if (send(sockfd, argv[4], strlen(argv[4]), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Send the dot command to indicate the end of the message.
  char dot_command[1024];
  snprintf(dot_command, sizeof(dot_command), ".\r\n");
  if (send(sockfd, dot_command, strlen(dot_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Read the SMTP server's response to the dot command.
  memset(buffer, 0, sizeof(buffer));
  bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_read < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Send the QUIT command.
  char quit_command[1024];
  snprintf(quit_command, sizeof(quit_command), "QUIT\r\n");
  if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}