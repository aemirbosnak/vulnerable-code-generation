//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: distributed
// EmailClient.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 25

int main(int argc, char *argv[]) {
  int sockfd, n;
  char recvBuf[BUFFER_SIZE];
  struct sockaddr_in serverAddr;
  struct hostent *server;

  // Check command-line arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <server>\n", argv[0]);
    exit(1);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Resolve the server address
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error resolving server address\n");
    exit(1);
  }

  // Set up the server address
  bzero((char *) &serverAddr, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
        (char *)&serverAddr.sin_addr.s_addr,
        server->h_length);
  serverAddr.sin_port = htons(PORT);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send the message
  send(sockfd, "Hello, world!", 13, 0);

  // Receive the message
  n = recv(sockfd, recvBuf, BUFFER_SIZE, 0);
  if (n < 0) {
    perror("Error receiving message");
    exit(1);
  }

  // Print the received message
  printf("Received: %s\n", recvBuf);

  // Close the socket
  close(sockfd);

  return 0;
}