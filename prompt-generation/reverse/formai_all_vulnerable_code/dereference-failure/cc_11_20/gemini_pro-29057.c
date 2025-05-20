//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_LINE 1024
#define MAX_ARGS 10

int main(int argc, char *argv[]) {
  int sockfd, n;
  char buf[MAX_LINE];
  char *args[MAX_ARGS];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send the command to the server
  sprintf(buf, "LOGIN %s %s\n", argv[3], argv[4]);
  write(sockfd, buf, strlen(buf));

  // Read the response from the server
  n = read(sockfd, buf, MAX_LINE);
  if (n < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Parse the response
  int num_args = 0;
  char *ptr = strtok(buf, " ");
  while (ptr != NULL && num_args < MAX_ARGS) {
    args[num_args++] = ptr;
    ptr = strtok(NULL, " ");
  }

  // Check the response status
  if (strcmp(args[0], "OK") != 0) {
    fprintf(stderr, "Error: %s\n", args[1]);
    exit(EXIT_FAILURE);
  }

  // Print the welcome message
  printf("%s\n", args[1]);

  // Get the list of messages
  write(sockfd, "LIST\n", strlen("LIST\n"));
  n = read(sockfd, buf, MAX_LINE);
  if (n < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Parse the response
  num_args = 0;
  ptr = strtok(buf, " ");
  while (ptr != NULL && num_args < MAX_ARGS) {
    args[num_args++] = ptr;
    ptr = strtok(NULL, " ");
  }

  // Check the response status
  if (strcmp(args[0], "OK") != 0) {
    fprintf(stderr, "Error: %s\n", args[1]);
    exit(EXIT_FAILURE);
  }

  // Print the list of messages
  for (int i = 1; i < num_args; i++) {
    printf("%s\n", args[i]);
  }

  // Close the socket
  close(sockfd);

  return 0;
}