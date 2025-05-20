//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES_PER_VOTER 1

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Candidate;

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Voter;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates, num_voters, i, j, k;
    char choice;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("\nEnter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("\nEnter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
    }

    printf("\nVoting has started...\n");

    for (i = 0; i < num_voters; i++) {
        printf("\n%s is voting:\n", voters[i].name);
        for (j = 0; j < num_candidates; j++) {
            printf("Enter your vote for %s (0-1): ", candidates[j].name);
            scanf("%d", &voters[i].votes[j]);
        }
    }

    printf("\nVoting has ended...\n");

    for (i = 0; i < num_candidates; i++) {
        printf("\n%s has %d votes:\n", candidates[i].name, 0);
        for (j = 0; j < num_voters; j++) {
            for (k = 0; k < MAX_VOTES_PER_VOTER; k++) {
                if (voters[j].votes[i] == 1) {
                    printf("%s voted for %s\n", voters[j].name, candidates[i].name);
                    candidates[i].votes[j] = 1;
                    break;
                }
            }
        }
    }

    printf("\nThe winner is:\n");
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes[0] == 1) {
            printf("%s\n", candidates[i].name);
            break;
        }
    }

    return 0;
}