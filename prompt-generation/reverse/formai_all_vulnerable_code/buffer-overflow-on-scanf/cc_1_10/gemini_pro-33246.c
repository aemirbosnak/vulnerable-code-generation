//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  char sendline[MAXLINE], recvline[MAXLINE];
  struct sockaddr_in servaddr;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server IP address> <port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid IP address\n");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    fprintf(stderr, "Connect failed\n");
    exit(1);
  }

  printf("Enter the email address of the recipient: ");
  scanf("%s", sendline);
  write(sockfd, sendline, strlen(sendline));

  printf("Enter the subject of the email: ");
  scanf(" %s", sendline);
  write(sockfd, sendline, strlen(sendline));

  printf("Enter the body of the email: ");
  while ((n = read(0, sendline, MAXLINE)) > 0) {
    write(sockfd, sendline, n);
  }

  close(sockfd);
  return 0;
}