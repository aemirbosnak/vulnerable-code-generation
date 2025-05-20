//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
  int sockfd, n, i, j, k, l, m, flag = 0, count = 0;
  char buffer[1024], str[1024], hostname[256], username[256], password[256], message[1024];

  printf("Enter hostname: ");
  scanf("%s", hostname);

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  // Connect to POP3 server
  sockfd = socket(AF_INET, SOCK_STREAM, htons(110));
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(1000);
  serv_addr.sin_addr.s_addr = inet_addr(hostname);
  connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

  // Login to POP3 server
  sprintf(buffer, "USER %s\r\n", username);
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, 1024);

  sprintf(buffer, "PASS %s\r\n", password);
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, 1024);

  // Get number of messages
  sprintf(buffer, "STAT\r\n");
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, 1024);

  // List messages
  for (i = 0; i < count; i++) {
    sprintf(buffer, "RETR %d\r\n", i + 1);
    write(sockfd, buffer, strlen(buffer));
    read(sockfd, buffer, 1024);

    printf("Subject: %s\n", buffer);
    printf("From: %s\n", buffer);
    printf("Content: %s\n\n", buffer);
  }

  // Logout from POP3 server
  sprintf(buffer, "QUIT\r\n");
  write(sockfd, buffer, strlen(buffer));
  read(sockfd, buffer, 1024);

  close(sockfd);

  return 0;
}