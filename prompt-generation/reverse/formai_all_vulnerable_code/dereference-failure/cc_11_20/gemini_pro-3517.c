//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <server> <sender> <recipient> <message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the SMTP server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SMTP_PORT);
  if (inet_aton(argv[1], &serv_addr.sin_addr) == 0) {
    fprintf(stderr, "Invalid server address: %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Read the SMTP server's greeting
  char greeting[1024];
  if (recv(sockfd, greeting, sizeof(greeting), 0) <= 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s\n", greeting);

  // Send the HELO command
  char helo[1024];
  snprintf(helo, sizeof(helo), "HELO %s\r\n", argv[2]);
  if (send(sockfd, helo, strlen(helo), 0) <= 0) {
    perror("send");
    return EXIT_FAILURE;
  }
  printf("%s\n", helo);

  // Read the SMTP server's response to the HELO command
  char response[1024];
  if (recv(sockfd, response, sizeof(response), 0) <= 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s\n", response);

  // Send the MAIL FROM command
  char mailfrom[1024];
  snprintf(mailfrom, sizeof(mailfrom), "MAIL FROM: <%s>\r\n", argv[2]);
  if (send(sockfd, mailfrom, strlen(mailfrom), 0) <= 0) {
    perror("send");
    return EXIT_FAILURE;
  }
  printf("%s\n", mailfrom);

  // Read the SMTP server's response to the MAIL FROM command
  if (recv(sockfd, response, sizeof(response), 0) <= 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s\n", response);

  // Send the RCPT TO command
  char rcptto[1024];
  snprintf(rcptto, sizeof(rcptto), "RCPT TO: <%s>\r\n", argv[3]);
  if (send(sockfd, rcptto, strlen(rcptto), 0) <= 0) {
    perror("send");
    return EXIT_FAILURE;
  }
  printf("%s\n", rcptto);

  // Read the SMTP server's response to the RCPT TO command
  if (recv(sockfd, response, sizeof(response), 0) <= 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s\n", response);

  // Send the DATA command
  char data[1024];
  snprintf(data, sizeof(data), "DATA\r\n");
  if (send(sockfd, data, strlen(data), 0) <= 0) {
    perror("send");
    return EXIT_FAILURE;
  }
  printf("%s\n", data);

  // Read the SMTP server's response to the DATA command
  if (recv(sockfd, response, sizeof(response), 0) <= 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s\n", response);

  // Send the message
  if (send(sockfd, argv[4], strlen(argv[4]), 0) <= 0) {
    perror("send");
    return EXIT_FAILURE;
  }
  printf("%s\n", argv[4]);

  // Send the newline
  char newline[1024];
  snprintf(newline, sizeof(newline), "\r\n");
  if (send(sockfd, newline, strlen(newline), 0) <= 0) {
    perror("send");
    return EXIT_FAILURE;
  }
  printf("%s\n", newline);

  // Send the dot
  char dot[1024];
  snprintf(dot, sizeof(dot), ".\r\n");
  if (send(sockfd, dot, strlen(dot), 0) <= 0) {
    perror("send");
    return EXIT_FAILURE;
  }
  printf("%s\n", dot);

  // Read the SMTP server's response to the dot
  if (recv(sockfd, response, sizeof(response), 0) <= 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s\n", response);

  // Send the QUIT command
  char quit[1024];
  snprintf(quit, sizeof(quit), "QUIT\r\n");
  if (send(sockfd, quit, strlen(quit), 0) <= 0) {
    perror("send");
    return EXIT_FAILURE;
  }
  printf("%s\n", quit);

  // Read the SMTP server's response to the QUIT command
  if (recv(sockfd, response, sizeof(response), 0) <= 0) {
    perror("recv");
    return EXIT_FAILURE;
  }
  printf("%s\n", response);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}