//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
  char name[20];
  int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char *candidate) {
  int i;
  for (i = 0; i < MAX_CANDIDATES; i++) {
    if (strcmp(candidates[i].name, candidate) == 0) {
      candidates[i].votes++;
      break;
    }
  }
}

int main() {
  int i;
  char vote_choice;
  system("/bin/clear");

  // Initialize candidates
  for (i = 0; i < MAX_CANDIDATES; i++) {
    candidates[i].votes = 0;
  }

  // Print candidate list
  printf("Available candidates:\n");
  for (i = 0; i < MAX_CANDIDATES; i++) {
    printf("%s\n", candidates[i].name);
  }

  // Get vote choice
  printf("Enter the name of the candidate you want to vote for: ");
  scanf("%c", &vote_choice);

  // Validate vote choice
  if (vote_choice >= 'a' && vote_choice <= 'a' + MAX_CANDIDATES - 1) {
    vote(&candidates[vote_choice - 'a'].name);
    printf("Your vote has been cast.\n");
  } else {
    printf("Invalid vote choice.\n");
  }

  return 0;
}