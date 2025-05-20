//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to clear the screen
void clearScreen() {
    system("clear");
}

// function to display the voting options
void displayOptions() {
    printf("VOTING OPTIONS:\n");
    printf("1. Candidate 1\n");
    printf("2. Candidate 2\n");
    printf("3. Candidate 3\n");
    printf("4. NOTA (None of the above)\n");
    printf("\n");
}

// function to cast a vote
void castVote(int candidateVotes[], int candidateNumber) {
    candidateVotes[candidateNumber - 1]++;
    printf("Your vote has been cast!\n");
}

// function to display the results
void displayResults(int candidateVotes[]) {
    printf("VOTING RESULTS:\n");
    printf("Candidate 1: %d votes\n", candidateVotes[0]);
    printf("Candidate 2: %d votes\n", candidateVotes[1]);
    printf("Candidate 3: %d votes\n", candidateVotes[2]);
    printf("Total Votes: %d\n", candidateVotes[0] + candidateVotes[1] + candidateVotes[2]);
    printf("\n");
}

int main() {
    // initialize candidate vote counts to zero
    int candidateVotes[3] = {0, 0, 0};

    // loop until user chooses to exit
    int choice = 0;
    while (choice != 4) {
        clearScreen();
        displayOptions();

        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // cast the vote based on user's choice
        switch (choice) {
            case 1:
                castVote(candidateVotes, 1);
                break;
            case 2:
                castVote(candidateVotes, 2);
                break;
            case 3:
                castVote(candidateVotes, 3);
                break;
            case 4:
                // exit the loop
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    // display the final results
    clearScreen();
    displayResults(candidateVotes);

    return 0;
}