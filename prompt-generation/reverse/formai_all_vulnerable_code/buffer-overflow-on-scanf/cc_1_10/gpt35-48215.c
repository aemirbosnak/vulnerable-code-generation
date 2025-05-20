//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of candidates, voters and their names
#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_NAME_LEN 50

// Define candidate structure
typedef struct candidate {
    char name[MAX_NAME_LEN];
    int votes;
} candidate;

// Define voter structure
typedef struct voter {
    char name[MAX_NAME_LEN];
    int vote;
    int has_voted;
} voter;

// Define global variable for candidates and voters
candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

// Define function for adding candidates
void add_candidate(int index) {
    char name[MAX_NAME_LEN];
    printf("Enter candidate name: ");
    scanf("%s", name);
    strcpy(candidates[index].name, name);
    candidates[index].votes = 0;
}

// Define function for adding voters
void add_voter(int index) {
    char name[MAX_NAME_LEN];
    printf("Enter voter name: ");
    scanf("%s", name);
    strcpy(voters[index].name, name);
    voters[index].vote = -1; // set default vote to -1 (invalid)
    voters[index].has_voted = 0; // set has_voted flag to 0 (false)
}

// Define function for printing candidate list
void print_candidates(int num_candidates) {
    printf("Candidate List:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Define function for printing voter list
void print_voters(int num_voters) {
    printf("Voter List:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%d. %s\n", i+1, voters[i].name);
    }
}

// Define function for casting votes
void cast_vote(int index, int num_candidates) {
    int vote;
    printf("Enter candidate number to vote for (1-%d): ", num_candidates);
    scanf("%d", &vote);
    if (vote < 1 || vote > num_candidates) {
        printf("Invalid candidate number!\n");
    } else {
        voters[index].vote = vote-1;
        candidates[vote-1].votes++;
        voters[index].has_voted = 1;
        printf("Vote cast successfully!\n");
    }
}

// Define function for printing election results
void print_results(int num_candidates) {
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s: %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int num_candidates = 0;
    int num_voters = 0;
    int choice = 0;

    while (choice != 5) {
        printf("\nElectronic Voting System Menu:\n");
        printf("1. Add Candidate\n");
        printf("2. Add Voter\n");
        printf("3. Cast Vote\n");
        printf("4. Print Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_candidates < MAX_CANDIDATES) {
                    add_candidate(num_candidates++);
                } else {
                    printf("Maximum number of candidates reached!\n");
                }
                break;
            case 2:
                if (num_voters < MAX_VOTERS) {
                    add_voter(num_voters++);
                } else {
                    printf("Maximum number of voters reached!\n");
                }
                break;
            case 3:
                if (num_voters == 0) {
                    printf("No voters added yet!\n");
                } else if (num_candidates == 0) {
                    printf("No candidates added yet!\n");
                } else {
                    int index;
                    printf("Enter voter number to cast vote (1-%d): ", num_voters);
                    scanf("%d", &index);
                    if (index < 1 || index > num_voters) {
                        printf("Invalid voter number!\n");
                    } else if (voters[index-1].has_voted == 1) {
                        printf("Voter has already cast vote!\n");
                    } else {
                        cast_vote(index-1, num_candidates);
                    }
                }
                break;
            case 4:
                if (num_voters == 0) {
                    printf("No voters added yet!\n");
                } else if (num_candidates == 0) {
                    printf("No candidates added yet!\n");
                } else {
                    print_results(num_candidates);
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}