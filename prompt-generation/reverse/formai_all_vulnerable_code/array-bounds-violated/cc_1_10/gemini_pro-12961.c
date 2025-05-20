//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd, port, n;
  struct sockaddr_in servaddr;
  char buf[1024], username[256], password[256];

  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[2]);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set up the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(1);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Get the username and password
  printf("Username: ");
  fgets(username, sizeof(username), stdin);
  username[strcspn(username, "\n")] = 0;

  printf("Password: ");
  fgets(password, sizeof(password), stdin);
  password[strcspn(password, "\n")] = 0;

  // Send the login command
  snprintf(buf, sizeof(buf), "LOGIN %s %s\r\n", username, password);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    exit(1);
  }

  // Receive the response
  n = recv(sockfd, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    exit(1);
  }

  buf[n] = 0;
  printf("Response: %s\n", buf);

  // Close the socket
  close(sockfd);

  return 0;
}