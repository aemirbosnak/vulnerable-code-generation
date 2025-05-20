//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define PORT 80

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    return 1;
  }

  char *url = argv[1];
  char host[MAX_LINE];
  char path[MAX_LINE];

  if (parse_url(url, host, path) < 0) {
    fprintf(stderr, "Invalid URL: %s\n", url);
    return 1;
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);

  if (inet_pton(AF_INET, host, &server.sin_addr) <= 0) {
    fprintf(stderr, "Invalid host: %s\n", host);
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect");
    return 1;
  }

  char request[MAX_LINE];
  sprintf(request, "GET %s HTTP/1.1\r\n", path);
  sprintf(request, "%sHost: %s\r\n", request, host);
  sprintf(request, "%sUser-Agent: My HTTP Client\r\n", request);
  sprintf(request, "%sConnection: close\r\n", request);
  sprintf(request, "%s\r\n", request);

  if (send(sock, request, strlen(request), 0) < 0) {
    perror("send");
    return 1;
  }

  char buffer[MAX_LINE];
  while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
    printf("%s", buffer);
  }

  close(sock);
  return 0;
}

int parse_url(char *url, char *host, char *path) {
  char *host_start = strstr(url, "://");
  if (!host_start) {
    return -1;
  }
  host_start += 3;

  char *host_end = strchr(host_start, '/');
  if (!host_end) {
    return -1;
  }

  strncpy(host, host_start, host_end - host_start);
  host[host_end - host_start] = '\0';

  strcpy(path, host_end);

  return 0;
}