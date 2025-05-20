//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
  
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int listenfd, connfd;
  struct sockaddr_in servaddr, cliaddr;
  char buf[BUFSIZE];
  int n;
  
  // Check if the correct number of arguments were provided.
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <destination_ip>\n", argv[0]);
    exit(1);
  }
  
  // Create a listening socket.
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if (listenfd < 0) {
    perror("socket");
    exit(1);
  }
  
  // Set up the listening socket address.
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));
  
  // Bind the listening socket to the address.
  if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(1);
  }
  
  // Listen for incoming connections.
  if (listen(listenfd, 10) < 0) {
    perror("listen");
    exit(1);
  }
  
  // Accept incoming connections.
  while (1) {
    // Accept a connection.
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, (socklen_t *)&n);
    if (connfd < 0) {
      perror("accept");
      continue;
    }
    
    // Read the HTTP request from the client.
    n = read(connfd, buf, BUFSIZE);
    if (n < 0) {
      perror("read");
      close(connfd);
      continue;
    }
    
    // Parse the HTTP request.
    char *method = strtok(buf, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\r\n");
    
    // Check if the HTTP request is valid.
    if (strcmp(method, "GET") != 0) {
      fprintf(stderr, "Invalid HTTP request: %s\n", buf);
      close(connfd);
      continue;
    }
    
    // Connect to the destination server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      perror("socket");
      close(connfd);
      continue;
    }
    
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr.s_addr = inet_addr(argv[2]);
    dest_addr.sin_port = htons(80);
    
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
      perror("connect");
      close(connfd);
      close(sockfd);
      continue;
    }
    
    // Forward the HTTP request to the destination server.
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
      perror("write");
      close(connfd);
      close(sockfd);
      continue;
    }
    
    // Read the HTTP response from the destination server.
    char resp[BUFSIZE];
    while ((n = read(sockfd, resp, BUFSIZE)) > 0) {
      // Write the HTTP response to the client.
      n = write(connfd, resp, n);
      if (n < 0) {
        perror("write");
        close(connfd);
        close(sockfd);
        break;
      }
    }
    
    // Close the connections.
    close(connfd);
    close(sockfd);
  }
  
  return 0;
}