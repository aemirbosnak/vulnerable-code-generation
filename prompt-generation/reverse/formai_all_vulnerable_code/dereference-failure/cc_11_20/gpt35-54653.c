//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {

  int sockfd, newsockfd, portno;
  struct hostent *server;
  struct sockaddr_in serv_addr, cli_addr;
  char buffer[BUFFER_SIZE];
  int n;

  // check for correct command line arguments
  if (argc < 4) {
    fprintf(stderr, "usage: %s port hostname path\n", argv[0]);
    exit(1);
  }

  // create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("error creating socket\n");
    exit(1);
  }

  // get the host by name
  server = gethostbyname(argv[2]);
  if (server == NULL) {
    fprintf(stderr,"error, no such host\n");
    exit(1);
  }

  // zero out the address structure
  bzero((char *) &serv_addr, sizeof(serv_addr));
  // set address family, port, and IP address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(atoi(argv[1]));
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

  // bind to the local address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("error on binding\n");
    exit(1);
  }

  // listen for incoming connections
  listen(sockfd, 5);
  socklen_t clilen = sizeof(cli_addr);

  // loop to handle requests
  while (1) {
    // accept incoming connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("error on accept\n");
      exit(1);
    }

    // zero out the buffer
    bzero(buffer, BUFFER_SIZE);

    // read the request from the client
    n = read(newsockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
      perror("error reading from socket\n");
      exit(1);
    }

    // extract the method, hostname, and path from the request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *http_ver = strtok(NULL, "\r\n");
    char *hostname;

    // check if request is valid
    if (method == NULL || path == NULL || http_ver == NULL) {
      fprintf(stderr, "error: invalid request\n");
      exit(1);
    }

    // check if method is GET
    if (strcmp(method, "GET") != 0) {
      fprintf(stderr, "error: only GET method is supported\n");
      exit(1);
    }

    // check if URL begins with http://
    if (strncmp(path, "http://", 7) == 0) {
      // extract hostname from URL
      hostname = strtok(path + 7, "/");
      // extract path from URL
      path = strtok(NULL, "\r\n");
    } else {
      // extract hostname from rest of request
      hostname = strtok(NULL, "/");
    }

    // get the host by name
    server = gethostbyname(hostname);
    if (server == NULL) {
      fprintf(stderr,"error, no such host\n");
      exit(1);
    }

    // zero out the address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    // set address family, port, and IP address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // create socket to connect to remote host
    int remote_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_sockfd < 0) {
      perror("error creating socket\n");
      exit(1);
    }

    // connect to remote host
    if (connect(remote_sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("error connecting to remote host\n");
      exit(1);
    }

    // send request to remote host
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "%s /%s %s\r\nHost: %s\r\n\r\n", method, path, http_ver, hostname);
    n = write(remote_sockfd, request, strlen(request));
    if (n < 0) {
      perror("error writing to socket\n");
      exit(1);
    }

    // read response from remote host
    bzero(buffer, BUFFER_SIZE);
    n = read(remote_sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
      perror("error reading from socket\n");
      exit(1);
    }

    // send response back to client
    n = write(newsockfd, buffer, strlen(buffer));
    if (n < 0) {
      perror("error writing to socket\n");
      exit(1);
    }

    close(remote_sockfd);
    close(newsockfd);
  }

  close(sockfd);
  return 0;
}