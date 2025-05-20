//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip address> <file name>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send the username
  char username[] = "user\n";
  if (send(sockfd, username, strlen(username), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the welcome message
  char welcome[512];
  if (recv(sockfd, welcome, sizeof(welcome), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", welcome);

  // Send the password
  char password[] = "password\n";
  if (send(sockfd, password, strlen(password), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the login message
  char login[512];
  if (recv(sockfd, login, sizeof(login), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", login);

  // Send the CWD command
  char cwd[] = "CWD /\n";
  if (send(sockfd, cwd, strlen(cwd), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the CWD message
  char cwd_msg[512];
  if (recv(sockfd, cwd_msg, sizeof(cwd_msg), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", cwd_msg);

  // Send the RETR command
  char retr[512];
  snprintf(retr, sizeof(retr), "RETR %s\n", argv[2]);
  if (send(sockfd, retr, strlen(retr), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the RETR message
  char retr_msg[512];
  if (recv(sockfd, retr_msg, sizeof(retr_msg), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", retr_msg);

  // Create a file
  FILE *fp = fopen(argv[2], "wb");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Receive the file data
  char buffer[512];
  while (1) {
    int n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
      perror("recv");
      exit(EXIT_FAILURE);
    } else if (n == 0) {
      break;
    }
    fwrite(buffer, 1, n, fp);
  }

  // Close the file
  fclose(fp);

  // Send the QUIT command
  char quit[] = "QUIT\n";
  if (send(sockfd, quit, strlen(quit), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Close the socket
  close(sockfd);

  return 0;
}