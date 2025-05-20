//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void die(const char* msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char** argv) {
  if (argc!= 4) {
    printf("usage: %s host port file\n", argv[0]);
    return 1;
  }

  char* host = argv[1];
  char* port = argv[2];
  char* file = argv[3];

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) die("socket");

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(port));

  if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) die("inet_pton");

  if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) die("connect");

  char request[100];
  sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", file, host);

  if (send(sock, request, strlen(request), 0) == -1) die("send");

  char buffer[BUFFER_SIZE];
  int bytes_read = 0;

  while ((bytes_read = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
    buffer[bytes_read] = '\0';
    printf("%s", buffer);
  }

  close(sock);
  return 0;
}