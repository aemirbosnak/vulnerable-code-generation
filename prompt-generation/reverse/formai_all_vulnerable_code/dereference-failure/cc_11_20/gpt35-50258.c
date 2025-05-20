//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char ** argv) {
  char * server = "mail.example.com";
  char * user = "user@example.com";
  char * password = "password123";

  struct sockaddr_in serv_addr;
  struct hostent * server_info;

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  server_info = gethostbyname(server);
  if (server_info == NULL) {
    perror("Error finding host");
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = ((struct in_addr *)(server_info->h_addr))->s_addr;
  serv_addr.sin_port = htons(110);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  char buffer[BUFFER_SIZE];
  int n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("Error receiving data");
    exit(1);
  }
  buffer[n] = 0;

  printf("Server response: %s", buffer);

  sprintf(buffer, "USER %s\r\n", user);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error sending data");
    exit(1);
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("Error receiving data");
    exit(1);
  }
  buffer[n] = 0;

  printf("Server response: %s", buffer);

  sprintf(buffer, "PASS %s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error sending data");
    exit(1);
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("Error receiving data");
    exit(1);
  }
  buffer[n] = 0;

  printf("Server response: %s", buffer);

  sprintf(buffer, "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Error sending data");
    exit(1);
  }

  n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (n < 0) {
    perror("Error receiving data");
    exit(1);
  }
  buffer[n] = 0;

  printf("Server response: %s", buffer);

  close(sockfd);

  return 0;
}