//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 3

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
int numCandidates = 0;
int numVoters = 0;

void registerCandidate() {
    if(numCandidates < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[numCandidates].name);
        candidates[numCandidates].votes = 0;
        numCandidates++;
        printf("Candidate registered successfully!\n");
    } else {
        printf("Maximum number of candidates reached.\n");
    }
}

void registerVoter() {
    if(numVoters < MAX_VOTERS) {
        printf("Enter voter name: ");
        scanf("%s", voters[numVoters].name);
        voters[numVoters].hasVoted = 0;
        numVoters++;
        printf("Voter registered successfully!\n");
    } else {
        printf("Maximum number of voters reached.\n");
    }
}

void castVote() {
    char voterName[50];
    printf("Enter your name to vote: ");
    scanf("%s", voterName);

    for(int i = 0; i < numVoters; i++) {
        if(strcmp(voters[i].name, voterName) == 0) {
            if(voters[i].hasVoted) {
                printf("Error: You have already voted!\n");
                return;
            } else {
                printf("Available candidates:\n");
                for(int j = 0; j < numCandidates; j++) {
                    printf("%d. %s\n", j + 1, candidates[j].name);
                }
                int choice;
                printf("Select candidate number to vote: ");
                scanf("%d", &choice);
                if(choice > 0 && choice <= numCandidates) {
                    candidates[choice - 1].votes++;
                    voters[i].hasVoted = 1;
                    printf("Thank you for voting!\n");
                } else {
                    printf("Invalid candidate number.\n");
                }
                return;
            }
        }
    }
    printf("Error: Voter not registered.\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int option;

    while(1) {
        printf("\nElectronic Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option) {
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
                displayResults();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
    
    return 0;
}