//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NUM_CANDIDATES 3

typedef struct Voter {
  char name[20];
  int vote;
} Voter;

int main() {
  Voter voters[100];
  int numVoters = 0;
  int i, j;
  char candidate[20];

  // Initialize voters
  for (i = 0; i < 100; i++) {
    voters[i].name[0] = '\0';
    voters[i].vote = -1;
  }

  // Register voters
  while (1) {
    printf("Enter your name: ");
    scanf("%s", voters[numVoters].name);

    printf("Enter your vote (1-3): ");
    scanf("%d", &voters[numVoters].vote);

    if (voters[numVoters].vote < 1 || voters[numVoters].vote > NUM_CANDIDATES) {
      printf("Invalid vote.\n");
    } else {
      numVoters++;
      break;
    }
  }

  // Print results
  printf("Results:\n");
  for (i = 0; i < numVoters; i++) {
    printf("%s voted for candidate %d.\n", voters[i].name, voters[i].vote);
  }

  // Calculate winner
  int winner = -1;
  for (i = 0; i < numVoters; i++) {
    if (winner == -1) {
      winner = voters[i].vote;
    } else if (voters[i].vote == winner) {
      winner = voters[i].vote;
    }
  }

  // Announce winner
  printf("The winner is candidate %d.\n", winner);

  return 0;
}