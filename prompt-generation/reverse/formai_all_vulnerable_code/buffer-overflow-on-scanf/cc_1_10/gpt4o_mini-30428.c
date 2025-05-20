//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int candidateCount = 0;

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Cannot add more candidates. Maximum limit reached.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate '%s' added successfully.\n", candidates[candidateCount - 1].name);
}

void castVote() {
    char name[NAME_LENGTH];
    printf("Enter the name of the candidate you wish to vote for: ");
    scanf("%s", name);
    
    for (int i = 0; i < candidateCount; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            printf("Vote casted for '%s'.\n", name);
            return;
        }
    }
    printf("Candidate '%s' not found.\n", name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void showMenu() {
    printf("\nElectronic Voting System\n");
    printf("1. Add Candidate\n");
    printf("2. Cast Vote\n");
    printf("3. Display Results\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}