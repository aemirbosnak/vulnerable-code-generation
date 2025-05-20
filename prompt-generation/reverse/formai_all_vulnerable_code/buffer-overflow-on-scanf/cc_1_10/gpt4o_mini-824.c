//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
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
    char voter_id[10];
    int has_voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void initialize_candidates() {
    for (int i = 0; i < MAX_CANDIDATES; ++i) {
        printf("Enter the name of candidate %d: ", i + 1);
        fgets(candidates[i].name, sizeof(candidates[i].name), stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0; // Remove newline
        candidates[i].votes = 0;
        candidate_count++;
    }
}

void register_voter() {
    if (voter_count >= MAX_VOTERS) {
        printf("Maximum voter limit reached!\n");
        return;
    }
    printf("Enter voter ID: ");
    scanf("%s", voters[voter_count].voter_id);
    voters[voter_count].has_voted = 0;
    voter_count++;
}

int find_voter(const char *voter_id) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0)
            return i;
    }
    return -1; // Voter not found
}

void cast_vote() {
    char voter_id[10];
    printf("Enter your voter ID: ");
    scanf("%s", voter_id);

    int voter_index = find_voter(voter_id);
    if (voter_index == -1) {
        printf("Voter ID not registered!\n");
        return;
    }

    if (voters[voter_index].has_voted) {
        printf("You have already voted!\n");
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int vote_choice;
    printf("Choose a candidate to vote for (1-%d): ", candidate_count);
    scanf("%d", &vote_choice);

    if (vote_choice < 1 || vote_choice > candidate_count) {
        printf("Invalid choice!\n");
        return;
    }

    candidates[vote_choice - 1].votes++;
    voters[voter_index].has_voted = 1;
    printf("Vote cast successfully for %s!\n", candidates[vote_choice - 1].name);
}

void display_results() {
    printf("\nVoting Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    printf("Welcome to the Electronic Voting System!\n");
    initialize_candidates();

    while (1) {
        printf("\nMenu:\n");
        printf("1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_voter();
                break;
            case 2:
                cast_vote();
                break;
            case 3:
                display_results();
                break;
            case 4:
                printf("Exiting the voting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}