//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    return -1;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  char buffer[BUFFER_SIZE];
  memset(buffer, 0, sizeof(buffer));

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  inet_aton(argv[1], &server_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return -1;
  }

  printf("Connected to %s:%s\n", argv[1], argv[2]);

  int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("recv");
    return -1;
  }

  printf("Received: %s", buffer);

  char *hello = "HELO localhost\r\n";
  if (send(sockfd, hello, strlen(hello), 0) < 0) {
    perror("send");
    return -1;
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("recv");
    return -1;
  }

  printf("Received: %s", buffer);

  char *from = "MAIL FROM: <john.doe@example.com>\r\n";
  if (send(sockfd, from, strlen(from), 0) < 0) {
    perror("send");
    return -1;
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("recv");
    return -1;
  }

  printf("Received: %s", buffer);

  char *to = "RCPT TO: <jane.doe@example.com>\r\n";
  if (send(sockfd, to, strlen(to), 0) < 0) {
    perror("send");
    return -1;
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("recv");
    return -1;
  }

  printf("Received: %s", buffer);

  char *data = "DATA\r\n";
  if (send(sockfd, data, strlen(data), 0) < 0) {
    perror("send");
    return -1;
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("recv");
    return -1;
  }

  printf("Received: %s", buffer);

  char *message = "From: john.doe@example.com\r\nTo: jane.doe@example.com\r\nSubject: Hello, World!\r\n\r\nThis is a test message.\r\n.\r\n";
  if (send(sockfd, message, strlen(message), 0) < 0) {
    perror("send");
    return -1;
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("recv");
    return -1;
  }

  printf("Received: %s", buffer);

  char *quit = "QUIT\r\n";
  if (send(sockfd, quit, strlen(quit), 0) < 0) {
    perror("send");
    return -1;
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("recv");
    return -1;
  }

  printf("Received: %s", buffer);

  close(sockfd);

  return 0;
}