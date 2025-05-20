//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server> <port> <username>\n", argv[0]);
    return 1;
  }

  char *server = argv[1];
  int port = atoi(argv[2]);
  char *username = argv[3];

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    return 1;
  }

  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "Error converting server address\n");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  char buf[1024];
  int n;

  // Receive welcome message
  n = recv(sockfd, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("Error receiving welcome message");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send username
  snprintf(buf, sizeof(buf), "USER %s\r\n", username);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("Error sending username");
    return 1;
  }

  // Receive username response
  n = recv(sockfd, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("Error receiving username response");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Send password
  snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[4]);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("Error sending password");
    return 1;
  }

  // Receive password response
  n = recv(sockfd, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("Error receiving password response");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // List messages
  snprintf(buf, sizeof(buf), "LIST\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("Error sending LIST command");
    return 1;
  }

  // Receive message list
  n = recv(sockfd, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("Error receiving message list");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Retrieve message
  snprintf(buf, sizeof(buf), "RETR %s\r\n", argv[5]);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("Error sending RETR command");
    return 1;
  }

  // Receive message content
  n = recv(sockfd, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("Error receiving message content");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  // Quit
  snprintf(buf, sizeof(buf), "QUIT\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n < 0) {
    perror("Error sending QUIT command");
    return 1;
  }

  // Receive quit response
  n = recv(sockfd, buf, sizeof(buf) - 1, 0);
  if (n < 0) {
    perror("Error receiving quit response");
    return 1;
  }
  buf[n] = '\0';
  printf("%s", buf);

  close(sockfd);

  return 0;
}