//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
/*
 * POP3 Client Example Program
 *
 * This program is a simple POP3 client that connects to a POP3 server and
 * retrieves emails from the server.
 *
 * Usage:
 *   pop3_client <host> <port> <username> <password>
 *
 * Example:
 *   pop3_client pop.example.com 110 my_username my_password
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
    return 1;
  }

  const char *host = argv[1];
  int port = atoi(argv[2]);
  const char *username = argv[3];
  const char *password = argv[4];

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Send the username and password
  char buffer[BUFSIZE];
  snprintf(buffer, sizeof(buffer), "%s\r\n", username);
  send(sock, buffer, strlen(buffer), 0);

  snprintf(buffer, sizeof(buffer), "%s\r\n", password);
  send(sock, buffer, strlen(buffer), 0);

  // Read the response
  memset(buffer, 0, BUFSIZE);
  recv(sock, buffer, BUFSIZE, 0);

  printf("%s\n", buffer);

  // Read the emails
  int i = 0;
  while (1) {
    // Read the email number
    memset(buffer, 0, BUFSIZE);
    recv(sock, buffer, BUFSIZE, 0);

    if (buffer[0] == '.') {
      break;
    }

    int email_num = atoi(buffer);
    printf("Email %d: ", email_num);

    // Read the email
    memset(buffer, 0, BUFSIZE);
    recv(sock, buffer, BUFSIZE, 0);

    printf("%s\n", buffer);
  }

  close(sock);

  return 0;
}