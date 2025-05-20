//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

#define HOST "localhost"
#define PORT 8080

int main() {
  int sockfd, n, err;
  struct sockaddr_in servaddr;
  char buf[1024];
  time_t start, end;

  // Set up the socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
  if (sockfd == -1) {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to the server
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("Error connecting to server");
    exit(1);
  }

  // Start the timer
  start = time(NULL);

  // Send a message to the server
  printf("Enter a message: ");
  scanf("%s", buf);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("Error sending message");
    exit(1);
  }

  // Receive a message from the server
  n = recv(sockfd, buf, 1024, 0);
  if (n == -1) {
    perror("Error receiving message");
    exit(1);
  }

  // Stop the timer
  end = time(NULL);

  // Print the message from the server
  printf("Message from the server: %s\n", buf);

  // Calculate the time taken
  n = end - start;
  printf("Time taken: %d seconds\n", n);

  // Close the socket
  close(sockfd);

  return 0;
}