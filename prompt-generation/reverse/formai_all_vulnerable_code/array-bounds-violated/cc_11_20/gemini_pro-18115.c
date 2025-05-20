//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Connect to the POP3 server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
    perror("inet_pton");
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the welcome message from the server
  char buf[BUF_SIZE];
  int len = recv(sockfd, buf, BUF_SIZE - 1, 0);
  if (len == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buf[len] = '\0';
  printf("%s", buf);

  // Send the USER command
  snprintf(buf, BUF_SIZE, "USER %s\r\n", argv[2]);
  len = send(sockfd, buf, strlen(buf), 0);
  if (len == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  len = recv(sockfd, buf, BUF_SIZE - 1, 0);
  if (len == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buf[len] = '\0';
  printf("%s", buf);

  // Send the PASS command
  snprintf(buf, BUF_SIZE, "PASS %s\r\n", argv[3]);
  len = send(sockfd, buf, strlen(buf), 0);
  if (len == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  len = recv(sockfd, buf, BUF_SIZE - 1, 0);
  if (len == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buf[len] = '\0';
  printf("%s", buf);

  // Send the LIST command
  snprintf(buf, BUF_SIZE, "LIST\r\n");
  len = send(sockfd, buf, strlen(buf), 0);
  if (len == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  len = recv(sockfd, buf, BUF_SIZE - 1, 0);
  if (len == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buf[len] = '\0';
  printf("%s", buf);

  // Send the RETR command
  snprintf(buf, BUF_SIZE, "RETR 1\r\n");
  len = send(sockfd, buf, strlen(buf), 0);
  if (len == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  len = recv(sockfd, buf, BUF_SIZE - 1, 0);
  if (len == -1) {
    perror("recv");
    close(sockfd);
    return EXIT_FAILURE;
  }
  buf[len] = '\0';
  printf("%s", buf);

  // Send the QUIT command
  snprintf(buf, BUF_SIZE, "QUIT\r\n");
  len = send(sockfd, buf, strlen(buf), 0);
  if (len == -1) {
    perror("send");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}