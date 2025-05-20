//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER "mail.example.com"
#define PORT 110

int main() {
  int sock, recv_size;
  struct sockaddr_in server;

  char username[50], password[50], response[256];

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  // create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Could not create socket.");
    return -1;
  }

  // set server details
  server.sin_addr.s_addr = inet_addr(SERVER);
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);

  // connect to server
  if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
    printf("Could not connect.");
    return -1;
  }

  // receive server response
  if (recv(sock, response, 256, 0) < 0) {
    printf("Error receiving server response.");
    return -1;
  }

  // send username to server
  char user_command[100] = {'\0'};
  strcat(user_command, "USER ");
  strcat(user_command, username);
  strcat(user_command, "\r\n");
  send(sock, user_command, strlen(user_command), 0);

  // receive server response to username
  if (recv(sock, response, 256, 0) < 0) {
    printf("Error receiving server response.");
    return -1;
  }

  // send password to server
  char pass_command[100] = {'\0'};
  strcat(pass_command, "PASS ");
  strcat(pass_command, password);
  strcat(pass_command, "\r\n");
  send(sock, pass_command, strlen(pass_command), 0);

  // receive server response to password
  if (recv(sock, response, 256, 0) < 0) {
    printf("Error receiving server response.");
    return -1;
  }

  // send command to list messages
  char list_command[] = "LIST\r\n";
  send(sock, list_command, strlen(list_command), 0);

  // receive server response to list command
  if (recv(sock, response, 256, 0) < 0) {
    printf("Error receiving server response.");
    return -1;
  }

  // loop through all messages and print the message size
  char *token = strtok(response, " ");
  while (token != NULL) {
    if (isdigit(*token)) {
      printf("Message size: %s\n", token);
    }
    token = strtok(NULL, " ");
  }

  // close socket
  close(sock);

  return 0;
}