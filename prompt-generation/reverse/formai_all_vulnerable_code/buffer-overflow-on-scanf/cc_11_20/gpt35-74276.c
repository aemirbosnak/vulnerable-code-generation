//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of candidates the system can handle
#define MAX_CANDIDATES 10

// Define the maximum number of voters the system can handle
#define MAX_VOTERS 1000

// Define the candidate structure
typedef struct {
    char name[50];      // name
    int votes;          // number of votes received
} Candidate;

// Define the voter structure
typedef struct {
    int id;             // unique voter ID
    int has_voted;      // flag to check if a voter has voted before
} Voter;

int main() {

    // Declare the variables and arrays needed for the voting system
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    Voter voters[MAX_VOTERS];
    int num_voters = 0;
    int voter_id;
    int candidate_id;

    // Display welcome message and prompt the user to enter the number of candidates
    printf("Welcome to the electronic voting system!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Prompt the user to enter the name of each candidate
    for (int i = 0; i < num_candidates; i++) {
        printf("Please enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);

        // Initialize the number of votes received by each candidate to 0
        candidates[i].votes = 0;
    }

    // Display the list of candidates
    printf("\nList of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    // Prompt the user to enter the number of voters
    printf("\nPlease enter the number of voters: ");
    scanf("%d", &num_voters);

    // Prompt the user to enter the unique ID of each voter
    for (int i = 0; i < num_voters; i++) {
        printf("Please enter the unique ID of voter %d: ", i + 1);
        scanf("%d", &voters[i].id);

        // Initialize the has_voted flag to 0 for each voter
        voters[i].has_voted = 0;
    }

    // Loop until all the voters have casted their votes
    while (1) {
        // Prompt the user to enter their ID to cast their vote
        printf("\nPlease enter your ID to cast your vote (or enter -1 to exit): ");
        scanf("%d", &voter_id);

        // If the user enters -1, exit the program
        if (voter_id == -1) {
            printf("\nThank you for using the electronic voting system!\n");
            break;
        }

        // Search for the voter by ID
        int voter_index = -1;
        for (int i = 0; i < num_voters; i++) {
            if (voters[i].id == voter_id) {
                voter_index = i;
                break;
            }
        }

        // If the voter is not found, display an error message and re-prompt the user for their ID
        if (voter_index == -1) {
            printf("\nError: Voter with ID %d not found.\n", voter_id);
            continue;
        }

        // If the voter has already casted their vote, display an error message and re-prompt the user for their ID
        if (voters[voter_index].has_voted) {
            printf("\nError: Voter with ID %d has already casted their vote.\n", voter_id);
            continue;
        }

        // Display the list of candidates and prompt the user to enter their choice
        printf("\nList of candidates:\n");
        for (int i = 0; i < num_candidates; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }
        printf("\nPlease enter the candidate ID you wish to vote for: ");
        scanf("%d", &candidate_id);

        // If the candidate ID entered is not valid, display an error message and re-prompt the user for their choice
        if (candidate_id < 1 || candidate_id > num_candidates) {
            printf("\nError: Invalid candidate ID.\n");
            continue;
        }

        // Increment the vote count for the selected candidate and set the has_voted flag to 1 for the voter
        candidates[candidate_id - 1].votes++;
        voters[voter_index].has_voted = 1;

        // Display a confirmation message for the voter
        printf("\nThank you for casting your vote!\n");
    }

    // Display the results of the election
    printf("\nElection Results:\n");
    int total_votes = 0;
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        total_votes += candidates[i].votes;
    }
    printf("Total Votes: %d\n", total_votes);

    // Determine the winning candidate
    int max_votes = 0;
    int winning_candidate = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winning_candidate = i;
        }
    }

    // Display the winning candidate
    printf("\nWinning Candidate: %s\n", candidates[winning_candidate].name);

    return 0;
}