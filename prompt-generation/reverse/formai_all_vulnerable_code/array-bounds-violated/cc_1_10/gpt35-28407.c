//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 80 // This is the default HTTP port

int main(int argc, char *argv[]) {

  char *hostname = "example.com"; // Change this to the website you want to connect to
  char *path = "/"; // Change this to the page you want to request
  struct hostent *hostinfo;
  struct sockaddr_in address;
  int sockfd, nbytes;
  char buffer[8192];

  // Step 1: Resolve the hostname to an IP address
  hostinfo = gethostbyname(hostname);
  if (hostinfo == NULL) {
    fprintf(stderr, "Unknown host %s.\n", hostname);
    exit(1);
  }

  // Step 2: Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error creating socket: %s.\n", strerror(errno));
    exit(1);
  }

  // Step 3: Connect to the server
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);
  memcpy(&address.sin_addr, hostinfo->h_addr, hostinfo->h_length);
  if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    fprintf(stderr, "Error connecting to server: %s.\n", strerror(errno));
    exit(1);
  }

  // Step 4: Send the HTTP request
  sprintf(buffer, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);
  nbytes = send(sockfd, buffer, strlen(buffer), 0);
  if (nbytes < 0) {
    fprintf(stderr, "Error sending request: %s.\n", strerror(errno));
    exit(1);
  }

  // Step 5: Receive the server's response
  while ((nbytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
    buffer[nbytes] = '\0';
    printf("%s", buffer);
  }

  // Step 6: Close the socket
  close(sockfd);

  return 0;
}