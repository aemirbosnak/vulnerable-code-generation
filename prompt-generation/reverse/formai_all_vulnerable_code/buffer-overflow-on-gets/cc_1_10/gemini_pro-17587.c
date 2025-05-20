//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
  char name[50];
  int votes;
};

struct Candidate candidates[10];
int num_candidates = 0;

void add_candidate(char* name) {
  if (num_candidates >= 10) {
    printf("Error: Too many candidates.\n");
    return;
  }

  strcpy(candidates[num_candidates].name, name);
  candidates[num_candidates].votes = 0;
  num_candidates++;
}

void vote(char* name) {
  int i;
  for (i = 0; i < num_candidates; i++) {
    if (strcmp(candidates[i].name, name) == 0) {
      candidates[i].votes++;
      return;
    }
  }

  printf("Error: Invalid candidate name.\n");
}

void print_results() {
  int i;
  printf("Election Results:\n");
  for (i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

int main() {
  int i;
  char name[50];
  char choice;

  printf("Welcome to the Electronic Voting System!\n");
  printf("Please enter the names of the candidates:\n");

  for (i = 0; i < 5; i++) {
    printf("Candidate %d: ", i + 1);
    gets(name);
    add_candidate(name);
  }

  printf("Now, let's vote!\n");

  while (1) {
    printf("Please enter the name of the candidate you want to vote for: ");
    gets(name);

    if (strcmp(name, "exit") == 0) {
      break;
    }

    vote(name);
  }

  printf("Thank you for voting!\n");
  print_results();

  return 0;
}