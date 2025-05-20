//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_VOTER_NAME_LENGTH 50
#define MAX_CANDIDATE_NAME_LENGTH 50

typedef struct {
    char name[MAX_CANDIDATE_NAME_LENGTH];
    int votes[MAX_VOTERS];
} Candidate;

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int vote;
} Voter;

int main() {
    int num_candidates, num_voters;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);
        for (int j = 0; j < MAX_VOTERS; j++) {
            candidates[i].votes[j] = 0;
        }
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter voter %d's name: ", i + 1);
        scanf("%s", voters[i].name);
    }

    printf("Enter the votes:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %s's vote: ", voters[i].name);
        scanf("%d", &voters[i].vote);
    }

    for (int i = 0; i < num_candidates; i++) {
        for (int j = 0; j < num_voters; j++) {
            if (strcmp(voters[j].name, "") == 0) {
                break;
            }
            if (strcmp(candidates[i].name, voters[j].name) == 0) {
                candidates[i].votes[j] = voters[j].vote;
            }
        }
    }

    printf("The results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: ", candidates[i].name);
        for (int j = 0; j < num_voters; j++) {
            if (candidates[i].votes[j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}