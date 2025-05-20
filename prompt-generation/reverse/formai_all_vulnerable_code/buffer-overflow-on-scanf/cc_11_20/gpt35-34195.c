//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

typedef struct {
    int id;
    char name[20];
    int age;
    char gender[10];
} Voter;

typedef struct {
    int id;
    char name[20];
} Candidate;

int num_voters, num_candidates;
Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];

int main() {
    printf("Welcome to the Electronic Voting System!\n");

    // Get number of voters and candidates from user
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    
    printf("Enter the number of candidates (maximum is %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);

    // Get voter information from user
    for (int i = 0; i < num_voters; i++) {
        printf("Enter information for Voter %d:\n", i+1);

        printf("  ID: ");
        scanf("%d", &voters[i].id);

        printf("  Name: ");
        scanf("%s", voters[i].name);

        printf("  Age: ");
        scanf("%d", &voters[i].age);

        printf("  Gender: ");
        scanf("%s", voters[i].gender);
    }

    // Get candidate information from user
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter information for Candidate %d:\n", i+1);

        printf("  ID: ");
        scanf("%d", &candidates[i].id);

        printf("  Name: ");
        scanf("%s", candidates[i].name);
    }

    // Display the voting options to the user
    printf("\nVoting Options:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("  %d. %s\n", candidates[i].id, candidates[i].name);
    }

    // Allow voters to cast their votes
    int votes[MAX_CANDIDATES] = {0};
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d, enter your vote (enter the candidate ID): ", i+1);

        int vote;
        scanf("%d", &vote);

        // Check if the vote is valid
        int valid_vote = 0;
        for (int j = 0; j < num_candidates; j++) {
            if (vote == candidates[j].id) {
                valid_vote = 1;
                votes[j]++;
                break;
            }
        }

        if (!valid_vote) {
            printf("Invalid vote, please try again.\n");
            i--;
        }
    }

    // Display the election results
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("  %s: %d votes\n", candidates[i].name, votes[i]);
    }

    // Determine the winner
    int winner = 0;
    int max_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner = i;
        }
    }

    printf("\nThe winner is %s with %d votes!\n", candidates[winner].name, max_votes);

    return 0;
}