//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <server_ip> <server_port> <sender_email> <recipient_email>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a socket for TCP communication
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Specify the server address and port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  // Connect to the SMTP server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Receive the welcome message from the server
  char buffer[MAX_BUFFER_SIZE];
  memset(buffer, 0, MAX_BUFFER_SIZE);
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("Server welcome message: %s\n", buffer);

  // Send the HELO command to the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  sprintf(buffer, "HELO %s\r\n", "client.example.com");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("Server HELO response: %s\n", buffer);

  // Send the MAIL FROM command to the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  sprintf(buffer, "MAIL FROM: %s\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("Server MAIL FROM response: %s\n", buffer);

  // Send the RCPT TO command to the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  sprintf(buffer, "RCPT TO: %s\r\n", argv[4]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("Server RCPT TO response: %s\n", buffer);

  // Send the DATA command to the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  strcpy(buffer, "DATA\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("Server DATA response: %s\n", buffer);

  // Send the email body to the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  strcpy(buffer, "Subject: Test email\r\n\r\nThis is a test email.\r\n.");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send the QUIT command to the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  strcpy(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  memset(buffer, 0, MAX_BUFFER_SIZE);
  if (recv(sockfd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("Server QUIT response: %s\n", buffer);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}