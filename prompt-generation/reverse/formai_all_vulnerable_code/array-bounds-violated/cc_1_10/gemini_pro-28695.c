//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 143

int main() {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Set up the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(IMAP_PORT);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the IMAP command
  char *cmd = "CAPABILITIES\r\n";
  if (send(sockfd, cmd, strlen(cmd), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the response from the server
  char buf[1024];
  int n;
  while ((n = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
    // Process the response
    buf[n] = '\0';
    printf("%s", buf);
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}