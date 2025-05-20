//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

typedef struct {
    char name[50];
    int vote_count;
} Candidate;

typedef struct {
    char name[50];
    int voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char name[]) {
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].vote_count = 0;
    num_candidates++;
}

void add_voter(char name[]) {
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voted = 0;
    num_voters++;
}

void cast_vote(char voter_name[], char candidate_name[]) {
    int i, j;
    for (i = 0; i < num_voters; i++) {
        if (strcmp(voters[i].name, voter_name) == 0) {
            if (voters[i].voted == 0) {
                for (j = 0; j < num_candidates; j++) {
                    if (strcmp(candidates[j].name, candidate_name) == 0) {
                        candidates[j].vote_count++;
                        voters[i].voted = 1;
                        printf("Vote cast successfully!\n");
                        return;
                    }
                }
                printf("Error: Candidate not found.\n");
                return;
            }
            printf("Error: Voter has already cast a vote.\n");
            return;
        }
    }
    printf("Error: Voter not found.\n");
}

void print_results() {
    int i;
    printf("Candidates:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }
}

int main() {
    int option;
    char name[50];
    char voter_name[50];
    char candidate_name[50];
    printf("Welcome to the Electronic Voting System.\n");
    while (1) {
        printf("Options:\n1. Add Candidate\n2. Add Voter\n3. Cast Vote\n4. View Results\n5. Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter candidate name:\n");
                scanf("%s", name);
                add_candidate(name);
                printf("Candidate added successfully!\n");
                break;
            case 2:
                printf("Enter voter name:\n");
                scanf("%s", name);
                add_voter(name);
                printf("Voter added successfully!\n");
                break;
            case 3:
                printf("Enter voter name:\n");
                scanf("%s", voter_name);
                printf("Enter candidate name:\n");
                scanf("%s", candidate_name);
                cast_vote(voter_name, candidate_name);
                break;
            case 4:
                print_results();
                break;
            case 5:
                printf("Thank you for using the Electronic Voting System.\n");
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    }
    return 0;
}