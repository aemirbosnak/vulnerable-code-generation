//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include <stdio.h>

#define MAX_NUM_CANDIDATES 5

struct Candidate {
    char name[50];
    int votes;
};

int main() {
    struct Candidate candidates[MAX_NUM_CANDIDATES];
    int numCandidates = 0, totalVotes = 0;

    printf("Welcome to the Electronic Voting System!\n");

    printf("How many candidates are running for election? (Enter a number between 1 and %d): ", MAX_NUM_CANDIDATES);
    scanf("%d", &numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Ready to start voting? (Y/N): ");
    char ready;
    scanf(" %c", &ready);

    if (ready == 'Y' || ready == 'y') {
        int vote;
        do {
            printf("\n\n");

            for (int i = 0; i < numCandidates; i++) {
                printf("Enter %d to vote for %s\n", i+1, candidates[i].name);
            }
            printf("Enter 0 to end the voting process.\n");
            printf("\n\nPlease enter your vote: ");
            scanf("%d", &vote);

            if (vote > 0 && vote <= numCandidates) {
                candidates[vote - 1].votes++;
                totalVotes++;
                printf("Thank you for your vote!\n\n");
            } else if (vote == 0) {
                printf("Voting has ended. Thank you for your participation!\n\n");
            } else {
                printf("Invalid vote. Please try again.\n\n");
            }
        } while (vote != 0);
    } else {
        printf("Voting process has been cancelled.\n");
    }

    printf("\n\n\nELECTION RESULTS\n");

    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].votes, (float) candidates[i].votes / totalVotes * 100);
    }

    return 0;
}