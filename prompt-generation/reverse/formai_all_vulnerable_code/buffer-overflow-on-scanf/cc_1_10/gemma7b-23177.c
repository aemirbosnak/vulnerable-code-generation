//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 3

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[NUM_CANDIDATES] = {
    {"Romeo", 0},
    {"Juliet", 0},
    {"Benvolio", 0}
};

void vote(char voter_choice) {
    switch (voter_choice) {
        case 'r':
            candidates[0].votes++;
            break;
        case 'j':
            candidates[1].votes++;
            break;
        case 'b':
            candidates[2].votes++;
            break;
        default:
            printf("Invalid vote.\n");
            break;
    }
}

int main() {
    char vote_choice;

    // Register voters
    printf("Enter your vote for:\n");
    printf("r - Romeo\nj - Juliet\nb - Benvolio\n");
    scanf("%c", &vote_choice);

    // Vote
    vote(vote_choice);

    // Print results
    printf("The results are:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}