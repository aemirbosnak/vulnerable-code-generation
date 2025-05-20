//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc < 5) {
    printf("Usage: %s <server> <port> <from> <to>\n", argv[0]);
    return 1;
  }

  int sockfd;
  struct sockaddr_in servaddr;
  char buffer[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return 1;
  }

  // Receive greeting
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buffer);

  // Send HELO
  snprintf(buffer, sizeof(buffer), "HELO %s\r\n", argv[1]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive HELO response
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buffer);

  // Send MAIL FROM
  snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive MAIL FROM response
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buffer);

  // Send RCPT TO
  snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", argv[4]);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive RCPT TO response
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buffer);

  // Send DATA
  if (send(sockfd, "DATA\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive DATA response
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buffer);

  // Send message body
  snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s", "Test message", "This is a test message.");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send");
    return 1;
  }

  // Send QUIT
  if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive QUIT response
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buffer);

  close(sockfd);

  return 0;
}