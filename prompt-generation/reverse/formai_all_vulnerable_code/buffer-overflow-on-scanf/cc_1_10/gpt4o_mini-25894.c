//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct {
    char name[50];
    int voteCount;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int totalVotes = 0;

void initializeCandidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // Remove newline
        candidates[i].voteCount = 0;
    }
}

void castVote() {
    int choice;
    printf("Vote for your candidate (1 to %d): ", MAX_CANDIDATES);
    scanf("%d", &choice);
    if (choice >= 1 && choice <= MAX_CANDIDATES) {
        candidates[choice - 1].voteCount++;
        totalVotes++;
        printf("Vote casted successfully for %s!\n", candidates[choice - 1].name);
    } else {
        printf("Invalid choice. Please try again.\n");
        castVote();
    }
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes (%.2f%%)\n", 
            candidates[i].name, 
            candidates[i].voteCount, 
            (totalVotes ? (candidates[i].voteCount * 100.0 / totalVotes) : 0));
    }
}

void showMenu() {
    printf("\n--- Electronic Voting System ---\n");
    printf("1. Cast a vote\n");
    printf("2. Display results\n");
    printf("3. Exit\n");
}

int main() {
    int choice;
    
    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    int numCandidates;
    scanf("%d", &numCandidates);
    getchar(); // Consume newline

    if (numCandidates > MAX_CANDIDATES || numCandidates <= 0) {
        printf("Invalid number of candidates. Exiting.\n");
        return 1;
    }

    initializeCandidates();

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                castVote();
                break;
            case 2:
                displayResults();
                break;
            case 3:
                printf("Exiting the voting system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}