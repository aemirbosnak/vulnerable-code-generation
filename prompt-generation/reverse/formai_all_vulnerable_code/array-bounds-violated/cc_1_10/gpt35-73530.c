//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_RESPONSE_SIZE 1024
#define HTTP_PORT 80

void error(char *message) {
  perror(message);
  exit(EXIT_FAILURE);
}

char *sanitize_url(char *url) {
  char *new_url = malloc(strlen(url) + 1);
  char *p1 = url;
  char *p2 = new_url;

  while(*p1 != '\0') {
    if(isalnum(*p1) || *p1 == '/' || *p1 == ':')
      *p2++ = *p1;
    else if(*p1 == ' ')
      *p2++ = '+';
    else {
      *p2++ = '%';
      *p2++ = "0123456789ABCDEF"[(*p1 >> 4) & 0xF];
      *p2++ = "0123456789ABCDEF"[*p1 & 0xF];
    }
    p1++;
  }
  *p2 = '\0';
  return new_url;
}

char *parse_host(char *url) {
  size_t header_size = strlen("http://");
  char *p = strstr(url, "http://");

  if(p) {
    char *host = malloc(strlen(p + header_size) + 1);
    strcpy(host, p + header_size);
    char *slash = strchr(host, '/');
    if(slash)
      *slash = '\0';

    return host;
  }
  return NULL;
}

char *parse_request(char *url) {
  char *request = malloc(strlen(url) + 1);
  char *p = strchr(url, '/');

  if(p) {
    size_t request_size = strlen(p);
    memcpy(request, p, request_size);
    request[request_size] = '\0';
  } else {
    *request = '/';
    request[1] = '\0';
  }
  return request;
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    fprintf(stderr, "usage: %s url\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *url = argv[1];
  char *host = NULL;
  char *request = NULL;

  host = parse_host(url);
  request = parse_request(url);

  char *sanitized_url = sanitize_url(url);
  free(url);

  struct sockaddr_in server_address = {
    .sin_family = AF_INET,
    .sin_port = htons(HTTP_PORT),
    .sin_addr.s_addr = inet_addr(host),
  };
  free(host);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0)
    error("ERROR opening socket");

  if(connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0)
    error("ERROR connecting");

  char *http_request = malloc(MAX_RESPONSE_SIZE);
  snprintf(http_request, MAX_RESPONSE_SIZE,
    "GET %s HTTP/1.1\r\n"
    "Host: %s\r\n"
    "Connection: close\r\n"
    "\r\n", request, sanitized_url);
  free(request);
  free(sanitized_url);

  if(send(sockfd, http_request, strlen(http_request), 0) < 0)
    error("ERROR sending request");
  free(http_request);

  char response[MAX_RESPONSE_SIZE];
  ssize_t bytes_received = recv(sockfd, response, MAX_RESPONSE_SIZE, 0);

  if(bytes_received < 0)
    error("ERROR receiving response");

  response[bytes_received] = '\0';

  close(sockfd);

  return 0;
}