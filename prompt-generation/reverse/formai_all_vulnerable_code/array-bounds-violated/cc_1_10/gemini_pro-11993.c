//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 110

void print_usage() {
  printf("Usage: %s <server> <username> <password>\n", "pop3-client");
}

int main(int argc, char **argv) {
  if (argc != 4) {
    print_usage();
    return 1;
  }

  // Get server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid server address: %s\n", argv[1]);
    return 1;
  }

  // Connect to server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Read welcome message
  char buffer[1024];
  int bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_read < 0) {
    perror("recv");
    return 1;
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // Send USER command
  sprintf(buffer, "USER %s\r\n", argv[2]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read USER response
  bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_read < 0) {
    perror("recv");
    return 1;
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // Send PASS command
  sprintf(buffer, "PASS %s\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Read PASS response
  bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_read < 0) {
    perror("recv");
    return 1;
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // Send STAT command
  if (send(sockfd, "STAT\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read STAT response
  bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_read < 0) {
    perror("recv");
    return 1;
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // Send LIST command
  if (send(sockfd, "LIST\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Read LIST response
  bytes_read = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
  if (bytes_read < 0) {
    perror("recv");
    return 1;
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // Send QUIT command
  if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Close connection
  close(sockfd);

  return 0;
}