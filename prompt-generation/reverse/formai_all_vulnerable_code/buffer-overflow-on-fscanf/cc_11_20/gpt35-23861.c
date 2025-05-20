//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>

#define MAX_VOTERS 1000

struct candidate {
  char name[50];
  int votes;
};

struct voter {
  int id;
  bool voted;
};

int main() {
  struct candidate candidates[10];
  int num_candidates = 0;
  struct voter voters[MAX_VOTERS];
  int num_voters = 0;

  // Read candidate names from file
  FILE *file = fopen("candidates.txt", "r");
  if (file == NULL) {
    printf("Error reading candidate file.\n");
    return 1;
  }
  while (fscanf(file, "%s", candidates[num_candidates].name) != EOF) {
    candidates[num_candidates].votes = 0;
    num_candidates++;
  }
  fclose(file);

  // Read voter IDs from file
  file = fopen("voters.txt", "r");
  if (file == NULL) {
    printf("Error reading voter file.\n");
    return 1;
  }
  while (fscanf(file, "%d", &voters[num_voters].id) != EOF) {
    voters[num_voters].voted = false;
    num_voters++;
  }
  fclose(file);

  // Loop through voters and ask for vote
  int num_votes = 0;
  while (num_votes < num_voters) {
    int voter_id;
    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);
    bool found_voter = false;
    for (int i = 0; i < num_voters; i++) {
      if (voters[i].id == voter_id) {
        found_voter = true;
        if (voters[i].voted) {
          printf("You have already voted.\n");
        } else {
          printf("Candidates:\n");
          for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
          }
          int candidate_choice;
          printf("Enter your choice (1-%d): ", num_candidates);
          scanf("%d", &candidate_choice);
          candidates[candidate_choice-1].votes++;
          voters[i].voted = true;
          num_votes++;
        }
        break;
      }
    }
    if (!found_voter) {
      printf("Invalid voter ID.\n");
    }
  }

  // Print results
  printf("Results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }

  return 0;
}