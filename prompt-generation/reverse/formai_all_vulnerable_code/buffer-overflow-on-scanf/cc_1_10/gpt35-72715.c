//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
  int candidate_id;
  char name[30];
  int votes;
};

struct voter {
  int voter_id;
  int voted_candidate_id;
};

void add_candidate(struct candidate [], int *);
void display_candidates(struct candidate [], int);
void add_voter(struct voter [], int *);
void display_voters(struct voter [], int);
void vote(struct voter [], int, struct candidate [], int);
void display_results(struct candidate [], int);

int main() {
  struct candidate candidates[100];
  struct voter voters[100];
  int num_of_candidates = 0;
  int num_of_voters = 0;
  int option;

  while (1) {
    printf("Electronic Voting System\n");
    printf("1. Add Candidate\n");
    printf("2. Display Candidates\n");
    printf("3. Add Voter\n");
    printf("4. Display Voters\n");
    printf("5. Vote\n");
    printf("6. Display Results\n");
    printf("7. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        add_candidate(candidates, &num_of_candidates);
        break;

      case 2:
        display_candidates(candidates, num_of_candidates);
        break;

      case 3:
        add_voter(voters, &num_of_voters);
        break;

      case 4:
        display_voters(voters, num_of_voters);
        break;

      case 5:
        vote(voters, num_of_voters, candidates, num_of_candidates);
        break;

      case 6:
        display_results(candidates, num_of_candidates);
        break;

      case 7:
        printf("Exiting...\n");
        exit(0);
        break;

      default:
        printf("Invalid option entered!\n");
        break;
    }
  }

  return 0;
}

void add_candidate(struct candidate candidates[], int *num_of_candidates) {
  struct candidate new_candidate;

  printf("Enter candidate ID: ");
  scanf("%d", &new_candidate.candidate_id);

  printf("Enter candidate name: ");
  scanf("%s", new_candidate.name);

  new_candidate.votes = 0;

  candidates[*num_of_candidates] = new_candidate;
  (*num_of_candidates)++;
}

void display_candidates(struct candidate candidates[], int num_of_candidates) {
  if (num_of_candidates == 0) {
    printf("No candidates added yet!\n");
    return;
  }

  printf("Candidate ID\tCandidate Name\tVotes Received\n");

  for (int i = 0; i < num_of_candidates; i++) {
    printf("%d\t\t%s\t\t%d\n", candidates[i].candidate_id, candidates[i].name, candidates[i].votes);
  }
}

void add_voter(struct voter voters[], int *num_of_voters) {
  struct voter new_voter;

  printf("Enter voter ID: ");
  scanf("%d", &new_voter.voter_id);

  new_voter.voted_candidate_id = -1;

  voters[*num_of_voters] = new_voter;
  (*num_of_voters)++;
}

void display_voters(struct voter voters[], int num_of_voters) {
  if (num_of_voters == 0) {
    printf("No voters added yet!\n");
    return;
  }

  printf("Voter ID\tVoted Candidate ID\n");

  for (int i = 0; i < num_of_voters; i++) {
    printf("%d\t\t%d\n", voters[i].voter_id, voters[i].voted_candidate_id);
  }
}

void vote(struct voter voters[], int num_of_voters, struct candidate candidates[], int num_of_candidates) {
  int voter_id, candidate_id;

  printf("Enter voter ID: ");
  scanf("%d", &voter_id);

  for (int i = 0; i < num_of_voters; i++) {
    if (voters[i].voter_id == voter_id && voters[i].voted_candidate_id == -1) {
      printf("Enter candidate ID to vote for: ");
      scanf("%d", &candidate_id);

      for (int j = 0; j < num_of_candidates; j++) {
        if (candidates[j].candidate_id == candidate_id) {
          candidates[j].votes++;
          voters[i].voted_candidate_id = candidate_id;
          printf("Vote recorded successfully!\n");
          return;
        }
      }

      printf("No candidate with that ID found!\n");
      return;
    }
  }

  printf("Either voter has already voted or voter ID not found!\n");
}

void display_results(struct candidate candidates[], int num_of_candidates) {
  if (num_of_candidates == 0) {
    printf("No candidates added yet!\n");
    return;
  }

  int max_votes = candidates[0].votes;
  int winner_id = candidates[0].candidate_id;

  for (int i = 1; i < num_of_candidates; i++) {
    if (candidates[i].votes > max_votes) {
      max_votes = candidates[i].votes;
      winner_id = candidates[i].candidate_id;
    }
  }

  printf("Candidate ID\tCandidate Name\tVotes Received\n");

  for (int i = 0; i < num_of_candidates; i++) {
    printf("%d\t\t%s\t\t%d", candidates[i].candidate_id, candidates[i].name, candidates[i].votes);

    if (candidates[i].candidate_id == winner_id) {
      printf("\tWinner");
    }

    printf("\n");
  }
}