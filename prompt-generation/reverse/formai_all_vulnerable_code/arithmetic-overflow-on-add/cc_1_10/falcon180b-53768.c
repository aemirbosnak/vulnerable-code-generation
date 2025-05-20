//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 3
#define NUM_VOTERS 10

// Function to display the candidates
void display_candidates() {
    printf("The candidates are:\n");
    printf("1. Romeo\n");
    printf("2. Juliet\n");
    printf("3. Paris\n");
}

// Function to display the voting instructions
void display_instructions() {
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your choice of candidate.\n");
    printf("Enter 1 for Romeo, 2 for Juliet, or 3 for Paris.\n");
}

// Function to count the votes
void count_votes(int votes[NUM_CANDIDATES]) {
    int i;
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %d received %d votes.\n", i + 1, votes[i]);
    }
}

// Function to generate a random voter ID
int generate_voter_id() {
    return rand() % NUM_VOTERS + 1;
}

int main() {
    int votes[NUM_CANDIDATES] = {0};
    int voter_id;
    int choice;

    // Seed the random number generator
    srand(time(NULL));

    // Display the candidates
    display_candidates();

    // Get the voter ID
    voter_id = generate_voter_id();

    // Display the voting instructions
    display_instructions();

    // Get the voter's choice
    printf("Enter your choice of candidate: ");
    scanf("%d", &choice);

    // Increment the vote count for the chosen candidate
    votes[choice - 1]++;

    // Print the voter's confirmation
    printf("Thank you for voting, voter %d!\n", voter_id);

    // Count the votes
    count_votes(votes);

    return 0;
}