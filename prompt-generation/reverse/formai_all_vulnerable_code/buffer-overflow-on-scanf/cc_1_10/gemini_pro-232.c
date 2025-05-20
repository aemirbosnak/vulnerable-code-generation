//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: curious
// Pinging the enigmatic digital realm, like a curious feline chasing shadows.

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

int main() {
  // Declare the variables like a meticulous scientist preparing for an experiment.
  int sockfd, n;
  char hostname[100];
  struct sockaddr_in servaddr;
  struct timeval timeout;
  timeout.tv_sec = 1;
  timeout.tv_usec = 0;

  // Prompt the user like a curious explorer seeking knowledge.
  printf("Enter the domain you wish to ping, brave adventurer: ");
  scanf("%s", hostname);

  // Create the socket like an architect laying the foundation of a grand structure.
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    printf("Socket creation failed, alas!");
    exit(EXIT_FAILURE);
  }

  // Set the socket options like a wise wizard casting ancient runes.
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&timeout, sizeof(timeout));

  // Initialize the server address like a cartographer charting the vast digital landscape.
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(80);
  if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
    printf("Invalid address, gentle traveler!");
    exit(EXIT_FAILURE);
  }

  // Ping the server like a playful dolphin leaping from the depths.
  char ping[100] = "PING";
  sendto(sockfd, ping, strlen(ping), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

  // Receive the response like a keen-eyed eagle scanning the horizon.
  char buffer[100];
  n = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);

  // Analyze the response like a skilled detective sifting through clues.
  if (n > 0) {
    printf("Ahoy! Response received from %s!\n", hostname);
  } else {
    printf("Alas, no response from %s. The sea remains silent.\n", hostname);
  }

  // Close the socket like a cautious voyager folding their sails.
  close(sockfd);

  // Farewell the user with a touch of whimsy.
  printf("May your digital adventures be filled with wonder and discovery, fair traveler!");

  return 0;
}