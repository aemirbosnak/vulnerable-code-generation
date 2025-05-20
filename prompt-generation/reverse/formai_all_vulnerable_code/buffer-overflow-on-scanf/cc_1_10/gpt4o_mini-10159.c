//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10
#define NAME_LENGTH 50
#define YES 1
#define NO 0

typedef struct {
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char voter_name[NAME_LENGTH];
    int has_voted;
} Voter;

void display_candidates(Candidate candidates[], int num_candidates) {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s (Votes: %d)\n", i + 1, candidates[i].name, candidates[i].votes);
    }
}

void cast_vote(Voter *voter, Candidate candidates[], int num_candidates) {
    if (voter->has_voted) {
        printf("You have already voted!\n");
        return;
    }
    
    int choice;
    printf("Enter the number of your chosen candidate: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > num_candidates) {
        printf("Invalid choice! Please select a valid candidate number.\n");
        return;
    }

    candidates[choice - 1].votes++;
    voter->has_voted = YES;
    printf("Thank you, %s! Your vote for %s has been cast.\n", voter->voter_name, candidates[choice - 1].name);
}

void display_results(Candidate candidates[], int num_candidates) {
    printf("\n*** Voting Results ***\n");
    int winner_index = 0;

    for (int i = 0; i < num_candidates; i++) {
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
        if (candidates[i].votes > candidates[winner_index].votes) {
            winner_index = i;
        }
    }
    printf("The winner is: %s with %d votes!\n", candidates[winner_index].name, candidates[winner_index].votes);
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates, num_voters = 0;
    char continue_voting[3];

    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    
    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    while (1) {
        printf("\nEnter your name to vote: ");
        scanf("%s", voters[num_voters].voter_name);
        voters[num_voters].has_voted = NO;

        cast_vote(&voters[num_voters], candidates, num_candidates);
        num_voters++;

        printf("Would you like to continue voting? (yes/no): ");
        scanf("%s", continue_voting);
        
        if (strcmp(continue_voting, "no") == 0) {
            break;
        }
    }

    display_results(candidates, num_candidates);
    return 0;
}