//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the candidate struct, which holds the name and number of votes
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Define the voting system struct, which holds the list of candidates and eligible voters
typedef struct {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    int voters[MAX_VOTERS];
    int num_voters;
} VotingSystem;

// Declare functions
void initialize_voting_system(VotingSystem* vs);
void add_candidate(VotingSystem* vs);
void add_voter(VotingSystem* vs);
void cast_vote(VotingSystem* vs);
void print_results(VotingSystem* vs);

int main() {
    // Initialize the voting system
    VotingSystem vs;
    initialize_voting_system(&vs);
    
    // Display menu options to user and get user input until they choose to exit
    int choice;
    do {
        printf("Welcome to the Electronic Voting System!\n");
        printf("What would you like to do?\n");
        printf("1. Add Candidate\n");
        printf("2. Add Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Print Results\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_candidate(&vs); break;
            case 2: add_voter(&vs); break;
            case 3: cast_vote(&vs); break;
            case 4: print_results(&vs); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n"); break;
        }
    } while (choice != 5);
    
    return 0;
}

// Initialize the voting system by setting the number of candidates and voters to 0
void initialize_voting_system(VotingSystem* vs) {
    vs->num_candidates = 0;
    vs->num_voters = 0;
}

// Add a candidate to the system
void add_candidate(VotingSystem* vs) {
    if (vs->num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached. Cannot add another candidate.\n");
        return;
    }
    
    printf("Enter the name of the candidate: ");
    scanf("%s", vs->candidates[vs->num_candidates].name);
    vs->candidates[vs->num_candidates].votes = 0;
    vs->num_candidates++;
}

// Add a voter to the system
void add_voter(VotingSystem* vs) {
    if (vs->num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached. Cannot add another voter.\n");
        return;
    }
    
    printf("Enter the ID of the voter: ");
    scanf("%d", &vs->voters[vs->num_voters]);
    vs->num_voters++;
}

// Cast a vote for a candidate
void cast_vote(VotingSystem* vs) {
    int voter_id, candidate_id;
    
    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);
    
    // Check if voter is eligible to vote
    int voter_found = 0;
    for (int i = 0; i < vs->num_voters; i++) {
        if (vs->voters[i] == voter_id) {
            voter_found = 1;
            break;
        }
    }
    if (!voter_found) {
        printf("Invalid voter ID. Cannot cast vote.\n");
        return;
    }
    
    // Display list of candidates and get user input for candidate to vote for
    printf("List of candidates:\n");
    for (int i = 0; i < vs->num_candidates; i++) {
        printf("%d. %s\n", i+1, vs->candidates[i].name);
    }
    printf("Enter the number of the candidate you would like to vote for: ");
    scanf("%d", &candidate_id);
    
    // Check if candidate exists and cast vote
    if (candidate_id < 1 || candidate_id > vs->num_candidates) {
        printf("Invalid candidate number. Cannot cast vote.\n");
        return;
    }
    vs->candidates[candidate_id - 1].votes++;
    printf("Thank you for voting!\n");
}

// Print the results of the election
void print_results(VotingSystem* vs) {
    if (vs->num_candidates == 0) {
        printf("No candidates added yet. Cannot print results.\n");
        return;
    }
    
    printf("Election results:\n");
    for (int i = 0; i < vs->num_candidates; i++) {
        printf("%s - %d votes\n", vs->candidates[i].name, vs->candidates[i].votes);
    }
}