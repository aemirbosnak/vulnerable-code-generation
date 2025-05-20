//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main() {
  char *host = "pop.example.com";
  int port = 110;
  char *username = "user";
  char *password = "password";

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server
  struct sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(port);
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }
  memcpy(&serveraddr.sin_addr, hostent->h_addr, hostent->h_length);
  if (connect(sock, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Receive the welcome message
  char buf[BUFSIZE];
  int n = recv(sock, buf, BUFSIZE, 0);
  if (n == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s", buf);
    return EXIT_FAILURE;
  }

  // Send the USER command
  sprintf(buf, "USER %s\r\n", username);
  n = send(sock, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  n = recv(sock, buf, BUFSIZE, 0);
  if (n == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s", buf);
    return EXIT_FAILURE;
  }

  // Send the PASS command
  sprintf(buf, "PASS %s\r\n", password);
  n = send(sock, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  n = recv(sock, buf, BUFSIZE, 0);
  if (n == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s", buf);
    return EXIT_FAILURE;
  }

  // Send the LIST command
  sprintf(buf, "LIST\r\n");
  n = send(sock, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  n = recv(sock, buf, BUFSIZE, 0);
  if (n == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s", buf);
    return EXIT_FAILURE;
  }

  // Parse the LIST response
  char *line = buf;
  while (*line != '\0') {
    char *space = strchr(line, ' ');
    if (space == NULL) {
      break;
    }
    *space = '\0';
    int msgno = atoi(line);
    int size = atoi(space + 1);
    printf("Message %d: %d bytes\n", msgno, size);
    line = space + 1;
  }

  // Send the QUIT command
  sprintf(buf, "QUIT\r\n");
  n = send(sock, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  n = recv(sock, buf, BUFSIZE, 0);
  if (n == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Error: %s", buf);
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sock);

  return EXIT_SUCCESS;
}