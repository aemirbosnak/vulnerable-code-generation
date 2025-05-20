//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

// Voter struct
typedef struct voter_t {
    int id; // Voter ID
    char name[50]; // Voter name
    int has_voted; // Flag to check if the voter has already voted
} Voter;

// Candidate struct
typedef struct candidate_t {
    int id; // Candidate ID
    char name[50]; // Candidate name
    int votes; // Total number of votes received
} Candidate;

// Function to display the main menu
void display_menu() {
    printf("\n");
    printf("1. Add a voter\n");
    printf("2. Add a candidate\n");
    printf("3. Cast a vote\n");
    printf("4. View election results\n");
    printf("5. Exit\n\n");
}

// Function to add a new voter
void add_voter(Voter *voters, int *num_voters) {
    if (*num_voters < MAX_VOTERS) {
        Voter new_voter;
        new_voter.id = *num_voters + 1;
        printf("Enter voter name: ");
        scanf("%s", new_voter.name);
        new_voter.has_voted = 0;
        voters[*num_voters] = new_voter;
        (*num_voters)++;
        printf("Voter added successfully!\n");
    } else {
        printf("Maximum limit of voters reached!\n");
    }
}

// Function to add a new candidate
void add_candidate(Candidate *candidates, int *num_candidates) {
    if (*num_candidates < MAX_CANDIDATES) {
        Candidate new_candidate;
        new_candidate.id = *num_candidates + 1;
        printf("Enter candidate name: ");
        scanf("%s", new_candidate.name);
        new_candidate.votes = 0;
        candidates[*num_candidates] = new_candidate;
        (*num_candidates)++;
        printf("Candidate added successfully!\n");
    } else {
        printf("Maximum limit of candidates reached!\n");
    }
}

// Function to cast a vote
void cast_vote(Voter *voters, int num_voters, Candidate *candidates, int num_candidates) {
    int voter_id, candidate_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);
    printf("Enter candidate ID: ");
    scanf("%d", &candidate_id);

    int voter_index = -1;
    int candidate_index = -1;

    // Search for the voter and candidate indices
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            voter_index = i;
            break;
        }
    }

    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            candidate_index = i;
            break;
        }
    }

    if (voter_index == -1 || candidate_index == -1) {
        printf("Error: Invalid voter or candidate ID!\n");
        return;
    }

    // Check if the voter has already voted
    if (voters[voter_index].has_voted == 1) {
        printf("Error: This voter has already cast a vote!\n");
        return;
    } else {
        voters[voter_index].has_voted = 1;
    }

    candidates[candidate_index].votes++;
    printf("Vote cast successfully!\n");
}

// Function to view election results
void view_results(Candidate *candidates, int num_candidates) {
    printf("Election Results:\n\n");
    printf("%-10s %-30s %s\n", "ID", "Candidate Name", "Votes");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%-10d %-30s %d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

int main() {

    // Initialize voters and candidates array
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];
    int num_voters = 0;
    int num_candidates = 0;

    int choice = 0;

    printf("Welcome to the Happy Electronic Voting System!\n");

    while (choice != 5) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                add_voter(voters, &num_voters);
                break;
            case 2:
                add_candidate(candidates, &num_candidates);
                break;
            case 3:
                cast_vote(voters, num_voters, candidates, num_candidates);
                break;
            case 4:
                view_results(candidates, num_candidates);
                break;
            case 5:
                printf("Thank you for using Happy Electronic Voting System!\n");
                break;
            default:
                printf("Error: Invalid choice! Please choose a valid option.\n");
                break;
        }
    }

    return 0;
}