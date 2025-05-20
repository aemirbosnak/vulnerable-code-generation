//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 143

int main() {
  // create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket creation error");
    return 1;
  }

  // server address and port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  if (inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr) <= 0) {
    perror("inet_pton error");
    return 1;
  }

  // connect to server
  if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("connection failed");
    return 1;
  }

  // get server greeting
  char greeting[1024];
  ssize_t bytes = recv(sock, greeting, sizeof(greeting), 0);
  if (bytes < 0) {
    perror("recv error");
    return 1;
  }

  // print server greeting
  printf("%.*s", (int)bytes, greeting);

  // login to server
  char username[256], password[256];
  printf("Enter username and password: ");
  scanf("%s %s", username, password);
  char login_command[1024];
  sprintf(login_command, "LOGIN %s %s\r\n", username, password);

  // send login command
  if (send(sock, login_command, strlen(login_command), 0) < 0) {
    perror("send error");
    return 1;
  }

  // get server response
  char response[1024];
  bytes = recv(sock, response, sizeof(response), 0);
  if (bytes < 0) {
    perror("recv error");
    return 1;
  }

  // print server response
  printf("%.*s", (int)bytes, response);

  // select mailbox
  char mailbox_name[256];
  printf("Enter mailbox name: ");
  scanf("%s", mailbox_name);
  char select_command[1024];
  sprintf(select_command, "SELECT %s\r\n", mailbox_name);

  // send select command
  if (send(sock, select_command, strlen(select_command), 0) < 0) {
    perror("send error");
    return 1;
  }

  // get server response
  bytes = recv(sock, response, sizeof(response), 0);
  if (bytes < 0) {
    perror("recv error");
    return 1;
  }

  // print server response
  printf("%.*s", (int)bytes, response);

  // logout
  if (send(sock, "LOGOUT\r\n", strlen("LOGOUT\r\n"), 0) < 0) {
    perror("send error");
    return 1;
  }

  // close socket
  close(sock);

  return 0;
}