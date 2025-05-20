//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }

  struct sockaddr_in server_addr;
  struct hostent *server_hostent;
  int sockfd;
  char recvbuf[1024];
  char sendbuf[1024];

  // Get the server's address and port
  server_hostent = gethostbyname(argv[1]);
  if (server_hostent == NULL) {
    printf("Error: Could not resolve hostname %s\n", argv[1]);
    return 1;
  }
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  server_addr.sin_addr = *(struct in_addr *)server_hostent->h_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: Could not create socket");
    return 1;
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error: Could not connect to server");
    return 1;
  }

  // Send the POP3 USER command
  sprintf(sendbuf, "USER your_username\r\n");
  if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
    perror("Error: Could not send USER command");
    return 1;
  }
  if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) < 0) {
    perror("Error: Could not receive response to USER command");
    return 1;
  }
  printf("%s", recvbuf);

  // Send the POP3 PASS command
  sprintf(sendbuf, "PASS your_password\r\n");
  if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
    perror("Error: Could not send PASS command");
    return 1;
  }
  if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) < 0) {
    perror("Error: Could not receive response to PASS command");
    return 1;
  }
  printf("%s", recvbuf);

  // Send the POP3 STAT command
  sprintf(sendbuf, "STAT\r\n");
  if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
    perror("Error: Could not send STAT command");
    return 1;
  }
  if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) < 0) {
    perror("Error: Could not receive response to STAT command");
    return 1;
  }
  printf("%s", recvbuf);

  // Send the POP3 LIST command
  sprintf(sendbuf, "LIST\r\n");
  if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
    perror("Error: Could not send LIST command");
    return 1;
  }
  if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) < 0) {
    perror("Error: Could not receive response to LIST command");
    return 1;
  }
  printf("%s", recvbuf);

  // Send the POP3 RETR command
  sprintf(sendbuf, "RETR 1\r\n");
  if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
    perror("Error: Could not send RETR command");
    return 1;
  }
  if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) < 0) {
    perror("Error: Could not receive response to RETR command");
    return 1;
  }
  printf("%s", recvbuf);

  // Send the POP3 DELE command
  sprintf(sendbuf, "DELE 1\r\n");
  if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
    perror("Error: Could not send DELE command");
    return 1;
  }
  if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) < 0) {
    perror("Error: Could not receive response to DELE command");
    return 1;
  }
  printf("%s", recvbuf);

  // Send the POP3 QUIT command
  sprintf(sendbuf, "QUIT\r\n");
  if (send(sockfd, sendbuf, strlen(sendbuf), 0) < 0) {
    perror("Error: Could not send QUIT command");
    return 1;
  }
  if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) < 0) {
    perror("Error: Could not receive response to QUIT command");
    return 1;
  }
  printf("%s", recvbuf);

  // Close the socket
  close(sockfd);

  return 0;
}