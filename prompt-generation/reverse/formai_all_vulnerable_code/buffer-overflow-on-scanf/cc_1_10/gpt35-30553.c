//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// structure to hold voter information
struct Voter {
    int id;
    int has_voted;
    struct Voter* next;
};

// structure to hold candidate information
struct Candidate {
    int id;
    char* name;
    int num_votes;
    struct Candidate* next;
};

// function to display the voting screen
void display_voting_screen(struct Candidate* candidates) {
    printf("CANDIDATES:\n");
    while (candidates != NULL) {
        printf("%d) %s\n", candidates->id, candidates->name);
        candidates = candidates->next;
    }
    printf("\nEnter the ID number of the candidate you want to vote for: ");
}

// function to display the results of the election
void display_election_results(struct Candidate* candidates) {
    printf("ELECTION RESULTS:\n");
    while (candidates != NULL) {
        printf("%s: %d votes\n", candidates->name, candidates->num_votes);
        candidates = candidates->next;
    }
}

int main() {
    // initialize candidates
    struct Candidate* candidates = malloc(sizeof(struct Candidate));
    candidates->id = 1;
    candidates->name = "Candidate A";
    candidates->num_votes = 0;
    candidates->next = malloc(sizeof(struct Candidate));
    candidates->next->id = 2;
    candidates->next->name = "Candidate B";
    candidates->next->num_votes = 0;
    candidates->next->next = NULL;
    
    // initialize voters
    struct Voter* voters = malloc(sizeof(struct Voter));
    voters->id = 1;
    voters->has_voted = 0;
    voters->next = malloc(sizeof(struct Voter));
    voters->next->id = 2;
    voters->next->has_voted = 0;
    voters->next->next = NULL;
    
    // loop through voters and allow them to vote
    int num_voters = 2;
    int total_votes = 0;
    while (total_votes < num_voters) {
        struct Voter* current_voter = voters;
        while (current_voter != NULL) {
            if (current_voter->has_voted == 0) {
                display_voting_screen(candidates);
                int candidate_id;
                scanf("%d", &candidate_id);
                // check if candidate id is valid
                struct Candidate* current_candidate = candidates;
                int valid_candidate_id = 0;
                while (current_candidate != NULL) {
                    if (current_candidate->id == candidate_id) {
                        valid_candidate_id = 1;
                        current_candidate->num_votes++;
                        break;
                    }
                    current_candidate = current_candidate->next;
                }
                // if candidate id is valid, mark voter as voted
                if (valid_candidate_id) {
                    current_voter->has_voted = 1;
                    total_votes++;
                }
                else {
                    printf("Invalid candidate ID\n");
                }
            }
            current_voter = current_voter->next;
        }
    }
    
    // display election results
    display_election_results(candidates);
    
    // free memory
    struct Candidate* current_candidate = candidates;
    while (current_candidate != NULL) {
        struct Candidate* temp = current_candidate;
        current_candidate = current_candidate->next;
        free(temp);
    }
    struct Voter* current_voter = voters;
    while (current_voter != NULL) {
        struct Voter* temp = current_voter;
        current_voter = current_voter->next;
        free(temp);
    }
    
    return 0;
}