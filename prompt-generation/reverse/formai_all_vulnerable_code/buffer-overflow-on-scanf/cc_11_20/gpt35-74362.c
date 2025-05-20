//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define MAX_NAME 20

// Declare the candidate struct
typedef struct Candidate {
    char name[MAX_NAME];
    int votes;
} Candidate;

// Declare the voter struct
typedef struct Voter {
    char name[MAX_NAME];
    int voted;
} Voter;

// The main function
int main() {
    // Declare the variables
    int num_voters, num_candidates;
    char c, name[MAX_NAME], code[4];
    int i, j, k, index, candidate_index, winner_index, max_votes;
    Candidate candidates[MAX_CANDIDATES], *winner;
    Voter voters[MAX_VOTERS];

    // Prompt the user for the number of voters and candidates
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Prompt the user to enter the candidates' names
    printf("Enter the names of the candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize the votes to zero
    }

    // Prompt the user to enter the voters' names and code
    for (i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0; // Initialize the voted flag to zero
        printf("Enter the code for voter %d: ", i+1);
        scanf("%s", code);
        if (strcmp(code, "abc") != 0) {
            printf("Invalid code. This voter cannot vote.\n");
            num_voters--; // Decrement the total number of voters
            i--; // Decrement the index so that the same user can retry
        }
    }

    // Prompt the user to vote for a candidate
    for (i = 0; i < num_voters; i++) {
        // Check if the voter has already voted
        if (voters[i].voted == 0) {
            printf("\n%s, please vote for a candidate:\n", voters[i].name);
            for (j = 0; j < num_candidates; j++) {
                printf("%d. %s\n", j+1, candidates[j].name);
            }
            scanf("%d", &index);
            candidate_index = index - 1;
            if (candidate_index >= 0 && candidate_index < num_candidates) {
                candidates[candidate_index].votes++;
                voters[i].voted = 1;
                printf("Thank you, %s. Your vote has been counted.\n", voters[i].name);
            } else {
                printf("Invalid candidate selected. Please try again.\n");
            }
        } else {
            printf("%s, you have already voted.\n", voters[i].name);
        }
    }

    // Determine the winner
    max_votes = candidates[0].votes;
    winner_index = 0;
    winner = &candidates[0];
    for (i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
            winner = &candidates[i];
        } else if (candidates[i].votes == max_votes) {
            printf("There is a tie between %s and %s with %d votes each.\n",
                   candidates[i].name, winner->name, max_votes);
        }
    }

    printf("The winner of the election is %s with %d votes.\n",
           winner->name, winner->votes);

    return 0;
}