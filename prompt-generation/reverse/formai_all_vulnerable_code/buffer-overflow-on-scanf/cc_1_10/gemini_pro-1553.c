//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to create a socket connection
int create_socket() {
  int sockfd;
  struct sockaddr_in server_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Failed to create socket");
    return -1;
  }

  // Set server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(25);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to connect to server");
    close(sockfd);
    return -1;
  }

  return sockfd;
}

// Function to send an email
int send_email(int sockfd,
               char *sender,
               char *recipient,
               char *subject,
               char *body) {
  char buffer[1024];

  // Send HELO command
  sprintf(buffer, "HELO %s\r\n", "localhost");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send HELO command");
    return -1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Failed to receive HELO response");
    return -1;
  }

  // Send MAIL FROM command
  sprintf(buffer, "MAIL FROM: <%s>\r\n", sender);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send MAIL FROM command");
    return -1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Failed to receive MAIL FROM response");
    return -1;
  }

  // Send RCPT TO command
  sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send RCPT TO command");
    return -1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Failed to receive RCPT TO response");
    return -1;
  }

  // Send DATA command
  sprintf(buffer, "DATA\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send DATA command");
    return -1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Failed to receive DATA response");
    return -1;
  }

  // Send email headers
  sprintf(buffer, "From: %s\r\n", sender);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send From header");
    return -1;
  }
  sprintf(buffer, "To: %s\r\n", recipient);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send To header");
    return -1;
  }
  sprintf(buffer, "Subject: %s\r\n", subject);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send Subject header");
    return -1;
  }

  // Send email body
  if (send(sockfd, body, strlen(body), 0) < 0) {
    perror("Failed to send email body");
    return -1;
  }

  // Send dot (.) to end email
  sprintf(buffer, ".\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send dot to end email");
    return -1;
  }

  // Send QUIT command
  sprintf(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Failed to send QUIT command");
    return -1;
  }
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Failed to receive QUIT response");
    return -1;
  }

  return 0;
}

// Main function
int main() {
  int sockfd;
  char sender[100], recipient[100], subject[100], body[1000];

  // Get sender, recipient, subject, and body from user
  printf("Enter sender email address: ");
  scanf("%s", sender);
  printf("Enter recipient email address: ");
  scanf("%s", recipient);
  printf("Enter email subject: ");
  scanf("%s", subject);
  printf("Enter email body: ");
  scanf("%s", body);

  // Create a socket connection
  sockfd = create_socket();
  if (sockfd < 0) {
    return -1;
  }

  // Send the email
  if (send_email(sockfd, sender, recipient, subject, body) < 0) {
    return -1;
  }

  // Close the socket connection
  close(sockfd);

  return 0;
}