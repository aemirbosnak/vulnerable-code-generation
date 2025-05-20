//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>

int main() {
  int sockfd, port, n, clientlen;
  struct sockaddr_in servaddr, clientaddr;
  char buffer[1024];
  time_t tStart, tEnd, tElapsed;

  // Define port number
  port = 8080;

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

  // Bind socket to port
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  // Listen for client connection
  clientlen = sizeof(clientaddr);
  n = accept(sockfd, (struct sockaddr *)&clientaddr, &clientlen);

  // Start timer
  tStart = time(NULL);

  // Receive data
  n = read(n, buffer, 1024);

  // Send data
  write(n, buffer, n);

  // End timer
  tEnd = time(NULL);

  // Calculate elapsed time
  tElapsed = tEnd - tStart;

  // Print elapsed time
  printf("Elapsed time: %ld seconds\n", tElapsed);

  // Close connection
  close(sockfd);

  return 0;
}