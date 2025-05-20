//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    int id;
    char name[50];
    int votes;
};

void printCandidates(struct candidate candidates[], int size) {
    printf("Candidates:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
    printf("\n");
}

int main() {
    struct candidate candidates[4];

    // Initialize candidates
    candidates[0].id = 1;
    strcpy(candidates[0].name, "John");
    candidates[0].votes = 0;

    candidates[1].id = 2;
    strcpy(candidates[1].name, "Jane");
    candidates[1].votes = 0;

    candidates[2].id = 3;
    strcpy(candidates[2].name, "Bob");
    candidates[2].votes = 0;

    candidates[3].id = 4;
    strcpy(candidates[3].name, "Lisa");
    candidates[3].votes = 0;

    printCandidates(candidates, 4);

    int voterCount;
    printf("Enter the number of voters: ");
    scanf("%d", &voterCount);

    for (int i = 1; i <= voterCount; i++) {
        printf("Voter %d:\n", i);

        int choice;
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        candidates[choice - 1].votes++;
    }
    printf("\n");

    // Find winner
    int maxVotes = 0;
    struct candidate winner = candidates[0];

    for (int i = 1; i < 4; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winner = candidates[i];
        }
    }

    printf("The winner is %s with %d votes!\n", winner.name, winner.votes);

    return 0;
}