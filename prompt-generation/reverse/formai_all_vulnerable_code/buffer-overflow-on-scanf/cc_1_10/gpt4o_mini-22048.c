//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int count) {
    printf("\n--- Candidates for 'Most Romantic Couple' ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Votes: %d\n", i + 1, candidates[i].name, candidates[i].votes);
    }
    printf("--------------------------------------------\n");
}

int castVote(Candidate candidates[], int count) {
    int choice;
    printf("Enter the number corresponding to your favorite couple: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > count) {
        printf("Oh dear! It seems you've chosen an invalid option. Let your heart guide you to a better choice.\n");
        return -1;  // Invalid choice
    }
    
    candidates[choice - 1].votes++;
    printf("Your vote for %s has been cast! Love is indeed in the air!\n", candidates[choice - 1].name);
    return 0;  // Valid choice
}

void announceWinners(Candidate candidates[], int count) {
    int maxVotes = candidates[0].votes;
    int winners[MAX_CANDIDATES];
    int winnerCount = 0;

    for (int i = 0; i < count; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerCount = 0;
            winners[winnerCount++] = i;
        } else if (candidates[i].votes == maxVotes) {
            winners[winnerCount++] = i;
        }
    }

    printf("\n--- And the Most Romantic Couple(s) are... ---\n");
    for (int i = 0; i < winnerCount; i++) {
        printf("%s\n", candidates[winners[i]].name);
    }
    printf("------------------------------------------\n");
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"Romeo & Juliet", 0},
        {"Jack & Rose", 0},
        {"Elizabeth & Darcy", 0},
        {"Tristan & Isolde", 0},
        {"Winnie & Pooh", 0}
    };

    int totalVotes = 0;

    printf("Welcome to the Electronic Voting for the Most Romantic Couple!\n");
    printf("Each of you will have the chance to imprint love upon these timeless legends.\n");

    while (totalVotes < MAX_VOTES) {
        displayCandidates(candidates, MAX_CANDIDATES);
        if (castVote(candidates, MAX_CANDIDATES) == 0) {
            totalVotes++;
        }

        char continueVoting;
        printf("Would you like to cast another vote? (Y/N): ");
        scanf(" %c", &continueVoting);
        
        if (continueVoting == 'N' || continueVoting == 'n') {
            break;
        }
    }

    printf("\nVoting has concluded. Let the love shine through the numbers!\n");
    announceWinners(candidates, MAX_CANDIDATES);
    
    printf("Thank you for participating in this celebration of love!\n");
    return 0;
}