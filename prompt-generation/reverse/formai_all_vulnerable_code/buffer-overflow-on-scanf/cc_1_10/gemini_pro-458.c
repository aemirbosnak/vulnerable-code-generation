//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define the structure of a candidate
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Define the structure of a voter
typedef struct {
    char name[50];
    int voted;
} Voter;

// Create an array of candidates
Candidate candidates[MAX_CANDIDATES];

// Create an array of voters
Voter voters[MAX_VOTERS];

// Get the number of candidates
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

// Get the details of the candidates
void get_candidate_details(int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

// Get the number of voters
int get_num_voters() {
    int num_voters;
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);
    return num_voters;
}

// Get the details of the voters
void get_voter_details(int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }
}

// Print the results of the election
void print_results(int num_candidates) {
    printf("\nThe results of the election are:\n\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s received %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Conduct the election
void conduct_election(int num_candidates, int num_voters) {
    int vote;
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].voted == 0) {
            printf("\n%s, it is your turn to vote.\n", voters[i].name);
            printf("Enter the number of the candidate you want to vote for: ");
            scanf("%d", &vote);
            if (vote >= 1 && vote <= num_candidates) {
                candidates[vote - 1].votes++;
                voters[i].voted = 1;
            } else {
                printf("Invalid vote. Please try again.\n");
            }
        }
    }
}

// Main function
int main() {
    int num_candidates = get_num_candidates();
    get_candidate_details(num_candidates);
    int num_voters = get_num_voters();
    get_voter_details(num_voters);
    conduct_election(num_candidates, num_voters);
    print_results(num_candidates);
    return 0;
}