//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Constants
#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

// Candidate struct
typedef struct {
    char name[50];
    int votes;
} Candidate;

// Voter struct
typedef struct {
    int voter_id;
    bool has_voted;
} Voter;

// Helper functions
int get_candidate_index(Candidate candidates[], int num_candidates, char name[]);
void print_candidates(Candidate candidates[], int num_candidates);
void print_voters(Voter voters[], int num_voters);

// Main function
int main() {
    // Initialize variables
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates = 0, num_voters = 0;
    char voter_response;

    // Gather candidate information
    printf("Welcome to the electronic voting system!\n");
    printf("Please enter the names of the candidates (up to %d candidates, or type 'done' when finished):\n", MAX_CANDIDATES);
    while (num_candidates < MAX_CANDIDATES) {
        char candidate_name[50];
        printf("Candidate %d: ", num_candidates + 1);
        scanf("%s", candidate_name);
        if (strcmp(candidate_name, "done") == 0) {
            break;
        }
        candidates[num_candidates].votes = 0;
        strcpy(candidates[num_candidates].name, candidate_name);
        num_candidates++;
    }

    // Gather voter information
    printf("Please enter the voter IDs (up to %d voters, or type 'done' when finished):\n", MAX_VOTERS);
    while (num_voters < MAX_VOTERS) {
        int voter_id;
        printf("Voter %d: ", num_voters + 1);
        scanf("%d", &voter_id);
        if (voter_id == 0) {
            break;
        }
        voters[num_voters].has_voted = false;
        voters[num_voters].voter_id = voter_id;
        num_voters++;
    }

    // Begin voting process
    printf("Voting has begun!\n");
    printf("Enter 'v' to vote, 's' to show current results, or 'q' to quit:\n");
    while (true) {
        char user_input;
        scanf(" %c", &user_input);

        // Process user input
        if (user_input == 'v') {
            int voter_id, candidate_index;
            printf("Please enter your voter ID: ");
            scanf("%d", &voter_id);

            // Check if voter has already voted
            bool voter_found = false;
            for (int i = 0; i < num_voters; i++) {
                if (voters[i].voter_id == voter_id) {
                    if (voters[i].has_voted) {
                        printf("Error: You have already voted!\n");
                        voter_found = true;
                        break;
                    } else {
                        voter_found = true;
                        voters[i].has_voted = true;
                        printf("Please enter the name of the candidate you would like to vote for:\n");
                        print_candidates(candidates, num_candidates);
                        char candidate_name[50];
                        scanf("%s", candidate_name);
                        candidate_index = get_candidate_index(candidates, num_candidates, candidate_name);
                        if (candidate_index == -1) {
                            printf("Error: Invalid candidate name!\n");
                        } else {
                            candidates[candidate_index].votes++;
                            printf("Thank you for voting for %s!\n", candidate_name);
                            break;
                        }
                    }
                }
            }
            if (!voter_found) {
                printf("Error: Invalid voter ID!\n");
            }
        } else if (user_input == 's') {
            printf("Current results:\n");
            print_candidates(candidates, num_candidates);
            printf("\n");
            print_voters(voters, num_voters);
        } else if (user_input == 'q') {
            printf("Thank you for using the electronic voting system!\n");
            break;
        } else {
            printf("Error: Invalid input!\n");
        }
    }
    
    return 0;
}

// Returns the index of a candidate in the candidates array, or -1 if the candidate is not found
int get_candidate_index(Candidate candidates[], int num_candidates, char name[]) {
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Prints the candidates and their vote counts
void print_candidates(Candidate candidates[], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

// Prints the voters and their vote status
void print_voters(Voter voters[], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d - ID: %d, Has voted: %s\n", i + 1, voters[i].voter_id, voters[i].has_voted ? "Yes" : "No");
    }
}