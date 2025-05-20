//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

typedef struct {
    int voter_id;
    int selected_candidate;
} vote;

candidate candidates[MAX_CANDIDATES];
vote voters[MAX_VOTERS];
int num_candidates = 0;
int num_voters = 0;

void add_candidate(char name[50]) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached!\n");
        return;
    }
    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void add_voter(int voter_id, int selected_candidate) {
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached!\n");
        return;
    }
    voters[num_voters].voter_id = voter_id;
    voters[num_voters].selected_candidate = selected_candidate;
    num_voters++;
}

void print_results() {
    int i;
    printf("Election Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int i, j, choice;
    char name[50];
    int voter_id, selected_candidate;

    srand(time(NULL));

    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter 1 to add a candidate.\n");
    printf("Enter 2 to vote.\n");
    printf("Enter 3 to display results.\n");
    printf("Enter 0 to exit.\n");

    while (1) {
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            printf("Enter candidate name: ");
            scanf("%s", name);
            add_candidate(name);
        } else if (choice == 2) {
            printf("Enter voter ID: ");
            scanf("%d", &voter_id);
            printf("Enter selected candidate: ");
            scanf("%d", &selected_candidate);
            add_voter(voter_id, selected_candidate);
        } else if (choice == 3) {
            print_results();
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}