//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110

int main() {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char recvline[1024], sendline[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(POP3_PORT);
  inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr); // Replace with the server IP address

  connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  n = recv(sockfd, recvline, 1024, 0);
  recvline[n] = 0;
  printf("%s", recvline);

  // Send USER command
  strcpy(sendline, "USER username\r\n");
  n = send(sockfd, sendline, strlen(sendline), 0);

  n = recv(sockfd, recvline, 1024, 0);
  recvline[n] = 0;
  printf("%s", recvline);

  // Send PASS command
  strcpy(sendline, "PASS password\r\n");
  n = send(sockfd, sendline, strlen(sendline), 0);

  n = recv(sockfd, recvline, 1024, 0);
  recvline[n] = 0;
  printf("%s", recvline);

  // Send STAT command
  strcpy(sendline, "STAT\r\n");
  n = send(sockfd, sendline, strlen(sendline), 0);

  n = recv(sockfd, recvline, 1024, 0);
  recvline[n] = 0;
  printf("%s", recvline);

  // Send LIST command
  strcpy(sendline, "LIST\r\n");
  n = send(sockfd, sendline, strlen(sendline), 0);

  n = recv(sockfd, recvline, 1024, 0);
  recvline[n] = 0;
  printf("%s", recvline);

  // Send RETR command
  strcpy(sendline, "RETR 1\r\n");
  n = send(sockfd, sendline, strlen(sendline), 0);

  n = recv(sockfd, recvline, 1024, 0);
  recvline[n] = 0;
  printf("%s", recvline);

  // Send QUIT command
  strcpy(sendline, "QUIT\r\n");
  n = send(sockfd, sendline, strlen(sendline), 0);

  close(sockfd);

  return 0;
}