//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in serveraddr;
  char username[50];
  char password[50];
  char server_reply[100];
  char *token;
  int port = 110; // POP3 port
  int n;
  FILE *fp;

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(port);
  serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // IP address of the server

  connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

  send(sockfd, "USER ", 5, 0);
  send(sockfd, username, strlen(username), 0);
  send(sockfd, "\r\n", 2, 0);

  recv(sockfd, server_reply, sizeof(server_reply), 0);
  printf("Server reply: %s\n", server_reply);

  send(sockfd, "PASS ", 5, 0);
  send(sockfd, password, strlen(password), 0);
  send(sockfd, "\r\n", 2, 0);

  recv(sockfd, server_reply, sizeof(server_reply), 0);
  printf("Server reply: %s\n", server_reply);

  send(sockfd, "LIST\r\n", 6, 0);

  recv(sockfd, server_reply, sizeof(server_reply), 0);
  printf("Server reply: %s\n", server_reply);

  token = strtok(server_reply, "\r\n");
  while (token!= NULL) {
    printf("%s\n", token);
    token = strtok(NULL, "\r\n");
  }

  close(sockfd);

  return 0;
}