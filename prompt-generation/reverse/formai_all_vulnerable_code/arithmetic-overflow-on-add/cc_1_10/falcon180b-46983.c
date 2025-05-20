//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    int votes;
} candidate;

void addCandidate(candidate* candidates, int numCandidates, char name[30]) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Candidate %s is already in the list.\n", name);
            return;
        }
    }
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void displayCandidates(candidate* candidates, int numCandidates) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        printf("%d. %s (%d votes)\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int numCandidates = 0;
    candidate candidates[100];
    char name[30];

    printf("Welcome to the Electronic Voting System!\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add candidate\n");
        printf("2. Display candidates\n");
        printf("3. Vote for a candidate\n");
        printf("4. Display election results\n");
        printf("5. Exit\n");

        scanf("%d", &numCandidates);

        switch (numCandidates) {
        case 1:
            printf("Enter the name of the candidate: ");
            scanf("%s", name);
            addCandidate(candidates, numCandidates, name);
            break;

        case 2:
            displayCandidates(candidates, numCandidates);
            break;

        case 3:
            printf("Enter the number of the candidate you want to vote for: ");
            scanf("%d", &numCandidates);
            candidates[numCandidates - 1].votes++;
            break;

        case 4:
            printf("Election Results:\n");
            displayCandidates(candidates, numCandidates);
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}