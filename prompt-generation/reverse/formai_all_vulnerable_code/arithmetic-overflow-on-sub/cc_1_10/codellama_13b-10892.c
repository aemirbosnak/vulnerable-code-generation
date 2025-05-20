//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
/*
 * Electronic Voting System
 * -------------------------
 *
 * A unique C program that allows users to vote for their preferred candidate.
 * The program is designed to be fast and efficient, with a user-friendly interface.
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Structures
typedef struct {
    char name[20];
    int vote_count;
} Candidate;

typedef struct {
    char name[20];
    char password[20];
    int has_voted;
} Voter;

// Functions
void print_menu();
void print_candidates(Candidate *candidates, int num_candidates);
void print_voters(Voter *voters, int num_voters);
void add_candidate(Candidate *candidates, int *num_candidates);
void add_voter(Voter *voters, int *num_voters);
void vote(Candidate *candidates, int num_candidates, Voter *voters, int num_voters);

// Main Function
int main() {
    // Initialize variables
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates = 0;
    int num_voters = 0;

    // Print menu
    print_menu();

    // Add candidates
    add_candidate(candidates, &num_candidates);

    // Add voters
    add_voter(voters, &num_voters);

    // Vote
    vote(candidates, num_candidates, voters, num_voters);

    return 0;
}

// Function definitions
void print_menu() {
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select an option:\n");
    printf("1. Add a candidate\n");
    printf("2. Add a voter\n");
    printf("3. Vote\n");
    printf("4. Quit\n");
}

void print_candidates(Candidate *candidates, int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void print_voters(Voter *voters, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("%d. %s\n", i + 1, voters[i].name);
    }
}

void add_candidate(Candidate *candidates, int *num_candidates) {
    // Get candidate name
    char name[20];
    printf("Enter candidate name: ");
    scanf("%s", name);

    // Add candidate
    strcpy(candidates[*num_candidates].name, name);
    candidates[*num_candidates].vote_count = 0;
    *num_candidates += 1;
}

void add_voter(Voter *voters, int *num_voters) {
    // Get voter name and password
    char name[20];
    char password[20];
    printf("Enter voter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // Add voter
    strcpy(voters[*num_voters].name, name);
    strcpy(voters[*num_voters].password, password);
    voters[*num_voters].has_voted = 0;
    *num_voters += 1;
}

void vote(Candidate *candidates, int num_candidates, Voter *voters, int num_voters) {
    // Get voter ID
    int voter_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);

    // Get candidate ID
    int candidate_id;
    printf("Enter candidate ID: ");
    scanf("%d", &candidate_id);

    // Check if voter has already voted
    if (voters[voter_id - 1].has_voted == 1) {
        printf("Error: Voter has already voted.\n");
        return;
    }

    // Check if candidate is valid
    if (candidate_id < 1 || candidate_id > num_candidates) {
        printf("Error: Invalid candidate ID.\n");
        return;
    }

    // Cast vote
    voters[voter_id - 1].has_voted = 1;
    candidates[candidate_id - 1].vote_count += 1;
}