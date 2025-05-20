//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

struct Candidate {
    char name[50];
    int votes;
};

struct Candidate candidates[10];
int numCandidates;

void addCandidate() {
    if(numCandidates == 10) {
        printf("Maximum number of candidates reached.\n");
        return;
    }
    struct Candidate newCandidate;
    printf("Enter candidate name: ");
    scanf("%s", newCandidate.name);
    newCandidate.votes = 0;
    candidates[numCandidates++] = newCandidate;
    printf("Candidate added successfully.\n");
}

void displayCandidates() {
    printf("List of candidates:\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void castVote() {
    printf("Enter candidate number to vote for: ");
    int choice;
    scanf("%d", &choice);
    if(choice < 1 || choice > numCandidates) {
        printf("Invalid choice.\n");
        return;
    }
    candidates[choice-1].votes++;
    printf("Vote casted for %s.\n", candidates[choice-1].name);
}

void displayResults() {
    printf("Results:\n");
    for(int i=0; i<numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    numCandidates = 0;
    while(1) {
        printf("\n1. Add candidate\n2. Display candidates\n3. Cast vote\n4. Display results\n5. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                displayCandidates();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}