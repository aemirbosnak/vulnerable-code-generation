//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char buffer[1024];

  if (argc != 3) {
    printf("Usage: %s <server_ip> <username>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Resolve the server's address
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Fill in the server's address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr = *(struct in_addr *)host->h_addr;
  servaddr.sin_port = htons(POP3_PORT);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Receive the server's welcome message
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }
  printf("%s", buffer);

  // Send the username
  snprintf(buffer, sizeof(buffer), "USER %s\r\n", argv[2]);
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }
  printf("%s", buffer);

  // Send the password
  snprintf(buffer, sizeof(buffer), "PASS %s\r\n", argv[3]);
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }
  printf("%s", buffer);

  // Send the STAT command
  snprintf(buffer, sizeof(buffer), "STAT\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }
  printf("%s", buffer);

  // Send the LIST command
  snprintf(buffer, sizeof(buffer), "LIST\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }
  printf("%s", buffer);

  // Send the RETR command
  snprintf(buffer, sizeof(buffer), "RETR 1\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }
  printf("%s", buffer);

  // Send the DELE command
  snprintf(buffer, sizeof(buffer), "DELE 1\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server's response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }
  printf("%s", buffer);

  // Send the QUIT command
  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  n = send(sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Close the socket
  close(sockfd);

  return 0;
}