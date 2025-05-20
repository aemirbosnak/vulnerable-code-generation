//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, n;
  char buf[BUFSIZE], *command;
  struct sockaddr_in servaddr;

  // Create socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    error("Error creating socket");

  // Set server address settings
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(143);
  if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0)
    error("Error setting server address");

  // Connect to server
  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    error("Error connecting to server");

  // Login to server
  command = "LOGIN user@example.com password\n";
  write(sockfd, command, strlen(command));
  bzero(buf, BUFSIZE);
  n = read(sockfd, buf, BUFSIZE);
  buf[n] = '\0';
  printf("Server response: %s", buf);

  // Select mailbox
  command = "SELECT INBOX\n";
  write(sockfd, command, strlen(command));
  bzero(buf, BUFSIZE);
  n = read(sockfd, buf, BUFSIZE);
  buf[n] = '\0';
  printf("Server response: %s", buf);

  // Logout from server
  command = "LOGOUT\n";
  write(sockfd, command, strlen(command));
  bzero(buf, BUFSIZE);
  n = read(sockfd, buf, BUFSIZE);
  buf[n] = '\0';
  printf("Server response: %s", buf);

  // Close socket
  close(sockfd);

  return 0;
}