//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTES 100

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int num_candidates = 0;

void add_candidate(char *name) {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    strcpy(candidates[num_candidates].name, name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote(int index) {
    if (index < 0 || index >= num_candidates) {
        printf("Invalid candidate index.\n");
        return;
    }

    candidates[index].votes++;
}

void display_results() {
    printf("\n--- Post-Apocalyptic Voting Results ---\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    char command[50];
    char name[50];
    int vote_index;

    while (1) {
        printf("\n--- Post-Apocalyptic Voting System ---\n");
        printf("Enter command (add/vote/results/quit): ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        if (strcmp(command, "add") == 0) {
            printf("Enter candidate name: ");
            scanf("%s", name);
            add_candidate(name);
        } else if (strcmp(command, "vote") == 0) {
            printf("Enter candidate index: ");
            scanf("%d", &vote_index);
            vote(vote_index - 1);
        } else if (strcmp(command, "results") == 0) {
            display_results();
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}