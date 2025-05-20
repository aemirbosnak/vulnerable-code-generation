//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
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
    char name[50];
    int voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Candidate limit reached. Cannot add more candidates.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("Candidate '%s' added successfully!\n", candidates[candidateCount - 1].name);
}

void castVote() {
    char voterName[50];
    int foundVoter = 0;
    
    printf("Enter your name: ");
    scanf("%s", voterName);
    
    for (int i = 0; i < voterCount; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            printf("You have already voted!\n");
            foundVoter = 1;
            break;
        }
    }
    
    if (!foundVoter) {
        printf("Available candidates:\n");
        for (int i = 0; i < candidateCount; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }
        
        int choice;
        printf("Select candidate number to vote: ");
        scanf("%d", &choice);
        
        if (choice > 0 && choice <= candidateCount) {
            candidates[choice - 1].votes++;
            voters[voterCount].voted = 1;
            strcpy(voters[voterCount].name, voterName);
            voterCount++;
            printf("Thank you for voting for '%s'!\n", candidates[choice - 1].name);
        } else {
            printf("Invalid candidate selection.\n");
        }
    }
}

void viewResults() {
    printf("Election Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Electronic Voting System ===\n");
        printf("1. Add Candidate\n");
        printf("2. Cast Vote\n");
        printf("3. View Results\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                castVote();
                break;
            case 3:
                viewResults();
                break;
            case 4:
                printf("Exiting the voting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    
    return 0;
}