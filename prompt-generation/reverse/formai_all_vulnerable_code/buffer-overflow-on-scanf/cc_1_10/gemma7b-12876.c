//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 5

typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];

void vote(char candidate) {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == candidate) {
            candidates[i].votes++;
            break;
        }
    }
}

int main() {
    int i;
    char choice;

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }

    // Create a loop for voting
    while (1) {
        printf("Enter candidate's name (or 'q' to quit): ");
        scanf(" %c", &choice);

        if (choice == 'q') {
            break;
        }

        vote(choice);
    }

    // Print the results
    printf("Election results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s has received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}