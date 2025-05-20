//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 10

// Structure to hold voter details
typedef struct Voter {
    char name[30];
    int choice; // 1 for Montagues, 2 for Capulets
} Voter;

// Function prototypes
void displayChoices();
void castVote(Voter *voter);
void tallyVotes(Voter voters[], int count);
void displayResults(int montagueVotes, int capuletVotes);

// Main function
int main() {
    Voter voters[MAX_VOTERS];
    int voterCount = 0, choice;
    
    printf("Enter the number of voters (upto %d): ", MAX_VOTERS);
    scanf("%d", &voterCount);
    
    if (voterCount > MAX_VOTERS) {
        printf("Too many voters! Limiting to %d.\n", MAX_VOTERS);
        voterCount = MAX_VOTERS;
    }

    printf("Welcome to the Romeo and Juliet Electronic Voting System!\n");
    printf("Choose the destiny of the families: Montagues or Capulets.\n");

    // Loop to collect votes
    for (int i = 0; i < voterCount; i++) {
        printf("\nVoter %d, please enter your name: ", i + 1);
        scanf("%s", voters[i].name);
        castVote(&voters[i]);
    }

    // Tally the votes
    tallyVotes(voters, voterCount);
    
    return 0;
}

// Function to display voting choices
void displayChoices() {
    printf("Choose your allegiance:\n");
    printf("1. Montagues\n");
    printf("2. Capulets\n");
}

// Function to cast a vote
void castVote(Voter *voter) {
    displayChoices();
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &voter->choice);
    
    // Validate the choice
    while (voter->choice != 1 && voter->choice != 2) {
        printf("Invalid choice! Please choose 1 for Montagues or 2 for Capulets: ");
        scanf("%d", &voter->choice);
    }
    printf("%s, your vote for %s has been recorded.\n", 
        voter->name, (voter->choice == 1) ? "Montagues" : "Capulets");
}

// Function to tally the votes
void tallyVotes(Voter voters[], int count) {
    int montagueVotes = 0, capuletVotes = 0;

    for (int i = 0; i < count; i++) {
        if (voters[i].choice == 1) {
            montagueVotes++;
        } else {
            capuletVotes++;
        }
    }

    displayResults(montagueVotes, capuletVotes);
}

// Function to display the results
void displayResults(int montagueVotes, int capuletVotes) {
    printf("\n--- Election Results ---\n");
    printf("Montagues: %d votes\n", montagueVotes);
    printf("Capulets: %d votes\n", capuletVotes);

    if (montagueVotes > capuletVotes) {
        printf("The Montagues have won the heart of Verona!\n");
    } else if (capuletVotes > montagueVotes) {
        printf("The Capulets reign supreme in Verona!\n");
    } else {
        printf("A tragic tie... Both families shall share the night.\n");
    }

    printf("May love and peace prevail in Verona!\n");
}