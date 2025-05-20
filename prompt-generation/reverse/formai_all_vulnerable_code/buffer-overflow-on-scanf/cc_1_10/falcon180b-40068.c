//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 10

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Candidate;

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Voter;

int main() {
    int num_candidates, num_voters;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int i, j, k, choice, valid_votes = 0;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);

        printf("How many votes does %s have? ", voters[i].name);
        scanf("%d", &choice);

        if (choice > 0 && choice <= MAX_VOTES_PER_VOTER) {
            voters[i].votes[0] = choice;
            valid_votes++;
        } else {
            printf("Invalid number of votes.\n");
        }
    }

    printf("\nElection Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: ", candidates[i].name);
        for (j = 0; j < MAX_VOTES_PER_VOTER; j++) {
            if (candidates[i].votes[j] > 0) {
                printf("%d ", candidates[i].votes[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    return 0;
}