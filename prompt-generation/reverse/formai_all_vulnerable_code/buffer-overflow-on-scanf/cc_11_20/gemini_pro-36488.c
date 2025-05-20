//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Get the hostname and port number from the user.
  char hostname[1024];
  printf("Enter the hostname of the IMAP server: ");
  scanf("%s", hostname);
  printf("Enter the port number of the IMAP server: ");
  scanf("%d", &portno);

  // Create a socket.
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Get the IP address of the server.
  server = gethostbyname(hostname);
  if (server == NULL) {
    perror("ERROR, no such host");
    exit(1);
  }

  // Fill in the server's address.
  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to the server.
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send the IMAP LOGIN command.
  char login_command[1024];
  snprintf(login_command, sizeof(login_command), "LOGIN username password\r\n");
  if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
    perror("ERROR sending LOGIN command");
    exit(1);
  }

  // Receive the response from the server.
  char response[1024];
  if (recv(sockfd, response, sizeof(response), 0) < 0) {
    perror("ERROR receiving response");
    exit(1);
  }

  // Check if the login was successful.
  if (strncmp(response, "+OK", 3) != 0) {
    printf("ERROR: %s", response);
    exit(1);
  }

  // Send the IMAP SELECT command.
  char select_command[1024];
  snprintf(select_command, sizeof(select_command), "SELECT INBOX\r\n");
  if (send(sockfd, select_command, strlen(select_command), 0) < 0) {
    perror("ERROR sending SELECT command");
    exit(1);
  }

  // Receive the response from the server.
  if (recv(sockfd, response, sizeof(response), 0) < 0) {
    perror("ERROR receiving response");
    exit(1);
  }

  // Check if the SELECT command was successful.
  if (strncmp(response, "+OK", 3) != 0) {
    printf("ERROR: %s", response);
    exit(1);
  }

  // Send the IMAP FETCH command.
  char fetch_command[1024];
  snprintf(fetch_command, sizeof(fetch_command), "FETCH 1:* (BODY.PEEK[HEADER.FIELDS (FROM)])\r\n");
  if (send(sockfd, fetch_command, strlen(fetch_command), 0) < 0) {
    perror("ERROR sending FETCH command");
    exit(1);
  }

  // Receive the response from the server.
  while (1) {
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
      perror("ERROR receiving response");
      exit(1);
    }

    if (strncmp(response, "+OK", 3) == 0) {
      break;
    } else if (strncmp(response, "* 1 FETCH", 9) == 0) {
      char *from_field = strstr(response, "FROM");
      if (from_field != NULL) {
        printf("From: %s", from_field + 5);
      }
    }
  }

  // Send the IMAP CLOSE command.
  char close_command[1024];
  snprintf(close_command, sizeof(close_command), "CLOSE\r\n");
  if (send(sockfd, close_command, strlen(close_command), 0) < 0) {
    perror("ERROR sending CLOSE command");
    exit(1);
  }

  // Receive the response from the server.
  if (recv(sockfd, response, sizeof(response), 0) < 0) {
    perror("ERROR receiving response");
    exit(1);
  }

  // Check if the CLOSE command was successful.
  if (strncmp(response, "+OK", 3) != 0) {
    printf("ERROR: %s", response);
    exit(1);
  }

  // Close the socket.
  close(sockfd);

  return 0;
}