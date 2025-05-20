//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) < 0) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  char buf[BUFSIZE];

  // Send the login command
  snprintf(buf, BUFSIZE, "A001 LOGIN %s %s\r\n", "user", "pass");
  if (write(sockfd, buf, strlen(buf)) < 0) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  // Read the response
  memset(buf, 0, BUFSIZE);
  if (read(sockfd, buf, BUFSIZE) < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Check the response code
  if (strncmp(buf, "A001 OK", 6) != 0) {
    fprintf(stderr, "Login failed: %s\n", buf);
    exit(EXIT_FAILURE);
  }

  // Send the list command
  snprintf(buf, BUFSIZE, "A002 LIST \"\"\r\n");
  if (write(sockfd, buf, strlen(buf)) < 0) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  // Read the response
  memset(buf, 0, BUFSIZE);
  if (read(sockfd, buf, BUFSIZE) < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Check the response code
  if (strncmp(buf, "A002 OK", 6) != 0) {
    fprintf(stderr, "List failed: %s\n", buf);
    exit(EXIT_FAILURE);
  }

  // Print the list of mailboxes
  char *ptr = buf;
  while (*ptr != '\0') {
    printf("%s\n", ptr);
    ptr += strlen(ptr) + 1;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}