//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// Define candidate structure
typedef struct Candidate {
    char name[20];
    int votes;
} Candidate;

// Define voter structure
typedef struct Voter {
    char name[20];
    int voted_for;
    int has_voted;
} Voter;

// Declare global variables
Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

// Function prototypes
void addCandidate(char *name);
void listCandidates();
void addVoter(char *name);
int findVoter(char *name);
void castVote(char *voter_name, char *candidate_name);
void calculateResults();
void printResults();

// Main function
int main() {
    printf("Welcome to the Electronic Voting System!\n");

    // Display menu and prompt for user input
    char choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add candidate\n");
        printf("2. List candidates\n");
        printf("3. Add voter\n");
        printf("4. Cast vote\n");
        printf("5. Calculate results\n");
        printf("6. Print results\n");
        printf("7. Exit\n");
        printf("Enter your choice (1-7): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                // Add candidate
                printf("Enter candidate name: ");
                char name[20];
                scanf("%s", name);
                addCandidate(name);
                break;
            case '2':
                // List candidates
                listCandidates();
                break;
            case '3':
                // Add voter
                printf("Enter voter name: ");
                char voter_name[20];
                scanf("%s", voter_name);
                addVoter(voter_name);
                break;
            case '4':
                // Cast vote
                printf("Enter voter name: ");
                char voter[20];
                scanf("%s", voter);
                int voter_index = findVoter(voter);
                if (voter_index != -1) {
                    if (voters[voter_index].has_voted == 0) {
                        printf("Enter candidate name: ");
                        char candidate[20];
                        scanf("%s", candidate);
                        castVote(voter, candidate);
                    } else {
                        printf("Error: This voter has already cast their vote.\n");
                    }
                } else {
                    printf("Error: Voter not found.\n");
                }
                break;
            case '5':
                // Calculate results
                calculateResults();
                break;
            case '6':
                // Print results
                printResults();
                break;
            case '7':
                // Exit
                printf("Thank you for using the Electronic Voting System.\n");
                exit(0);
                break;
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    } while (choice != '7');

    return 0;
}

// Function to add a candidate to the system
void addCandidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Error: Maximum number of candidates reached.\n");
    } else {
        // Check if candidate already exists
        for (int i = 0; i < num_candidates; i++) {
            if (strcmp(candidates[i].name, name) == 0) {
                printf("Error: Candidate already exists.\n");
                return;
            }
        }

        // Add candidate
        Candidate candidate;
        strcpy(candidate.name, name);
        candidate.votes = 0;
        candidates[num_candidates] = candidate;
        num_candidates++;
        printf("Candidate added successfully.\n");
    }
}

// Function to list all candidates in the system
void listCandidates() {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

// Function to add a voter to the system
void addVoter(char *name) {
    if (num_voters >= MAX_VOTERS) {
        printf("Error: Maximum number of voters reached.\n");
    } else {
        // Check if voter already exists
        for (int i = 0; i < num_voters; i++) {
            if (strcmp(voters[i].name, name) == 0) {
                printf("Error: Voter already exists.\n");
                return;
            }
        }

        // Add voter
        Voter voter;
        strcpy(voter.name, name);
        voter.voted_for = -1;
        voter.has_voted = 0;
        voters[num_voters] = voter;
        num_voters++;
        printf("Voter added successfully.\n");
    }
}

// Function to find a voter by name
int findVoter(char *name) {
    for (int i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to cast a vote for a candidate
void castVote(char *voter_name, char *candidate_name) {
    // Find voter and candidate
    int voter_index = findVoter(voter_name);
    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            break;
        }
    }

    if (voter_index != -1 && candidate_index != -1) {
        // Cast vote
        voters[voter_index].voted_for = candidate_index;
        voters[voter_index].has_voted = 1;
        candidates[candidate_index].votes++;
        printf("Vote cast successfully.\n");
    } else {
        printf("Error: Invalid voter or candidate.\n");
    }
}

// Function to calculate the results of the election
void calculateResults() {
    printf("Calculating results...\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to print the final results of the election
void printResults() {
    printf("Final results:\n");
    int max_votes = candidates[0].votes;
    int winners[MAX_CANDIDATES];
    int num_winners = 0;

    // Find candidate(s) with the most votes
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            num_winners = 0;
            winners[num_winners] = i;
            num_winners++;
        } else if (candidates[i].votes == max_votes) {
            winners[num_winners] = i;
            num_winners++;
        }
    }

    // Print winner(s)
    if (num_winners == 1) {
        printf("%s has won the election with %d votes!\n", candidates[winners[0]].name, max_votes);
    } else {
        printf("There is a tie between the following candidates:\n");
        for (int i = 0; i < num_winners; i++) {
            printf("%s\n", candidates[winners[i]].name);
        }
        printf("Please hold a run-off election.\n");
    }
}