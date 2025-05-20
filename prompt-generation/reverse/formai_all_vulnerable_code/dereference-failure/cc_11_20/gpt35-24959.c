//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

static const char* const IMAP_SERVER = "imap.gmail.com";
static const int IMAP_PORT = 993;

int main() {
  
  // Connect to IMAP server
  struct hostent *server;
  struct sockaddr_in server_addr;

  server = gethostbyname(IMAP_SERVER);
  if (server == NULL) {
    fprintf(stderr, "ERROR: Unable to resolve server address\n");
    exit(1);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "ERROR: Unable to create socket\n");
    exit(1);
  }

  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(IMAP_PORT);

  if (connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
    fprintf(stderr, "ERROR: Unable to connect to server\n");
    exit(1);
  }

  // Request server greeting
  char buffer[256];
  bzero(buffer,256);
  if (read(sockfd,buffer,255) < 0) {
    fprintf(stderr, "ERROR: Unable to read from socket\n");
    exit(1);
  }
  printf("%s", buffer);

  // Send login command
  char* username = "your_username";
  char* password = "your_password";
  char login_command[256];
  sprintf(login_command, "a001 LOGIN %s %s\r\n", username, password);
  if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
    fprintf(stderr, "ERROR: Unable to send login command\n");
    exit(1);
  }

  // Read login response
  bzero(buffer, 256);
  if (read(sockfd, buffer, 255) < 0) {
    fprintf(stderr, "ERROR: Unable to read from socket\n");
    exit(1);
  }
  printf("%s", buffer);

  // Send select command for inbox folder
  char select_command[256];
  sprintf(select_command, "a002 SELECT INBOX\r\n");
  if (send(sockfd, select_command, strlen(select_command), 0) < 0) {
    fprintf(stderr, "ERROR: Unable to send select command\n");
    exit(1);
  }

  // Read select response
  bzero(buffer, 256);
  if (read(sockfd, buffer, 255) < 0) {
    fprintf(stderr, "ERROR: Unable to read from socket\n");
    exit(1);
  }
  printf("%s", buffer);

  // Send fetch command to retrieve first 5 messages
  char fetch_command[256];
  sprintf(fetch_command, "a003 FETCH 1:5 BODY[HEADER.FIELDS (SUBJECT FROM)]\r\n");
  if (send(sockfd, fetch_command, strlen(fetch_command), 0) < 0) {
    fprintf(stderr, "ERROR: Unable to send fetch command\n");
    exit(1);
  }

  // Read fetch response
  bzero(buffer, 256);
  if (read(sockfd, buffer, 255) < 0) {
    fprintf(stderr, "ERROR: Unable to read from socket\n");
    exit(1);
  }
  printf("%s", buffer);

  // Close connection
  close(sockfd);

  return 0;
}