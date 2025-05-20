//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store voter information
typedef struct voter {
    char name[20];
    int rollno;
    char vote;
} voter;

// Function to read voter information
void readVoterInfo(voter *v)
{
    printf("Enter your name: ");
    scanf("%s", v->name);

    printf("Enter your roll number: ");
    scanf("%d", &v->rollno);

    printf("Enter your vote (Y/N): ");
    scanf("%c", &v->vote);
}

// Function to validate voter information
int validateVoterInfo(voter *v)
{
    // Check if the voter's roll number is valid
    if (v->rollno < 1 || v->rollno > 100) {
        return 0;
    }

    // Check if the voter has already voted
    if (v->vote == 'Y') {
        return 0;
    }

    return 1;
}

// Function to cast a vote
void castVote(voter *v)
{
    v->vote = 'Y';
    printf("Your vote has been cast.\n");
}

int main()
{
    // Create an array of voters
    voter voters[100];

    // Read voter information
    readVoterInfo(voters);

    // Validate voter information
    if (validateVoterInfo(voters) == 1) {
        // Cast a vote
        castVote(voters);
    } else {
        printf("Your vote has not been cast.\n");
    }

    return 0;
}