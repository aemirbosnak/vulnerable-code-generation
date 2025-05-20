//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voter_id[20];
    int voted;
} Voter;

void displayCandidates(Candidate candidates[], int total) {
    printf("\nCandidates:\n");
    for(int i = 0; i < total; i++) {
        printf("%d: %s with %d votes\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

int getCandidateIndex(Candidate candidates[], int total) {
    int choice;
    printf("Select your candidate (1-%d): ", total);
    scanf("%d", &choice);
    return choice - 1; // Adjusting for zero indexing
}

int validateVoter(Voter voters[], int total, char *voter_id) {
    for(int i = 0; i < total; i++) {
        if(strcmp(voters[i].voter_id, voter_id) == 0) {
            return i;
        }
    }
    return -1; // Voter not found
}

void castVote(Candidate candidates[], Voter voters[], int total_candidates, int total_voters) {
    char voter_id[20];
    printf("Enter your voter ID: ");
    scanf("%s", voter_id);

    int voter_index = validateVoter(voters, total_voters, voter_id);
    if (voter_index == -1) {
        printf("Voter ID not found!\n");
        return;
    }

    if(voters[voter_index].voted) {
        printf("You have already voted!\n");
        return;
    }

    displayCandidates(candidates, total_candidates);
    int candidate_index = getCandidateIndex(candidates, total_candidates);

    if (candidate_index < 0 || candidate_index >= total_candidates) {
        printf("Invalid candidate selection!\n");
        return;
    }

    candidates[candidate_index].votes++;
    voters[voter_index].voted = 1;
    printf("Vote casted successfully for %s!\n", candidates[candidate_index].name);
}

void displayResults(Candidate candidates[], int total) {
    printf("\nElection Results:\n");
    for(int i = 0; i < total; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int total_candidates = 0, total_voters = 0, choice;
    
    // Initialize candidates
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &total_candidates);
    
    for(int i = 0; i < total_candidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initializing votes to zero
    }

    // Register voters
    printf("Enter number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &total_voters);
    
    for(int i = 0; i < total_voters; i++) {
        printf("Enter Voter ID for voter %d: ", i + 1);
        scanf("%s", voters[i].voter_id);
        voters[i].voted = 0; // Initialize to not voted
    }

    while (1) {
        printf("\n--- Electronic Voting System ---\n");
        printf("1. Cast Vote\n");
        printf("2. Show Results\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                castVote(candidates, voters, total_candidates, total_voters);
                break;
            case 2:
                displayResults(candidates, total_candidates);
                break;
            case 3:
                printf("Exiting Voting System.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}