//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 50
#define MAX_VOTERS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    int id;
    int voted; // 0 for no, 1 for yes
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void addCandidate() {
    if (candidateCount >= MAX_CANDIDATES) {
        printf("Maximum candidates reached!\n");
        return;
    }
    
    printf("Enter candidate's name: ");
    scanf("%s", candidates[candidateCount].name);
    candidates[candidateCount].votes = 0; // initialize votes to 0
    candidateCount++;
    printf("Candidate %s added successfully!\n", candidates[candidateCount - 1].name);
}

void castVote() {
    int voterId;
    printf("Enter voter ID (1-%d): ", voterCount + 1);
    scanf("%d", &voterId);
    
    if (voterId < 1 || voterId > voterCount) {
        printf("Invalid voter ID!\n");
        return;
    }

    if (voters[voterId - 1].voted) {
        printf("Voter ID %d has already voted!\n", voterId);
        return;
    }

    printf("Available Candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    
    int candidateId;
    printf("Enter the candidate number you wish to vote for: ");
    scanf("%d", &candidateId);
    
    if (candidateId < 1 || candidateId > candidateCount) {
        printf("Invalid candidate number!\n");
        return;
    }

    candidates[candidateId - 1].votes++;
    voters[voterId - 1].voted = 1; // mark the voter as having voted
    printf("Thank you! Your vote for %s has been counted.\n", candidates[candidateId - 1].name);
}

void registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        printf("Maximum number of voters registered!\n");
        return;
    }
    
    voters[voterCount].id = voterCount + 1;
    voters[voterCount].voted = 0; // initialize to not voted
    voterCount++;
    printf("Voter registered successfully! Your voter ID is %d.\n", voters[voterCount - 1].id);
}

void showResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    printf("Welcome to the Electronic Voting System! 🎉\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("Please select an option (1-5): ");
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
                showResults();
                break;
            case 5:
                printf("Exiting the system. Goodbye! 💼\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}