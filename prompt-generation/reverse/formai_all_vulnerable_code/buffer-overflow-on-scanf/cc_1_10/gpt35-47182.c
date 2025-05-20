//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 50
#define MAX_VOTERS 1000

// Structure to represent each candidate
typedef struct Candidate {
    int id;
    char name[50];
    int votes;
} Candidate;

// Structure to represent each voter
typedef struct Voter {
    int id;
    char name[50];
    int voted_for;
} Voter;

// Global variables holding the candidate and voter data
Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;
Voter voters[MAX_VOTERS];
int num_voters = 0;

// Function to add a new candidate to the system
void add_candidate() {
    Candidate candidate;
    printf("Enter candidate name: ");
    scanf("%s", candidate.name);
    candidate.votes = 0;
    candidate.id = num_candidates + 1;
    candidates[num_candidates] = candidate;
    printf("Candidate added successfully!\n");
    num_candidates++;
}

// Function to add a new voter to the system
void add_voter() {
    Voter voter;
    printf("Enter voter name: ");
    scanf("%s", voter.name);
    voter.id = num_voters + 1;
    voter.voted_for = -1;
    voters[num_voters] = voter;
    printf("Voter added successfully!\n");
    num_voters++;
}

// Function to print the list of candidates
void list_candidates() {
    for(int i=0; i<num_candidates; i++) {
        printf("%d. %s - %d votes\n", candidates[i].id, candidates[i].name, candidates[i].votes);
    }
}

// Function to print the list of voters
void list_voters() {
    for(int i=0; i<num_voters; i++) {
        printf("%d. %s\n", voters[i].id, voters[i].name);
    }
}

// Function to get the index of a candidate by ID
int get_candidate_index(int candidate_id) {
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].id == candidate_id) {
            return i;
        }
    }
    return -1;
}

// Function to get the index of a voter by ID
int get_voter_index(int voter_id) {
    for(int i=0; i<num_voters; i++) {
        if(voters[i].id == voter_id) {
            return i;
        }
    }
    return -1;
}

// Function to allow a voter to cast their vote
void cast_vote() {
    int voter_id, candidate_id;
    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);
    int voter_index = get_voter_index(voter_id);
    if(voter_index == -1) {
        printf("Voter not found!\n");
        return;
    }
    if(voters[voter_index].voted_for != -1) {
        printf("You have already cast your vote!\n");
        return;
    }
    printf("Available candidates:\n");
    list_candidates();
    printf("Enter the ID of the candidate you want to vote for: ");
    scanf("%d", &candidate_id);
    int candidate_index = get_candidate_index(candidate_id);
    if(candidate_index == -1) {
        printf("Candidate not found!\n");
        return;
    }
    candidates[candidate_index].votes++;
    voters[voter_index].voted_for = candidate_id;
    printf("Vote cast successfully!\n");
}

// Function to show the results of the election
void show_results() {
    int max_votes = 0, winner_index = -1;
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    printf("Winner: %s with %d votes.\n", candidates[winner_index].name, max_votes);
}

// Main function to drive the program
int main() {
    int option;
    while(1) {
        printf("\n-------- Electronic Voting System Menu ---------\n");
        printf("1. Add Candidate\n");
        printf("2. Add Voter\n");
        printf("3. List Candidates\n");
        printf("4. List Voters\n");
        printf("5. Cast Vote\n");
        printf("6. Show Results\n");
        printf("7. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_candidate();
                break;
            case 2:
                add_voter();
                break;
            case 3:
                list_candidates();
                break;
            case 4:
                list_voters();
                break;
            case 5:
                cast_vote();
                break;
            case 6:
                show_results();
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option! Try again.\n");
        }
    }
    return 0;
}