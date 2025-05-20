//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#define MAX 100

int main() {
  const char *to = "receiver@example.com";
  const char *from = "sender@example.com";
  const char *subject = "Test Mail";
  const char *body = "This is a test mail from SMTP client";
  int sockfd, port;
  char buffer[MAX];
  struct sockaddr_in server_addr;
  struct hostent *server;

  printf("Enter server IP: ");
  fgets(buffer, MAX, stdin);
  buffer[strcspn(buffer, "\n")] = 0;
  server = gethostbyname(buffer);

  printf("Enter server port: ");
  scanf("%d", &port);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  bzero((char*) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char*) server->h_addr, (char*) &server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(port);

  if(connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  read(sockfd, buffer, MAX);
  printf("%s", buffer);

  snprintf(buffer, MAX, "EHLO example.com\r\n");
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, MAX);
  printf("%s", buffer);

  snprintf(buffer, MAX, "MAIL FROM:<%s>\r\n", from);
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, MAX);
  printf("%s", buffer);

  snprintf(buffer, MAX, "RCPT TO:<%s>\r\n", to);
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, MAX);
  printf("%s", buffer);

  snprintf(buffer, MAX, "DATA\r\n");
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, MAX);
  printf("%s", buffer);

  snprintf(buffer, MAX, "From: %s\r\n", from);
  write(sockfd, buffer, strlen(buffer));
  snprintf(buffer, MAX, "To: %s\r\n", to);
  write(sockfd, buffer, strlen(buffer));
  snprintf(buffer, MAX, "Subject: %s\r\n", subject);
  write(sockfd, buffer, strlen(buffer));
  snprintf(buffer, MAX, "\r\n%s\r\n", body);
  write(sockfd, buffer, strlen(buffer));

  snprintf(buffer, MAX, ".\r\n");
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, MAX);
  printf("%s", buffer);

  snprintf(buffer, MAX, "QUIT\r\n");
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, MAX);
  printf("%s", buffer);

  close(sockfd);
  return 0;
}