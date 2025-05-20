//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUFSIZE 1024

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("Usage: %s <server_address> <port> <message>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get server address
  struct hostent* server = gethostbyname(argv[1]);
  if (server == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  server_addr.sin_port = htons(atoi(argv[2]));
  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send message
  char buf[BUFSIZE];
  memset(buf, 0, BUFSIZE);
  snprintf(buf, BUFSIZE, "MAIL FROM: <%s>\r\n", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  memset(buf, 0, BUFSIZE);
  snprintf(buf, BUFSIZE, "RCPT TO: <%s>\r\n", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  memset(buf, 0, BUFSIZE);
  snprintf(buf, BUFSIZE, "DATA\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  memset(buf, 0, BUFSIZE);
  snprintf(buf, BUFSIZE, "Subject: Test Email\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  memset(buf, 0, BUFSIZE);
  snprintf(buf, BUFSIZE, "From: %s\r\n", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  memset(buf, 0, BUFSIZE);
  snprintf(buf, BUFSIZE, "To: %s\r\n", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  memset(buf, 0, BUFSIZE);
  strcpy(buf, "This is a test email.\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  memset(buf, 0, BUFSIZE);
  snprintf(buf, BUFSIZE, ".\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Close socket
  close(sockfd);

  return EXIT_SUCCESS;
}