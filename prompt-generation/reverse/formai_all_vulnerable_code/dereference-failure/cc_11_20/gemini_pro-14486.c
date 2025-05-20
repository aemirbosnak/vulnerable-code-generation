//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
  struct hostent *server;
  int sockfd;
  char *hostname = "pop3.example.com";
  char *username = "username";
  char *password = "password";

  server = gethostbyname(hostname);
  if (server == NULL) {
    perror("gethostbyname");
    exit(-1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(-1);
  }

  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(110);
  server_addr.sin_addr = *(struct in_addr *)server->h_addr;

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(-1);
  }

  char buffer[1024];
  int bytes_received;

  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(-1);
  }

  // Send USER command
  snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(-1);
  }

  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(-1);
  }

  // Send PASS command
  snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(-1);
  }

  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(-1);
  }

  printf("Authenticated successfully.\n");

  // Send LIST command
  if (send(sockfd, "LIST\r\n", 6, 0) == -1) {
    perror("send");
    exit(-1);
  }

  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(-1);
  }

  printf("Message list:\n");
  printf("%s\n", buffer);

  // Send RETR command
  if (send(sockfd, "RETR 1\r\n", 9, 0) == -1) {
    perror("send");
    exit(-1);
  }

  bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(-1);
  }

  printf("Message content:\n");
  printf("%s\n", buffer);

  // Send QUIT command
  if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
    perror("send");
    exit(-1);
  }

  close(sockfd);

  return 0;
}