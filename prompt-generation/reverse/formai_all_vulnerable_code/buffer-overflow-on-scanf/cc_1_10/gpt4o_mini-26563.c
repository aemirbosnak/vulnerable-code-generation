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
    int id;
    int voted; // 0: not voted, 1: voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int totalVoters = 0;
int totalCandidates = 0;

void initializeCandidates() {
    // Let's happily welcoming candidates!
    printf("🎉 Welcome to the Electronic Voting System! 🎉\n");
    printf("Please enter the names of the candidates:\n");
    
    while (totalCandidates < MAX_CANDIDATES) {
        printf("Candidate %d Name: ", totalCandidates + 1);
        scanf("%s", candidates[totalCandidates].name);
        candidates[totalCandidates].votes = 0;
        totalCandidates++;
        
        char choice;
        printf("Do you want to add another candidate? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') {
            break;
        }
    }
}

void registerVoters() {
    printf("\nNow, let's register the voters! 😊\n");
    
    while (totalVoters < MAX_VOTERS) {
        int id;
        printf("Enter Voter ID (unique number): ");
        scanf("%d", &id);
        
        int found = 0;
        for (int i = 0; i < totalVoters; i++) {
            if (voters[i].id == id) {
                printf("🚫 Voter ID already exists! Please enter a unique ID.\n");
                found = 1;
                break;
            }
        }

        if (!found) {
            voters[totalVoters].id = id;
            voters[totalVoters].voted = 0; // Not voted yet
            totalVoters++;
        }

        char choice;
        printf("Do you want to register another voter? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') {
            break;
        }
    }
}

void castVote() {
    printf("\n🗳️ Time to cast your vote! 🎊\n");
    
    for (int i = 0; i < totalVoters; i++) {
        if (voters[i].voted == 0) { // Check if not voted
            int vote;
            printf("Voter ID %d, please cast your vote (1-%d): ", voters[i].id, totalCandidates);
            scanf("%d", &vote);
            
            if (vote >= 1 && vote <= totalCandidates) {
                candidates[vote - 1].votes++; // Increment the vote for the candidate
                voters[i].voted = 1; // Mark voter as having voted
                printf("Thank you! Your vote for %s has been counted! 🎉\n", candidates[vote - 1].name);
            } else {
                printf("🚫 Invalid vote! Please vote between 1 and %d.\n", totalCandidates);
            }
        } else {
            printf("Voter ID %d has already voted. Thank you! 🌟\n", voters[i].id);
        }
    }
}

void displayResults() {
    printf("\n🎊 Election Results 🎊\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
    
    int maxVotes = 0;
    int winnerIndex = -1;
    for (int i = 0; i < totalCandidates; i++) {
        if (candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }
    
    if (winnerIndex != -1) {
        printf("🥳 The winner is %s with %d votes! 🎉\n", candidates[winnerIndex].name, maxVotes);
    } else {
        printf("No votes cast! 🤷‍♂️ Better luck next time!\n");
    }
}

int main() {
    initializeCandidates();
    registerVoters();
    castVote();
    displayResults();
    
    printf("\n🎉 Thank you for using the Electronic Voting System! See you next time! 🎉\n");
    return 0;
}