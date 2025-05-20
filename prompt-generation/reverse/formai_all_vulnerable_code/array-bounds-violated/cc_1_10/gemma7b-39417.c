//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the voter structure
typedef struct Voter {
    char name[50];
    int vote;
} Voter;

// Create an array of voters
Voter voters[MAX_VOTERS];

// Function to read the voter's name and vote
void read_voter_info(int voter_id) {
    printf("Enter your name: ");
    scanf("%s", voters[voter_id].name);

    printf("Enter your vote: ");
    scanf("%d", &voters[voter_id].vote);
}

// Function to validate the voter's vote
int validate_vote(int vote) {
    if (vote < 1 || vote > 5) {
        return 0;
    } else {
        return 1;
    }
}

// Function to cast a vote
void cast_vote(int voter_id) {
    if (validate_vote(voters[voter_id].vote) == 1) {
        printf("Your vote has been cast.\n");
    } else {
        printf("Invalid vote.\n");
    }
}

int main() {
    int i, voter_id;

    // Initialize the voters
    for (i = 0; i < MAX_VOTERS; i++) {
        voters[i].vote = 0;
    }

    // Read the voter's information and cast a vote
    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);

    read_voter_info(voter_id);
    cast_vote(voter_id);

    return 0;
}