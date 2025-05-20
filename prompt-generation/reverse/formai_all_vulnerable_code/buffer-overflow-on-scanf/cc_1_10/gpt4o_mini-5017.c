//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: curious
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
    char name[50];
    int voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0;
int voter_count = 0;

void register_candidate() {
    if (candidate_count >= MAX_CANDIDATES) {
        printf("Maximum candidate limit reached.\n");
        return;
    }
    
    printf("Enter candidate name: ");
    scanf("%s", candidates[candidate_count].name);
    candidates[candidate_count].votes = 0;
    candidate_count++;
    printf("Candidate %s registered successfully!\n", candidates[candidate_count - 1].name);
}

void register_voter() {
    if (voter_count >= MAX_VOTERS) {
        printf("Maximum voter limit reached.\n");
        return;
    }
    
    printf("Enter voter name: ");
    scanf("%s", voters[voter_count].name);
    voters[voter_count].voted = 0;
    voter_count++;
    printf("Voter %s registered successfully!\n", voters[voter_count - 1].name);
}

int find_voter(char *name) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int find_candidate(char *name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void cast_vote() {
    char voter_name[50], candidate_name[50];
    
    printf("Enter your name to vote: ");
    scanf("%s", voter_name);
    
    int voter_index = find_voter(voter_name);
    if (voter_index == -1) {
        printf("Voter %s is not registered.\n", voter_name);
        return;
    }
    if (voters[voter_index].voted) {
        printf("Voter %s has already voted.\n", voter_name);
        return;
    }
    
    printf("Enter candidate name to vote: ");
    scanf("%s", candidate_name);
    
    int candidate_index = find_candidate(candidate_name);
    if (candidate_index == -1) {
        printf("Candidate %s is not registered.\n", candidate_name);
        return;
    }
    
    candidates[candidate_index].votes++;
    voters[voter_index].voted = 1;
    printf("Vote casted successfully for candidate %s!\n", candidate_name);
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("Candidate %s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

void display_menu() {
    printf("\nElectronic Voting System Menu:\n");
    printf("1. Register Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Quit\n");
}

int main() {
    int choice;
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_candidate();
                break;
                
            case 2:
                register_voter();
                break;
                
            case 3:
                cast_vote();
                break;
                
            case 4:
                display_results();
                break;
                
            case 5:
                printf("Exiting the system.\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    
    return 0;
}