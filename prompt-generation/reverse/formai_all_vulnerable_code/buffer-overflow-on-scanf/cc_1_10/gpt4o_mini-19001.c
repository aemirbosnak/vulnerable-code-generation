//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
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
    int hasVoted; // 0 for not voted, 1 for voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;

void initializeCandidates() {
    strcpy(candidates[0].name, "Alice");
    candidates[0].votes = 0;

    strcpy(candidates[1].name, "Bob");
    candidates[1].votes = 0;

    strcpy(candidates[2].name, "Charlie");
    candidates[2].votes = 0;

    strcpy(candidates[3].name, "Diana");
    candidates[3].votes = 0;

    strcpy(candidates[4].name, "Edward");
    candidates[4].votes = 0;
}

void displayCandidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote(int voterIndex) {
    int choice;
    
    printf("Enter the candidate number (1 - 5) you wish to vote for: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > MAX_CANDIDATES) {
        printf("Invalid choice! Vote not counted.\n");
        return;
    }

    if (voters[voterIndex].hasVoted) {
        printf("You have already voted!\n");
        return;
    }

    candidates[choice - 1].votes++;
    voters[voterIndex].hasVoted = 1;
    printf("Vote cast successfully for %s!\n", candidates[choice - 1].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

void registerVoter() {
    if (totalVoters >= MAX_VOTERS) {
        printf("Maximum number of voters reached!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", voters[totalVoters].name);
    voters[totalVoters].hasVoted = 0;
    totalVoters++;
    printf("Voter %s registered successfully!\n", voters[totalVoters - 1].name);
}

int main() {
    int option, voterIndex;

    initializeCandidates();

    while (1) {
        printf("\n*** Welcome to the Electronic Voting System ***\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Candidates\n");
        printf("4. Show Results\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                registerVoter();
                break;
            case 2:
                if (totalVoters == 0) {
                    printf("No voters registered yet!\n");
                    break;
                }
                printf("Select your voter index (0 to %d): ", totalVoters - 1);
                scanf("%d", &voterIndex);
                if (voterIndex < 0 || voterIndex >= totalVoters) {
                    printf("Invalid voter index!\n");
                    break;
                }
                castVote(voterIndex);
                break;
            case 3:
                displayCandidates();
                break;
            case 4:
                displayResults();
                break;
            case 5:
                printf("Exiting the voting system. Thank you for participating!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}