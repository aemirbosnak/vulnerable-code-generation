//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: modular
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
    int hasVoted; // 0 for no vote, 1 for voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidateCount = 0;
int voterCount = 0;

void initializeCandidates() {
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &candidateCount);
    getchar(); // Consume newline

    for (int i = 0; i < candidateCount; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = '\0'; // Remove newline
        candidates[i].votes = 0;
    }
}

void initializeVoters() {
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &voterCount);
    getchar(); // Consume newline

    for (int i = 0; i < voterCount; i++) {
        printf("Enter name of voter %d: ", i + 1);
        fgets(voters[i].name, sizeof(voters[i].name), stdin);
        voters[i].name[strcspn(voters[i].name, "\n")] = '\0'; // Remove newline
        voters[i].hasVoted = 0;
    }
}

void castVote(int voterIndex) {
    printf("Voter %s, please cast your vote:\n", voters[voterIndex].name);
    for (int i = 0; i < candidateCount; i++) {
        printf("%d: %s\n", i + 1, candidates[i].name);
    }

    int vote;
    printf("Enter the candidate number you wish to vote for: ");
    scanf("%d", &vote);
    if (vote > 0 && vote <= candidateCount) {
        candidates[vote - 1].votes++;
        voters[voterIndex].hasVoted = 1;
        printf("Vote casted successfully for %s.\n", candidates[vote - 1].name);
    } else {
        printf("Invalid candidate number.\n");
    }
}

void displayResults() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s - Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void displayVoterStatus() {
    printf("\nVoter Status:\n");
    for (int i = 0; i < voterCount; i++) {
        printf("%s - ", voters[i].name);
        if (voters[i].hasVoted) {
            printf("Voter has already voted.\n");
        } else {
            printf("Voter has not voted yet.\n");
        }
    }
}

int main() {
    int choice;
    initializeCandidates();
    initializeVoters();

    do {
        printf("\nElectronic Voting System\n");
        printf("1. Cast Vote\n");
        printf("2. View Results\n");
        printf("3. View Voter Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                for (int i = 0; i < voterCount; i++) {
                    if (!voters[i].hasVoted) {
                        castVote(i);
                    } else {
                        printf("Voter %s has already voted.\n", voters[i].name);
                    }
                }
                break;
            }
            case 2:
                displayResults();
                break;
            case 3:
                displayVoterStatus();
                break;
            case 4:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 4);

    return 0;
}