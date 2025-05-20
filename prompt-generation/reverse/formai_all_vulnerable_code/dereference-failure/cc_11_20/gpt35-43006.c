//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  const char *host = argv[1];
  int port = atoi(argv[2]);

  // Create socket
  int sockfd;
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Receive welcome message
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Send username
  char username[BUFFER_SIZE], response[BUFFER_SIZE];
  printf("username: ");
  fgets(username, BUFFER_SIZE, stdin);
  username[strcspn(username, "\n")] = '\0';
  send(sockfd, username, strlen(username), 0);
  
  // Receive password prompt
  memset(buffer, 0, BUFFER_SIZE);
  memset(response, 0, BUFFER_SIZE);
  if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Send password
  char password[BUFFER_SIZE];
  printf("password: ");
  fgets(password, BUFFER_SIZE, stdin);
  password[strcspn(password, "\n")] = '\0';
  send(sockfd, password, strlen(password), 0);

  // Receive authentication response
  memset(buffer, 0, BUFFER_SIZE);
  memset(response, 0, BUFFER_SIZE);
  if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Main loop
  while (1) {
    printf("> ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    // Send command
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    memset(response, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
      perror("recv");
      exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Exit loop if command is "quit"
    if (strncmp(buffer, "221", 3) == 0) {
      break;
    }
  }

  close(sockfd);
  return 0;
}