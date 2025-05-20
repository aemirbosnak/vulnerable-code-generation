//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HTTP_PORT 80
#define HTTP_MAX_BUFFER 4096

void die(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

void get_http(char *host, char *path) {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    die("socket");
  }

  // Set up the server address
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(HTTP_PORT);
  if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
    die("inet_pton");
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    die("connect");
  }

  // Send the HTTP request
  char request[HTTP_MAX_BUFFER];
  snprintf(request, HTTP_MAX_BUFFER, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
  if (send(sockfd, request, strlen(request), 0) < 0) {
    die("send");
  }

  // Receive the HTTP response
  char response[HTTP_MAX_BUFFER];
  int n;
  while ((n = recv(sockfd, response, HTTP_MAX_BUFFER - 1, 0)) > 0) {
    response[n] = '\0';
    printf("%s", response);
  }

  if (n < 0) {
    die("recv");
  }

  // Close the socket
  close(sockfd);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <host> <path>\n", argv[0]);
    return EXIT_FAILURE;
  }

  get_http(argv[1], argv[2]);

  return EXIT_SUCCESS;
}