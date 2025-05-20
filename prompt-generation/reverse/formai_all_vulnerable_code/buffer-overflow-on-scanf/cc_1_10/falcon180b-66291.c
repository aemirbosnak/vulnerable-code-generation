//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void addCandidate(candidate *candidates, int numCandidates, char *name) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Candidate %s already exists.\n", name);
            return;
        }
    }
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void displayCandidates(candidate *candidates, int numCandidates) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int main() {
    int numCandidates = 0, choice, i;
    candidate candidates[100];
    char name[50];

    srand(time(NULL));

    printf("Welcome to the Electronic Voting System!\n");
    printf("How many candidates are there? ");
    scanf("%d", &numCandidates);

    while (numCandidates == 0) {
        printf("Invalid number of candidates. Please enter again: ");
        scanf("%d", &numCandidates);
    }

    for (i = 0; i < numCandidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
    }

    while (1) {
        printf("\nPlease select a candidate:\n");
        displayCandidates(candidates, numCandidates);
        scanf("%d", &choice);

        if (choice < 1 || choice > numCandidates) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        candidates[choice-1].votes++;
        printf("Your vote has been counted for %s.\n", candidates[choice-1].name);

        if (numCandidates == 1) {
            printf("%s has won with %d votes!\n", candidates[0].name, candidates[0].votes);
            break;
        } else if (candidates[0].votes >= numCandidates/2 + 1) {
            printf("%s has won with %d votes!\n", candidates[0].name, candidates[0].votes);
            break;
        }
    }

    return 0;
}