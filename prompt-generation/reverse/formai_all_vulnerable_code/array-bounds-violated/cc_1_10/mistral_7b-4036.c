//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <URL>\n", argv[0]);
    return 1;
  }

  char url[256];
  strcpy(url, argv[1]);

  int port = 80;
  char host[256];
  sscanf(url, "http://%255s:%d%*s", host, &port);

  int sockfd;
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  inet_pton(AF_INET, host, &server_addr.sin_addr);

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    close(sockfd);
    return 1;
  }

  char request[BUFFER_SIZE];
  snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: Turing's-Client/1.0\r\nAccept: */*\r\n\r\n", url, host);

  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    close(sockfd);
    return 1;
  }

  char response[BUFFER_SIZE];
  int bytes_received;
  while ((bytes_received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
    response[bytes_received] = '\0';
    printf("%s", response);
    memset(response, 0, BUFFER_SIZE);
  }

  if (bytes_received < 0) {
    perror("recv");
  } else if (bytes_received == 0) {
    printf("Connection closed by server.\n");
  }

  close(sockfd);
  return 0;
}