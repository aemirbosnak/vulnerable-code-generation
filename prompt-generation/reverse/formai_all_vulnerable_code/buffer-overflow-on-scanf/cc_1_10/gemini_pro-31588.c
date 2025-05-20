//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
  int sockfd;
  struct sockaddr_in servaddr;
  char buffer[MAXLINE];

  // Creating a TCP socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Filling server information
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connecting to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connection failed");
    exit(EXIT_FAILURE);
  }

  // Keeping communication with the server
  while (1) {
    // Reading data from standard input (the user)
    printf("Enter a message: ");
    scanf("%s", buffer);

    // Sending data to the server
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      perror("send failed");
      exit(EXIT_FAILURE);
    }

    // Reading the response from the server
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      perror("recv failed");
      exit(EXIT_FAILURE);
    }

    // Printing the response to standard output
    printf("Message from server: %s\n", buffer);
  }

  // Closing the socket
  close(sockfd);

  return 0;
}