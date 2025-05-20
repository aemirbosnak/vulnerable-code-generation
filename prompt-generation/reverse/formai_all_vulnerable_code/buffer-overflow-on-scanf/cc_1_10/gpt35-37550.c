//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Array to store party names
char parties[10][20];

// Array to store vote counts
int votes[10] = {0};

// Function to display the available parties
void displayParties(int n) {
    printf("Available parties:\n");
    for(int i = 0; i < n; i++) {
        printf("%d. %s\n", i+1, parties[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, voter_id;
    char name[20];

    printf("Enter the number of parties: ");
    scanf("%d", &n);

    // Get party names from the user
    printf("Enter party names:\n");
    for(int i = 0; i < n; i++) {
        printf("%d. ", i+1);
        scanf("%s", parties[i]);
    }

    // Display the list of parties
    displayParties(n);

    // Get voter details
    printf("Enter Voter ID: ");
    scanf("%d", &voter_id);

    printf("Enter your name: ");
    scanf("%s", name);

    // Check if the voter has already voted
    char filename[20];
    sprintf(filename, "%d.txt", voter_id);
    FILE *file = fopen(filename, "r");
    if(file) {
        printf("\nYou have already voted!\n");
        fclose(file);
        return 0;
    }

    // Display the list of parties and get the user's vote
    displayParties(n);
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // If the choice is valid, update the vote count and save the vote
    if(choice > 0 && choice <= n) {
        votes[choice-1]++;
        printf("\nThanks for voting!\n");

        // Save the vote in a file
        file = fopen(filename, "w");
        fprintf(file, "Name: %s\nVoted for: %s\n", name, parties[choice-1]);
        fclose(file);
    } else {
        printf("\nInvalid choice!\n");
    }

    // Display the final vote count
    printf("\nFinal vote count:\n");
    for(int i = 0; i < n; i++) {
        printf("%s: %d\n", parties[i], votes[i]);
    }

    return 0;
}