//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
// A cheerful POP3 client in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MSG_LEN 1024

int main() {
  // Create socket
  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set up socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Create server address structure
  struct sockaddr_in serveraddr;
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = inet_addr("localhost");
  serveraddr.sin_port = htons(110);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send username
  char username[] = "testuser";
  send(sockfd, username, strlen(username), 0);

  // Receive server response
  char response[MAX_MSG_LEN];
  int n = recv(sockfd, response, MAX_MSG_LEN, 0);
  if (n < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print server response
  printf("Server response: %s\n", response);

  // Send password
  char password[] = "testpassword";
  send(sockfd, password, strlen(password), 0);

  // Receive server response
  n = recv(sockfd, response, MAX_MSG_LEN, 0);
  if (n < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print server response
  printf("Server response: %s\n", response);

  // Send command to list messages
  char cmd[] = "LIST";
  send(sockfd, cmd, strlen(cmd), 0);

  // Receive server response
  n = recv(sockfd, response, MAX_MSG_LEN, 0);
  if (n < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Print server response
  printf("Server response: %s\n", response);

  // Receive messages
  int num_messages;
  if (sscanf(response, "%d", &num_messages)!= 1) {
    perror("sscanf");
    exit(EXIT_FAILURE);
  }
  for (int i = 0; i < num_messages; i++) {
    char msg[MAX_MSG_LEN];
    if (recv(sockfd, msg, MAX_MSG_LEN, 0) < 0) {
      perror("recv");
      exit(EXIT_FAILURE);
    }
    printf("Message %d: %s\n", i+1, msg);
  }

  // Disconnect from server
  if (close(sockfd) < 0) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  return 0;
}