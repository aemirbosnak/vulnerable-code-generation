//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store voter information
typedef struct Voter {
    char name[50];
    int rollNo;
    char voteCast;
} Voter;

// Function to add a voter to the system
void addVoter(Voter *voter) {
    printf("Enter voter's name: ");
    scanf("%s", voter->name);

    printf("Enter voter's roll number: ");
    scanf("%d", &voter->rollNo);

    printf("Enter voter's vote cast: ");
    scanf(" %c", &voter->voteCast);
}

// Function to display the list of voters
void displayVoters(Voter *voter) {
    for (int i = 0; voter[i].name[0] != '\0'; i++) {
        printf("%s (%d) - Vote cast: %c\n", voter[i].name, voter[i].rollNo, voter[i].voteCast);
    }
}

// Function to conduct an election
void conductElection(Voter *voter) {
    printf("Enter the candidate's name: ");
    char candidateName[50];
    scanf("%s", candidateName);

    int totalVotes = 0;
    for (int i = 0; voter[i].name[0] != '\0'; i++) {
        if (voter[i].voteCast == candidateName[0]) {
            totalVotes++;
        }
    }

    printf("Total votes for %s: %d\n", candidateName, totalVotes);
}

int main() {
    // Create a voter structure
    Voter voter;

    // Add voters to the system
    addVoter(&voter);
    addVoter(&voter);
    addVoter(&voter);

    // Display the list of voters
    displayVoters(&voter);

    // Conduct an election
    conductElection(&voter);

    return 0;
}