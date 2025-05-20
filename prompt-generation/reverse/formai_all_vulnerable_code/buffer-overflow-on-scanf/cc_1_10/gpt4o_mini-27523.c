//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: statistical
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
    int voted; // 1 if voted, 0 if not
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

int candidate_count = 0;
int voter_count = 0;

void displayCandidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void registerCandidate() {
    if (candidate_count >= MAX_CANDIDATES) {
        printf("Maximum candidate limit reached.\n");
        return;
    }
    
    printf("Enter the name of the candidate: ");
    scanf("%s", candidates[candidate_count].name);
    candidates[candidate_count].votes = 0;
    candidate_count++;
    printf("Candidate %s registered successfully!\n", candidates[candidate_count - 1].name);
}

void registerVoter() {
    if (voter_count >= MAX_VOTERS) {
        printf("Maximum voter limit reached.\n");
        return;
    }

    printf("Enter the name of the voter: ");
    scanf("%s", voters[voter_count].name);
    voters[voter_count].voted = 0;
    voter_count++;
    printf("Voter %s registered successfully!\n", voters[voter_count - 1].name);
}

void castVote() {
    char voterName[50];
    printf("Enter the name of the voter: ");
    scanf("%s", voterName);

    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            if (voters[i].voted) {
                printf("Voter %s has already voted.\n", voterName);
                return;
            }

            displayCandidates();
            int choice;
            printf("Enter the candidate number you want to vote for: ");
            scanf("%d", &choice);

            if (choice < 1 || choice > candidate_count) {
                printf("Invalid candidate number.\n");
                return;
            }

            candidates[choice - 1].votes++;
            voters[i].voted = 1;
            printf("Vote casted for %s successfully!\n", candidates[choice - 1].name);
            return;
        }
    }
    printf("Voter %s not found!\n", voterName);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayStatistics() {
    int totalVotes = 0;
    for (int i = 0; i < candidate_count; i++) {
        totalVotes += candidates[i].votes;
    }

    printf("\nStatistical Summary:\n");
    printf("Total Votes: %d\n", totalVotes);
    printf("Total Voters Registered: %d\n", voter_count);
    printf("Vote Distribution:\n");
    for (int i = 0; i < candidate_count; i++) {
        if (totalVotes > 0) {
            double percentage = (double)candidates[i].votes / totalVotes * 100;
            printf("%s: %.2f%% of total votes\n", candidates[i].name, percentage);
        } else {
            printf("%s: 0%% of total votes\n", candidates[i].name);
        }
    }
}

int main() {
    int choice;

    do {
        printf("\n=== Electronic Voting System ===\n");
        printf("1. Register Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Display Statistics\n");
        printf("6. Exit\n");
        printf("Select an action: ");
        scanf("%d", &choice);

        switch (choice) {
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
                displayStatistics();
                break;
            case 6:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}