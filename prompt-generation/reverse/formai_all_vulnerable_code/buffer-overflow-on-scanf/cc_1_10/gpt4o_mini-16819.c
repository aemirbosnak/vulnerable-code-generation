//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <string.h>

// Maximum number of candidates and voters
#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

// Structure to store candidate information
typedef struct {
    int id;
    char name[50];
    int votes;
} Candidate;

// Structure to store voter information
typedef struct {
    int id;
    int voted; // 0: not voted, 1: voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

// Function to add a candidate
void add_candidate(char name[]) {
    if (candidate_count < MAX_CANDIDATES) {
        candidates[candidate_count].id = candidate_count + 1;
        strcpy(candidates[candidate_count].name, name);
        candidates[candidate_count].votes = 0;
        candidate_count++;
        printf("Candidate added: %s\n", name);
    } else {
        printf("Cannot add more candidates.\n");
    }
}

// Function to cast a vote
void cast_vote(int voter_id, int candidate_id) {
    if (voter_id < 1 || voter_id > voter_count) {
        printf("Voter ID not valid.\n");
        return;
    }
    if (voters[voter_id - 1].voted) {
        printf("Voter has already voted!\n");
        return;
    }
    if (candidate_id < 1 || candidate_id > candidate_count) {
        printf("Candidate ID not valid.\n");
        return;
    }
    candidates[candidate_id - 1].votes++;
    voters[voter_id - 1].voted = 1;
    printf("Vote casted for candidate %s by voter %d.\n", candidates[candidate_id - 1].name, voter_id);
}

// Function to display results
void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("Candidate %s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to initialize voters
void initialize_voters(int num_voters) {
    voter_count = num_voters;
    for (int i = 0; i < voter_count; i++) {
        voters[i].id = i + 1;
        voters[i].voted = 0; // Not voted yet
    }
}

// Main function
int main() {
    int option, voter_id, candidate_id;

    // Initialize some candidates
    add_candidate("Alice");
    add_candidate("Bob");
    add_candidate("Charlie");
    add_candidate("Diana");
    add_candidate("Ethan");

    // Initialize voters
    initialize_voters(10);

    do {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Cast Vote\n");
        printf("2. Display Results\n");
        printf("3. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter your Voter ID (1 - %d): ", voter_count);
                scanf("%d", &voter_id);
                printf("Available Candidates:\n");
                for (int i = 0; i < candidate_count; i++) {
                    printf("ID: %d Name: %s\n", candidates[i].id, candidates[i].name);
                }
                printf("Enter Candidate ID to vote for: ");
                scanf("%d", &candidate_id);
                cast_vote(voter_id, candidate_id);
                break;
            case 2:
                display_results();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please select again.\n");
                break;
        }
    } while (option != 3);

    return 0;
}