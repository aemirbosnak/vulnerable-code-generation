//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define TIMEOUT 5

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <host>\n", argv[0]);
    exit(1);
  }

  char* host = argv[1];
  struct hostent* h = gethostbyname(host);
  if (h == NULL) {
    printf("Error: Unable to resolve host '%s'\n", host);
    exit(1);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: Unable to create socket\n");
    exit(1);
  }

  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(80);
  memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);

  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    printf("Error: Unable to connect to host '%s'\n", host);
    exit(1);
  }

  char* request = "HEAD / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
  int len = strlen(request);
  char buf[BUFSIZE];

  while (len > 0) {
    int n = write(sockfd, request, len);
    if (n < 0) {
      printf("Error: Unable to write to socket\n");
      exit(1);
    }
    len -= n;
  }

  fd_set readfds;
  struct timeval timeout;
  timeout.tv_sec = TIMEOUT;
  timeout.tv_usec = 0;

  while (1) {
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) < 0) {
      printf("Error: Unable to select\n");
      exit(1);
    }

    if (FD_ISSET(sockfd, &readfds)) {
      int n = read(sockfd, buf, BUFSIZE);
      if (n < 0) {
        printf("Error: Unable to read from socket\n");
        exit(1);
      }

      if (n == 0) {
        printf("Host '%s' is down\n", host);
        close(sockfd);
        exit(0);
      }

      int status = atoi(buf + 9);
      if (status >= 200 && status < 300) {
        printf("Host '%s' is up\n", host);
        close(sockfd);
        exit(0);
      }
    }
  }

  close(sockfd);
  return 0;
}