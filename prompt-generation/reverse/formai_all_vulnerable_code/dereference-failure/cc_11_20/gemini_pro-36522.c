//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <server IP address> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the server's IP address and port number.
  char *server_ip_address = argv[1];
  int port = atoi(argv[2]);

  // Create a socket for communicating with the server.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server.
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  inet_pton(AF_INET, server_ip_address, &server_address.sin_addr);

  if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send a greeting to the server.
  char greeting[] = "HELO my dear friend\r\n";
  if (send(sockfd, greeting, strlen(greeting), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  char response[MAX_LINE_LENGTH];
  if (recv(sockfd, response, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("The server says: %s\n", response);

  // Send a mail command to the server.
  char mail_command[] = "MAIL FROM: <sender@example.com>\r\n";
  if (send(sockfd, mail_command, strlen(mail_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  if (recv(sockfd, response, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("The server says: %s\n", response);

  // Send a recipient command to the server.
  char recipient_command[] = "RCPT TO: <recipient@example.com>\r\n";
  if (send(sockfd, recipient_command, strlen(recipient_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  if (recv(sockfd, response, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("The server says: %s\n", response);

  // Send a data command to the server.
  char data_command[] = "DATA\r\n";
  if (send(sockfd, data_command, strlen(data_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  if (recv(sockfd, response, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("The server says: %s\n", response);

  // Send the email message to the server.
  char email_message[] = "This is a test email message.\n";
  if (send(sockfd, email_message, strlen(email_message), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send a period (.) to indicate the end of the email message.
  char period[] = ".\r\n";
  if (send(sockfd, period, strlen(period), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server's response.
  if (recv(sockfd, response, MAX_LINE_LENGTH, 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  printf("The server says: %s\n", response);

  // Close the connection to the server.
  close(sockfd);

  return EXIT_SUCCESS;
}