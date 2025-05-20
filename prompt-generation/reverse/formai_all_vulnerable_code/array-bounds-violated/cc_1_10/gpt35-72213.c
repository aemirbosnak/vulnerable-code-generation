//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

#define IMAP_PORT "143" // IMAP default port
#define BUFFER_SIZE 1024 // buffer size for reading server messages

int main(int argc, char *argv[]) {
  int sockfd, status, bytes_received;
  char buffer[BUFFER_SIZE];
  struct addrinfo hints, *res;
  
  // check command line arguments
  if (argc != 4) {
    fprintf(stderr, "Usage: imapclient <server> <username> <password>\n");
    exit(1);
  }
  
  // set up hints for getaddrinfo function
  memset(&hints, 0, sizeof(hints)); // zero out struct
  hints.ai_family = AF_UNSPEC; // allow IPv4 or IPv6
  hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
  
  // get server address information
  if ((status = getaddrinfo(argv[1], IMAP_PORT, &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
    exit(2);
  }
  
  // create a socket to connect to the server
  if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
    perror("socket error");
    exit(3);
  }
  
  // connect to the server
  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    perror("connect error");
    exit(4);
  }
  
  // receive server greeting message
  if ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) == -1) {
    perror("recv error");
    exit(5);
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);
  
  // send login command to the server
  snprintf(buffer, BUFFER_SIZE, "LOGIN %s %s\r\n", argv[2], argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send error");
    exit(6);
  }
  
  // receive server response to login command
  if ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) == -1) {
    perror("recv error");
    exit(7);
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);
  
  // send logout command to the server
  snprintf(buffer, BUFFER_SIZE, "LOGOUT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("send error");
    exit(8);
  }
  
  // receive server response to logout command
  if ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) == -1) {
    perror("recv error");
    exit(9);
  }
  buffer[bytes_received] = '\0';
  printf("%s", buffer);
  
  // close the socket
  close(sockfd);
  
  return 0;
}