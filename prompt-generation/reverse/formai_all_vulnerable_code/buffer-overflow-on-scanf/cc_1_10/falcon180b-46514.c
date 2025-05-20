//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

void print_candidates(candidate candidates[], int num_candidates) {
    printf("Candidate Name\tVotes\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

void vote(candidate candidates[], int num_candidates, int voter_id) {
    int choice;
    printf("Enter your choice (0-%d): ", num_candidates - 1);
    scanf("%d", &choice);
    candidates[choice].votes++;
}

int main() {
    srand(time(NULL));
    candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;
    char name[50];
    while (num_candidates < MAX_CANDIDATES) {
        printf("Enter candidate name (or leave blank to stop): ");
        scanf("%s", name);
        if (name[0] == '\0') {
            break;
        }
        strcpy(candidates[num_candidates].name, name);
        candidates[num_candidates].votes = 0;
        num_candidates++;
    }
    int num_voters = rand() % MAX_VOTERS + 1;
    int votes[MAX_VOTERS];
    for (int i = 0; i < num_voters; i++) {
        votes[i] = rand() % num_candidates;
    }
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        votes[i] = rand() % num_voters;
        candidates[i].votes += votes[i];
    }
    print_candidates(candidates, num_candidates);
    return 0;
}