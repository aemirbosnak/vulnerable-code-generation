//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 8192
#define MAX_HOSTNAME_SIZE 256
#define MAX_PORT_SIZE 6
#define DEFAULT_PORT 80

int main(int argc, char **argv) {
  int listenfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t clilen;
  char request[MAX_REQUEST_SIZE], response[MAX_RESPONSE_SIZE];
  char hostname[MAX_HOSTNAME_SIZE], port[MAX_PORT_SIZE];
  int port_number;

  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  port_number = atoi(argv[1]);
  if (port_number <= 0 || port_number > 65535) {
    printf("Invalid port number: %s\n", argv[1]);
    return 1;
  }

  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    return 1;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(port_number);

  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(listenfd, SOMAXCONN) < 0) {
    perror("listen");
    return 1;
  }

  for (;;) {
    clilen = sizeof(cliaddr);
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
    if (connfd < 0) {
      perror("accept");
      continue;
    }

    if (recv(connfd, request, MAX_REQUEST_SIZE, 0) < 0) {
      perror("recv");
      close(connfd);
      continue;
    }

    if (sscanf(request, "GET %s %s", hostname, port) != 2) {
      printf("Invalid request: %s\n", request);
      close(connfd);
      continue;
    }

    if (strcmp(port, "HTTP/1.1") != 0) {
      printf("Invalid request: %s\n", request);
      close(connfd);
      continue;
    }

    int hostfd = socket(AF_INET, SOCK_STREAM, 0);
    if (hostfd < 0) {
      perror("socket");
      close(connfd);
      continue;
    }

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
      printf("Invalid hostname: %s\n", hostname);
      close(hostfd);
      close(connfd);
      continue;
    }

    struct sockaddr_in hostaddr;
    memset(&hostaddr, 0, sizeof(hostaddr));
    hostaddr.sin_family = AF_INET;
    hostaddr.sin_addr = *((struct in_addr *)host->h_addr);
    hostaddr.sin_port = htons(80);

    if (connect(hostfd, (struct sockaddr *)&hostaddr, sizeof(hostaddr)) < 0) {
      perror("connect");
      close(hostfd);
      close(connfd);
      continue;
    }

    if (send(hostfd, request, strlen(request), 0) < 0) {
      perror("send");
      close(hostfd);
      close(connfd);
      continue;
    }

    int bytes_received = 0;
    while ((bytes_received = recv(hostfd, response + bytes_received, MAX_RESPONSE_SIZE - bytes_received, 0)) > 0) {
      if (bytes_received < 0) {
        perror("recv");
        close(hostfd);
        close(connfd);
        continue;
      }
    }

    if (bytes_received == 0) {
      printf("Connection closed by host\n");
      close(hostfd);
      close(connfd);
      continue;
    }

    if (send(connfd, response, bytes_received, 0) < 0) {
      perror("send");
      close(hostfd);
      close(connfd);
      continue;
    }

    close(hostfd);
    close(connfd);
  }

  close(listenfd);

  return 0;
}