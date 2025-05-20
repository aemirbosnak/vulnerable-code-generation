//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define MAX_VOTES 10

int main() {
  int sockfd, clientfd, vote_num, vote_choice;
  char vote_message[255];
  struct sockaddr_in server_addr, client_addr;
  char hostname[255];

  // Socket setup
  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Server address and hostname
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);
  gethostname(hostname, sizeof(hostname));
  server_addr.sin_addr.s_addr = inet_addr(hostname);

  // Client connection
  clientfd = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (clientfd < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Voting process
  printf("Enter your vote number (1-10): ");
  scanf("%d", &vote_num);
  if (vote_num < 1 || vote_num > MAX_VOTES) {
    printf("Invalid vote number.\n");
    exit(1);
  }

  // Vote choice
  printf("Enter your vote choice (A-F): ");
  scanf(" %c", &vote_choice);
  vote_message[0] = vote_num;
  vote_message[1] = vote_choice;

  // Sending vote
  send(clientfd, vote_message, sizeof(vote_message), 0);

  // Vote confirmation
  printf("Your vote has been submitted.\n");

  // Closing connections
  close(clientfd);
  close(sockfd);

  return 0;
}