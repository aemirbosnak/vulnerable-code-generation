//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

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

void addCandidate() {
    if (candidate_count >= MAX_CANDIDATES) {
        printf("Candidate limit reached.\n");
        return;
    }

    printf("Enter candidate's name: ");
    scanf(" %[^\n]%*c", candidates[candidate_count].name);
    candidates[candidate_count].votes = 0;
    candidate_count++;
    printf("Candidate added successfully!\n");
}

void registerVoter() {
    if (voter_count >= MAX_VOTERS) {
        printf("Voter limit reached.\n");
        return;
    }

    printf("Enter voter ID: ");
    scanf("%s", voters[voter_count].voter_id);
    voters[voter_count].has_voted = 0;
    voter_count++;
    printf("Voter registered successfully!\n");
}

int findVoterIndex(char* voter_id) {
    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].voter_id, voter_id) == 0) {
            return i;
        }
    }
    return -1;
}

void vote() {
    char voter_id[10];
    printf("Enter your voter ID: ");
    scanf("%s", voter_id);
    
    int voter_index = findVoterIndex(voter_id);
    if (voter_index == -1) {
        printf("Voter not registered!\n");
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

    int candidate_index;
    printf("Select candidate number to vote: ");
    scanf("%d", &candidate_index);
    
    if (candidate_index < 1 || candidate_index > candidate_count) {
        printf("Invalid candidate number!\n");
        return;
    }

    candidates[candidate_index - 1].votes++;
    voters[voter_index].has_voted = 1;
    printf("Thank you for voting!\n");
}

void viewResults() {
    printf("Voting Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Add Candidate\n");
        printf("2. Register Voter\n");
        printf("3. Vote\n");
        printf("4. View Results\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCandidate();
                break;
            case 2:
                registerVoter();
                break;
            case 3:
                vote();
                break;
            case 4:
                viewResults();
                break;
            case 5:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}