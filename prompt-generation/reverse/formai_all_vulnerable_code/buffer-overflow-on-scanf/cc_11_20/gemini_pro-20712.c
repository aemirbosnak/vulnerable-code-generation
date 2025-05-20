//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main()
{
  // Introspection: We start by declaring the variables we'll need.
  int sockfd, port;
  char *hostname, *username, *password, *message;
  struct sockaddr_in servaddr;

  // Introspection: Now, let's get the user input.
  printf("Enter hostname: ");
  scanf("%s", hostname);
  printf("Enter port: ");
  scanf("%d", &port);
  printf("Enter username: ");
  scanf("%s", username);
  printf("Enter password: ");
  scanf("%s", password);
  printf("Enter message: ");
  scanf("%s", message);

  // Introspection: Time to create the socket.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Introspection: Let's set up the server address.
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return -1;
  }

  // Introspection: Now, let's connect to the server.
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return -1;
  }

  // Introspection: Let's send the HELO command.
  char buffer[1024];
  sprintf(buffer, "HELO %s\r\n", hostname);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Now, let's send the AUTH LOGIN command.
  sprintf(buffer, "AUTH LOGIN\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Let's send the username.
  sprintf(buffer, "%s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Now, let's send the password.
  sprintf(buffer, "%s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Let's send the MAIL FROM command.
  sprintf(buffer, "MAIL FROM: %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Now, let's send the RCPT TO command.
  sprintf(buffer, "RCPT TO: %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Let's send the DATA command.
  sprintf(buffer, "DATA\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Now, let's send the message.
  sprintf(buffer, "%s\r\n", message);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Let's send the QUIT command.
  sprintf(buffer, "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return -1;
  }

  // Introspection: Let's close the socket.
  close(sockfd);

  return 0;
}