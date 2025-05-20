//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTES 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

void displayCandidates(Candidate candidates[], int num) {
    printf("Candidates:\n");
    for (int i = 0; i < num; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

int castVote(Candidate candidates[], int num) {
    int choice;
    printf("Enter the candidate number to vote (1-%d): ", num);
    scanf("%d", &choice);
    
    if(choice < 1 || choice > num) {
        printf("Invalid choice. Vote not cast.\n");
        return -1;
    }

    candidates[choice - 1].votes++;
    printf("Vote cast for %s.\n", candidates[choice - 1].name);
    return 0;
}

void displayResults(Candidate candidates[], int num) {
    printf("\nElection Results:\n");
    for (int i = 0; i < num; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    int winnerIndex = 0;
    for (int i = 1; i < num; i++) {
        if (candidates[i].votes > candidates[winnerIndex].votes) {
            winnerIndex = i;
        }
    }
    
    printf("Winner: %s with %d votes!\n", candidates[winnerIndex].name, candidates[winnerIndex].votes);
}

int main() {
    Candidate candidates[MAX_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"Diana", 0},
        {"Evan", 0}
    };
    
    int maxVotes = MAX_VOTES;
    int votesCast = 0;
    char continueVoting;

    printf("Welcome to the Electronic Voting System\n");

    while (votesCast < maxVotes) {
        displayCandidates(candidates, MAX_CANDIDATES);
        
        if (castVote(candidates, MAX_CANDIDATES) == 0) {
            votesCast++;
        }
        
        if (votesCast < maxVotes) {
            printf("Do you want to cast another vote? (y/n): ");
            scanf(" %c", &continueVoting);
            if (continueVoting != 'y' && continueVoting != 'Y') {
                break;
            }
        }
    }

    displayResults(candidates, MAX_CANDIDATES);
    printf("Thank you for participating in the election!\n");
    
    return 0;
}