//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  // Initialize variables
  int sockfd, port = 110;
  char *host = "mail.example.com";
  char username[256], password[256];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Resolve the host
  struct hostent *hostent = gethostbyname(host);
  if (hostent == NULL) {
    perror("gethostbyname");
    return 1;
  }

  // Create a socket address
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  memcpy(&serv_addr.sin_addr.s_addr, hostent->h_addr_list[0], hostent->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Receive the welcome message
  char buf[1024];
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  // Send the user command
  memset(buf, 0, sizeof(buf));
  strcpy(buf, "USER ");
  strcat(buf, username);
  strcat(buf, "\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  // Send the pass command
  memset(buf, 0, sizeof(buf));
  strcpy(buf, "PASS ");
  strcat(buf, password);
  strcat(buf, "\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  // Send the list command
  memset(buf, 0, sizeof(buf));
  strcpy(buf, "LIST\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  memset(buf, 0, sizeof(buf));
  while (recv(sockfd, buf, sizeof(buf), 0) > 0) {
    printf("%s\n", buf);
  }
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  // Send the quit command
  memset(buf, 0, sizeof(buf));
  strcpy(buf, "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }

  // Receive the response
  memset(buf, 0, sizeof(buf));
  if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  // Close the socket
  close(sockfd);

  return 0;
}