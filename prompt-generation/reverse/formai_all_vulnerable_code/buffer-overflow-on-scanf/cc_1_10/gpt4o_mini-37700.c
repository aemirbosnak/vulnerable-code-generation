//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold candidate information
typedef struct {
    int id;
    char name[50];
    int voteCount;
} Candidate;

// Function declarations
void displayCandidates(Candidate candidates[], int totalCandidates);
void castVote(Candidate candidates[], int totalCandidates);
void displayResults(Candidate candidates[], int totalCandidates);

int main() {
    // Welcome message
    printf("🎉 Welcome to the Electronic Voting System! 🎉\n\n");

    // Define candidates
    int totalCandidates = 3;
    Candidate candidates[3] = {
        {1, "Alice Johnson", 0},
        {2, "Bob Smith", 0},
        {3, "Charlie Brown", 0},
    };

    int choice;

    do {
        printf("Please select an option:\n");
        printf("1. Display Candidates\n");
        printf("2. Cast Your Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayCandidates(candidates, totalCandidates);
                break;
            case 2:
                castVote(candidates, totalCandidates);
                break;
            case 3:
                displayResults(candidates, totalCandidates);
                break;
            case 4:
                printf("🚀 Thank you for using the Electronic Voting System! Goodbye! 🚀\n");
                break;
            default:
                printf("❌ Invalid choice! Please try again. ❌\n");
        }
    } while (choice != 4);

    return 0;
}

void displayCandidates(Candidate candidates[], int totalCandidates) {
    printf("\n📜 List of Candidates 📜\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("ID: %d, Name: %s\n", candidates[i].id, candidates[i].name);
    }
    printf("\n");
}

void castVote(Candidate candidates[], int totalCandidates) {
    int voteId;
    printf("Enter the ID of the candidate you want to vote for: ");
    scanf("%d", &voteId);

    if (voteId < 1 || voteId > totalCandidates) {
        printf("❌ Invalid candidate ID! Please try again. ❌\n\n");
    } else {
        candidates[voteId - 1].voteCount++;
        printf("✅ Your vote for %s has been cast successfully! ✅\n\n", candidates[voteId - 1].name);
    }
}

void displayResults(Candidate candidates[], int totalCandidates) {
    printf("\n📊 Voting Results 📊\n");
    for (int i = 0; i < totalCandidates; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].voteCount);
    }

    // Determine winner
    int maxVotes = -1;
    char winner[50];
    for (int i = 0; i < totalCandidates; i++) {
        if (candidates[i].voteCount > maxVotes) {
            maxVotes = candidates[i].voteCount;
            strcpy(winner, candidates[i].name);
        }
    }

    printf("\n🏆 The winner is: %s with %d votes! 🏆\n\n", winner, maxVotes);
}