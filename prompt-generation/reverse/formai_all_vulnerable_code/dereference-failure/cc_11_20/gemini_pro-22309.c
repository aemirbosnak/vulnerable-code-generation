//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Attempt to resolve the hostname.
  struct hostent *hostinfo = gethostbyname(argv[1]);
  if (!hostinfo) {
    fprintf(stderr, "Error resolving hostname: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Create a socket.
  int sockfd = socket(PF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the server.
  struct sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(atoi(argv[2]));
  memcpy(&serveraddr.sin_addr, hostinfo->h_addr, hostinfo->h_length);

  if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send a request to the server.
  char *request = "USER anonymous\r\n";
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive a response from the server.
  char buf[BUFSIZE];
  int bytes_received = recv(sockfd, buf, BUFSIZE - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Check if the response is a success.
  if (strncmp(buf, "230 ", 4) != 0) {
    fprintf(stderr, "Error logging in: %s\n", buf);
    exit(EXIT_FAILURE);
  }

  // Send a request to the server to list the files in the current directory.
  request = "LIST\r\n";
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive a response from the server.
  bytes_received = recv(sockfd, buf, BUFSIZE - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Check if the response is a success.
  if (strncmp(buf, "150 ", 4) != 0) {
    fprintf(stderr, "Error listing files: %s\n", buf);
    exit(EXIT_FAILURE);
  }

  // Print the files in the current directory.
  printf("%s\n", buf);

  // Send a request to the server to quit.
  request = "QUIT\r\n";
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive a response from the server.
  bytes_received = recv(sockfd, buf, BUFSIZE - 1, 0);
  if (bytes_received < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Check if the response is a success.
  if (strncmp(buf, "221 ", 4) != 0) {
    fprintf(stderr, "Error quitting: %s\n", buf);
    exit(EXIT_FAILURE);
  }

  // Close the socket.
  close(sockfd);

  return EXIT_SUCCESS;
}