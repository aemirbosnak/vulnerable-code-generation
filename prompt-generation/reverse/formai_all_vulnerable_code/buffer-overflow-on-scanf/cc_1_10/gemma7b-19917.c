//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

void vote(Candidate *candidates, int *votes) {
    char voter_name[20];
    char candidate_name[20];

    printf("Enter your name: ");
    scanf("%s", voter_name);

    printf("Enter the candidate's name: ");
    scanf("%s", candidate_name);

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidates[i].votes++;
            *votes++;
            break;
        }
    }

    printf("Thank you for voting.\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int votes = 0;

    // Initialize candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Vote
    vote(candidates, &votes);

    // Print results
    printf("The results of the election:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    printf("The total number of votes is: %d\n", votes);

    return 0;
}