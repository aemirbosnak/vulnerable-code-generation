//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define MAXLEN 100

int main(int argc, char *argv[]) {
  int sockfd, n;
  char recvbuf[BUFSIZE];
  struct sockaddr_in servaddr;
  char username[MAXLEN], password[MAXLEN];
  char* server = "pop.example.com";
  int port = 110;
  char buf[BUFSIZE];

  printf("Enter your username:");
  scanf("%s", username);

  printf("Enter your password:");
  scanf("%s", password);

  /* Create a TCP socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  /* Fill in the structure describing the server */
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  inet_pton(AF_INET, server, &servaddr.sin_addr);

  /* Connect to the server */
  if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  /* Receive the greeting message from the server */
  n = recv(sockfd, recvbuf, BUFSIZE-1, 0);
  recvbuf[n] = '\0';
  printf("%s", recvbuf);

  /* Send the request to log in */
  sprintf(buf, "USER %s\r\n", username);
  write(sockfd, buf, strlen(buf));
  printf("%s", buf);
  n = recv(sockfd, recvbuf, BUFSIZE-1, 0);
  recvbuf[n] = '\0';
  printf("%s", recvbuf);

  sprintf(buf, "PASS %s\r\n", password);
  write(sockfd, buf, strlen(buf));
  printf("%s", buf);
  n = recv(sockfd, recvbuf, BUFSIZE-1, 0);
  recvbuf[n] = '\0';
  printf("%s", recvbuf);

  /* Send the command to list the messages */
  sprintf(buf, "LIST\r\n");
  write(sockfd, buf, strlen(buf));
  printf("%s", buf);
  n = recv(sockfd, recvbuf, BUFSIZE-1, 0);
  recvbuf[n] = '\0';
  printf("%s", recvbuf);

  /* Quit */
  sprintf(buf, "QUIT\r\n");
  write(sockfd, buf, strlen(buf));
  printf("%s", buf);
  n = recv(sockfd, recvbuf, BUFSIZE-1, 0);
  recvbuf[n] = '\0';
  printf("%s", recvbuf);

  /* Close the socket */
  close(sockfd);

  return 0;
}