//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int voter_id[MAX_VOTERS];
int num_voters = 0;
int num_candidates = 0;

void setup() {
    printf("Welcome to the Retro Electronic Voting System!\n");
    printf("Enter the number of candidates:\n");
    scanf("%d", &num_candidates);

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nVoting has started. Please enter your voter ID to cast your vote.\n");
}

int is_valid_voter(int id) {
    for (int i = 0; i < num_voters; i++) {
        if (voter_id[i] == id) {
            return 1;
        }
    }

    return 0;
}

void vote(int id, int candidate) {
    if (is_valid_voter(id)) {
        candidates[candidate - 1].votes++;
        voter_id[num_voters++] = id;
        printf("Vote casted for candidate %s.\n", candidates[candidate - 1].name);
    } else {
        printf("Invalid voter ID.\n");
    }
}

void display_results() {
    printf("\nResults:\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));
    int choice, id, candidate;

    setup();

    while (1) {
        printf("\n1. Cast Vote\n2. Display Results\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your voter ID: ");
                scanf("%d", &id);
                printf("Enter the number of the candidate you want to vote for: ");
                scanf("%d", &candidate);
                vote(id, candidate);
                break;
            case 2:
                display_results();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}