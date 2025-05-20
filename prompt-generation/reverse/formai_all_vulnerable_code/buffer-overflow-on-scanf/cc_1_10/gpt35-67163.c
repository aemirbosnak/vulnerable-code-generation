//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the constants for the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 50

// Declare the candidate struct
typedef struct candidate {
    char name[50];
    int votes;
} candidate_t;

// Declare the voter struct
typedef struct voter {
    char name[50];
    int voted_for;
} voter_t;

// Declare the global arrays for candidates and voters
candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];

// Declare the global variable for the number of candidates
int num_candidates = 0;

// Declare the global variable for the number of voters
int num_voters = 0;

// Function to add a candidate
void add_candidate() {
    // Check if we have reached the maximum number of candidates
    if (num_candidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    // Get the name of the candidate
    char name[50];
    printf("Enter the name of the candidate: ");
    scanf("%s", name);

    // Add the candidate to the candidates array
    candidate_t candidate;
    strcpy(candidate.name, name);
    candidate.votes = 0;
    candidates[num_candidates] = candidate;

    // Increment the number of candidates
    num_candidates++;

    printf("Candidate added.\n");
}

// Function to vote for a candidate
void vote() {
    // Check if we have reached the maximum number of voters
    if (num_voters == MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    // Get the name of the voter
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    // Check if the voter has already voted
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            printf("You have already voted.\n");
            return;
        }
    }

    // Display the list of candidates
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }

    // Get the candidate to vote for
    int voted_for;
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &voted_for);

    // Check if the candidate number is valid
    if (voted_for < 1 || voted_for > num_candidates) {
        printf("Invalid candidate number.\n");
        return;
    }

    // Add the vote
    candidates[voted_for-1].votes++;
    voters[num_voters].voted_for = voted_for-1;
    strcpy(voters[num_voters].name, name);

    // Increment the number of voters
    num_voters++;

    printf("Vote counted.\n");
}

// Function to display the results
void display_results() {
    // Display the header
    printf("Candidate           Votes\n");
    printf("-------------------------\n");

    // Display the candidates and their votes
    for (int i = 0; i < num_candidates; i++) {
        printf("%-20s %5d\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Display the welcome message
    printf("Welcome to the electronic voting system!\n");

    // Loop until the user quits
    int choice;
    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1. Add Candidate\n");
        printf("2. Vote\n");
        printf("3. Display Results\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected action
        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                vote();
                break;
            case 3:
                display_results();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    // Exit the program
    return 0;
}