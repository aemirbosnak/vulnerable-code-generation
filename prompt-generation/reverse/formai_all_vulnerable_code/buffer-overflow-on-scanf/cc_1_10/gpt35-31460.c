//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining maximum number of voters and candidates
#define MAX_VOTERS 1000
#define MAX_CANDIDATES 10

// structure to store voter information
struct voter {
    int id; // voter ID
    char name[50]; // voter name
    int voted; // has voted or not
    int candidate_id; // candidate voted for
};

// structure to store candidate information
struct candidate {
    int id; // candidate ID
    char name[50]; // candidate name
    int votes; // number of votes received
};

// function to print menu and get user input
int get_option() {
    int option;
    printf("\nElectronic Voting System\n"
           "1. Add Voters\n"
           "2. Add Candidates\n"
           "3. View Polling Results\n"
           "4. Exit Program\n"
           "Enter your option: ");
    scanf("%d", &option);
    return option;
}

// function to add voters
void add_voters(struct voter voters[], int *num_voters) {
    // check if maximum number of voters have been reached
    if (*num_voters == MAX_VOTERS) {
        printf("Maximum number of voters reached\n");
        return;
    }
    
    // get voter information
    printf("\nEnter Voter details\n");
    printf("Voter ID: ");
    scanf("%d", &voters[*num_voters].id);
    printf("Name: ");
    scanf(" %[^\n]", voters[*num_voters].name);
    
    // mark voter as not voted
    voters[*num_voters].voted = 0;
    
    // increment number of voters
    *num_voters += 1;
    
    printf("Voter successfully added\n");
}

// function to add candidates
void add_candidates(struct candidate candidates[], int *num_candidates) {
    // check if maximum number of candidates have been reached
    if (*num_candidates == MAX_CANDIDATES) {
        printf("Maximum number of candidates reached\n");
        return;
    }
    
    // get candidate information
    printf("\nEnter Candidate details\n");
    printf("Candidate ID: ");
    scanf("%d", &candidates[*num_candidates].id);
    printf("Name: ");
    scanf(" %[^\n]", candidates[*num_candidates].name);
    
    // initialise number of votes to zero
    candidates[*num_candidates].votes = 0;
    
    // increment number of candidates
    *num_candidates += 1;
    
    printf("Candidate successfully added\n");
}

// function to view polling results
void view_polling_results(struct candidate candidates[], int num_candidates) {
    printf("\nPolling Results\n");
    printf("Candidate ID\tCandidate Name\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d\t\t%s\t\t%d\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

// function to display menu for a voter
int get_voter_option(char *voter_name) {
    int option;
    printf("\nWelcome %s\n"
           "1. Vote\n"
           "2. Exit\n"
           "Enter your option: ", voter_name);
    scanf("%d", &option);
    return option;
}

// function to get candidate ID for voting
int get_candidate_id(struct candidate candidates[], int num_candidates) {
    int candidate_id;
    printf("\nEnter candidate ID to vote for: ");
    scanf("%d", &candidate_id);
    
    // check if candidate ID is valid
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            printf("\nVote successfully casted for %s\n", candidates[i].name);
            return candidate_id;
        }
    }
    
    // candidate ID is not valid
    printf("\nInvalid candidate ID, please try again\n");
    return get_candidate_id(candidates, num_candidates);
}

// main function
int main() {
    // initialise variables
    struct voter voters[MAX_VOTERS];
    struct candidate candidates[MAX_CANDIDATES];
    int num_voters = 0;
    int num_candidates = 0;
    int option, voter_id, candidate_id;
    char voter_name[50];
    
    while (1) {
        // get user option from main menu
        option = get_option();
        
        switch (option) {
            case 1: // add voters
                add_voters(voters, &num_voters);
                break;
            case 2: // add candidates
                add_candidates(candidates, &num_candidates);
                break;
            case 3: // view polling results
                view_polling_results(candidates, num_candidates);
                break;
            case 4: // exit program
                printf("\nExiting program...\n");
                return 0;
                break;
            default: // invalid option
                printf("\nInvalid option, please try again\n");
                break;
        }
        
        // check if any voters have not voted yet
        for (int i = 0; i < num_voters; i++) {
            if (voters[i].voted == 0) {
                voter_id = voters[i].id;
                strcpy(voter_name, voters[i].name);
                // display menu for voter
                while (1) {
                    option = get_voter_option(voter_name);
                    if (option == 1) { // vote
                        candidate_id = get_candidate_id(candidates, num_candidates);
                        // mark voter as voted
                        voters[i].voted = 1;
                        voters[i].candidate_id = candidate_id;
                        // increment candidate vote count
                        for (int j = 0; j < num_candidates; j++) {
                            if (candidates[j].id == candidate_id) {
                                candidates[j].votes += 1;
                                break;
                            }
                        }
                        break;
                    }
                    else if (option == 2) { // exit
                        break;
                    }
                    else { // invalid option
                        printf("\nInvalid option, please try again\n");
                    }
                }
            }
        }
    }
    
    return 0;
}