//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Check if the required command line arguments were passed
  if (argc != 4) {
    printf("Usage: %s [SMTP server] [From email] [To email]\n", argv[0]);
    exit(1);
  }

  char *smtp_server = argv[1];
  char *from_email = argv[2];
  char *to_email = argv[3];

  // Connect to the SMTP server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  struct hostent *server = gethostbyname(smtp_server);

  if (server == NULL) {
    perror("Error finding server");
    exit(1);
  }

  struct sockaddr_in server_addr;
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(25);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  char buffer[BUFFER_SIZE];
  int n;

  // Read greeting from server
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send HELO command to server
  sprintf(buffer, "HELO %s\r\n", smtp_server);

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send MAIL FROM command to server
  sprintf(buffer, "MAIL FROM:<%s>\r\n", from_email);

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send RCPT TO command to server
  sprintf(buffer, "RCPT TO:<%s>\r\n", to_email);

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send DATA command to server
  sprintf(buffer, "DATA\r\n");

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send message to server
  char *message = "Subject: Test email\r\n\r\nThis is a test email from my SMTP client.\r\n.\r\n";

  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send QUIT command to server
  sprintf(buffer, "QUIT\r\n");

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Error writing to socket");
    exit(1);
  }

  // Read response from server
  n = read(sockfd, buffer, BUFFER_SIZE - 1);
  if (n < 0) {
    perror("Error reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("%s", buffer);

  close(sockfd);

  return 0;
}