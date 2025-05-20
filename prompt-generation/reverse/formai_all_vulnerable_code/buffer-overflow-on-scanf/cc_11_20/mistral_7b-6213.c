//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CANDIDATES 10
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    int votes;
} Candidate;

int main() {
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;

    while (num_candidates < MAX_CANDIDATES) {
        printf("Enter candidate name (%d remaining): ", MAX_CANDIDATES - num_candidates);
        scanf("%s", candidates[num_candidates].name);

        // Check if name is already in the array
        int name_exists = 0;
        for (int i = 0; i < num_candidates; i++) {
            if (strcmp(candidates[i].name, candidates[num_candidates].name) == 0) {
                name_exists = 1;
                break;
            }
        }

        if (name_exists) {
            printf("Candidate with name '%s' already exists.\n", candidates[num_candidates].name);
            num_candidates--;
            continue;
        }

        candidates[num_candidates].votes = 0;
        num_candidates++;
    }

    printf("\nVoting has started...\n");

    for (int i = 0; i < num_candidates; i++) {
        char voted_name[MAX_NAME_LENGTH + 1];
        printf("\nEnter candidate name to cast your vote (%d remaining): ", num_candidates - i);
        scanf("%s", voted_name);

        for (int j = 0; j < num_candidates; j++) {
            if (strcmp(voted_name, candidates[j].name) == 0) {
                candidates[j].votes++;
                break;
            }
        }
    }

    int max_votes = 0;
    int winner_index = -1;

    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    if (winner_index != -1) {
        printf("\nThe winner is: %s", candidates[winner_index].name);
    } else {
        printf("\nAn error occurred during vote counting.\n");
    }

    return 0;
}