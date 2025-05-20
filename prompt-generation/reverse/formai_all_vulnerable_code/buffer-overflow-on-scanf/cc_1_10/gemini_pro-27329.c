//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates
#define MAX_CANDIDATES 10

// Define the maximum number of voters
#define MAX_VOTERS 1000

// Define the structure of a candidate
typedef struct candidate {
    char name[50];
    int votes;
} candidate;

// Define the structure of a voter
typedef struct voter {
    char name[50];
    int candidate_id;
} voter;

// Define the array of candidates
candidate candidates[MAX_CANDIDATES];

// Define the array of voters
voter voters[MAX_VOTERS];

// Define the number of candidates
int num_candidates;

// Define the number of voters
int num_voters;

// Get the number of candidates
int get_num_candidates() {
    int num;
    printf("Enter the number of candidates: ");
    scanf("%d", &num);
    return num;
}

// Get the details of a candidate
candidate get_candidate_details(int id) {
    candidate c;
    printf("Enter the name of candidate %d: ", id + 1);
    scanf("%s", c.name);
    c.votes = 0;
    return c;
}

// Get the number of voters
int get_num_voters() {
    int num;
    printf("Enter the number of voters: ");
    scanf("%d", &num);
    return num;
}

// Get the details of a voter
voter get_voter_details(int id) {
    voter v;
    printf("Enter the name of voter %d: ", id + 1);
    scanf("%s", v.name);
    printf("Enter the candidate ID for voter %d: ", id + 1);
    scanf("%d", &v.candidate_id);
    return v;
}

// Print the results of the election
void print_results() {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    // Get the number of candidates
    num_candidates = get_num_candidates();

    // Get the details of each candidate
    for (int i = 0; i < num_candidates; i++) {
        candidates[i] = get_candidate_details(i);
    }

    // Get the number of voters
    num_voters = get_num_voters();

    // Get the details of each voter
    for (int i = 0; i < num_voters; i++) {
        voters[i] = get_voter_details(i);
    }

    // Count the votes for each candidate
    for (int i = 0; i < num_voters; i++) {
        candidates[voters[i].candidate_id - 1].votes++;
    }

    // Print the results of the election
    print_results();

    return 0;
}