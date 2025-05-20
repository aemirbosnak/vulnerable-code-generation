//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of candidates and the maximum number of voters
#define NUM_CANDIDATES 5
#define MAX_VOTERS 100

// Define the structure for a voter
typedef struct {
    char name[20];
    int age;
    char gender;
    char candidate[20];
} Voter;

// Define the structure for a candidate
typedef struct {
    char name[20];
    int votes;
} Candidate;

// Define the function to add a voter to the system
void addVoter(Voter *voter, Candidate *candidates) {
    // Prompt the user for the voter's information
    printf("Enter the voter's name: ");
    scanf("%s", voter->name);
    printf("Enter the voter's age: ");
    scanf("%d", &voter->age);
    printf("Enter the voter's gender (M/F): ");
    scanf(" %c", &voter->gender);
    printf("Enter the voter's candidate: ");
    scanf("%s", voter->candidate);

    // Check if the candidate is valid
    int i;
    for (i = 0; i < NUM_CANDIDATES; i++) {
        if (strcmp(voter->candidate, candidates[i].name) == 0) {
            // Increment the candidate's vote count
            candidates[i].votes++;
            break;
        }
    }

    // If the candidate is not valid, print an error message
    if (i == NUM_CANDIDATES) {
        printf("Invalid candidate\n");
    }
}

// Define the function to display the results
void displayResults(Candidate *candidates) {
    // Print the results for each candidate
    int i;
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    // Declare an array of voters
    Voter voters[MAX_VOTERS];

    // Declare an array of candidates
    Candidate candidates[NUM_CANDIDATES] = {
        {"Alice", 0},
        {"Bob", 0},
        {"Charlie", 0},
        {"David", 0},
        {"Eve", 0}
    };

    // Add voters to the system
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        addVoter(&voters[i], candidates);
    }

    // Display the results
    displayResults(candidates);

    return 0;
}