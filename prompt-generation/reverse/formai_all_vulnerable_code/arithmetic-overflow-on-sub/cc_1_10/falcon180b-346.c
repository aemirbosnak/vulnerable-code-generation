//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTER_NAME_LENGTH 50
#define MAX_CANDIDATE_NAME_LENGTH 50

typedef struct {
    char name[MAX_CANDIDATE_NAME_LENGTH];
    int votes;
} candidate_t;

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int voter_id;
    int voted;
} voter_t;

candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];

int num_candidates = 0;
int num_voters = 0;

int main() {
    srand(time(NULL));

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf(" %[^\n]", candidates[i].name);
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (int i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf(" %[^\n]", voters[i].name);
    }

    printf("Enter your voter ID: ");
    scanf("%d", &voters[num_voters - 1].voter_id);

    int valid_votes = 0;

    for (int i = 0; i < num_voters; i++) {
        if (!voters[i].voted) {
            printf("Voter %s (%d) is eligible to vote.\n", voters[i].name, voters[i].voter_id);

            int vote;

            printf("Enter your vote (1-%d): ", num_candidates);
            scanf("%d", &vote);

            for (int j = 0; j < num_candidates; j++) {
                if (candidates[j].votes == vote) {
                    printf("You have voted for %s.\n", candidates[j].name);
                    candidates[j].votes++;
                    break;
                }
            }

            voters[i].voted = 1;
            valid_votes++;
        } else {
            printf("Voter %s (%d) has already voted.\n", voters[i].name, voters[i].voter_id);
        }
    }

    printf("Total valid votes: %d\n", valid_votes);

    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %s has %d votes.\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}