//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <servername> <message>\n", argv[0]);
    return 1;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Resolve the servername
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SMTP_PORT);
  if (inet_aton(argv[1], &server_addr.sin_addr) == 0) {
    printf("Invalid servername: %s\n", argv[1]);
    return 1;
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the HELO command
  char buf[256];
  snprintf(buf, sizeof(buf), "HELO %s\r\n", argv[0]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server response
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  // Send the MAIL FROM command
  snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", argv[0]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server response
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  // Send the RCPT TO command
  snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", argv[1]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server response
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  // Send the DATA command
  if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server response
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  // Send the message
  if (send(sockfd, argv[2], strlen(argv[2]), 0) == -1) {
    perror("send");
    return 1;
  }

  // Send the end of message
  if (send(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server response
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv");
    return 1;
  }

  // Send the QUIT command
  if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
    perror("send");
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}