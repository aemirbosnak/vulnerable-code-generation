//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: medieval
// The Royal IMAP Client

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

// Declaring the knights
char *server_address;
char *username;
char *password;
int server_port;

// The quest begins
int main(int argc, char **argv) {
  // Parsing the royal commands
  if (argc < 5) {
    printf("Usage: %s <server address> <server port> <username> <password>\n", argv[0]);
    return 1;
  }

  // Setting the journey
  server_address = argv[1];
  server_port = atoi(argv[2]);
  username = argv[3];
  password = argv[4];

  // Establishing the connection
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 2;
  }

  struct hostent *server = gethostbyname(server_address);
  if (server == NULL) {
    herror("gethostbyname");
    return 3;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  server_addr.sin_port = htons(server_port);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 4;
  }

  // Greeting the server
  char buf[1024];
  recv(sockfd, buf, sizeof(buf), 0);
  if (strstr(buf, "IMAP4rev1") == NULL) {
    printf("Not an IMAP server\n");
    return 5;
  }

  // Sending our credentials
  sprintf(buf, "A LOGIN %s %s\r\n", username, password);
  send(sockfd, buf, strlen(buf), 0);

  // Reading the response
  recv(sockfd, buf, sizeof(buf), 0);
  if (strstr(buf, "OK") == NULL) {
    printf("Login failed\n");
    return 6;
  }

  // Entering the mail chamber
  printf("Welcome to your mail chamber, sire\n");

  // Fetching missives
  sprintf(buf, "A LIST \"\"\r\n");
  send(sockfd, buf, strlen(buf), 0);

  recv(sockfd, buf, sizeof(buf), 0);
  while (strstr(buf, "OK") == NULL) {
    recv(sockfd, buf, sizeof(buf), 0);
  }

  // Parsing the missives
  char *missives = buf;
  while ((missives = strstr(missives, "INBOX")) != NULL) {
    char *end = strstr(missives, "\r\n");
    int mailbox_num = atoi(missives + 5);
    printf("Mailbox (%d): %.*s\n", mailbox_num, end - missives - 5, missives + 5);
    missives = end + 2;
  }

  // Reading a missive
  printf("Enter the number of the missive to read: ");
  int mailbox_num;
  scanf("%d", &mailbox_num);

  sprintf(buf, "A FETCH %d (BODY[TEXT])\r\n", mailbox_num);
  send(sockfd, buf, strlen(buf), 0);

  recv(sockfd, buf, sizeof(buf), 0);
  while (strstr(buf, "OK") == NULL) {
    recv(sockfd, buf, sizeof(buf), 0);
  }

  // Displaying the missive
  char *body = strstr(buf, "BODY[TEXT]");
  if (body != NULL) {
    printf("Missive:\n%s", body + 12);
  }

  // Departing
  printf("May your mailbox bear good tidings, sire\n");

  close(sockfd);

  return 0;
}