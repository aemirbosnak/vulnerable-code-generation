//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct candidate {
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

candidate_t candidates[MAX_CANDIDATES];
int num_candidates = 0;
char voter_list[MAX_VOTERS][MAX_NAME_LENGTH];
int num_voters = 0;

void add_candidate(char *name) {
    if (num_candidates < MAX_CANDIDATES) {
        strncpy(candidates[num_candidates].name, name, MAX_NAME_LENGTH);
        candidates[num_candidates].votes = 0;
        num_candidates++;
        printf("Candidate added successfully\n");
    } else {
        printf("Maximum number of candidates reached\n");
    }
}

void add_voter(char *name) {
    if (num_voters < MAX_VOTERS) {
        strncpy(voter_list[num_voters], name, MAX_NAME_LENGTH);
        num_voters++;
        printf("Voter added successfully\n");
    } else {
        printf("Maximum number of voters reached\n");
    }
}

void cast_vote(int candidate_index, char *voter_name) {
    if (candidate_index >= 0 && candidate_index < num_candidates) {
        for (int i = 0; i < num_voters; i++) {
            if (strcmp(voter_name, voter_list[i]) == 0) {
                printf("This voter has already voted\n");
                return;
            }
        }
        candidates[candidate_index].votes++;
        add_voter(voter_name);
        printf("Vote cast successfully\n");
    } else {
        printf("Invalid candidate index\n");
    }
}

void display_results() {
    printf("Election Results\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d: %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    char voter_name[MAX_NAME_LENGTH];
    int candidate_index;

    while (1) {
        printf("Electronic Voting System\n");
        printf("1. Add Candidate\n2. Cast Vote\n3. Display Results\n4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter candidate name: ");
                scanf("%s", name);
                add_candidate(name);
                break;
            case 2:
                printf("Enter candidate index: ");
                scanf("%d", &candidate_index);
                printf("Enter voter name: ");
                scanf("%s", voter_name);
                cast_vote(candidate_index-1, voter_name);
                break;
            case 3:
                display_results();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}