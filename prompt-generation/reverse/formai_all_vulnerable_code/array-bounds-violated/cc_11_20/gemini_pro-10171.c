//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  int sockfd, port;
  struct sockaddr_in server_addr;
  char recvbuf[BUFSIZE], sendbuf[BUFSIZE];
  char *host, *username, *password;
  int bytes_recv, bytes_sent;

  if (argc != 5) {
    fprintf(stderr, "Usage: %s <host> <port> <username> <password>\n", argv[0]);
    exit(1);
  }

  host = argv[1];
  port = atoi(argv[2]);
  username = argv[3];
  password = argv[4];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Set up the server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Receive the welcome message
  bytes_recv = recv(sockfd, recvbuf, BUFSIZE, 0);
  if (bytes_recv == -1) {
    perror("recv");
    exit(1);
  }
  recvbuf[bytes_recv] = '\0';
  printf("Received welcome message: %s", recvbuf);

  // Send the USER command
  sprintf(sendbuf, "USER %s\r\n", username);
  bytes_sent = send(sockfd, sendbuf, strlen(sendbuf), 0);
  if (bytes_sent == -1) {
    perror("send");
    exit(1);
  }

  // Receive the USER response
  bytes_recv = recv(sockfd, recvbuf, BUFSIZE, 0);
  if (bytes_recv == -1) {
    perror("recv");
    exit(1);
  }
  recvbuf[bytes_recv] = '\0';
  printf("Received USER response: %s", recvbuf);

  // Send the PASS command
  sprintf(sendbuf, "PASS %s\r\n", password);
  bytes_sent = send(sockfd, sendbuf, strlen(sendbuf), 0);
  if (bytes_sent == -1) {
    perror("send");
    exit(1);
  }

  // Receive the PASS response
  bytes_recv = recv(sockfd, recvbuf, BUFSIZE, 0);
  if (bytes_recv == -1) {
    perror("recv");
    exit(1);
  }
  recvbuf[bytes_recv] = '\0';
  printf("Received PASS response: %s", recvbuf);

  // Send the LIST command
  sprintf(sendbuf, "LIST\r\n");
  bytes_sent = send(sockfd, sendbuf, strlen(sendbuf), 0);
  if (bytes_sent == -1) {
    perror("send");
    exit(1);
  }

  // Receive the LIST response
  bytes_recv = recv(sockfd, recvbuf, BUFSIZE, 0);
  if (bytes_recv == -1) {
    perror("recv");
    exit(1);
  }
  recvbuf[bytes_recv] = '\0';
  printf("Received LIST response: %s", recvbuf);

  // Send the RETR command
  sprintf(sendbuf, "RETR 1\r\n");
  bytes_sent = send(sockfd, sendbuf, strlen(sendbuf), 0);
  if (bytes_sent == -1) {
    perror("send");
    exit(1);
  }

  // Receive the RETR response
  bytes_recv = recv(sockfd, recvbuf, BUFSIZE, 0);
  if (bytes_recv == -1) {
    perror("recv");
    exit(1);
  }
  recvbuf[bytes_recv] = '\0';
  printf("Received RETR response: %s", recvbuf);

  // Send the QUIT command
  sprintf(sendbuf, "QUIT\r\n");
  bytes_sent = send(sockfd, sendbuf, strlen(sendbuf), 0);
  if (bytes_sent == -1) {
    perror("send");
    exit(1);
  }

  // Close the socket
  close(sockfd);

  return 0;
}