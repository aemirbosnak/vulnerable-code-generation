//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
// EVotingSystem.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define MAX_VOTES 100

// Voter structure
typedef struct {
  char name[20];
  char password[20];
  int vote;
} Voter;

// Candidate structure
typedef struct {
  char name[20];
  int votes;
} Candidate;

// Global variables
Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];
int num_voters, num_candidates, num_votes;

// Function to read voter information from file
void read_voters() {
  FILE *fp = fopen("voters.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  int i = 0;
  while (fscanf(fp, "%s %s %d", voters[i].name, voters[i].password, &voters[i].vote) != EOF && i < MAX_VOTERS) {
    i++;
  }

  num_voters = i;

  fclose(fp);
}

// Function to read candidate information from file
void read_candidates() {
  FILE *fp = fopen("candidates.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  int i = 0;
  while (fscanf(fp, "%s %d", candidates[i].name, &candidates[i].votes) != EOF && i < MAX_CANDIDATES) {
    i++;
  }

  num_candidates = i;

  fclose(fp);
}

// Function to read vote information from file
void read_votes() {
  FILE *fp = fopen("votes.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  int i = 0;
  while (fscanf(fp, "%s %d", voters[i].name, &voters[i].vote) != EOF && i < MAX_VOTES) {
    i++;
  }

  num_votes = i;

  fclose(fp);
}

// Function to write vote information to file
void write_votes() {
  FILE *fp = fopen("votes.txt", "w");
  if (fp == NULL) {
    printf("Error opening file\n");
    return;
  }

  for (int i = 0; i < num_voters; i++) {
    fprintf(fp, "%s %d\n", voters[i].name, voters[i].vote);
  }

  fclose(fp);
}

// Function to display results
void display_results() {
  printf("Vote Results:\n");
  for (int i = 0; i < num_candidates; i++) {
    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
  }
}

// Main function
int main() {
  // Read voter information from file
  read_voters();

  // Read candidate information from file
  read_candidates();

  // Read vote information from file
  read_votes();

  // Display results
  display_results();

  // Write vote information to file
  write_votes();

  return 0;
}