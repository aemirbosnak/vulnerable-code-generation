//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

// A simple HTTP client that can send GET requests to a specified URL

int main(int argc, char **argv) {

  if (argc < 2) {
    fprintf(stderr, "Usage: %s URL\n", argv[0]);
    return 1;
  }

  char *host, *path;
  // Parse the URL into host and path components
  {
    char *colon = strchr(argv[1], ':');
    char *slash = strchr(argv[1], '/');
    if (colon == NULL || slash == NULL || colon > slash) {
      fprintf(stderr, "Invalid URL: %s\n", argv[1]);
      return 1;
    }
    *colon = '\0';
    host = argv[1];
    path = slash;
  }

  // Resolve the host to an IP address
  struct hostent *he = gethostbyname(host);
  if (he == NULL) {
    herror("gethostbyname");
    return 1;
  }
  struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
  char *ip = inet_ntoa(*addr_list[0]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  // Connect to the server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(80);
  serv_addr.sin_addr.s_addr = inet_addr(ip);
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
    perror("connect");
    close(sockfd);
    return 1;
  }

  // Send the HTTP request
  char request[1024];
  snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    close(sockfd);
    return 1;
  }

  // Receive the HTTP response
  char response[4096];
  int n;
  while ((n = recv(sockfd, response, sizeof(response), 0)) > 0) {
    fwrite(response, 1, n, stdout);
  }
  if (n == -1) {
    perror("recv");
    close(sockfd);
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}