//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate_t;

typedef struct {
    int voter_id;
    int candidate_id;
} vote_t;

candidate_t candidates[MAX_CANDIDATES];
vote_t votes[MAX_VOTERS];

void add_candidate(char* name) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0] == '\0') {
            strcpy(candidates[i].name, name);
            candidates[i].votes = 0;
            return;
        }
    }
    printf("Maximum number of candidates reached.\n");
}

void add_vote(int voter_id, int candidate_id) {
    int i;
    for (i = 0; i < MAX_VOTERS; i++) {
        if (votes[i].voter_id == -1) {
            votes[i].voter_id = voter_id;
            votes[i].candidate_id = candidate_id;
            return;
        }
    }
    printf("Maximum number of voters reached.\n");
}

void print_results() {
    int i, j;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0]!= '\0') {
            printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        }
    }
}

int main() {
    int choice, voter_id, candidate_id;

    system("clear");

    printf("Welcome to the Electronic Voting System!\n");
    printf("----------------------------------------\n");

    while (1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add a candidate\n");
        printf("2. Add a vote\n");
        printf("3. Print results\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the candidate: ");
                scanf("%s", candidates[0].name);
                break;
            case 2:
                printf("Enter your voter ID: ");
                scanf("%d", &voter_id);
                printf("Enter the candidate ID: ");
                scanf("%d", &candidate_id);
                add_vote(voter_id, candidate_id);
                break;
            case 3:
                print_results();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}