//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: funny
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 1024

int main() {
  // Let's imagine we're building a POP3 client. Shall we?
  // First, we'll establish a connection to the mail server.
  // Picture this: Our program strutting up to the server's doorstep, all suave and stuff.
  int sockfd;
  struct sockaddr_in servaddr;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(110);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  // Now, let's say "Hello" to the server. We're all about politeness here!
  char buffer[MAXLINE];
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);
  strcpy(buffer, "USER username@example.com\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // Time for the secret handshake. We'll send our password. Shhh, don't tell anyone!
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);
  strcpy(buffer, "PASS password\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // Now, let's list the emails in our inbox. Curiosity killed the cat, but satisfaction brought it back!
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);
  strcpy(buffer, "LIST\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // Oh, look! We've got some emails. Let's peek inside one, shall we?
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);
  int email_number;
  printf("Which email do you want to open? Enter its number: ");
  scanf("%d", &email_number);
  sprintf(buffer, "RETR %d\r\n", email_number);
  send(sockfd, buffer, strlen(buffer), 0);

  // And here's the juicy part - the email's content!
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);
  strcpy(buffer, "QUIT\r\n");
  send(sockfd, buffer, strlen(buffer), 0);

  // Phew! That was fun. Time to say goodbye to the server.
  recv(sockfd, buffer, MAXLINE, 0);
  printf("%s", buffer);

  // And finally, we're out. Off to do more important things, like eating ice cream.
  close(sockfd);

  return 0;
}