//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 50
#define MAX_VOTES 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int vote;
} Voter;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int num_candidates = 0, num_voters = 0;
    char input[100];
    int choice;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates (up to %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    printf("Please enter the number of voters (up to %d): ", MAX_VOTERS);
    scanf("%d", &num_voters);

    for (int i = 0; i < num_candidates; i++) {
        printf("Please enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    for (int i = 0; i < num_voters; i++) {
        printf("Please enter the name of voter %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Please enter the vote of voter %s: ", voters[i].name);
        scanf("%d", &voters[i].vote);
    }

    printf("Voting has started!\n");
    for (int i = 0; i < num_voters; i++) {
        printf("\nVoter %s's vote: ", voters[i].name);
        for (int j = 0; j < num_candidates; j++) {
            printf("%d. %s ", j+1, candidates[j].name);
        }
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        candidates[choice-1].votes++;
        voters[i].vote = choice;
    }

    printf("\nVoting has ended!\n");
    printf("The results are:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}