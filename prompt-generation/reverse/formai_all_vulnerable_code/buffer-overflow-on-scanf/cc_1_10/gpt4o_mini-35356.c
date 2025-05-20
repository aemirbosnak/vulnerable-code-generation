//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
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
    int voted; // 0: not voted, 1: voted
} Voter;

void initialize_candidates(Candidate candidates[], int num);
void initialize_voters(Voter voters[], int num);
void cast_vote(Candidate candidates[], int num_candidates, Voter voters[], int num_voters);
void display_results(Candidate candidates[], int num_candidates);
void print_instructions();

int main() {
    printf("Welcome to the Electronic Voting System\n");
    print_instructions();

    int num_candidates, num_voters;
    printf("Enter number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    if (num_candidates > MAX_CANDIDATES || num_candidates < 1) {
        printf("Invalid number of candidates. Exiting...\n");
        return 1;
    }

    printf("Enter number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);
    if (num_voters > MAX_VOTERS || num_voters < 1) {
        printf("Invalid number of voters. Exiting...\n");
        return 1;
    }

    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];

    initialize_candidates(candidates, num_candidates);
    initialize_voters(voters, num_voters);
    cast_vote(candidates, num_candidates, voters, num_voters);
    display_results(candidates, num_candidates);

    return 0;
}

void print_instructions() {
    printf("\nInstructions:\n");
    printf("1. Each voter can vote for one candidate.\n");
    printf("2. You cannot vote multiple times.\n");
    printf("3. At the end of the voting, results will be displayed.\n\n");
}

void initialize_candidates(Candidate candidates[], int num) {
    for (int i = 0; i < num; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0; // Initialize the votes to 0
    }
}

void initialize_voters(Voter voters[], int num) {
    for (int i = 0; i < num; i++) {
        printf("Enter name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0; // Initialize voting status to not voted
    }
}

void cast_vote(Candidate candidates[], int num_candidates, Voter voters[], int num_voters) {
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].voted == 0) {
            printf("Voter %s, please vote! Enter candidate number (1 to %d): ", voters[i].name, num_candidates);
            int choice;
            scanf("%d", &choice);
            if (choice < 1 || choice > num_candidates) {
                printf("Invalid choice. No vote recorded.\n");
            } else {
                candidates[choice - 1].votes++;
                voters[i].voted = 1; // Mark voter as having voted
                printf("Thank you for voting, %s!\n", voters[i].name);
            }
        } else {
            printf("Sorry, %s, you have already voted.\n", voters[i].name);
        }
    }
}

void display_results(Candidate candidates[], int num_candidates) {
    printf("\nElection Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int max_votes = -1;
    int winner_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    printf("The winner is: %s with %d votes!\n", candidates[winner_index].name, max_votes);
}