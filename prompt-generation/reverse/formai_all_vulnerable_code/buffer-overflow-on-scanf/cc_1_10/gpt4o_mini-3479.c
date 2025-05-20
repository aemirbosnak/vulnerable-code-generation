//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int candidateCount) {
    printf("Available candidates:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void vote(Candidate candidates[], int candidateCount) {
    int choice;
    printf("Enter the number of the candidate you want to vote for (1-%d): ", candidateCount);
    scanf("%d", &choice);

    if (choice < 1 || choice > candidateCount) {
        printf("Invalid choice! Please try again.\n");
    } else {
        candidates[choice - 1].votes++;
        printf("Thank you for voting for %s!\n", candidates[choice - 1].name);
    }
}

void displayResults(Candidate candidates[], int candidateCount) {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void resetVotes(Candidate candidates[], int candidateCount) {
    for (int i = 0; i < candidateCount; i++) {
        candidates[i].votes = 0;
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice Johnson", 0},
        {"Bob Smith", 0},
        {"Charlie Brown", 0},
        {"Diana Prince", 0},
        {"Edward Green", 0}
    };
    int candidateCount = 5;
    int choice;

    do {
        printf("\nWelcome to the Electronic Voting System!\n");
        printf("1. Vote\n");
        printf("2. Display Results\n");
        printf("3. Reset Votes\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayCandidates(candidates, candidateCount);
                vote(candidates, candidateCount);
                break;
            case 2:
                displayResults(candidates, candidateCount);
                break;
            case 3:
                resetVotes(candidates, candidateCount);
                printf("All votes have been reset.\n");
                break;
            case 4:
                printf("Thank you for using the Electronic Voting System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }

        sleep(1); // Sleep for 1 second before clearing the screen
        system("clear");

    } while (choice != 4);

    return 0;
}