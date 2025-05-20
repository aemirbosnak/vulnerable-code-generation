//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Resolve the hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Set up the server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Send the USER command
  char user_cmd[MAX_LINE];
  sprintf(user_cmd, "USER %s\r\n", "username");
  if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server response
  char server_resp[MAX_LINE];
  if (recv(sockfd, server_resp, MAX_LINE, 0) == -1) {
    perror("recv");
    exit(1);
  }

  // Print the server response
  printf("%s", server_resp);

  // Send the PASS command
  char pass_cmd[MAX_LINE];
  sprintf(pass_cmd, "PASS %s\r\n", "password");
  if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server response
  if (recv(sockfd, server_resp, MAX_LINE, 0) == -1) {
    perror("recv");
    exit(1);
  }

  // Print the server response
  printf("%s", server_resp);

  // Send the LIST command
  char list_cmd[MAX_LINE];
  strcpy(list_cmd, "LIST\r\n");
  if (send(sockfd, list_cmd, strlen(list_cmd), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the server response
  if (recv(sockfd, server_resp, MAX_LINE, 0) == -1) {
    perror("recv");
    exit(1);
  }

  // Print the server response
  printf("%s", server_resp);

  // Send the QUIT command
  char quit_cmd[MAX_LINE];
  strcpy(quit_cmd, "QUIT\r\n");
  if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Close the socket
  close(sockfd);

  return 0;
}