//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char name[50];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;
int totalCandidates = 0;

void registerCandidate() {
    if (totalCandidates < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[totalCandidates].name);
        candidates[totalCandidates].votes = 0;
        totalCandidates++;
        printf("Candidate '%s' registered successfully!\n", candidates[totalCandidates - 1].name);
    } else {
        printf("Candidate limit reached! Can't register more candidates.\n");
    }
}

void registerVoter() {
    if (totalVoters < MAX_VOTERS) {
        printf("Enter voter name: ");
        scanf("%s", voters[totalVoters].name);
        voters[totalVoters].hasVoted = 0;
        totalVoters++;
        printf("Voter '%s' registered successfully!\n", voters[totalVoters - 1].name);
    } else {
        printf("Voter limit reached! Can't register more voters.\n");
    }
}

void castVote() {
    char voterName[50];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);
    
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted, %s!\n", voterName);
                return;
            }
            voters[i].hasVoted = 1;

            printf("Candidates:\n");
            for (int j = 0; j < totalCandidates; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            int choice;
            printf("Enter candidate number to vote: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > totalCandidates) {
                printf("Invalid choice. Vote not counted.\n");
                return;
            }
            candidates[choice - 1].votes++;
            printf("Vote casted successfully for '%s'!\n", candidates[choice - 1].name);
            return;
        }
    }
    printf("Voter not found! Please register first.\n");
}

void viewResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("\n--- Electronic Voting System Menu ---\n");
    printf("1. Register Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. View Results\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;
    
    while (1) {
        displayMenu();
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                registerCandidate();
                break;
            case 2:
                registerVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                viewResults();
                break;
            case 5:
                printf("Exiting the Voting System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}