//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a voter
typedef struct {
    char name[100];
    char voting_option[20];
} Voter;

// Function to print out the voting options
void print_options(const char* options) {
    printf("Voting options:\n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. None of the above\n");
    printf("Enter your option: ");
}

// Function to cast a vote
int cast_vote(Voter* voter) {
    int option;
    printf("Enter your option: ");
    scanf("%d", &option);
    if (option == 1) {
        strcpy(voter->voting_option, "Candidate A");
        return 1;
    } else if (option == 2) {
        strcpy(voter->voting_option, "Candidate B");
        return 2;
    } else if (option == 3) {
        strcpy(voter->voting_option, "None of the above");
        return 3;
    } else {
        printf("Invalid option\n");
        return -1;
    }
}

// Function to validate a voter
int validate_voter(Voter* voter) {
    // Check if the voter is already registered
    if (strlen(voter->name) == 0) {
        printf("Invalid voter\n");
        return -1;
    }
    // Check if the voter has already voted
    if (strlen(voter->voting_option) > 0) {
        printf("Voter has already voted\n");
        return -1;
    }
    // Otherwise, the voter is valid
    return 1;
}

// Main function
int main() {
    // Create an array of voters
    Voter voters[5];
    int num_voters = 5;
    int i;

    // Initialize the voters
    for (i = 0; i < num_voters; i++) {
        strcpy(voters[i].name, "");
        strcpy(voters[i].voting_option, "");
    }

    // Print the voting options
    printf("Voting system\n");
    print_options("1. Candidate A\n2. Candidate B\n3. None of the above");

    // Loop through the voters and cast their votes
    for (i = 0; i < num_voters; i++) {
        // Validate the voter
        if (validate_voter(&voters[i])) {
            // Cast the vote
            int vote = cast_vote(&voters[i]);
            if (vote == 1) {
                printf("Voted for Candidate A\n");
            } else if (vote == 2) {
                printf("Voted for Candidate B\n");
            } else if (vote == 3) {
                printf("Voted for None of the above\n");
            }
        }
    }

    return 0;
}