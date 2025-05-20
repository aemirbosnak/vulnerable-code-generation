//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 110  // Standard POP3 port
#define MAX_BUFF_SIZE 1024

int main() {
  int sockfd;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[MAX_BUFF_SIZE], cmd[MAX_BUFF_SIZE], user[MAX_BUFF_SIZE], password[MAX_BUFF_SIZE];
  int n;

  printf("Welcome to POP3 Client, medieval style!\n");
  printf("Please enter your username:\n");
  scanf("%s", user);
  printf("Please enter your password:\n");
  scanf("%s", password);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  server = gethostbyname("pop.server.com");
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(PORT);

  if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  n = recv(sockfd, buffer, MAX_BUFF_SIZE - 1, 0);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response from server: %s", buffer);

  // Send username
  sprintf(cmd, "USER %s\r\n", user);
  n = send(sockfd, cmd, strlen(cmd), 0);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = recv(sockfd, buffer, MAX_BUFF_SIZE - 1, 0);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response from server: %s", buffer);

  // Send password
  sprintf(cmd, "PASS %s\r\n", password);
  n = send(sockfd, cmd, strlen(cmd), 0);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = recv(sockfd, buffer, MAX_BUFF_SIZE - 1, 0);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response from server: %s", buffer);

  // Successfully logged in, ready to retrieve messages
  sprintf(cmd, "LIST\r\n");
  n = send(sockfd, cmd, strlen(cmd), 0);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = recv(sockfd, buffer, MAX_BUFF_SIZE - 1, 0);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response from server: %s", buffer);

  // Log out and quit
  printf("Logging out of POP3 server...\n");
  sprintf(cmd, "QUIT\r\n");
  n = send(sockfd, cmd, strlen(cmd), 0);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  n = recv(sockfd, buffer, MAX_BUFF_SIZE - 1, 0);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  buffer[n] = '\0';
  printf("Response from server: %s", buffer);

  close(sockfd);
  printf("Disconnected from POP3 server.\n");

  return 0;
}