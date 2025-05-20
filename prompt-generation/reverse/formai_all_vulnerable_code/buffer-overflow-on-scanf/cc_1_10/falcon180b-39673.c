//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define POP3_PORT 110
#define MAX_LINE_LEN 1024
#define MAX_USERNAME_LEN 64
#define MAX_PASSWORD_LEN 64


int main() {
  int sock;
  struct sockaddr_in server_addr;
  char response[MAX_LINE_LEN];
  char username[MAX_USERNAME_LEN];
  char password[MAX_PASSWORD_LEN];

  // Open socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Error opening socket\n");
    return 1;
  }

  // Set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("Error connecting to server\n");
    return 1;
  }

  // Send username
  printf("Enter username: ");
  scanf("%s", username);
  sprintf(response, "USER %s\r\n", username);
  send(sock, response, strlen(response), 0);

  // Send password
  printf("Enter password: ");
  scanf("%s", password);
  sprintf(response, "PASS %s\r\n", password);
  send(sock, response, strlen(response), 0);

  // Receive server response
  memset(response, 0, MAX_LINE_LEN);
  recv(sock, response, MAX_LINE_LEN, 0);

  // Print server response
  printf("Server response: %s\n", response);

  // Close socket
  close(sock);

  return 0;
}