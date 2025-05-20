//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voted; // Flag to check if the voter has already voted
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
    } else {
        printf("Maximum candidate limit reached.\n");
    }
}

void register_voter(const char* name) {
    if (voter_count < MAX_VOTERS) {
        strcpy(voters[voter_count].name, name);
        voters[voter_count].voted = 0;
        voter_count++;
    } else {
        printf("Maximum voter limit reached.\n");
    }
}

void cast_vote() {
    char voter_name[MAX_NAME_LENGTH];
    char candidate_name[MAX_NAME_LENGTH];
    int voter_found = 0;

    printf("Enter your name to vote: ");
    scanf("%s", voter_name);

    for (int i = 0; i < voter_count; i++) {
        if (strcmp(voters[i].name, voter_name) == 0) {
            voter_found = 1;
            if (voters[i].voted) {
                printf("You have already voted!\n");
                return;
            } else {
                voters[i].voted = 1;
                break;
            }
        }
    }

    if (!voter_found) {
        printf("You are not registered to vote.\n");
        return;
    }

    printf("Candidates:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("Enter the name of the candidate you want to vote for: ");
    scanf("%s", candidate_name);

    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidates[i].votes++;
            printf("Vote cast successfully for %s.\n", candidate_name);
            return;
        }
    }

    printf("Candidate not found.\n");
}

void display_results() {
    printf("\nElection Results:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

void print_menu() {
    printf("\nElectronic Voting System\n");
    printf("1. Add Candidate\n");
    printf("2. Register Voter\n");
    printf("3. Cast Vote\n");
    printf("4. Display Results\n");
    printf("5. Exit\n");
}

int main() {
    int option;
    char candidate_name[MAX_NAME_LENGTH];
    char voter_name[MAX_NAME_LENGTH];

    while (1) {
        print_menu();
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the name of the candidate: ");
                scanf("%s", candidate_name);
                add_candidate(candidate_name);
                break;
            case 2:
                printf("Enter your name to register: ");
                scanf("%s", voter_name);
                register_voter(voter_name);
                break;
            case 3:
                cast_vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                printf("Exiting the voting system.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}