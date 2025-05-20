//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return 1;
  }

  char *url = argv[1];
  char *host = strtok(url, "/");
  char *path = strtok(NULL, "/");

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    return 1;
  }

  char request[BUF_SIZE];
  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

  if (send(sock, request, strlen(request), 0) == -1) {
    perror("send");
    return 1;
  }

  char buf[BUF_SIZE];
  int bytes_read = 0;
  while ((bytes_read = recv(sock, buf, BUF_SIZE, 0)) > 0) {
    printf("%.*s", bytes_read, buf);
  }

  close(sock);
  return 0;
}