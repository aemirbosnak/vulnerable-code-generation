//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of candidates and voters
#define MAX_CANDIDATES 20
#define MAX_VOTERS 1000

// Define the candidate and voter structures
typedef struct {
    int id;
    char name[50];
    int vote_count;
} candidate_t;

typedef struct {
    int id;
    char name[50];
    int voted_for;
} voter_t;

// Define the array of candidates and voters
candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];

// Define the current number of candidates and voters
int num_candidates = 0;
int num_voters = 0;

// Function to add a candidate
void add_candidate() {
    int id;
    char name[50];
    
    printf("\nEnter the candidate's ID: ");
    scanf("%d", &id);
    
    // Check if the candidate already exists
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == id) {
            printf("\nCandidate ID already exists. Please try again.\n");
            return;
        }
    }
    
    printf("\nEnter the candidate's name: ");
    scanf("%s", name);
    
    candidates[num_candidates].id = id;
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].vote_count = 0;
    
    num_candidates++;
    
    printf("\nCandidate added successfully!\n");
}

// Function to add a voter
void add_voter() {
    int id;
    char name[50];
    
    printf("\nEnter the voter's ID: ");
    scanf("%d", &id);
    
    // Check if the voter already exists
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == id) {
            printf("\nVoter already exists. Please try again.\n");
            return;
        }
    }
    
    printf("\nEnter the voter's name: ");
    scanf("%s", name);
    
    voters[num_voters].id = id;
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voted_for = -1;
    
    num_voters++;
    
    printf("\nVoter added successfully!\n");
}

// Function to start the election
void start_election() {
    if (num_candidates < 2 || num_voters < 1) {
        printf("\nCannot start election. Not enough candidates or voters.\n");
        return;
    }
    
    printf("\nElection started!\n");
    
    // Start the timer
    time_t start_time = time(NULL);
    
    // Wait for the election to end
    int end_election = 0;
    while (!end_election) {
        printf("\nPress 1 to end the election: ");
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            end_election = 1;
        }
    }
    
    // Stop the timer
    time_t end_time = time(NULL);
    time_t duration = end_time - start_time;
    
    // Show the election results
    printf("\nElection ended after %d seconds.\n", (int)duration);
    
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
    
    printf("\nThank you for participating!\n");
}

// Function to vote for a candidate
void cast_vote() {
    int voter_id, candidate_id;
    
    printf("\nEnter your voter ID: ");
    scanf("%d", &voter_id);
    
    // Check if the voter exists
    int voter_index = -1;
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            voter_index = i;
            break;
        }
    }
    
    if (voter_index == -1) {
        printf("\nVoter not found. Please try again.\n");
        return;
    }
    
    // Check if the voter already voted
    if (voters[voter_index].voted_for != -1) {
        printf("\nYou have already voted.\n");
        return;
    }
    
    printf("\nEnter the candidate's ID: ");
    scanf("%d", &candidate_id);
    
    // Check if the candidate exists
    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].id == candidate_id) {
            candidate_index = i;
            break;
        }
    }
    
    if (candidate_index == -1) {
        printf("\nCandidate not found. Please try again.\n");
        return;
    }
    
    printf("\nYou have voted for %s.\n", candidates[candidate_index].name);
    
    candidates[candidate_index].vote_count++;
    voters[voter_index].voted_for = candidate_id;
}

// Main function
int main() {
    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add a candidate\n");
        printf("2. Add a voter\n");
        printf("3. Start the election\n");
        printf("4. Cast your vote\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                add_voter();
                break;
            case 3:
                start_election();
                break;
            case 4:
                cast_vote();
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}