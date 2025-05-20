//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum input length and number of candidates
#define MAX_INPUT_LENGTH 100
#define NUM_CANDIDATES 5

// Function to display the menu and get user input
int getMenuChoice()
{
    int choice;
    
    printf("\nMENU\n");
    printf("1. Register as a voter\n");
    printf("2. Vote for a candidate\n");
    printf("3. Display current vote count\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// Function to register a voter
void registerVoter(int *voters)
{
    int voterID;
    printf("\nEnter your voter ID: ");
    scanf("%d", &voterID);
    
    voters[voterID-1] = 1; // Mark the voter as registered
    printf("You have been registered as a voter.\n");
}

// Function to vote for a candidate
void voteCandidate(int *votes)
{
    int candidateID;
    printf("\nEnter the candidate ID you want to vote for: ");
    scanf("%d", &candidateID);

    votes[candidateID-1]++; // Increase the vote count for the selected candidate
    printf("Your vote has been registered.\n");
}

// Function to display the current vote count
void displayVoteCount(int *votes)
{
    printf("\nCURRENT VOTE COUNT\n");
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        printf("Candidate %d: %d votes\n", i+1, votes[i]);
    }
}

// Main function that runs the program
int main()
{
    int voters[MAX_INPUT_LENGTH];
    int votes[NUM_CANDIDATES];

    // Initialize voters and votes arrays
    memset(voters, 0, sizeof(voters));
    memset(votes, 0, sizeof(votes));

    int choice;
    do {
        choice = getMenuChoice();

        switch (choice) {
            case 1: {
                registerVoter(voters);
                break;
            }
            case 2: {
                voteCandidate(votes);
                break;
            }
            case 3: {
                displayVoteCount(votes);
                break;
            }
            case 4: {
                printf("\nExiting program...\n");
                exit(0);
                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    } while (1);

    return 0;
}