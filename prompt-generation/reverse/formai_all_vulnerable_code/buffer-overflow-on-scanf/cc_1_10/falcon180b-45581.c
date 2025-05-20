//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void addCandidate(candidate *candidates, int *numCandidates, char *name) {
    strcpy(candidates[*numCandidates].name, name);
    candidates[*numCandidates].votes = 0;
    (*numCandidates)++;
}

int main() {
    int numCandidates = 0;
    candidate candidates[100];
    char input[100];
    int choice;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate %d's name: ", i+1);
        scanf("%s", input);
        addCandidate(candidates, &numCandidates, input);
    }

    printf("\n");
    printf("Cast your vote by entering the candidate's number:\n");
    printf("1. %s\n", candidates[0].name);
    for (int i = 1; i < numCandidates; i++) {
        printf("%d. %s\n", i, candidates[i].name);
    }

    while (1) {
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= numCandidates) {
            candidates[choice-1].votes++;
            printf("\nYour vote has been cast for %s.\n", candidates[choice-1].name);
            break;
        } else {
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    printf("\n");
    printf("Voting results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}