//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>

// Structure of a candidate
typedef struct Candidate {
    int id;
    char name[50];
    int vote_count;
} Candidate;

// Structure of a voter
typedef struct Voter {
    int id;
    char name[50];
    int has_voted;
} Voter;

// Declare the functions
void register_voters();
void list_candidates();
void cast_vote(int voter_id, int candidate_id);
void print_results();

// Array to store the candidates
Candidate candidates[10];

// Array to store the voters
Voter voters[100];

// Number of registered voters
int num_voters = 0;

// Number of candidates
int num_candidates = 0;

// Main function
int main() {
    int choice, voter_id, candidate_id;

    // Register the voters
    register_voters();

    // Add some candidates
    candidates[num_candidates++] = (Candidate) {1, "John Smith", 0};
    candidates[num_candidates++] = (Candidate) {2, "Jane Doe", 0};
    candidates[num_candidates++] = (Candidate) {3, "Bob Johnson", 0};
    candidates[num_candidates++] = (Candidate) {4, "Sally Thomas", 0};

    // Loop until the user quits
    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. List candidates\n");
        printf("2. Cast vote\n");
        printf("3. Print results\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // List the candidates
                list_candidates();
                break;
            case 2:
                // Cast a vote
                printf("\nEnter your voter ID: ");
                scanf("%d", &voter_id);
                printf("Enter the candidate ID you want to vote for: ");
                scanf("%d", &candidate_id);
                cast_vote(voter_id, candidate_id);
                break;
            case 3:
                // Print the results
                print_results();
                break;
            case 4:
                // Quit the program
                return 0;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

// Function to register voters
void register_voters() {
    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter the voter ID: ");
        scanf("%d", &voters[i].id);

        printf("Enter the voter name: ");
        scanf("%s", voters[i].name);

        voters[i].has_voted = 0;
    }
}

// Function to list the candidates
void list_candidates() {
    printf("\nList of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
}

// Function to cast a vote
void cast_vote(int voter_id, int candidate_id) {
    // Find the voter
    Voter *voter = NULL;
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            voter = &voters[i];
            break;
        }
    }

    if (voter == NULL) {
        printf("Invalid voter ID!\n");
        return;
    }

    // Check if the voter has already voted
    if (voter->has_voted) {
        printf("You have already voted!\n");
        return;
    }

    // Find the candidate
    Candidate *candidate = NULL;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            candidate = &candidates[i];
            break;
        }
    }

    if (candidate == NULL) {
        printf("Invalid candidate ID!\n");
        return;
    }

    // Increment the candidate's vote count
    candidate->vote_count++;

    // Set the voter's has_voted flag to true
    voter->has_voted = 1;

    printf("Thank you for casting your vote!\n");
}

// Function to print the results
void print_results() {
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}