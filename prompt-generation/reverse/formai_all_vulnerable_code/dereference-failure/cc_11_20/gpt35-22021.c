//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  // Connect to the IMAP server using TCP socket
  struct sockaddr_in serv_addr;
  char *server_name = "mail.example.com";
  char *username = "user@example.com";
  char *password = "<password>";
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("ERROR: Failed to create socket.\n");
    exit(-1);
  }
  struct hostent *server = gethostbyname(server_name);
  if (server == NULL) {
    printf("ERROR: Failed to resolve server address.\n");
    exit(-1);
  }
  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(143);
  if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("ERROR: Failed to connect to server.\n");
    exit(-1);
  }

  // Login to the server with username and password
  char buf[4096];
  int n = read(sock, buf, 4096);
  if (n < 0) {
    printf("ERROR: Failed to read server response.\n");
    exit(-1);
  }
  printf("Server response: %s\n", buf);
  sprintf(buf, "a001 LOGIN %s %s\r\n", username, password);
  n = write(sock, buf, strlen(buf));
  if (n < 0) {
    printf("ERROR: Failed to send login credentials.\n");
    exit(-1);
  }

  // Fetch a list of available mailboxes
  sprintf(buf, "a002 LIST \"\" *\r\n");
  n = write(sock, buf, strlen(buf));
  if (n < 0) {
    printf("ERROR: Failed to fetch mailbox list.\n");
    exit(-1);
  }
  n = read(sock, buf, 4096);
  if (n < 0) {
    printf("ERROR: Failed to read mailbox list.\n");
    exit(-1);
  }
  printf("Mailboxes:\n%s\n", buf);

  // Select a mailbox (e.g. INBOX) and fetch the list of messages
  sprintf(buf, "a003 SELECT INBOX\r\n");
  n = write(sock, buf, strlen(buf));
  if (n < 0) {
    printf("ERROR: Failed to select mailbox.\n");
    exit(-1);
  }
  n = read(sock, buf, 4096);
  if (n < 0) {
    printf("ERROR: Failed to read mailbox status.\n");
    exit(-1);
  }
  printf("Mailbox status: %s\n", buf);
  sprintf(buf, "a004 UID SEARCH ALL\r\n");
  n = write(sock, buf, strlen(buf));
  if (n < 0) {
    printf("ERROR: Failed to search mailbox.\n");
    exit(-1);
  }
  n = read(sock, buf, 4096);
  if (n < 0) {
    printf("ERROR: Failed to read mailbox search results.\n");
    exit(-1);
  }
  printf("Messages:\n%s\n", buf);

  // Logout and close the connection
  sprintf(buf, "a005 LOGOUT\r\n");
  n = write(sock, buf, strlen(buf));
  if (n < 0) {
    printf("ERROR: Failed to send logout command.\n");
  }
  close(sock);

  return 0;
}