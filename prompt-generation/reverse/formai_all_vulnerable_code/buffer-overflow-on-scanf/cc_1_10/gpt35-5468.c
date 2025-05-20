//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct candidate {
    char name[50];
    int vote_count;
} Candidate;

typedef struct voter {
    char name[50];
    bool has_voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int candidate_count = 0, voter_count = 0;

void add_candidate(char name[]);
void print_candidates();
void add_voter(char name[]);
void print_voters();
void cast_vote(char voter_name[], char candidate_name[]);

int main() {
    printf("Welcome to the Electronic Voting System\n\n");

    char option;
    do {
        printf("Please select an option:\n");
        printf("1. Add candidate\n");
        printf("2. Print candidates\n");
        printf("3. Add voter\n");
        printf("4. Print voters\n");
        printf("5. Cast vote\n");
        printf("6. Exit\n");

        scanf(" %c", &option);
        printf("\n");

        switch(option) {
            case '1': {
                char name[50];
                printf("Enter candidate name: ");
                scanf(" %[^\n]s", name);
                add_candidate(name);
                break;
            }
            case '2':
                print_candidates();
                break;
            case '3': {
                char name[50];
                printf("Enter voter name: ");
                scanf(" %[^\n]s", name);
                add_voter(name);
                break;
            }
            case '4':
                print_voters();
                break;
            case '5': {
                char voter_name[50], candidate_name[50];
                printf("Enter voter name: ");
                scanf(" %[^\n]s", voter_name);
                printf("Enter candidate name: ");
                scanf(" %[^\n]s", candidate_name);
                cast_vote(voter_name, candidate_name);
                break;
            }
            case '6':
                printf("Thank you for using the Electronic Voting System\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }

        printf("\n");
    } while(option != '6');

    return 0;
}

void add_candidate(char name[]) {
    if(candidate_count >= MAX_CANDIDATES) {
        printf("Maximum candidates reached. Cannot add more.\n");
        return;
    }

    for(int i = 0; i < candidate_count; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            printf("Candidate already exists.\n");
            return;
        }
    }

    Candidate new_candidate;
    strcpy(new_candidate.name, name);
    new_candidate.vote_count = 0;
    candidates[candidate_count++] = new_candidate;
    printf("Candidate added successfully.\n");
}

void print_candidates() {
    if(candidate_count == 0) {
        printf("No candidates added yet.\n");
        return;
    }

    printf("Candidates:\n");
    for(int i = 0; i < candidate_count; i++)
        printf("%d. %s (%d votes)\n", i+1, candidates[i].name, candidates[i].vote_count);
}

void add_voter(char name[]) {
    if(voter_count >= MAX_VOTERS) {
        printf("Maximum voters reached. Cannot add more.\n");
        return;
    }

    for(int i = 0; i < voter_count; i++) {
        if(strcmp(voters[i].name, name) == 0) {
            printf("Voter already exists.\n");
            return;
        }
    }

    Voter new_voter;
    strcpy(new_voter.name, name);
    new_voter.has_voted = false;
    voters[voter_count++] = new_voter;
    printf("Voter added successfully.\n");
}

void print_voters() {
    if(voter_count == 0) {
        printf("No voters added yet.\n");
        return;
    }

    printf("Voters:\n");
    for(int i = 0; i < voter_count; i++)
        printf("%d. %s (%s)\n", i+1, voters[i].name, voters[i].has_voted ? "has voted" : "has not voted");
}

void cast_vote(char voter_name[], char candidate_name[]) {
    Voter *voter = NULL;
    for(int i = 0; i < voter_count; i++) {
        if(strcmp(voters[i].name, voter_name) == 0) {
            voter = &voters[i];
            break;
        }
    }

    if(voter == NULL) {
        printf("Voter not found.\n");
        return;
    }

    if(voter->has_voted) {
        printf("Voter has already cast their vote.\n");
        return;
    }

    Candidate *candidate = NULL;
    for(int i = 0; i < candidate_count; i++) {
        if(strcmp(candidates[i].name, candidate_name) == 0) {
            candidate = &candidates[i];
            break;
        }
    }

    if(candidate == NULL) {
        printf("Candidate not found.\n");
        return;
    }

    candidate->vote_count++;
    voter->has_voted = true;
    printf("Vote casted successfully.\n");
}