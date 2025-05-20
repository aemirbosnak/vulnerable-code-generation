//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    exit(1);
  }

  int sockfd;
  struct sockaddr_in servaddr;

  // Create a socket.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set up the server address.
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "inet_pton error\n");
    exit(1);
  }

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Receive the welcome message.
  char buf[BUF_SIZE];
  int n;
  n = read(sockfd, buf, BUF_SIZE);
  if (n < 0) {
    perror("read");
    exit(1);
  }
  printf("%s", buf);

  // Send the user command.
  char user[BUF_SIZE];
  printf("Enter your username: ");
  scanf("%s", user);
  write(sockfd, "USER ", 5);
  write(sockfd, user, strlen(user));
  write(sockfd, "\r\n", 2);

  // Receive the user response.
  n = read(sockfd, buf, BUF_SIZE);
  if (n < 0) {
    perror("read");
    exit(1);
  }
  printf("%s", buf);

  // Send the password command.
  char pass[BUF_SIZE];
  printf("Enter your password: ");
  scanf("%s", pass);
  write(sockfd, "PASS ", 5);
  write(sockfd, pass, strlen(pass));
  write(sockfd, "\r\n", 2);

  // Receive the password response.
  n = read(sockfd, buf, BUF_SIZE);
  if (n < 0) {
    perror("read");
    exit(1);
  }
  printf("%s", buf);

  // Send the STAT command.
  write(sockfd, "STAT\r\n", 6);

  // Receive the STAT response.
  n = read(sockfd, buf, BUF_SIZE);
  if (n < 0) {
    perror("read");
    exit(1);
  }
  printf("%s", buf);

  // Send the LIST command.
  write(sockfd, "LIST\r\n", 6);

  // Receive the LIST response.
  while ((n = read(sockfd, buf, BUF_SIZE)) > 0) {
    if (n < 0) {
      perror("read");
      exit(1);
    }
    printf("%s", buf);
  }

  // Send the QUIT command.
  write(sockfd, "QUIT\r\n", 6);

  // Close the socket.
  close(sockfd);

  return 0;
}