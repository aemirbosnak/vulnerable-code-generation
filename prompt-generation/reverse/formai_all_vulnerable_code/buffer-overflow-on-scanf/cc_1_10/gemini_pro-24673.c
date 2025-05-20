//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";

  // Get the port number from the user
  printf("Enter the port number: ");
  scanf("%d", &portno);

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Get the server address
  server = gethostbyname("example.com");
  if (server == NULL) {
    perror("ERROR, no such host");
    exit(1);
  }

  // Fill in the server address structure
  memset((char *) &serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send the request
  if (write(sockfd, request, strlen(request)) < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Read the response
  memset(buffer, 0, sizeof(buffer));
  if (read(sockfd, buffer, sizeof(buffer)) < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Print the response
  printf("%s", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}