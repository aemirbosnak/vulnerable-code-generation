//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

int num_candidates; // Global variable to store number of candidates
char** candidates; // Global variable to store names of candidates
int* votes; // Global variable to store number of votes received by each candidate
int total_votes; // Global variable to store total number of votes cast
int* voter_ids; // Global variable to store voter ids
int* has_voted; // Global variable to store whether a voter has cast their vote or not
int num_voters; // Global variable to store number of voters

// Function to display the list of candidates
void display_candidates() {
    printf("\nList of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i]);
    }
}

// Function to display the voting results
void display_results() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes (%.2f%%)\n", candidates[i], votes[i], (float)votes[i]*100/total_votes);
    }
}

// Function to verify voter ID
int verify_voter(int id) {
    for (int i = 0; i < num_voters; i++) {
        if (voter_ids[i] == id) {
            if (has_voted[i] == 1) {
                printf("\nYou have already voted!\n");
                return 0;
            }
            else {
                has_voted[i] = 1;
                return 1;
            }
        }
    }
    printf("\nInvalid voter ID!\n");
    return 0;
}

// Function to cast vote
void cast_vote() {
    int id, choice;
    printf("\nEnter your voter ID: ");
    scanf("%d", &id);
    if (verify_voter(id)) {
        display_candidates();
        printf("\nEnter your choice (1-%d): ", num_candidates);
        scanf("%d", &choice);
        if (choice >= 1 && choice <= num_candidates) {
            votes[choice-1]++;
            total_votes++;
            printf("\nVote cast successfully!\n");
        }
        else {
            printf("\nInvalid choice!\n");
        }
    }
}

// Main function
int main() {
    char temp[50];
    printf("\nEnter number of candidates: ");
    scanf("%d", &num_candidates);
    candidates = (char**)malloc(num_candidates*sizeof(char*));
    votes = (int*)calloc(num_candidates, sizeof(int));
    printf("\nEnter names of candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        scanf("%s", temp);
        candidates[i] = (char*)malloc(strlen(temp)*sizeof(char));
        strcpy(candidates[i], temp);
    }
    printf("\nEnter number of voters: ");
    scanf("%d", &num_voters);
    voter_ids = (int*)malloc(num_voters*sizeof(int));
    has_voted = (int*)calloc(num_voters, sizeof(int));
    printf("\nEnter voter IDs:\n");
    for (int i = 0; i < num_voters; i++) {
        scanf("%d", &voter_ids[i]);
    }
    while (1) {
        printf("\nPress 1 to cast your vote\nPress 2 to display voting results\nPress 3 to exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: cast_vote(); break;
            case 2: display_results(); break;
            case 3: printf("\nExiting...\n"); exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}