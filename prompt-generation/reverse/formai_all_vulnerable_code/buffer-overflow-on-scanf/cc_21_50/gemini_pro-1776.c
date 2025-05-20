//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_HOSTNAME_LENGTH 256
#define MAX_PORT_NUMBER 5
#define MAX_EMAIL_ADDRESS_LENGTH 256
#define MAX_SUBJECT_LENGTH 256
#define MAX_BODY_LENGTH 1024

int main() {
  // Get the hostname and port number from the user.
  char hostname[MAX_HOSTNAME_LENGTH];
  int portNumber;
  printf("Enter the hostname of the SMTP server: ");
  scanf("%s", hostname);
  printf("Enter the port number of the SMTP server: ");
  scanf("%d", &portNumber);

  // Create a socket for connecting to the SMTP server.
  int socketFD = socket(AF_INET, SOCK_STREAM, 0);
  if (socketFD == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Get the IP address of the SMTP server.
  struct hostent *hostEntry = gethostbyname(hostname);
  if (hostEntry == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Create an address structure for connecting to the SMTP server.
  struct sockaddr_in serverAddress;
  memset(&serverAddress, 0, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_port = htons(portNumber);
  memcpy(&serverAddress.sin_addr, hostEntry->h_addr, hostEntry->h_length);

  // Connect to the SMTP server.
  if (connect(socketFD, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the HELO command to the SMTP server.
  char heloCommand[MAX_HOSTNAME_LENGTH + 6] = "HELO ";
  strcat(heloCommand, hostname);
  strcat(heloCommand, "\r\n");
  if (send(socketFD, heloCommand, strlen(heloCommand), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the SMTP server to the HELO command.
  char response[1024];
  if (recv(socketFD, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the response from the SMTP server indicates an error.
  if (strncmp(response, "250", 3) != 0) {
    printf("Error: %s\n", response);
    return EXIT_FAILURE;
  }

  // Send the MAIL FROM command to the SMTP server.
  char mailFromCommand[MAX_EMAIL_ADDRESS_LENGTH + 10] = "MAIL FROM: ";
  strcat(mailFromCommand, "sender@example.com");
  strcat(mailFromCommand, "\r\n");
  if (send(socketFD, mailFromCommand, strlen(mailFromCommand), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the SMTP server to the MAIL FROM command.
  if (recv(socketFD, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the response from the SMTP server indicates an error.
  if (strncmp(response, "250", 3) != 0) {
    printf("Error: %s\n", response);
    return EXIT_FAILURE;
  }

  // Send the RCPT TO command to the SMTP server.
  char rcptToCommand[MAX_EMAIL_ADDRESS_LENGTH + 10] = "RCPT TO: ";
  strcat(rcptToCommand, "recipient@example.com");
  strcat(rcptToCommand, "\r\n");
  if (send(socketFD, rcptToCommand, strlen(rcptToCommand), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the SMTP server to the RCPT TO command.
  if (recv(socketFD, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the response from the SMTP server indicates an error.
  if (strncmp(response, "250", 3) != 0) {
    printf("Error: %s\n", response);
    return EXIT_FAILURE;
  }

  // Send the DATA command to the SMTP server.
  if (send(socketFD, "DATA\r\n", 6, 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the SMTP server to the DATA command.
  if (recv(socketFD, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the response from the SMTP server indicates an error.
  if (strncmp(response, "354", 3) != 0) {
    printf("Error: %s\n", response);
    return EXIT_FAILURE;
  }

  // Send the email subject to the SMTP server.
  char subject[MAX_SUBJECT_LENGTH + 2] = "Subject: ";
  strcat(subject, "This is a test email");
  strcat(subject, "\r\n");
  if (send(socketFD, subject, strlen(subject), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send the email body to the SMTP server.
  char body[MAX_BODY_LENGTH + 2] = "This is the body of the test email.\r\n";
  if (send(socketFD, body, strlen(body), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send the end-of-message indicator to the SMTP server.
  if (send(socketFD, ".\r\n", 3, 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the SMTP server to the end-of-message indicator.
  if (recv(socketFD, response, sizeof(response), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the response from the SMTP server indicates an error.
  if (strncmp(response, "250", 3) != 0) {
    printf("Error: %s\n", response);
    return EXIT_FAILURE;
  }

  // Send the QUIT command to the SMTP server.
  if (send(socketFD, "QUIT\r\n", 6, 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Close the socket.
  close(socketFD);

  return EXIT_SUCCESS;
}