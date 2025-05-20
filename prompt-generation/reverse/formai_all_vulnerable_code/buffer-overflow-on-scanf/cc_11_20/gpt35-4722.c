//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define maximum number of voters
#define MAX_VOTERS 1000

// Define maximum number of candidates
#define MAX_CANDIDATES 10

// Data structure for candidates
typedef struct candidate {
    char name[50];
    int votes;
} Candidate;

// Data structure for voters
typedef struct voter {
    char name[50];
    int age;
    int voted; // 0 if not voted, 1 if voted
    int vote; // index of candidate voted for, -1 if not voted
} Voter;

int main() {
    int num_voters, num_candidates, i, j;
    char temp[50];
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    // Input number of voters and candidates
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Input candidate names
    for(i=0; i<num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize votes to zero
    }

    // Input voter names and ages
    for(i=0; i<num_voters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Enter the age of voter %d: ", i+1);
        scanf("%d", &voters[i].age);
        voters[i].voted = 0; // Initialize voted to zero
        voters[i].vote = -1; // Initialize vote index to -1
    }

    // Allow voters to cast their votes
    for(i=0; i<num_voters; i++) {
        // Check if voter is of legal voting age
        if(voters[i].age >= 18) {
            // Check if voter has not already voted
            if(voters[i].voted == 0) {
                // Display candidate names and allow voter to vote
                printf("Candidate list:\n");
                for(j=0; j<num_candidates; j++) {
                    printf("%d. %s\n", j+1, candidates[j].name);
                }
                printf("Enter the number of the candidate you want to vote for, or 0 to abstain: ");
                scanf("%d", &voters[i].vote);
                // Increment candidate's vote count if vote is valid
                if(voters[i].vote >= 1 && voters[i].vote <= num_candidates) {
                    candidates[voters[i].vote-1].votes++;
                } else if(voters[i].vote == 0) {
                    printf("You have abstained from voting.\n");
                } else {
                    printf("Invalid vote.\n");
                }
                // Mark voter as having voted
                voters[i].voted = 1;
            } else {
                printf("Voter %s has already voted.\n", voters[i].name);
            }
        } else {
            printf("Voter %s is not of legal voting age.\n", voters[i].name);
        }
    }

    // Display results
    printf("\n\nElection results:\n");
    for(i=0; i<num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    // Find winner(s)
    int max_votes = 0;
    for(i=0; i<num_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }
    printf("Winner(s):\n");
    for(i=0; i<num_candidates; i++) {
        if(candidates[i].votes == max_votes) {
            printf("%s\n", candidates[i].name);
        }
    }

    return 0;
}