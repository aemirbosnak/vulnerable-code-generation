//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 2048

int main(int argc, char **argv) {
  if (argc != 4) {
    printf("Usage: %s pop3_server username password\n", argv[0]);
    exit(1);
  }

  const char *pop3_server = argv[1];
  const char *username = argv[2];
  const char *password = argv[3];

  struct hostent *host = gethostbyname(pop3_server);
  if (host == NULL) {
    printf("Error: could not resolve hostname\n");
    exit(1);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(110);
  server_addr.sin_addr = *((struct in_addr *)host->h_addr);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error: could not connect to POP3 server\n");
    exit(1);
  }

  char buffer[MAX_BUFFER_SIZE];
  ssize_t bytes_read;

  bytes_read = read(sockfd, buffer, MAX_BUFFER_SIZE);
  if (bytes_read < 0) {
    printf("Error: could not receive data from POP3 server\n");
    exit(1);
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Error: could not send data to POP3 server\n");
    exit(1);
  }
  bytes_read = read(sockfd, buffer, MAX_BUFFER_SIZE);
  if (bytes_read < 0) {
    printf("Error: could not receive data from POP3 server\n");
    exit(1);
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  snprintf(buffer, sizeof(buffer), "PASS %s\r\n", password);
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Error: could not send data to POP3 server\n");
    exit(1);
  }
  bytes_read = read(sockfd, buffer, MAX_BUFFER_SIZE);
  if (bytes_read < 0) {
    printf("Error: could not receive data from POP3 server\n");
    exit(1);
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  snprintf(buffer, sizeof(buffer), "STAT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Error: could not send data to POP3 server\n");
    exit(1);
  }
  bytes_read = read(sockfd, buffer, MAX_BUFFER_SIZE);
  if (bytes_read < 0) {
    printf("Error: could not receive data from POP3 server\n");
    exit(1);
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    printf("Error: could not send data to POP3 server\n");
    exit(1);
  }
  bytes_read = read(sockfd, buffer, MAX_BUFFER_SIZE);
  if (bytes_read < 0) {
    printf("Error: could not receive data from POP3 server\n");
    exit(1);
  }
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  close(sockfd);

  return 0;
}