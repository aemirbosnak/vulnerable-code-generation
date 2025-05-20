//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

int num_voters = 0;
int num_candidates = 0;
int votes[MAX_VOTERS][MAX_CANDIDATES];
char candidate_names[MAX_CANDIDATES][50];

void add_candidate() {
  char name[50];

  printf("Enter candidate name: ");
  scanf("%s", name);

  strcpy(candidate_names[num_candidates], name);
  num_candidates++;
}

void cast_vote() {
  int voter_id;
  int candidate_id;

  printf("Enter voter ID: ");
  scanf("%d", &voter_id);

  if (voter_id >= num_voters) {
    printf("Invalid voter ID\n");
    return;
  }

  printf("Select candidate:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%d. %s\n", i+1, candidate_names[i]);
  }

  scanf("%d", &candidate_id);

  if (candidate_id < 1 || candidate_id > num_candidates) {
    printf("Invalid candidate ID\n");
    return;
  }

  // record vote
  votes[voter_id][candidate_id-1] = 1;
}

void count_votes() {
  int vote_count[MAX_CANDIDATES];
  int max_votes = 0;
  int winner_id = -1;

  for (int i = 0; i < num_candidates; i++) {
    vote_count[i] = 0;
  }

  for (int i = 0; i < num_voters; i++) {
    int valid_vote = 0;

    for (int j = 0; j < num_candidates; j++) {
      if (votes[i][j] == 1) {
        vote_count[j]++;
        valid_vote = 1;
      }
    }

    if (valid_vote) {
      printf("Voter %d successfully cast a vote\n", i);
    }
  }

  printf("\nVote Summary:\n");

  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidate_names[i], vote_count[i]);

    if (vote_count[i] > max_votes) {
      max_votes = vote_count[i];
      winner_id = i;
    }
  }

  if (max_votes > 0) {
    printf("\nWinner: %s\n", candidate_names[winner_id]);
  } else {
    printf("\nNo votes were cast\n");
  }
}

void print_menu() {
  printf("\nVoting System - Main Menu\n");
  printf("------------------------\n");
  printf("1. Add Candidate\n");
  printf("2. Cast Vote\n");
  printf("3. Count Votes\n");
  printf("4. Exit\n");
  printf("\nEnter choice: ");
}

int main() {
  int choice;

  while (1) {
    print_menu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_candidate();
        break;
      case 2:
        cast_vote();
        break;
      case 3:
        count_votes();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("\nInvalid choice\n");
    }
  }

  return 0;
}