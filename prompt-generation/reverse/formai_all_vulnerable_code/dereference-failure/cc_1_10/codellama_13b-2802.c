//Code Llama-13B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
/*
 * EVS - Electronic Voting System
 * A complete example program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a candidate
struct Candidate {
    char name[50];
    int votes;
};

// Structure to represent a voter
struct Voter {
    char name[50];
    int age;
    char gender;
};

// Structure to represent a voting ballot
struct Ballot {
    int candidate_count;
    int voter_count;
    struct Candidate *candidates;
    struct Voter *voters;
    char **votes;
};

// Function to create a new ballot
struct Ballot *create_ballot(int candidate_count, int voter_count) {
    struct Ballot *ballot = malloc(sizeof(struct Ballot));
    ballot->candidate_count = candidate_count;
    ballot->voter_count = voter_count;
    ballot->candidates = malloc(sizeof(struct Candidate) * candidate_count);
    ballot->voters = malloc(sizeof(struct Voter) * voter_count);
    ballot->votes = malloc(sizeof(char *) * voter_count);
    return ballot;
}

// Function to add a candidate to the ballot
void add_candidate(struct Ballot *ballot, char *name) {
    struct Candidate *candidate = &ballot->candidates[ballot->candidate_count];
    strcpy(candidate->name, name);
    candidate->votes = 0;
    ballot->candidate_count++;
}

// Function to add a voter to the ballot
void add_voter(struct Ballot *ballot, char *name, int age, char gender) {
    struct Voter *voter = &ballot->voters[ballot->voter_count];
    strcpy(voter->name, name);
    voter->age = age;
    voter->gender = gender;
    ballot->voter_count++;
}

// Function to cast a vote
void cast_vote(struct Ballot *ballot, char *candidate, char *voter) {
    int candidate_index = -1;
    int voter_index = -1;
    for (int i = 0; i < ballot->candidate_count; i++) {
        if (strcmp(ballot->candidates[i].name, candidate) == 0) {
            candidate_index = i;
            break;
        }
    }
    for (int i = 0; i < ballot->voter_count; i++) {
        if (strcmp(ballot->voters[i].name, voter) == 0) {
            voter_index = i;
            break;
        }
    }
    if (candidate_index >= 0 && voter_index >= 0) {
        ballot->candidates[candidate_index].votes++;
        ballot->votes[voter_index] = candidate;
    }
}

// Function to print the results
void print_results(struct Ballot *ballot) {
    printf("Candidate\tVotes\n");
    for (int i = 0; i < ballot->candidate_count; i++) {
        printf("%s\t%d\n", ballot->candidates[i].name, ballot->candidates[i].votes);
    }
}

int main() {
    // Create a new ballot with 5 candidates and 10 voters
    struct Ballot *ballot = create_ballot(5, 10);

    // Add candidates to the ballot
    add_candidate(ballot, "Alice");
    add_candidate(ballot, "Bob");
    add_candidate(ballot, "Charlie");
    add_candidate(ballot, "David");
    add_candidate(ballot, "Eve");

    // Add voters to the ballot
    add_voter(ballot, "Alice", 25, 'F');
    add_voter(ballot, "Bob", 30, 'M');
    add_voter(ballot, "Charlie", 35, 'M');
    add_voter(ballot, "David", 40, 'M');
    add_voter(ballot, "Eve", 45, 'F');

    // Cast votes
    cast_vote(ballot, "Alice", "Alice");
    cast_vote(ballot, "Bob", "Bob");
    cast_vote(ballot, "Charlie", "Charlie");
    cast_vote(ballot, "David", "David");
    cast_vote(ballot, "Eve", "Eve");
    cast_vote(ballot, "Alice", "Bob");
    cast_vote(ballot, "Bob", "Charlie");
    cast_vote(ballot, "Charlie", "David");
    cast_vote(ballot, "David", "Eve");
    cast_vote(ballot, "Eve", "Alice");

    // Print the results
    print_results(ballot);

    // Free the ballot
    free(ballot);

    return 0;
}