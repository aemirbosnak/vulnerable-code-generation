//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the Romeo and Juliet candidates
char *romeo = "Romeo";
char *juliet = "Juliet";

// Declare the array of voters
char **voters;

// Declare the number of voters
int num_voters;

// Declare the function to get the number of voters
int get_num_voters() {
  // Prompt the user to enter the number of voters
  printf("Enter the number of voters: ");

  // Get the number of voters from the user
  scanf("%d", &num_voters);

  // Return the number of voters
  return num_voters;
}

// Declare the function to get the voters
char **get_voters() {
  // Allocate memory for the array of voters
  voters = malloc(sizeof(char *) * num_voters);

  // Get the names of the voters from the user
  for (int i = 0; i < num_voters; i++) {
    printf("Enter the name of voter %d: ", i + 1);
    scanf("%s", voters[i]);
  }

  // Return the array of voters
  return voters;
}

// Declare the function to get the votes
int *get_votes() {
  // Allocate memory for the array of votes
  int *votes = malloc(sizeof(int) * num_voters);

  // Get the votes from the voters
  for (int i = 0; i < num_voters; i++) {
    printf("Who do you want to vote for, %s or %s? ", romeo, juliet);
    scanf("%s", votes[i]);
  }

  // Return the array of votes
  return votes;
}

// Declare the function to count the votes
int count_votes(int *votes) {
  // Initialize the vote counts
  int romeo_votes = 0;
  int juliet_votes = 0;

  // Count the votes
  for (int i = 0; i < num_voters; i++) {
    if (votes[i] == romeo) {
      romeo_votes++;
    } else if (votes[i] == juliet) {
      juliet_votes++;
    }
  }

  // Return the winner
  if (romeo_votes > juliet_votes) {
    return romeo;
  } else if (juliet_votes > romeo_votes) {
    return juliet;
  } else {
    return NULL;
  }
}

// Declare the function to print the results
void print_results(char *winner) {
  // Print the winner
  printf("The winner is %s!\n", winner);
}

// Declare the main function
int main() {
  // Get the number of voters
  num_voters = get_num_voters();

  // Get the voters
  voters = get_voters();

  // Get the votes
  int *votes = get_votes();

  // Count the votes
  char *winner = count_votes(votes);

  // Print the results
  print_results(winner);

  // Free the memory allocated for the array of voters
  free(voters);

  // Free the memory allocated for the array of votes
  free(votes);

  return 0;
}