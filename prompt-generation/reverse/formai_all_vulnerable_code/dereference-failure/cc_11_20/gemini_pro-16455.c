//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

// A simple FTP client in the spirit of Ken Thompson's original Unix tools.

int main(int argc, char **argv) {
  // Check for arguments.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <address> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the address and port from the arguments.
  char *address = argv[1];
  int port = atoi(argv[2]);

  // Create a socket.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the server.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, address, &server_addr.sin_addr) == -1) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Print the welcome message.
  char buf[1024];
  int n;
  if ((n = read(sockfd, buf, sizeof(buf))) == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  printf("%s", buf);

  // Loop until the user quits.
  while (1) {
    // Print the prompt.
    printf("> ");
    fflush(stdout);

    // Read the user input.
    if (fgets(buf, sizeof(buf), stdin) == NULL) {
      perror("fgets");
      exit(EXIT_FAILURE);
    }

    // Remove the newline character from the input.
    buf[strlen(buf) - 1] = '\0';

    // Check for the quit command.
    if (strcmp(buf, "quit") == 0) {
      break;
    }

    // Send the command to the server.
    if (write(sockfd, buf, strlen(buf)) == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }

    // Read the server's response.
    if ((n = read(sockfd, buf, sizeof(buf))) == -1) {
      perror("read");
      exit(EXIT_FAILURE);
    }

    // Print the server's response.
    printf("%s", buf);
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}