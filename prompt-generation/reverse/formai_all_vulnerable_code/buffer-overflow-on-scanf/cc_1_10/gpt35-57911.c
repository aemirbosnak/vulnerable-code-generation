//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// define maximum candidates allowed
#define MAX_CANDIDATES 10

// define maximum voters allowed
#define MAX_VOTERS 20

// define candidate structure
struct Candidate {
    char name[50];
    int vote_count;
};

// define voter structure
struct Voter {
    char name[50];
    bool has_voted;
    struct Candidate *selected_candidate;
};

// declare global variables
struct Candidate candidates[MAX_CANDIDATES];
struct Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

// function prototypes
void register_candidate();
void print_all_candidates();
void register_voter();
void cast_vote(struct Voter *);
void print_all_voters();
void display_results();

int main() {
    int option;

    // display menu and get user option
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Register Candidate\n");
        printf("2. Print All Candidates\n");
        printf("3. Register Voter\n");
        printf("4. Cast Vote\n");
        printf("5. Print All Voters\n");
        printf("6. Display Results\n");
        printf("0. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        // execute selected option
        switch(option) {
            case 1:
                register_candidate();
                break;
            case 2:
                print_all_candidates();
                break;
            case 3:
                register_voter();
                break;
            case 4:
                if(voter_count == 0) {
                    printf("No voters registered.\n");
                } else {
                    printf("Enter voter name: ");
                    char name[50];
                    scanf("%s", name);
                    struct Voter *voter;

                    // find voter with matching name
                    for(int i = 0; i < voter_count; i++) {
                        if(strcmp(voters[i].name, name) == 0) {
                            voter = &voters[i];
                            break;
                        }
                    }

                    cast_vote(voter);
                }
                break;
            case 5:
                print_all_voters();
                break;
            case 6:
                display_results();
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option selected. Try again.\n");
        }
    } while(option != 0);

    return 0;
}

void register_candidate() {
    if(candidate_count == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
    } else {
        printf("Enter candidate name: ");
        scanf("%s", candidates[candidate_count].name);
        candidates[candidate_count].vote_count = 0;
        candidate_count++;
        printf("Candidate successfully registered.\n");
    }
}

void print_all_candidates() {
    if(candidate_count == 0) {
        printf("No candidates registered.\n");
    } else {
        printf("All candidates:\n");
        for(int i = 0; i < candidate_count; i++) {
            printf("%d. %s - Votes: %d\n", i + 1, candidates[i].name, candidates[i].vote_count);
        }
    }
}

void register_voter() {
    if(voter_count == MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
    } else {
        printf("Enter voter name: ");
        scanf("%s", voters[voter_count].name);
        voters[voter_count].has_voted = false;
        voter_count++;
        printf("Voter successfully registered.\n");
    }
}

void cast_vote(struct Voter *voter) {
    if(voter->has_voted == true) {
        printf("This voter has already cast their vote.\n");
    } else {
        printf("Select candidate by number:\n");
        for(int i = 0; i < candidate_count; i++) {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }
        int selection;
        scanf("%d", &selection);

        // update candidate vote count
        candidates[selection - 1].vote_count++;

        // update voter selection and has_voted status
        voter->selected_candidate = &candidates[selection - 1];
        voter->has_voted = true;

        printf("Vote successfully cast for candidate %s.\n", voter->selected_candidate->name);
    }
}

void print_all_voters() {
    if(voter_count == 0) {
        printf("No voters registered.\n");
    } else {
        printf("All voters:\n");
        for(int i = 0; i < voter_count; i++) {
            char *selected_candidate_name;
            if(voters[i].has_voted == true) {
                selected_candidate_name = voters[i].selected_candidate->name;
            } else {
                selected_candidate_name = "none";
            }

            printf("%d. %s - Voted: %s\n", i + 1, voters[i].name, selected_candidate_name);
        }
    }
}

void display_results() {
    if(candidate_count == 0) {
        printf("No candidates registered.\n");
    } else {
        printf("Results:\n");
        for(int i = 0; i < candidate_count; i++) {
            printf("%d. %s - Votes: %d\n", i + 1, candidates[i].name, candidates[i].vote_count);
        }
    }
}