//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
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
int totalCandidates = 0;
int totalVoters = 0;

void initializeCandidates() {
    printf("Welcome to the Fun Electronic Voting System!\n");
    printf("Let's add some candidates!\n");

    // Adding candidates
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
        totalCandidates++;
    }
    
    printf("\nYay! You have successfully added %d candidates!\n", totalCandidates);
}

void castVote() {
    char voterName[50];
    
    if (totalVoters >= MAX_VOTERS) {
        printf("Sorry! We can't accept more voters. Maximum limit reached.\n");
        return;
    }

    printf("Enter your name (Voter): ");
    scanf("%s", voterName);

    // Check if the voter has already voted
    for (int i = 0; i < totalVoters; i++) {
        if (strcmp(voters[i].name, voterName) == 0) {
            printf("Oops! You've already voted, %s!\n", voterName);
            return;
        }
    }

    // Add the voter to the list
    strcpy(voters[totalVoters].name, voterName);
    voters[totalVoters].voted = 1;
    totalVoters++;

    int candidateChoice;
    printf("Choose a candidate to vote for (1 to %d):\n", totalCandidates);
    for (int i = 0; i < totalCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("Enter choice (1 to %d): ", totalCandidates);
    scanf("%d", &candidateChoice);

    if (candidateChoice < 1 || candidateChoice > totalCandidates) {
        printf("Invalid choice! Vote not counted!\n");
        return;
    }

    candidates[candidateChoice - 1].votes++;
    printf("Thank you for voting, %s! Your vote for %s has been counted!\n", voterName, candidates[candidateChoice - 1].name);
}

void showResults() {
    printf("\n🎉 Voting Results 🎉\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void printMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Add Candidates\n");
    printf("2. Cast Vote\n");
    printf("3. Show Results\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    initializeCandidates();

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Oops! Candidates are already added! Go on and vote!\n");
                break;
            case 2:
                castVote();
                break;
            case 3:
                showResults();
                break;
            case 4:
                printf("Thank you for using the Fun Electronic Voting System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }

    return 0;
}