//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

Candidate candidates[MAX_CANDIDATES];
int vote[MAX_CANDIDATES];

void initialize_candidates() {
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        strcpy(candidates[i].name, "");
        candidates[i].votes = 0;
    }
}

void display_candidates() {
    printf("\nCandidates:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++) {
        if (strlen(candidates[i].name) > 0) {
            printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
        }
    }
}

void cast_vote(int candidate_number) {
    if (candidate_number >= 1 && candidate_number <= MAX_CANDIDATES) {
        vote[candidate_number-1]++;
        candidates[candidate_number-1].votes++;
    } else {
        printf("Invalid candidate number.\n");
    }
}

int main() {
    int choice;

    initialize_candidates();

    while (1) {
        display_candidates();
        printf("\nEnter the number of the candidate you want to vote for, or 0 to exit:\n");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        } else {
            cast_vote(choice);
        }
    }

    printf("\nThe final vote count is:\n");
    display_candidates();

    return 0;
}