//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voter_id[MAX_NAME_LENGTH];
    int voted; // 0: not voted, 1: voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void add_candidate(const char* name) {
    if (candidate_count < MAX_CANDIDATES) {
        strcpy(candidates[candidate_count].name, name);
        candidates[candidate_count].votes = 0;
        candidate_count++;
        printf("Candidate '%s' added.\n", name);
    } else {
        printf("Maximum candidate limit reached!\n");
    }
}

void add_voter(const char* voter_id) {
    if (voter_count < MAX_VOTERS) {
        strcpy(voters[voter_count].voter_id, voter_id);
        voters[voter_count].voted = 0;
        voter_count++;
        printf("Voter '%s' added.\n", voter_id);
    } else {
        printf("Maximum voter limit reached!\n");
    }
}

int find_candidate(const char* name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int find_voter(const char* voter_id) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            return i;
        }
    }
    return -1;
}

void vote() {
    char voter_id[MAX_NAME_LENGTH];
    char candidate_name[MAX_NAME_LENGTH];
    
    printf("Enter your voter ID: ");
    scanf("%s", voter_id);
    int voter_index = find_voter(voter_id);
    
    if (voter_index == -1) {
        printf("Voter not found!\n");
        return;
    }

    if (voters[voter_index].voted) {
        printf("You have already voted!\n");
        return;
    }
    
    printf("Enter the candidate's name you wish to vote for: ");
    scanf("%s", candidate_name);
    int candidate_index = find_candidate(candidate_name);
    
    if (candidate_index == -1) {
        printf("Candidate not found!\n");
        return;
    }

    candidates[candidate_index].votes++;
    voters[voter_index].voted = 1;
    printf("Vote cast for '%s' by voter '%s'.\n", candidate_name, voter_id);
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

void configure_candidates() {
    int num_candidates;
    printf("How many candidates? (Max %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    
    for (int i = 0; i < num_candidates; i++) {
        char name[MAX_NAME_LENGTH];
        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", name);
        add_candidate(name);
    }
}

void configure_voters() {
    int num_voters;
    printf("How many voters? (Max %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);
    
    for (int i = 0; i < num_voters; i++) {
        char voter_id[MAX_NAME_LENGTH];
        printf("Enter voter %d ID: ", i + 1);
        scanf("%s", voter_id);
        add_voter(voter_id);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n----- Electronic Voting System -----\n");
        printf("1. Configure Candidates\n");
        printf("2. Configure Voters\n");
        printf("3. Cast Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                configure_candidates();
                break;
            case 2:
                configure_voters();
                break;
            case 3:
                vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}