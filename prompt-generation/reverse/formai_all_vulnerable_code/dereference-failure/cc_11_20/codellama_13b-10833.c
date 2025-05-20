//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
/*
 * POP3 Client Example Program
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define POP3_PORT 110
#define POP3_BUF_SIZE 1024
#define POP3_MSG_DELIM "\r\n.\r\n"

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
    return 1;
  }

  struct sockaddr_in server_addr;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  char *buf = malloc(POP3_BUF_SIZE);
  if (buf == NULL) {
    perror("malloc");
    return 1;
  }

  // Send the username
  snprintf(buf, POP3_BUF_SIZE, "USER %s\r\n", argv[2]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  // Send the password
  snprintf(buf, POP3_BUF_SIZE, "PASS <password>\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the server greeting
  if (recv(sockfd, buf, POP3_BUF_SIZE, 0) == -1) {
    perror("recv");
    return 1;
  }

  // Print the server greeting
  printf("Server greeting: %s\n", buf);

  // Receive the list of messages
  if (recv(sockfd, buf, POP3_BUF_SIZE, 0) == -1) {
    perror("recv");
    return 1;
  }

  // Print the list of messages
  printf("Message list: %s\n", buf);

  // Receive the message content
  if (recv(sockfd, buf, POP3_BUF_SIZE, 0) == -1) {
    perror("recv");
    return 1;
  }

  // Print the message content
  printf("Message content: %s\n", buf);

  // Close the socket
  close(sockfd);

  return 0;
}