//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {

  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[4096];
  char *content_length;
  char *response_body;
  char *response_header;
  
  if (argc < 3) {
    fprintf(stderr,"USAGE: %s hostname path\n", argv[0]);
    exit(0);
  }
  
  portno = 80;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }
  
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }
  
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);
  
  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  snprintf(buffer, sizeof(buffer), "GET %s HTTP/1.0\r\n\r\n", argv[2]);
  if (write(sockfd, buffer, strlen(buffer)) < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  response_header = malloc(4096);
  response_body   = malloc(4096);
  memset(response_header, 0, 4096);
  memset(response_body, 0, 4096);
  int header_len = 0;
  int body_len = 0;
  int header_done = 0;

  while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
    buffer[n] = '\0';

    if (!header_done) {
      char *header_end = strstr(buffer, "\r\n\r\n");

      if (header_end != NULL) {
        strncpy(response_header + header_len, buffer, header_end - buffer);
        header_len += header_end - buffer;
        header_done = 1;
        char *body_start = header_end + 4;
        int remaining = n - (body_start - buffer);
        strncpy(response_body, body_start, remaining);
        body_len += remaining;
      } else {
        strncpy(response_header + header_len, buffer, n);
        header_len += n;
      }

    } else {
      strncpy(response_body + body_len, buffer, n);
      body_len += n;
    }
  }

  content_length = strstr(response_header, "Content-Length: ");

  if (content_length != NULL) {
    int full_length = atoi(content_length + 16);

    while (body_len < full_length) {
      n = read(sockfd, response_body + body_len, full_length - body_len);

      if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
      }

      body_len += n;
    }
  }

  char *http_version = strstr(response_header, "HTTP/");

  if (http_version != NULL) {
    int status = atoi(http_version + 5);

    switch (status) {
      case 200:
        printf("HTTP 200 OK\n");
        break;
      case 400:
        printf("HTTP 400 Bad Request\n");
        break;
      case 403:
        printf("HTTP 403 Forbidden\n");
        break;
      case 404:
        printf("HTTP 404 Not Found\n");
        break;
      case 500:
        printf("HTTP 500 Internal Server Error\n");
        break;
      default:
        printf("Unknown HTTP status code %d\n", status);
        break;
    }
  }

  printf("Response:\n%s", response_body);

  free(response_header);
  free(response_body);

  close(sockfd);

  return 0;
}