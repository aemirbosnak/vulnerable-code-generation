//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voter_id[50];
    int voted; // 0: not voted, 1: voted
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int total_voters = 0;
int total_candidates = 0;

void registerCandidate(const char *name) {
    if (total_candidates < MAX_CANDIDATES) {
        strcpy(candidates[total_candidates].name, name);
        candidates[total_candidates].votes = 0;
        total_candidates++;
    } else {
        printf("Maximum candidates reached. Cannot register more.\n");
    }
}

void registerVoter(const char *voter_id) {
    if (total_voters < MAX_VOTERS) {
        strcpy(voters[total_voters].voter_id, voter_id);
        voters[total_voters].voted = 0;
        total_voters++;
    } else {
        printf("Maximum voters reached. Cannot register more.\n");
    }
}

int findVoter(const char *voter_id) {
    for (int i = 0; i < total_voters; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            return i;
        }
    }
    return -1; // Voter not found
}

void castVote(const char *voter_id, int candidate_index) {
    int voter_index = findVoter(voter_id);
    
    if (voter_index == -1) {
        printf("Voter ID not found!\n");
        return;
    }

    if (voters[voter_index].voted) {
        printf("You have already voted!\n");
        return;
    }

    if (candidate_index < 0 || candidate_index >= total_candidates) {
        printf("Invalid candidate selection.\n");
        return;
    }

    candidates[candidate_index].votes++;
    voters[voter_index].voted = 1; 
    printf("Vote cast for %s!\n", candidates[candidate_index].name);
}

void displayResults() {
    printf("\nElection Results:\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void displayMenu() {
    printf("\n----- Electronic Voting System -----\n");
    printf("1. Register Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        if (choice == 1) {
            char name[50];
            printf("Enter candidate name: ");
            scanf("%s", name);
            registerCandidate(name);
        } else if (choice == 2) {
            char voter_id[50];
            printf("Enter voter ID: ");
            scanf("%s", voter_id);
            registerVoter(voter_id);
        } else if (choice == 3) {
            char voter_id[50];
            int candidate_index;
            printf("Enter your voter ID: ");
            scanf("%s", voter_id);
            printf("Choose a candidate (0-%d): ", total_candidates - 1);
            scanf("%d", &candidate_index);
            castVote(voter_id, candidate_index);
        } else if (choice == 4) {
            displayResults();
        } else if (choice == 5) {
            printf("Exiting the voting system. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}