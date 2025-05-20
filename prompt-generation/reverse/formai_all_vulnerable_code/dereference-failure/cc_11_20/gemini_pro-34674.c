//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in servaddr;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
    return 1;
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Resolve the hostname
  struct hostent *hostinfo = gethostbyname(argv[1]);
  if (hostinfo == NULL) {
    fprintf(stderr, "gethostbyname failed\n");
    return 1;
  }

  // Set up the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(POP3_PORT);
  memcpy(&servaddr.sin_addr, hostinfo->h_addr, hostinfo->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return 1;
  }

  // Send the USER command
  char buffer[1024];
  snprintf(buffer, sizeof(buffer), "USER %s\r\n", argv[2]);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the USER response
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  // Send the PASS command
  snprintf(buffer, sizeof(buffer), "PASS %s\r\n", argv[2]);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the PASS response
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  // Send the LIST command
  if (send(sockfd, "LIST\r\n", 6, 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the LIST response
  while (1) {
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
      perror("recv");
      return 1;
    }

    printf("%s", buffer);

    if (strcmp(buffer, ".\r\n") == 0) {
      break;
    }
  }

  // Send the QUIT command
  if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
    perror("send");
    return 1;
  }

  // Receive the QUIT response
  if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
    perror("recv");
    return 1;
  }

  printf("%s", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}