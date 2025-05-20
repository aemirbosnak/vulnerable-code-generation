//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[1]);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return 1;
  }

  if (listen(sockfd, 5) < 0) {
    perror("listen");
    return 1;
  }

  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
  if (client_fd < 0) {
    perror("accept");
    return 1;
  }

  char buf[BUFSIZE];
  int n = read(client_fd, buf, BUFSIZE);
  if (n < 0) {
    perror("read");
    return 1;
  }

  buf[n] = '\0';
  printf("Request: %s\n", buf);

  char *http_headers = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
  n = write(client_fd, http_headers, strlen(http_headers));
  if (n < 0) {
    perror("write");
    return 1;
  }

  char *html = "<html><body>Hello, world!</body></html>";
  n = write(client_fd, html, strlen(html));
  if (n < 0) {
    perror("write");
    return 1;
  }

  close(client_fd);
  close(sockfd);

  return 0;
}