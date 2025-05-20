//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voter_id[20];
    int has_voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int total_voters = 0;
int total_candidates = 0;

void initialize_candidates() {
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &total_candidates);
  
    if (total_candidates > MAX_CANDIDATES) {
        printf("Exceeded maximum candidates limit. Setting to max %d.\n", MAX_CANDIDATES);
        total_candidates = MAX_CANDIDATES;
    }

    for (int i = 0; i < total_candidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf(" %[^\n]", candidates[i].name);
        candidates[i].votes = 0;
    }
}

int is_valid_voter(const char *id) {
    for (int i = 0; i < total_voters; i++) {
        if (strcmp(voters[i].voter_id, id) == 0 && voters[i].has_voted) {
            return 0; // Voter has already voted
        }
    }
    return 1; // Valid voter
}

void register_voter() {
    if (total_voters >= MAX_VOTERS) {
        printf("Maximum voters reached. Cannot register more voters.\n");
        return;
    }
    
    printf("Enter voter ID: ");
    char id[20];
    scanf("%s", id);
  
    if (!is_valid_voter(id)) {
        printf("Voter ID already exists or has voted. Please check.\n");
        return;
    }

    strcpy(voters[total_voters].voter_id, id);
    voters[total_voters].has_voted = 0;
    total_voters++;
    printf("Voter registered successfully.\n");
}

void cast_vote() {
    char id[20];
    printf("Enter your voter ID: ");
    scanf("%s", id);

    if (!is_valid_voter(id)) {
        printf("You cannot vote. Check your voter ID and voting status.\n");
        return;
    }

    printf("Available candidates:\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    int choice;
    printf("Enter the candidate number to vote for (1-%d): ", total_candidates);
    scanf("%d", &choice);

    if (choice < 1 || choice > total_candidates) {
        printf("Invalid choice. Vote not cast.\n");
        return;
    }

    candidates[choice - 1].votes++;
    for (int i = 0; i < total_voters; i++) {
        if (strcmp(voters[i].voter_id, id) == 0) {
            voters[i].has_voted = 1;
            break;
        }
    }
    printf("Vote casted successfully for %s!\n", candidates[choice - 1].name);
}

void display_results() {
    printf("Election Results:\n");
    for (int i = 0; i < total_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    initialize_candidates();

    while (1) {
        printf("\n1. Register Voter\n");
        printf("2. Cast Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
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
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}