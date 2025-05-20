//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct candidate {
int id;
char name[50];
int votes;
} candidate_t;

// Define the structure of a voter
typedef struct voter {
int id;
int vote;
} voter_t;

// Define the array of candidates
candidate_t candidates[MAX_CANDIDATES];

// Define the array of voters
voter_t voters[MAX_VOTERS];

// Define the number of candidates
int num_candidates;

// Define the number of voters
int num_voters;

// Get the number of candidates
void get_num_candidates() {
printf("Enter the number of candidates: ");
scanf("%d", &num_candidates);
}

// Get the details of the candidates
void get_candidate_details() {
for (int i = 0; i < num_candidates; i++) {
printf("Enter the ID of candidate %d: ", i + 1);
scanf("%d", &candidates[i].id);
printf("Enter the name of candidate %d: ", i + 1);
scanf("%s", candidates[i].name);
candidates[i].votes = 0;
}
}

// Get the number of voters
void get_num_voters() {
printf("Enter the number of voters: ");
scanf("%d", &num_voters);
}

// Get the votes of the voters
void get_voter_votes() {
for (int i = 0; i < num_voters; i++) {
printf("Enter the ID of voter %d: ", i + 1);
scanf("%d", &voters[i].id);
printf("Enter the vote of voter %d: ", i + 1);
scanf("%d", &voters[i].vote);
}
}

// Count the votes
void count_votes() {
for (int i = 0; i < num_voters; i++) {
for (int j = 0; j < num_candidates; j++) {
if (voters[i].vote == candidates[j].id) {
candidates[j].votes++;
}
}
}
}

// Print the results
void print_results() {
printf("The results of the election are as follows:\n");
for (int i = 0; i < num_candidates; i++) {
printf("Candidate %d (%s) received %d votes.\n", candidates[i].id, candidates[i].name, candidates[i].votes);
}
}

// Main function
int main() {
// Get the number of candidates
get_num_candidates();

// Get the details of the candidates
get_candidate_details();

// Get the number of voters
get_num_voters();

// Get the votes of the voters
get_voter_votes();

// Count the votes
count_votes();

// Print the results
print_results();

return 0;
}