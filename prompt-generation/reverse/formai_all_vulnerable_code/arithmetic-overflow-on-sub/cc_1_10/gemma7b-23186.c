//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

#define SERVER_NAME "localhost"
#define SERVER_PORT 8080

int main() {
  int sockfd, n, bytes_sent, bytes_received;
  struct sockaddr_in server_addr;
  char message[1024];
  time_t start_time, end_time;

  // Socket setup
  sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to server
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  server_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Start timer
  start_time = time(NULL);

  // Send message
  sprintf(message, "Hello, world!");
  bytes_sent = send(sockfd, message, sizeof(message), 0);

  // Receive message
  bytes_received = recv(sockfd, message, sizeof(message), 0);

  // End timer
  end_time = time(NULL);

  // Print results
  printf("Message sent: %s\n", message);
  printf("Message received: %s\n", message);
  printf("Time taken: %.2f seconds\n", (double)(end_time - start_time));

  // Close socket
  close(sockfd);

  return 0;
}