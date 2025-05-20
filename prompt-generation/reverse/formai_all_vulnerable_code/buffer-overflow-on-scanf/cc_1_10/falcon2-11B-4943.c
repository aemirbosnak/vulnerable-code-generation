//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define candidate names and votes
    char candidates[3][20] = {"Candidate A", "Candidate B", "Candidate C"};
    int votes[3] = {0, 0, 0};

    // Prompt user to vote
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select a candidate:\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");
    printf("Enter your selection: ");

    // Read user input and increment votes
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        votes[0]++;
    } else if (choice == 2) {
        votes[1]++;
    } else if (choice == 3) {
        votes[2]++;
    } else {
        printf("Invalid choice. Please try again.\n");
        return 1;
    }

    // Print results
    printf("\nResults:\n");
    printf("Candidate A: %d votes\n", votes[0]);
    printf("Candidate B: %d votes\n", votes[1]);
    printf("Candidate C: %d votes\n", votes[2]);

    // Determine winner
    int max_votes = votes[0];
    int winner_index = 0;
    for (int i = 1; i < 3; i++) {
        if (votes[i] > max_votes) {
            max_votes = votes[i];
            winner_index = i;
        }
    }

    printf("Congratulations! %s is the winner!\n", candidates[winner_index]);

    return 0;
}