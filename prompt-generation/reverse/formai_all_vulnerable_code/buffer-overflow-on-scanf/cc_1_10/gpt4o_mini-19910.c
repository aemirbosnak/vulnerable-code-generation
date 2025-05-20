//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
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
    int voted; // 0 - Not Voted, 1 - Voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int numCandidates = 0;
int numVoters = 0;

void addCandidate() {
    if (numCandidates >= MAX_CANDIDATES) {
        printf("Cannot add more candidates.\n");
        return;
    }
    printf("Enter name for candidate %d: ", numCandidates + 1);
    scanf("%s", candidates[numCandidates].name);
    candidates[numCandidates].votes = 0;
    numCandidates++;
}

void registerVoter() {
    if (numVoters >= MAX_VOTERS) {
        printf("Cannot register more voters.\n");
        return;
    }
    printf("Enter name for voter %d: ", numVoters + 1);
    scanf("%s", voters[numVoters].name);
    voters[numVoters].voted = 0; // Not yet voted
    numVoters++;
}

void castVote() {
    char voterName[50];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);
    
    for (int i = 0; i < numVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].voted) {
                printf("You have already voted!\n");
                return;
            }
            voters[i].voted = 1; // Mark as voted

            printf("Vote for: \n");
            for (int j = 0; j < numCandidates; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }
            int choice;
            printf("Enter candidate number: ");
            scanf("%d", &choice);
            
            if (choice > 0 && choice <= numCandidates) {
                candidates[choice - 1].votes++;
                printf("Vote cast successfully for %s!\n", candidates[choice - 1].name);
            } else {
                printf("Invalid candidate number!\n");
            }
            return;
        }
    }
    printf("Voter not registered!\n");
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void menu() {
    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                registerVoter();
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Electronic Voting System!\n");
    menu();
    return 0;
}