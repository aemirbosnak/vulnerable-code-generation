//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of candidates
#define MAX_CANDIDATES 10

// Define the maximum number of voters
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
    char name[50];
    int votes;
} candidate_t;

// Define the structure of a voter
typedef struct {
    char name[50];
    int voted;
} voter_t;

// Create an array of candidates
candidate_t candidates[MAX_CANDIDATES];

// Create an array of voters
voter_t voters[MAX_VOTERS];

// Get the number of candidates
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

// Get the candidates' names
void get_candidates_names(int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }
}

// Get the number of voters
int get_num_voters() {
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    return num_voters;
}

// Get the voters' names
void get_voters_names(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
    }
}

// Vote for a candidate
void vote(int num_candidates, int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        int candidate_index;
        printf("Enter the number of the candidate you want to vote for: ");
        scanf("%d", &candidate_index);
        candidates[candidate_index - 1].votes++;
        voters[i].voted = 1;
    }
}

// Print the results
void print_results(int num_candidates) {
    printf("The results of the election are:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Main function
int main() {
    int num_candidates = get_num_candidates();
    get_candidates_names(num_candidates);
    int num_voters = get_num_voters();
    get_voters_names(num_voters);
    vote(num_candidates, num_voters);
    print_results(num_candidates);
    return 0;
}