//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_OPTIONS 5

typedef struct {
    char name[50];
    int vote[MAX_OPTIONS];
} Voter;

void registerVoter(Voter voters[], int voterId, char name[]) {
    strcpy(voters[voterId].name, name);
    memset(voters[voterId].vote, 0, MAX_OPTIONS * sizeof(int));
}

void castVote(Voter voters[], int voterId, int optionId) {
    voters[voterId].vote[optionId]++;
}

void printResults(Voter voters[]) {
    int totalVotes = 0;
    for (int i = 0; i < MAX_VOTERS; i++) {
        if (strlen(voters[i].name) > 0) {
            totalVotes++;
            printf("\nVoter %d: %s", i, voters[i].name);
            for (int j = 0; j < MAX_OPTIONS; j++) {
                printf("\nOption %d: %d votes", j, voters[i].vote[j]);
            }
        }
    }

    printf("\nTotal votes cast: %d", totalVotes);
}

int main() {
    Voter voters[MAX_VOTERS];
    int numVoters, voterId, optionId;

    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    for (int i = 0; i < numVoters; i++) {
        printf("\nEnter voter name: ");
        scanf("%s", voters[i].name);
        registerVoter(voters, i, voters[i].name);
    }

    printf("\nCasting votes...\n");

    for (int i = 0; i < numVoters; i++) {
        printf("\nVoter %d, enter your option number (1-%d): ", i, MAX_OPTIONS);
        scanf("%d", &optionId);
        castVote(voters, i, optionId - 1);
    }

    printf("\nPrinting results...\n");
    printResults(voters);

    return 0;
}