//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFFSIZE 4096

int main(int argc, char const *argv[]) {
  char sendBuffer[BUFFSIZE] = {0};
  char recvBuffer[BUFFSIZE] = {0};
  char serverResponse[BUFFSIZE] = {0};
  char emailUsername[BUFFSIZE / 4] = {0};
  char emailPassword[BUFFSIZE / 4] = {0};
  char emailServer[BUFFSIZE / 4] = {0};
  char emailPort[100] = {0};
  int sfd = 0;
  struct sockaddr_in serv_addr;

  // Get email account details from user
  printf("Enter your email username: ");
  scanf("%s", emailUsername);

  printf("Enter your email password: ");
  scanf("%s", emailPassword);

  printf("Enter your email server: ");
  scanf("%s", emailServer);

  printf("Enter email server port: ");
  scanf("%s", emailPort);

  // Create socket
  if ((sfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket creation error.");
    return -1;
  }

  memset(&serv_addr, '0', sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(emailPort));

  if (inet_pton(AF_INET, emailServer, &serv_addr.sin_addr) <= 0) {
    perror("Email server not reachable.");
    return -1;
  }

  if (connect(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Server connection error.");
    return -1;
  }

  // Greet the server
  send(sfd, "1 LOGIN ", strlen("1 LOGIN "), 0);
  send(sfd, emailUsername, strlen(emailUsername), 0);
  send(sfd, " ", strlen(" "), 0);
  send(sfd, emailPassword, strlen(emailPassword), 0);
  send(sfd, "\r\n", strlen("\r\n"), 0);

  // Wait for server welcome message
  recv(sfd, serverResponse, BUFFSIZE, 0);
  printf("Server response: %s", serverResponse);

  // Set the mailbox to INBOX
  send(sfd, "2 SELECT INBOX\r\n", strlen("2 SELECT INBOX\r\n"), 0);

  recv(sfd, serverResponse, BUFFSIZE, 0);
  printf("Server response: %s", serverResponse);

  // Fetch mail info
  send(sfd, "3 FETCH 1 BODY[TEXT]\r\n", strlen("3 FETCH 1 BODY[TEXT]\r\n"), 0);

  recv(sfd, serverResponse, BUFFSIZE, 0);
  printf("Server response: %s", serverResponse);

  // Cleanup
  close(sfd);

  return 0;
}