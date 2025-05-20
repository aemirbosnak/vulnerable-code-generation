//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef struct {
    char name[50];
    int votes[3];
} Candidate;

int main() {
    int num_candidates = 3;
    int num_votes = 1000;
    int i, j, k;
    int total_votes[num_candidates];
    int winner_index = 0;

    Candidate candidates[num_candidates];
    for (i = 0; i < num_candidates; i++) {
        candidates[i].name[0] = 'C';
        candidates[i].name[1] = 'a';
        candidates[i].name[2] = 'n';
        candidates[i].name[3] = 'd';
        candidates[i].name[4] = 'i';
        candidates[i].name[5] = 'd';
        candidates[i].name[6] = 'a';
        candidates[i].name[7] = 't';
        candidates[i].name[8] = 'e';
        candidates[i].name[9] = 't';
        candidates[i].name[10] = 'e';
        candidates[i].name[11] = '\0';

        candidates[i].votes[0] = 0;
        candidates[i].votes[1] = 0;
        candidates[i].votes[2] = 0;
    }

    for (i = 0; i < num_votes; i++) {
        printf("Enter your vote for Candidate 1: ");
        scanf("%d", &candidates[0].votes[0]);

        printf("Enter your vote for Candidate 2: ");
        scanf("%d", &candidates[1].votes[0]);

        printf("Enter your vote for Candidate 3: ");
        scanf("%d", &candidates[2].votes[0]);

        printf("Enter your vote for Candidate 1: ");
        scanf("%d", &candidates[0].votes[1]);

        printf("Enter your vote for Candidate 2: ");
        scanf("%d", &candidates[1].votes[1]);

        printf("Enter your vote for Candidate 3: ");
        scanf("%d", &candidates[2].votes[1]);

        printf("Enter your vote for Candidate 1: ");
        scanf("%d", &candidates[0].votes[2]);

        printf("Enter your vote for Candidate 2: ");
        scanf("%d", &candidates[1].votes[2]);

        printf("Enter your vote for Candidate 3: ");
        scanf("%d", &candidates[2].votes[2]);
    }

    for (i = 0; i < num_candidates; i++) {
        total_votes[i] = candidates[i].votes[0] + candidates[i].votes[1] + candidates[i].votes[2];
    }

    for (i = 0; i < num_candidates; i++) {
        if (total_votes[i] > total_votes[winner_index]) {
            winner_index = i;
        }
    }

    printf("The winner is Candidate %d with %d votes.\n", winner_index + 1, total_votes[winner_index]);

    return 0;
}