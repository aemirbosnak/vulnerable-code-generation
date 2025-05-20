//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
/*
 * SMTP Client Example
 *
 * This program demonstrates how to build an SMTP client in C
 *
 * Usage:
 *   ./smtp_client [hostname] [port]
 *
 * Example:
 *   ./smtp_client smtp.gmail.com 587
 *
 * Author:
 *   John Doe
 *
 * Date:
 *   2023-01-01
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  // Check the number of arguments
  if (argc != 3) {
    printf("Usage: %s [hostname] [port]\n", argv[0]);
    return 1;
  }

  // Get the hostname and port
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket() failed");
    return 1;
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  inet_pton(AF_INET, hostname, &server_addr.sin_addr);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect() failed");
    return 1;
  }

  // Send the HELO command
  char buffer[BUFFER_SIZE];
  sprintf(buffer, "HELO %s\r\n", hostname);
  send(sock, buffer, strlen(buffer), 0);

  // Send the MAIL FROM command
  sprintf(buffer, "MAIL FROM:<%s>\r\n", hostname);
  send(sock, buffer, strlen(buffer), 0);

  // Send the RCPT TO command
  sprintf(buffer, "RCPT TO:<%s>\r\n", hostname);
  send(sock, buffer, strlen(buffer), 0);

  // Send the DATA command
  send(sock, "DATA\r\n", strlen("DATA\r\n"), 0);

  // Send the message
  char *message = "This is a test message\r\n";
  send(sock, message, strlen(message), 0);

  // Send the closing dot
  send(sock, "\r\n.\r\n", strlen("\r\n.\r\n"), 0);

  // Receive the server response
  recv(sock, buffer, BUFFER_SIZE, 0);
  printf("Response: %s\n", buffer);

  // Close the socket
  close(sock);

  return 0;
}