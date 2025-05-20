//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int votes;
} candidate;

void addCandidate(candidate* candidates, int numCandidates, char* name) {
    for (int i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Candidate already exists.\n");
            return;
        }
    }
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void displayCandidates(candidate* candidates, int numCandidates) {
    printf("Candidates:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int main() {
    candidate candidates[100];
    int numCandidates = 0;
    int choice;
    char name[50];

    do {
        printf("1. Add candidate\n");
        printf("2. Display candidates\n");
        printf("3. Vote\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                addCandidate(candidates, numCandidates, name);
                break;
            case 2:
                displayCandidates(candidates, numCandidates);
                break;
            case 3:
                printf("Enter candidate number: ");
                scanf("%d", &choice);
                if (choice < 1 || choice > numCandidates) {
                    printf("Invalid candidate number.\n");
                } else {
                    candidates[choice-1].votes++;
                    printf("Vote cast for %s.\n", candidates[choice-1].name);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}