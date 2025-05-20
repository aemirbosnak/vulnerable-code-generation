//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  // Check arguments
  if (argc < 5) {
    fprintf(stderr, "Usage: %s <server> <port> <username> <password>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get server address
  struct addrinfo hints, *result;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;
  int status = getaddrinfo(argv[1], argv[2], &hints, &result);
  if (status != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    return EXIT_FAILURE;
  }

  // Connect to server
  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    perror("socket");
    freeaddrinfo(result);
    return EXIT_FAILURE;
  }

  if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
    perror("connect");
    freeaddrinfo(result);
    close(sockfd);
    return EXIT_FAILURE;
  }

  freeaddrinfo(result);

  // Send LOGIN command
  char buf[BUF_SIZE];
  snprintf(buf, BUF_SIZE, "LOGIN %s %s\r\n", argv[3], argv[4]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive LOGIN response
  if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Check LOGIN response
  if (strncmp(buf, "+OK", 3) != 0) {
    fprintf(stderr, "LOGIN failed: %s\n", buf);
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send LIST command
  snprintf(buf, BUF_SIZE, "LIST \"\" *\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive LIST response
  while (1) {
    if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
      perror("recv");
      close(sockfd);
      return EXIT_FAILURE;
    }

    // Check for end of response
    if (strcmp(buf, "* OK\r\n") == 0) {
      break;
    }

    // Print mailbox name
    printf("%s\n", buf);
  }

  // Send LOGOUT command
  snprintf(buf, BUF_SIZE, "LOGOUT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive LOGOUT response
  if (recv(sockfd, buf, BUF_SIZE, 0) == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Check LOGOUT response
  if (strncmp(buf, "+OK", 3) != 0) {
    fprintf(stderr, "LOGOUT failed: %s\n", buf);
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Close socket
  close(sockfd);

  return EXIT_SUCCESS;
}