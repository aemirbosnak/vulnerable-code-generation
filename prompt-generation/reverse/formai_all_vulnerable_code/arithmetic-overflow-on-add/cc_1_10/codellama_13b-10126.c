//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
// unique_c_electronic_voting_system.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    int id;
    char name[100];
    char email[100];
    char party[100];
    int age;
    char address[100];
} voter;

typedef struct {
    int id;
    char name[100];
    char description[100];
    int votes;
} candidate;

// Function prototypes
void print_menu();
void add_voter(voter* voters, int* voter_count);
void add_candidate(candidate* candidates, int* candidate_count);
void vote(voter* voters, candidate* candidates, int* candidate_count);

// Main function
int main() {
    int voter_count = 0;
    int candidate_count = 0;
    voter* voters = NULL;
    candidate* candidates = NULL;

    // Menu
    print_menu();

    // Add voters
    printf("Enter the number of voters: ");
    scanf("%d", &voter_count);
    voters = (voter*)malloc(voter_count * sizeof(voter));
    for (int i = 0; i < voter_count; i++) {
        add_voter(&voters[i], &voter_count);
    }

    // Add candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);
    candidates = (candidate*)malloc(candidate_count * sizeof(candidate));
    for (int i = 0; i < candidate_count; i++) {
        add_candidate(&candidates[i], &candidate_count);
    }

    // Voting
    for (int i = 0; i < voter_count; i++) {
        vote(&voters[i], candidates, &candidate_count);
    }

    // Print results
    printf("Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("Candidate %s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    // Free memory
    free(voters);
    free(candidates);

    return 0;
}

// Function definitions
void print_menu() {
    printf("Welcome to the electronic voting system!\n");
    printf("1. Add voters\n");
    printf("2. Add candidates\n");
    printf("3. Vote\n");
    printf("4. Print results\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void add_voter(voter* voter, int* voter_count) {
    printf("Enter voter's name: ");
    scanf("%s", voter->name);
    printf("Enter voter's email: ");
    scanf("%s", voter->email);
    printf("Enter voter's party: ");
    scanf("%s", voter->party);
    printf("Enter voter's age: ");
    scanf("%d", &voter->age);
    printf("Enter voter's address: ");
    scanf("%s", voter->address);
    voter->id = *voter_count + 1;
    (*voter_count)++;
}

void add_candidate(candidate* candidate, int* candidate_count) {
    printf("Enter candidate's name: ");
    scanf("%s", candidate->name);
    printf("Enter candidate's description: ");
    scanf("%s", candidate->description);
    candidate->id = *candidate_count + 1;
    (*candidate_count)++;
}

void vote(voter* voter, candidate* candidates, int* candidate_count) {
    int candidate_id;
    printf("Enter the candidate's ID: ");
    scanf("%d", &candidate_id);
    for (int i = 0; i < *candidate_count; i++) {
        if (candidates[i].id == candidate_id) {
            candidates[i].votes++;
            break;
        }
    }
}