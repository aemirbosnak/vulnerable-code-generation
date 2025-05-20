//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define MAX_CLIENTS 10

int main(int argc, char **argv) {
  int listenfd, connfd, clientfd;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t clilen;
  char buf[BUFSIZE];
  int n;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  // Create a listening socket
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    exit(1);
  }

  // Set up the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));

  // Bind the socket to the server address
  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Listen for connections
  if (listen(listenfd, MAX_CLIENTS) < 0) {
    perror("listen");
    exit(1);
  }

  // Accept connections
  while (1) {
    clilen = sizeof(cliaddr);
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
    if (connfd < 0) {
      perror("accept");
      continue;
    }

    // Read the request from the client
    n = read(connfd, buf, BUFSIZE);
    if (n < 0) {
      perror("read");
      close(connfd);
      continue;
    }

    // Parse the request
    char *method = strtok(buf, " ");
    char *uri = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");

    // Check the request is valid
    if (strcmp(method, "GET") != 0 || strcmp(version, "HTTP/1.1") != 0) {
      fprintf(connfd, "HTTP/1.1 400 Bad Request\r\n\r\n");
      close(connfd);
      continue;
    }

    // Get the hostname from the URI
    char *hostname = strstr(uri, "://");
    if (hostname == NULL) {
      fprintf(connfd, "HTTP/1.1 400 Bad Request\r\n\r\n");
      close(connfd);
      continue;
    }
    hostname += 3;

    // Get the port number from the hostname
    char *port = strstr(hostname, ":");
    if (port == NULL) {
      port = "80";
    } else {
      *port = '\0';
      port++;
    }

    // Get the path from the URI
    char *path = strstr(hostname, "/");
    if (path == NULL) {
      path = "/";
    }

    // Create a socket to the destination server
    clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd < 0) {
      perror("socket");
      close(connfd);
      continue;
    }

    // Set up the destination server address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
      fprintf(connfd, "HTTP/1.1 404 Not Found\r\n\r\n");
      close(connfd);
      close(clientfd);
      continue;
    }
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr = *((struct in_addr *)host->h_addr);
    dest_addr.sin_port = htons(atoi(port));

    // Connect to the destination server
    if (connect(clientfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
      perror("connect");
      close(connfd);
      close(clientfd);
      continue;
    }

    // Send the request to the destination server
    write(clientfd, buf, n);

    // Read the response from the destination server
    while ((n = read(clientfd, buf, BUFSIZE)) > 0) {
      write(connfd, buf, n);
    }

    // Close the connections
    close(connfd);
    close(clientfd);
  }

  return 0;
}