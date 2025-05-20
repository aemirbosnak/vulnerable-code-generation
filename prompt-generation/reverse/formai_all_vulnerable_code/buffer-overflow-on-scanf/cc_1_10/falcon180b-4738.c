//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct {
    char name[100];
    int votes;
} candidate_t;

typedef struct {
    char name[100];
    int voter_id;
    int choice;
} vote_t;

candidate_t candidates[MAX_CANDIDATES];
vote_t votes[MAX_VOTERS];
int num_candidates, num_votes;

void add_candidate(char* name) {
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_vote(char* voter_name, int choice) {
    strcpy(votes[num_votes].name, voter_name);
    votes[num_votes].voter_id = num_votes + 1;
    votes[num_votes].choice = choice;
    num_votes++;
}

void count_votes() {
    for (int i = 0; i < num_votes; i++) {
        for (int j = 0; j < num_candidates; j++) {
            if (strcmp(candidates[j].name, votes[i].choice) == 0) {
                candidates[j].votes++;
                break;
            }
        }
    }
}

void print_results() {
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;

    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
    }

    printf("\nEnter number of voters: ");
    scanf("%d", &num_votes);

    for (int i = 0; i < num_votes; i++) {
        printf("Enter voter name: ");
        scanf("%s", votes[i].name);
        printf("Enter voter ID: ");
        scanf("%d", &votes[i].voter_id);
        printf("Enter choice: ");
        scanf("%d", &votes[i].choice);
    }

    count_votes();
    print_results();

    return 0;
}