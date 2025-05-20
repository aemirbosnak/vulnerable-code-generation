//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[50];
    int votes;
};

void addCandidate(struct candidate *candidates, int numCandidates, char name[50]) {
    int i;
    for (i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            printf("Candidate already added.\n");
            return;
        }
    }
    strcpy(candidates[numCandidates].name, name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void displayCandidates(struct candidate *candidates, int numCandidates) {
    int i;
    printf("Candidates:\n");
    for (i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

int main() {
    int numCandidates = 0;
    struct candidate candidates[100];
    char choice;
    int i;

    do {
        printf("Electronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. Display candidates\n");
        printf("3. Vote\n");
        printf("4. View results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                printf("Enter candidate name: ");
                scanf("%s", candidates[numCandidates].name);
                numCandidates++;
                break;
            case '2':
                displayCandidates(candidates, numCandidates);
                break;
            case '3':
                printf("Enter candidate number: ");
                scanf("%d", &i);
                if (i >= 1 && i <= numCandidates) {
                    candidates[i-1].votes++;
                } else {
                    printf("Invalid choice.\n");
                }
                break;
            case '4':
                printf("Candidates and their votes:\n");
                for (i = 0; i < numCandidates; i++) {
                    printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
                }
                break;
            case '5':
                printf("Thank you for using our Electronic Voting System.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= '5');

    return 0;
}