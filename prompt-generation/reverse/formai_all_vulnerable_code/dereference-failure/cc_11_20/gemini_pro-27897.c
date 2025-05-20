//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in server_addr;
  char buffer[1024];
  char *message;
  int bytes_sent, bytes_received;

  if (argc < 4) {
    printf("Usage: %s <server_ip> <server_port> <message>\n", argv[0]);
    return 1;
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket() failed");
    return 1;
  }

  // Set server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect() failed");
    return 1;
  }

  // Send the greeting message
  message = "HELO localhost\r\n";
  bytes_sent = send(sockfd, message, strlen(message), 0);
  if (bytes_sent == -1) {
    perror("send() failed");
    return 1;
  }

  // Receive the server's response
  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv() failed");
    return 1;
  }

  // Print the server's response
  printf("Server response: %s\n", buffer);

  // Send the mail from address
  message = "MAIL FROM: <sender@example.com>\r\n";
  bytes_sent = send(sockfd, message, strlen(message), 0);
  if (bytes_sent == -1) {
    perror("send() failed");
    return 1;
  }

  // Receive the server's response
  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv() failed");
    return 1;
  }

  // Print the server's response
  printf("Server response: %s\n", buffer);

  // Send the mail to address
  message = "RCPT TO: <receiver@example.com>\r\n";
  bytes_sent = send(sockfd, message, strlen(message), 0);
  if (bytes_sent == -1) {
    perror("send() failed");
    return 1;
  }

  // Receive the server's response
  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv() failed");
    return 1;
  }

  // Print the server's response
  printf("Server response: %s\n", buffer);

  // Send the data
  message = "DATA\r\n";
  bytes_sent = send(sockfd, message, strlen(message), 0);
  if (bytes_sent == -1) {
    perror("send() failed");
    return 1;
  }

  // Receive the server's response
  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv() failed");
    return 1;
  }

  // Print the server's response
  printf("Server response: %s\n", buffer);

  // Send the message body
  message = "This is the message body.\r\n";
  bytes_sent = send(sockfd, message, strlen(message), 0);
  if (bytes_sent == -1) {
    perror("send() failed");
    return 1;
  }

  // Send the end of data marker
  message = ".\r\n";
  bytes_sent = send(sockfd, message, strlen(message), 0);
  if (bytes_sent == -1) {
    perror("send() failed");
    return 1;
  }

  // Receive the server's response
  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv() failed");
    return 1;
  }

  // Print the server's response
  printf("Server response: %s\n", buffer);

  // Send the quit command
  message = "QUIT\r\n";
  bytes_sent = send(sockfd, message, strlen(message), 0);
  if (bytes_sent == -1) {
    perror("send() failed");
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}