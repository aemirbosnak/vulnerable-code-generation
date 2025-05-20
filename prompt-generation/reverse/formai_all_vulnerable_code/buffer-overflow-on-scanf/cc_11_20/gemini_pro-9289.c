//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFF_SIZE 1024

int main() {
  // Get the FTP server's hostname and port number
  char hostname[BUFF_SIZE];
  int port;
  printf("Enter the hostname of the FTP server: ");
  scanf("%s", hostname);
  printf("Enter the port number of the FTP server: ");
  scanf("%d", &port);

  // Create a socket and connect to the FTP server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(hostname);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Log in to the FTP server
  char username[BUFF_SIZE];
  char password[BUFF_SIZE];
  printf("Enter your username: ");
  scanf("%s", username);
  printf("Enter your password: ");
  scanf("%s", password);

  char login_command[BUFF_SIZE];
  sprintf(login_command, "USER %s", username);
  if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  char login_response[BUFF_SIZE];
  if (recv(sockfd, login_response, BUFF_SIZE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  if (strncmp(login_response, "331", 3) != 0) {
    printf("Login failed: %s\n", login_response);
    exit(EXIT_FAILURE);
  }

  sprintf(login_command, "PASS %s", password);
  if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  if (recv(sockfd, login_response, BUFF_SIZE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  if (strncmp(login_response, "230", 3) != 0) {
    printf("Login failed: %s\n", login_response);
    exit(EXIT_FAILURE);
  }

  // List the files in the current directory
  char list_command[BUFF_SIZE];
  sprintf(list_command, "LIST");
  if (send(sockfd, list_command, strlen(list_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  char list_response[BUFF_SIZE];
  while (recv(sockfd, list_response, BUFF_SIZE, 0) > 0) {
    printf("%s", list_response);
  }

  // Close the connection to the FTP server
  close(sockfd);

  return 0;
}