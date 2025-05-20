//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CANDIDATES 4
#define NUM_VOTERS 10

typedef struct {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[NUM_CANDIDATES] = { {"Alice", 0}, {"Bob", 0}, {"Charlie", 0}, {"David", 0} };

int main() {

    srand(time(NULL));

    char vote;
    int voter_id, candidate_id, i, j;

    printf("Welcome to the Electronic Voting System!\n\n");

    for(i=1; i<=NUM_VOTERS; i++) {

        printf("Voter #%d, please enter your ID: ", i);
        scanf("%d", &voter_id);

        printf("Thank you. Please cast your vote (A/B/C/D): ");
        scanf(" %c", &vote);

        candidate_id = -1;
        switch(vote) {
            case 'A': candidate_id = 0; break;
            case 'B': candidate_id = 1; break;
            case 'C': candidate_id = 2; break;
            case 'D': candidate_id = 3; break;
            default: printf("Invalid vote. Vote not cast.\n");
        }

        if(candidate_id != -1) {
            candidates[candidate_id].votes++;
            printf("Vote counted.\n");
        }

        printf("\n");

    }

    printf("Voting complete. Here are the results:\n\n");

    for(i=0; i<NUM_CANDIDATES; i++) {
        printf("Candidate %s: ", candidates[i].name);
        for(j=0; j<candidates[i].votes; j++) {
            printf("*");
        }
        printf(" %d votes\n", candidates[i].votes);
    }

    printf("\nThank you for voting!\n");

    return 0;
}