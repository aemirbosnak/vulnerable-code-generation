//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define candidate names
#define CANDIDATE1 "Warlord"
#define CANDIDATE2 "Scavenger"
#define CANDIDATE3 "Raider"

// Define enum for vote status
enum VoteStatus {
  VOTED,
  NOT_VOTED
};

// Define struct for voter data
typedef struct Voter {
  char name[50];
  int age;
  enum VoteStatus vote_status;
  int candidate_voted;
} Voter;

// Define struct for candidate data
typedef struct Candidate {
  char name[50];
  int vote_count;
} Candidate;

// Array of candidates
Candidate candidates[] = {
  {CANDIDATE1, 0},
  {CANDIDATE2, 0},
  {CANDIDATE3, 0}
};

// Array of voters
Voter voters[] = {
  {"John Smith", 35, NOT_VOTED},
  {"Jane Doe", 28, NOT_VOTED},
  {"Michael Jones", 42, NOT_VOTED},
  {"Sarah Miller", 30, NOT_VOTED},
  {"William Brown", 25, NOT_VOTED}
};

// Function to print voter data
void print_voter_data(Voter voter) {
  printf("Name: %s\n", voter.name);
  printf("Age: %d\n", voter.age);
  printf("Vote status: %s\n", voter.vote_status == VOTED ? "Voted" : "Not voted");
}

// Function to print candidate data
void print_candidate_data(Candidate candidate) {
  printf("Name: %s\n", candidate.name);
  printf("Vote count: %d\n", candidate.vote_count);
}

// Function to register a voter
void register_voter(Voter *voter) {
  printf("Enter your name: ");
  scanf("%s", voter->name);
  printf("Enter your age: ");
  scanf("%d", &voter->age);
  voter->vote_status = NOT_VOTED;
}

// Function to vote for a candidate
void vote(Voter *voter) {
  int candidate_index;
  printf("Enter the candidate you want to vote for (1-%d): ", sizeof(candidates) / sizeof(Candidate));
  scanf("%d", &candidate_index);
  if (candidate_index < 1 || candidate_index > sizeof(candidates) / sizeof(Candidate)) {
    printf("Invalid candidate index.\n");
    return;
  }
  candidates[candidate_index - 1].vote_count++;
  voter->vote_status = VOTED;
  voter->candidate_voted = candidate_index - 1;
}

// Function to announce the election results
void announce_results(Candidate *candidates) {
  int winning_candidate_index = 0;
  int highest_vote_count = 0;
  for (int i = 0; i < sizeof(candidates) / sizeof(Candidate); i++) {
    if (candidates[i].vote_count > highest_vote_count) {
      winning_candidate_index = i;
      highest_vote_count = candidates[i].vote_count;
    }
  }
  printf("The winner of the election is %s with %d votes.\n", candidates[winning_candidate_index].name, candidates[winning_candidate_index].vote_count);
}

int main() {
  // Register voters
  for (int i = 0; i < sizeof(voters) / sizeof(Voter); i++) {
    register_voter(&voters[i]);
  }

  // Allow voters to vote
  for (int i = 0; i < sizeof(voters) / sizeof(Voter); i++) {
    vote(&voters[i]);
  }

  // Announce the election results
  announce_results(candidates);

  return 0;
}