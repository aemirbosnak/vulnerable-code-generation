#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

int main() {
  int sockfd, port, err, msg_num, msg_size;
  char hostname[256], username[256], password[256], buffer[4096];

  // Connect to POP3 server
  sockfd = socket(AF_INET, SOCK_STREAM, htons(101));
  if (sockfd < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Authenticate user
  sprintf(buffer, "USER %s", username);
  send(sockfd, buffer, strlen(buffer), 0);
  err = recv(sockfd, buffer, 4096, 0);
  if (err < 0) {
    perror("Error authenticating");
    close(sockfd);
    exit(1);
  }

  // Get number of messages
  sprintf(buffer, "STAT");
  send(sockfd, buffer, strlen(buffer), 0);
  err = recv(sockfd, buffer, 4096, 0);
  if (err < 0) {
    perror("Error retrieving number of messages");
    close(sockfd);
    exit(1);
  }

  // Get message sizes
  sprintf(buffer, "LIST");
  send(sockfd, buffer, strlen(buffer), 0);
  err = recv(sockfd, buffer, 4096, 0);
  if (err < 0) {
    perror("Error retrieving message sizes");
    close(sockfd);
    exit(1);
  }

  // Quit
  sprintf(buffer, "QUIT");
  send(sockfd, buffer, strlen(buffer), 0);
  close(sockfd);

  return 0;
}
