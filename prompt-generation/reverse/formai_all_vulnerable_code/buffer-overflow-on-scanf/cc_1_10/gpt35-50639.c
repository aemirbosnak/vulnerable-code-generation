//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of voters
#define MAX_VOTERS 1000

// Define the number of candidates
#define NUM_CANDIDATES 3

// Define the possible choices
#define CHOICE_A 1
#define CHOICE_B 2
#define CHOICE_C 3

// Define the voter struct
typedef struct {
    int voter_id;
    int vote_choice;
} Voter;

// Define the candidate struct
typedef struct {
    int candidate_id;
    char name[50];
    int votes;
} Candidate;

// Initialize the candidates
Candidate candidates[NUM_CANDIDATES] = {
    {1, "John Smith", 0},
    {2, "Jane Doe", 0},
    {3, "Bob Johnson", 0}
};

// Declare the function to get a voter ID
int get_voter_id();

// Declare the function to get the voter's vote choice
int get_vote_choice();

// Declare the function to cast the vote
void cast_vote(Voter voter);

// Declare the function to display the final results
void display_results();

// Initialize the voters array
Voter voters[MAX_VOTERS];

// Initialize the number of voters
int num_voters = 0;

int main() {
    printf("*** Welcome to the Electronic Voting System ***\n");

    int choice = 0;

    // Loop until the user chooses to exit
    while (choice != 4) {
        printf("\n1) Cast a vote\n");
        printf("2) Display results\n");
        printf("3) Reset the system\n");
        printf("4) Exit the system\n");

        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                {
                    int voter_id = get_voter_id();
                    int vote_choice = get_vote_choice();

                    Voter new_voter = {voter_id, vote_choice};
                    cast_vote(new_voter);
                }
                break;

            case 2:
                display_results();
                break;

            case 3:
                num_voters = 0;
                for (int i = 0; i < NUM_CANDIDATES; i++) {
                    candidates[i].votes = 0;
                }
                printf("System has been reset.\n");
                break;

            case 4:
                printf("Thank you for using the Electronic Voting System.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

int get_voter_id() {
    int voter_id = 0;

    while (voter_id <= 0) {
        printf("\nPlease enter your voter ID: ");
        scanf("%d", &voter_id);

        // Check if the voter has already voted
        for (int i = 0; i < num_voters; i++) {
            if (voters[i].voter_id == voter_id) {
                printf("You have already voted. Please try again.\n");
                voter_id = 0;
                break;
            }
        }
    }

    return voter_id;
}

int get_vote_choice() {
    int vote_choice = 0;

    while (vote_choice <= 0 || vote_choice > NUM_CANDIDATES) {
        printf("\nPlease enter your vote choice:\n");
        for (int i = 0; i < NUM_CANDIDATES; i++) {
            printf("%d) %s\n", i+1, candidates[i].name);
        }
        scanf("%d", &vote_choice);

        if (vote_choice <= 0 || vote_choice > NUM_CANDIDATES) {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return vote_choice;
}

void cast_vote(Voter voter) {
    // Add the voter to the array
    voters[num_voters] = voter;
    num_voters++;

    // Update the candidate's vote count
    candidates[voter.vote_choice - 1].votes++;

    printf("Thank you for casting your vote.\n");
}

void display_results() {
    printf("\n*** Final Voting Results ***\n");

    // Calculate the total number of votes
    int total_votes = 0;
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        total_votes += candidates[i].votes;
    }

    // Display the results for each candidate
    for (int i = 0; i < NUM_CANDIDATES; i++) {
        float percentage = ((float)candidates[i].votes / total_votes) * 100;
        printf("%s: %d votes (%.2f%%)\n", candidates[i].name, candidates[i].votes, percentage);
    }
}