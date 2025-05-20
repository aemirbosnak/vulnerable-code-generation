//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 8192

int main(int argc, char* argv[]) {
  int port = 8080;

  // create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Name the socket
  struct sockaddr_in my_addr;
  bzero((char *) &my_addr, sizeof(my_addr));
  my_addr.sin_family = AF_INET;
  my_addr.sin_addr.s_addr = INADDR_ANY;
  my_addr.sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *) &my_addr, sizeof(my_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen on the socket
  if (listen(sockfd, 10) < 0) {
    perror("Error listening on socket");
    exit(1);
  }

  int newsockfd;
  struct sockaddr_in their_addr;
  socklen_t sin_size = sizeof(their_addr);

  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &their_addr, &sin_size);
    if (newsockfd < 0) {
      perror("Error accepting incoming connection");
      continue;
    }

    FILE* fp = fdopen(newsockfd, "r+");
    if (fp == NULL) {
      perror("Error opening socket as file");
      exit(1);
    }

    char buf[BUF_SIZE];
    char method[BUF_SIZE], url[BUF_SIZE], protocol[BUF_SIZE];
    if (fscanf(fp, "%s %s %s", method, url, protocol) != 3) {
      fprintf(fp, "HTTP/1.0 400 Bad Request\r\n");
      fclose(fp);
      continue;
    }

    if (strcasecmp(method, "GET")) {
      fprintf(fp, "HTTP/1.0 501 Not Implemented\r\n");
      fclose(fp);
      continue;
    }

    char* host = strstr(url, "http://");
    if (host == NULL)
      host = url;
    else
      host += 7;

    char* path = strchr(host, '/');
    if (path == NULL)
      path = "/";
    else
      *path++ = '\0';

    struct hostent* he = gethostbyname(host);
    if (he == NULL) {
      fprintf(fp, "HTTP/1.0 404 Not Found\r\n");
      fclose(fp);
      continue;
    }

    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr*)he->h_addr);

    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0) {
      perror("Error creating server socket");
      fclose(fp);
      continue;
    }

    if (connect(serverfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
      perror("Error connecting to server");
      fclose(fp);
      continue;
    }

    fprintf(fp, "HTTP/1.0 200 OK\r\n");

    char req[BUF_SIZE];
    sprintf(req, "GET /%s %s\r\nHost: %s\r\n\r\n", path, protocol, host);
    write(serverfd, req, strlen(req));

    int n;
    while ((n = read(serverfd, buf, BUF_SIZE)) > 0)
      write(fileno(fp), buf, n);

    fclose(fp);
    close(serverfd);
  }

  close(sockfd);
  return 0;
}