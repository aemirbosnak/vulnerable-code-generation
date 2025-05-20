//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VOTES 1000

struct candidate {
  char name[20];
  int votes;
};

int main() {
  int num_candidates, num_votes, i, j, max_votes = 0, max_index = 0;
  struct candidate candidates[20];
  char voter_name[20], candidate_name[20];
  int votes[MAX_VOTES];
  
  printf("Enter the number of candidates: ");
  scanf("%d", &num_candidates);

  for(i = 0; i < num_candidates; i++) {
    printf("Enter the name of candidate %d: ", i+1);
    scanf("%s", candidates[i].name);
  }

  printf("\nEnter the number of votes: ");
  scanf("%d", &num_votes);

  for(i = 0; i < num_votes; i++) {
    printf("Enter the name of voter %d: ", i+1);
    scanf("%s", voter_name);

    int valid = 0;

    while(!valid) {

      printf("Enter the name of the candidate you want to vote for: ");
      scanf("%s", candidate_name);

      for(j = 0; j < num_candidates; j++) {

        if(strcmp(candidates[j].name, candidate_name) == 0) {

          votes[i] = j;
          candidates[j].votes++;
          valid = 1;
          break;
        }
      }

      if(!valid) {
        printf("That is not a valid candidate. Please try again.\n");
      }
    }
  }

  printf("\nResults:\n");

  for(i = 0; i < num_candidates; i++) {

    printf("%s: %d\n", candidates[i].name, candidates[i].votes);

    if(candidates[i].votes > max_votes) {
      max_votes = candidates[i].votes;
      max_index = i;
    }
  }

  printf("\nThe winner is %s with %d votes!\n", candidates[max_index].name, max_votes);

  return 0;
}