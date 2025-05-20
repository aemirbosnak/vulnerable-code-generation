//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 20
#define MAX_VOTERS 100

typedef struct {
    char name[30];
    int votes;
} Candidate;

typedef struct {
    char name[30];
    int voted;
} Voter;

void display_candidates(Candidate candidates[], int num_candidates) {
    printf("\nCandidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (%d votes)\n", i+1, candidates[i].name, candidates[i].votes);
    }
    printf("\n");
}

void display_voters(Voter voters[], int num_voters) {
    printf("\nVoters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("%d. %s\n", i+1, voters[i].name);
    }
    printf("\n");
}

void vote(Candidate candidates[], int num_candidates, Voter *voter) {
    int selection;
    display_candidates(candidates, num_candidates);
    printf("%s, please enter the number of your chosen candidate: ", voter->name);
    scanf("%d", &selection);
    if (selection < 1 || selection > num_candidates) {
        printf("Invalid selection.\n");
    } else {
        candidates[selection-1].votes++;
        voter->voted = 1;
        printf("Thank you for voting!\n");
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates = 0;
    int num_voters = 0;
    char input[30];

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates: ");
    scanf("%d", &num_candidates);
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d name: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nPlease enter the number of voters: ");
    scanf("%d", &num_voters);
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d name: ", i+1);
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }

    while (1) {
        printf("\nPlease enter your name to vote (or 'q' to quit): ");
        scanf("%s", input);
        if (strcmp(input, "q") == 0) {
            break;
        }
        int found_voter = 0;
        for (int i = 0; i < num_voters; i++) {
            if (strcmp(input, voters[i].name) == 0) {
                found_voter = 1;
                if (voters[i].voted) {
                    printf("Sorry, you have already voted.\n");
                } else {
                    vote(candidates, num_candidates, &voters[i]);
                }
                break;
            }
        }
        if (!found_voter) {
            printf("You are not registered to vote.\n");
            printf("Please contact an election official.\n");
        }
    }

    printf("\nFinal Results:\n");
    display_candidates(candidates, num_candidates);
    display_voters(voters, num_voters);

    return 0;
}