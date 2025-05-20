//Code Llama-13B DATASET v1.0 Category: Smart home light control ; Style: portable
// smart_home_light_control.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  char buffer[BUF_SIZE];
  struct sockaddr_in server_addr;
  struct hostent *server;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Get the address of the server
  server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  // Set up the server address
  memset((char *) &server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  memcpy((char *) &server_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send the request
  n = write(sockfd, "GET /light/on HTTP/1.1\r\n\r\n", strlen("GET /light/on HTTP/1.1\r\n\r\n"));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Read the response
  n = read(sockfd, buffer, BUF_SIZE - 1);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Close the socket
  close(sockfd);

  // Print the response
  buffer[n] = '\0';
  printf("%s\n", buffer);

  return 0;
}