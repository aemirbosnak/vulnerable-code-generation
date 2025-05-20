//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(argv[1]);
  addr.sin_port = htons(atoi(argv[2]));
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Create a pollfd struct for the socket
  struct pollfd pfd;
  pfd.fd = sock;
  pfd.events = POLLIN;

  // Create a buffer for the data
  char buf[BUF_SIZE];

  // Main loop
  while (1) {
    // Poll the socket
    int ret = poll(&pfd, 1, -1);
    if (ret < 0) {
      perror("poll");
      return EXIT_FAILURE;
    }

    // Check if there is data to read
    if (pfd.revents & POLLIN) {
      // Read the data
      int n = read(sock, buf, BUF_SIZE);
      if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
      }

      // Parse the data
      char *line = strtok(buf, "\n");
      while (line != NULL) {
        // Process the line
        printf("%s\n", line);

        // Get the next line
        line = strtok(NULL, "\n");
      }
    }

    // Check if the user has entered a command
    if (pfd.revents & POLLOUT) {
      // Get the command
      char cmd[BUF_SIZE];
      fgets(cmd, BUF_SIZE, stdin);

      // Send the command
      int n = write(sock, cmd, strlen(cmd));
      if (n < 0) {
        perror("write");
        return EXIT_FAILURE;
      }
    }
  }

  // Close the socket
  close(sock);

  return EXIT_SUCCESS;
}