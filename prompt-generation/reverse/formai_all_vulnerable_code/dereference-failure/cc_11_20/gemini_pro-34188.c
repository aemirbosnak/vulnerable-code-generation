//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_ADDR "imap.gmail.com"
#define SERVER_PORT 993

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Set the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the login command
  char login_cmd[1024];
  sprintf(login_cmd, "A001 LOGIN username password\r\n");
  if (send(sockfd, login_cmd, strlen(login_cmd), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the login response
  char login_response[1024];
  if (recv(sockfd, login_response, sizeof(login_response), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Parse the login response
  char *status_code = strtok(login_response, " ");
  if (strcmp(status_code, "OK") != 0) {
    printf("Login failed: %s\n", login_response);
    return 1;
  }

  // Send the list command
  char list_cmd[1024];
  sprintf(list_cmd, "A002 LIST \"\" \"\"\r\n");
  if (send(sockfd, list_cmd, strlen(list_cmd), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the list response
  char list_response[1024];
  if (recv(sockfd, list_response, sizeof(list_response), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Parse the list response
  char *folders_list = strtok(list_response, "\r\n");
  while (folders_list != NULL) {
    printf("%s\n", folders_list);
    folders_list = strtok(NULL, "\r\n");
  }

  // Send the logout command
  char logout_cmd[1024];
  sprintf(logout_cmd, "A003 LOGOUT\r\n");
  if (send(sockfd, logout_cmd, strlen(logout_cmd), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the logout response
  char logout_response[1024];
  if (recv(sockfd, logout_response, sizeof(logout_response), 0) < 0) {
    perror("recv");
    return 1;
  }

  // Parse the logout response
  status_code = strtok(logout_response, " ");
  if (strcmp(status_code, "OK") != 0) {
    printf("Logout failed: %s\n", logout_response);
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}