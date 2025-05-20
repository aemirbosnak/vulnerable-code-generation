//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_LINE 1024
#define POP3_PORT 110
#define USER "user"
#define PASS "password"

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in server_addr;
  char username[20];
  char password[20];
  char buffer[MAX_LINE];
  int n;

  printf("Enter your username: ");
  scanf("%s", username);

  printf("Enter your password: ");
  scanf("%s", password);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: Unable to create socket\n");
    exit(1);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error: Unable to connect to server\n");
    exit(1);
  }

  printf("Connected to server\n");

  send(sockfd, "USER ", strlen("USER "), 0);
  send(sockfd, username, strlen(username), 0);
  send(sockfd, "\r\n", 2, 0);

  recv(sockfd, buffer, MAX_LINE, 0);
  printf("Server response: %s\n", buffer);

  send(sockfd, "PASS ", strlen("PASS "), 0);
  send(sockfd, password, strlen(password), 0);
  send(sockfd, "\r\n", 2, 0);

  recv(sockfd, buffer, MAX_LINE, 0);
  printf("Server response: %s\n", buffer);

  send(sockfd, "STAT\r\n", strlen("STAT\r\n"), 0);

  recv(sockfd, buffer, MAX_LINE, 0);
  printf("Server response: %s\n", buffer);

  send(sockfd, "RETR 1\r\n", strlen("RETR 1\r\n"), 0);

  recv(sockfd, buffer, MAX_LINE, 0);
  printf("Server response: %s\n", buffer);

  while ((n = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
    buffer[n] = '\0';
    printf("Server response: %s\n", buffer);
  }

  close(sockfd);
  return 0;
}