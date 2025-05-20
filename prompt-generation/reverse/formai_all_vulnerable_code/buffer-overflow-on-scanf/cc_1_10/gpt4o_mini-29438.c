//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void initializeCandidates(Candidate candidates[]) {
    strcpy(candidates[0].name, "Alice");
    strcpy(candidates[1].name, "Bob");
    strcpy(candidates[2].name, "Charlie");
    strcpy(candidates[3].name, "Diana");
    strcpy(candidates[4].name, "Ethan");

    for (int i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].votes = 0;
    }
}

void displayCandidates(Candidate candidates[]) {
    printf("\n== Candidates ==\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("=================\n");
}

void castVote(Candidate candidates[]) {
    int choice;
    printf("Enter the number of the candidate you want to vote for (1-%d): ", MAX_CANDIDATES);
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_CANDIDATES) {
        printf("Oops! That's not a valid choice. Please try again.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Yay! Your vote for %s has been recorded! 🗳\n", candidates[choice - 1].name);
    }
}

void displayResults(Candidate candidates[]) {
    printf("\n== Voting Results ==\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("=====================\n");
}

void findWinner(Candidate candidates[]) {
    int maxVotes = -1;
    char winner[MAX_NAME_LENGTH];
    
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            strcpy(winner, candidates[i].name);
        }
    }
    
    printf("🎉 The winner is %s with %d votes! 🎉\n", winner, maxVotes);
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int option;
    
    printf("Welcome to the Happy Electronic Voting System! 🎉\n\n");

    initializeCandidates(candidates);

    do {
        printf("\nMenu:\n");
        printf("1. Display Candidates\n");
        printf("2. Cast a Vote\n");
        printf("3. Display Results\n");
        printf("4. Find Winner\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayCandidates(candidates);
                break;
            case 2:
                castVote(candidates);
                break;
            case 3:
                displayResults(candidates);
                break;
            case 4:
                findWinner(candidates);
                break;
            case 5:
                printf("Thank you for participating! Goodbye! 😊\n");
                break;
            default:
                printf("Invalid option! Please choose again. 🥹\n");
        }
    } while (option != 5);

    return 0;
}