//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates) {
    int i;
    char vote;

    printf("Please select a candidate: ");
    scanf("%c", &vote);

    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == vote) {
            candidates[i].votes++;
            break;
        }
    }

    printf("Thank you for voting!\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"John Doe", 0},
        {"Jane Doe", 0},
        {"Peter Pan", 0},
        {"Mary Poppins", 0},
        {"Captain Hook", 0}
    };

    int numVotes = 0;

    while (numVotes < 10) {
        vote(candidates);
        numVotes++;
    }

    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}