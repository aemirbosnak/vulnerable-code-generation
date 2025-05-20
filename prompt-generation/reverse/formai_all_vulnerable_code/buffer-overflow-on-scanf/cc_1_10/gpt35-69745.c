//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 4096
#define SERVER_PORT 993

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Usage: %s <server_address> <username>\n", argv[0]);
    return -1;
  }

  // Creating a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Failed to create a socket\n");
    return -1;
  }

  // Set IP address and port of the server
  struct sockaddr_in server;
  server.sin_addr.s_addr = inet_addr(argv[1]);
  server.sin_family = AF_INET;
  server.sin_port = htons(SERVER_PORT);

  // Connecting to the server
  if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
    perror("Connection failed");
    return -1;
  }

  // Receive welcome message
  char response[MAXSIZE];
  recv(sock, response, MAXSIZE, 0);
  printf("%s", response);

  // Login with user credentials
  char user[MAXSIZE], pass[MAXSIZE];
  printf("Username: ");
  scanf("%s", user);
  printf("Password: ");
  scanf("%s", pass);

  char login_cmd[MAXSIZE];
  snprintf(login_cmd, MAXSIZE, "LOGIN %s %s\r\n", user, pass);
  send(sock, login_cmd, strlen(login_cmd), 0);

  // Receive response from the server
  recv(sock, response, MAXSIZE, 0);
  printf("%s", response);

  // List all mail boxes
  char list_cmd[MAXSIZE];
  snprintf(list_cmd, MAXSIZE, "LIST \"\" *\r\n");
  send(sock, list_cmd, strlen(list_cmd), 0);

  // Receive mail boxes list
  recv(sock, response, MAXSIZE, 0);
  printf("%s", response);

  // Close the socket
  close(sock);

  return 0;
}