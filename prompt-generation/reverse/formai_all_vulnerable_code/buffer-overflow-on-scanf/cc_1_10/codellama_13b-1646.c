//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: cheerful
// This is a unique C Electronic Voting System example program in a cheerful style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing the voting data
typedef struct {
    char name[30];
    char party[30];
    int votes;
} candidate_t;

// Array of candidates
candidate_t candidates[] = {
    { "John Doe", "Democrat", 0 },
    { "Jane Smith", "Republican", 0 },
    { "Bob Johnson", "Independent", 0 }
};

// Function to print the voting results
void print_results() {
    printf("Election Results:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to cast a vote
void cast_vote(char *name, char *party) {
    // Find the candidate with the given name and party
    for (int i = 0; i < 3; i++) {
        if (strcmp(candidates[i].name, name) == 0 && strcmp(candidates[i].party, party) == 0) {
            // Increment the candidate's vote count
            candidates[i].votes++;
            break;
        }
    }
}

// Main function
int main() {
    // Prompt the user to cast a vote
    printf("Welcome to the voting system!\n");
    printf("Please enter your name and party: ");
    char name[30];
    char party[30];
    scanf("%s %s", name, party);

    // Cast the vote
    cast_vote(name, party);

    // Print the voting results
    print_results();

    return 0;
}