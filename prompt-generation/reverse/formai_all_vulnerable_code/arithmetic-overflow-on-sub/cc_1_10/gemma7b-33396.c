//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define PORT 8080
#define SERVER "localhost"

int main() {
  int sockfd, newsockfd, clientlen;
  struct sockaddr_in server_addr, client_addr;
  time_t start_time, end_time;
  char buf[1024];

  // Socket setup
  sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind server to port
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Wait for client connection
  clientlen = sizeof(client_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
  if (newsockfd < 0) {
    perror("Error accepting client connection");
    exit(1);
  }

  // Start timer
  start_time = time(NULL);

  // Exchange messages
  while (1) {
    recv(newsockfd, buf, 1024, 0);
    send(newsockfd, buf, 1024, 0);

    if (strcmp(buf, "quit") == 0) {
      break;
    }
  }

  // End timer
  end_time = time(NULL);

  // Calculate uptime
  int uptime = (end_time - start_time) * 60;

  // Print uptime
  printf("Uptime: %d minutes\n", uptime);

  // Close connections
  close(sockfd);
  close(newsockfd);

  return 0;
}