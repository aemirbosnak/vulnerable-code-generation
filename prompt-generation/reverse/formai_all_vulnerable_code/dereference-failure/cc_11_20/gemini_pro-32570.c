//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 21
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in servaddr;
  char buf[BUFSIZE];
  int n;

  // Check arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  // Resolve the hostname
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Invalid hostname: %s\n", argv[1]);
    exit(1);
  }

  // Fill in the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Send the USER command
  sprintf(buf, "USER anonymous\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the response
  if ((n = recv(sockfd, buf, BUFSIZE, 0)) == -1) {
    perror("recv");
    exit(1);
  }

  // Print the response
  printf("%s", buf);

  // Send the PASS command
  sprintf(buf, "PASS anonymous@example.com\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the response
  if ((n = recv(sockfd, buf, BUFSIZE, 0)) == -1) {
    perror("recv");
    exit(1);
  }

  // Print the response
  printf("%s", buf);

  // Send the CWD command
  sprintf(buf, "CWD /%s\r\n", argv[2]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the response
  if ((n = recv(sockfd, buf, BUFSIZE, 0)) == -1) {
    perror("recv");
    exit(1);
  }

  // Print the response
  printf("%s", buf);

  // Send the RETR command
  sprintf(buf, "RETR %s\r\n", argv[2]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the response
  if ((n = recv(sockfd, buf, BUFSIZE, 0)) == -1) {
    perror("recv");
    exit(1);
  }

  // Print the response
  printf("%s", buf);

  // Close the socket
  close(sockfd);

  return 0;
}