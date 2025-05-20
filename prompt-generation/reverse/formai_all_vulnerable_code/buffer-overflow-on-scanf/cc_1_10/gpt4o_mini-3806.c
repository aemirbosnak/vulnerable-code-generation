//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
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
int candidate_count = 0;
int voter_count = 0;

void add_candidate() {
    if (candidate_count >= MAX_CANDIDATES) {
        printf("Candidate limit reached, cannot add more candidates.\n");
        return;
    }
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidate_count].name);
    candidates[candidate_count].votes = 0;
    candidate_count++;
    printf("Candidate added successfully.\n");
}

void register_voter() {
    if (voter_count >= MAX_VOTERS) {
        printf("Voter limit reached, cannot register more voters.\n");
        return;
    }
    printf("Enter voter ID: ");
    scanf("%s", voters[voter_count].voter_id);
    voters[voter_count].has_voted = 0;
    voter_count++;
    printf("Voter registered successfully.\n");
}

int find_voter(const char *voter_id) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            return i;
        }
    }
    return -1;
}

int find_candidate(const char *candidate_name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            return i;
        }
    }
    return -1;
}

void vote() {
    char voter_id[20], candidate_name[50];
    
    printf("Enter your voter ID: ");
    scanf("%s", voter_id);

    int voter_index = find_voter(voter_id);
    if (voter_index == -1) {
        printf("Voter not registered.\n");
        return;
    }
    
    if (voters[voter_index].has_voted) {
        printf("You have already voted.\n");
        return;
    }

    printf("Available Candidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s\n", candidates[i].name);
    }

    printf("Enter the name of the candidate you wish to vote for: ");
    scanf("%s", candidate_name);

    int candidate_index = find_candidate(candidate_name);
    if (candidate_index == -1) {
        printf("Candidate not found.\n");
        return;
    }

    candidates[candidate_index].votes++;
    voters[voter_index].has_voted = 1;
    printf("Vote cast successfully for %s!\n", candidates[candidate_index].name);
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("Candidate: %s, Votes: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Vote\n");
        printf("4. Display Results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                register_voter();
                break;
            case 3:
                vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}