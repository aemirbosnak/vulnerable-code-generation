//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define SERVER_NAME "localhost"
#define SERVER_PORT 8080

int main()
{
  struct sockaddr_in server_addr;
  int sockfd, result;
  char buf[1024];
  time_t tStart, tEnd;

  // Socket setup
  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (sockfd < 0)
  {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to server
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);
  result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (result < 0)
  {
    perror("Error connecting to server");
    exit(1);
  }

  // Measure time
  tStart = time(NULL);

  // Send and receive data
  send(sockfd, "Hello, world!", 13, 0);
  recv(sockfd, buf, 1024, 0);

  // Measure time
  tEnd = time(NULL);

  // Calculate time taken
  int timeTaken = (int) (tEnd - tStart);

  // Print results
  printf("Time taken to receive response: %d seconds\n", timeTaken);

  // Close socket
  close(sockfd);

  return 0;
}