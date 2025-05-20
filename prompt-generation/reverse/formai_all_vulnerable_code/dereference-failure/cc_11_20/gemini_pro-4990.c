//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143
#define IMAP_USER "username"
#define IMAP_PASS "password"

int main() {
  int sock, rv;
  struct sockaddr_in serv_addr;
  struct hostent *host;
  char buf[1024];

  /* Create a socket */
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  /* Resolve the hostname */
  host = gethostbyname("imap.example.com");
  if (!host) {
    perror("gethostbyname");
    return 1;
  }

  /* Set up the server address */
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(IMAP_PORT);
  serv_addr.sin_addr = *(struct in_addr *)host->h_addr;

  /* Connect to the server */
  rv = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (rv < 0) {
    perror("connect");
    return 1;
  }

  /* Send the login command */
  sprintf(buf, "LOGIN %s %s\r\n", IMAP_USER, IMAP_PASS);
  rv = send(sock, buf, strlen(buf), 0);
  if (rv < 0) {
    perror("send");
    return 1;
  }

  /* Receive the login response */
  rv = recv(sock, buf, sizeof(buf), 0);
  if (rv < 0) {
    perror("recv");
    return 1;
  }

  /* Parse the login response */
  if (strncmp(buf, "+OK ", 4) != 0) {
    printf("Login failed: %s", buf);
    return 1;
  }

  /* Send the list command */
  sprintf(buf, "LIST \"\" *\r\n");
  rv = send(sock, buf, strlen(buf), 0);
  if (rv < 0) {
    perror("send");
    return 1;
  }

  /* Receive the list response */
  rv = recv(sock, buf, sizeof(buf), 0);
  if (rv < 0) {
    perror("recv");
    return 1;
  }

  /* Parse the list response */
  while (rv > 0) {
    char *line = buf;
    while (*line != '\r' && *line != '\n' && rv > 0) {
      putchar(*line);
      line++;
      rv--;
    }
    if (*line == '\r') {
      rv--;
      line++;
      if (*line == '\n') {
        rv--;
        line++;
        putchar('\n');
      }
    }
    if (*line == '\n') {
      rv--;
      line++;
      putchar('\n');
    }
    rv = recv(sock, buf, sizeof(buf), 0);
  }

  /* Send the logout command */
  sprintf(buf, "LOGOUT\r\n");
  rv = send(sock, buf, strlen(buf), 0);
  if (rv < 0) {
    perror("send");
    return 1;
  }

  /* Close the socket */
  close(sock);
  return 0;
}