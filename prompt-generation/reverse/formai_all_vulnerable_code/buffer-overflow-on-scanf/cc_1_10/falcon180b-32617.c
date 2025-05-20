//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 5
#define MAX_CANDIDATE_NAME_LENGTH 50
#define MAX_VOTER_NAME_LENGTH 50

typedef struct {
    char name[MAX_CANDIDATE_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int votes[MAX_CANDIDATES];
} Voter;

int main() {
    int num_candidates, num_voters;
    char input[100];
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    // Read in number of candidates and candidate names
    printf("Enter the number of candidates (up to %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name (%d characters or less): ", MAX_CANDIDATE_NAME_LENGTH);
        scanf("%s", candidates[i].name);
    }

    // Read in number of voters and voter names
    printf("Enter the number of voters (up to %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);
    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter name (%d characters or less): ", MAX_VOTER_NAME_LENGTH);
        scanf("%s", voters[i].name);
    }

    // Read in votes from each voter
    for (int i = 0; i < num_voters; i++) {
        printf("Enter %s's votes (up to %d candidates): ", voters[i].name, MAX_VOTES_PER_VOTER);
        for (int j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            scanf("%s", input);
            for (int k = 0; k < num_candidates; k++) {
                if (strcmp(input, candidates[k].name) == 0) {
                    candidates[k].votes++;
                    voters[i].votes[k] = 1;
                    break;
                }
            }
        }
    }

    // Print out results
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("\n");

    return 0;
}