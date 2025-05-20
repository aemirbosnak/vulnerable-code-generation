//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define FTP_PORT 21
#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  char *filename = argv[2];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Resolve the hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }

  // Connect to the FTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(FTP_PORT);
  server_addr.sin_addr = *(struct in_addr *)host->h_addr;

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Receive the welcome message
  char line[MAX_LINE];
  if (recv(sockfd, line, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s", line);

  // Send the USER command
  char user_cmd[MAX_LINE];
  sprintf(user_cmd, "USER anonymous\r\n");
  if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response
  if (recv(sockfd, line, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s", line);

  // Send the PASS command
  char pass_cmd[MAX_LINE];
  sprintf(pass_cmd, "PASS anony@ftp.com\r\n");
  if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response
  if (recv(sockfd, line, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s", line);

  // Send the TYPE command
  char type_cmd[MAX_LINE];
  sprintf(type_cmd, "TYPE I\r\n");
  if (send(sockfd, type_cmd, strlen(type_cmd), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response
  if (recv(sockfd, line, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s", line);

  // Send the RETR command
  char retr_cmd[MAX_LINE];
  sprintf(retr_cmd, "RETR %s\r\n", filename);
  if (send(sockfd, retr_cmd, strlen(retr_cmd), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive the response
  if (recv(sockfd, line, MAX_LINE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("%s", line);

  // Open the file
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Receive the file data
  while (1) {
    int n = recv(sockfd, line, MAX_LINE, 0);
    if (n < 0) {
      perror("recv");
      exit(EXIT_FAILURE);
    } else if (n == 0) {
      break;
    }
    fwrite(line, 1, n, fp);
  }

  // Close the file
  fclose(fp);

  // Send the QUIT command
  char quit_cmd[MAX_LINE];
  sprintf(quit_cmd, "QUIT\r\n");
  if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Close the socket
  close(sockfd);

  return 0;
}