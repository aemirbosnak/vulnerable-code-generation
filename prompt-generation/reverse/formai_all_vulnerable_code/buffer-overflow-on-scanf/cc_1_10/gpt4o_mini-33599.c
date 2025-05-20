//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voterID[10];
    int hasVoted; // 0 = not voted, 1 = voted
} Voter;

Candidate candidates[MAX_CANDIDATES] = {
    {"Alice", 0},
    {"Bob", 0},
    {"Charlie", 0},
    {"Diana", 0},
    {"Eve", 0}
};

Voter voters[MAX_VOTERS];
int voterCount = 0;

void displayCandidates() {
    printf("\nCandidates for the Election:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int isVoterRegistered(char *voterID) {
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].voterID, voterID) == 0) {
            return i; // Voter found
        }
    }
    return -1; // Voter not found
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Voter registration limit reached.\n");
        return;
    }
    printf("Enter voter ID: ");
    scanf("%s", voters[voterCount].voterID);
    voters[voterCount].hasVoted = 0;
    voterCount++;
    printf("Voter registered successfully!\n");
}

void castVote() {
    char voterID[10];
    printf("Enter voter ID: ");
    scanf("%s", voterID);
    
    int idx = isVoterRegistered(voterID);
    
    if (idx == -1) {
        printf("Voter not registered.\n");
        return;
    }
    
    if (voters[idx].hasVoted) {
        printf("You have already voted. Thank you!\n");
        return;
    }
    
    displayCandidates();
    
    int choice;
    printf("Enter the candidate number you wish to vote for: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > MAX_CANDIDATES) {
        printf("Invalid choice.\n");
        return;
    }
    
    candidates[choice - 1].votes++;
    voters[idx].hasVoted = 1;
    
    printf("Thank you! Your vote has been cast for %s.\n", candidates[choice - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int option;
    
    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                registerVoter();
                break;
            case 2:
                castVote();
                break;
            case 3:
                displayResults();
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}