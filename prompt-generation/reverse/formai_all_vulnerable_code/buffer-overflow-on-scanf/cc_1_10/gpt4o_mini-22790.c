//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[100];
    int votes;
} Candidate;

typedef struct {
    char voterId[20];
    int hasVoted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0, totalCandidates = 0, totalVotes = 0;

void addCandidate() {
    if (totalCandidates < MAX_CANDIDATES) {
        printf("Enter candidate name: ");
        scanf(" %[^\n]", candidates[totalCandidates].name);
        candidates[totalCandidates].votes = 0;
        totalCandidates++;
        printf("Candidate added successfully.\n");
    } else {
        printf("Maximum number of candidates reached.\n");
    }
}

void registerVoter() {
    if (totalVoters < MAX_VOTERS) {
        printf("Enter voter ID: ");
        scanf(" %[^\n]", voters[totalVoters].voterId);
        voters[totalVoters].hasVoted = 0;
        totalVoters++;
        printf("Voter registered successfully.\n");
    } else {
        printf("Maximum number of voters reached.\n");
    }
}

void displayCandidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void castVote() {
    char voterId[20];
    printf("Enter your voter ID: ");
    scanf(" %[^\n]", voterId);

    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].voterId, voterId) == 0) {
            if (voters[i].hasVoted) {
                printf("You have already voted.\n");
                return;
            }

            displayCandidates();
            int vote;
            printf("Select candidate number to vote: ");
            scanf("%d", &vote);

            if (vote > 0 && vote <= totalCandidates) {
                candidates[vote - 1].votes++;
                voters[i].hasVoted = 1;
                totalVotes++;
                printf("Vote cast successfully for %s.\n", candidates[vote - 1].name);
                return;
            } else {
                printf("Invalid candidate number.\n");
                return;
            }
        }
    }
    printf("Voter ID not found. Please register.\n");
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s received %d votes (%.2f%%)\n", 
               candidates[i].name, 
               candidates[i].votes, 
               (totalVotes > 0) ? (candidates[i].votes * 100.0 / totalVotes) : 0);
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Select an option: ");
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
                printf("Exiting the system. Thank you for using the Electronic Voting System.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    printf("Welcome to the Electronic Voting System.\n");
    menu();
    return 0;
}