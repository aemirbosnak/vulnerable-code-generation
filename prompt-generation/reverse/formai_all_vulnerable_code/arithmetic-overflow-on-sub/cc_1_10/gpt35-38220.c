//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 10

typedef struct {
    char name[20];
    int votes;
} candidate_t;

typedef struct {
    int id;
    char name[20];
    int voted;
    int voted_for;
} voter_t;

candidate_t candidates[MAX_CANDIDATES];
int num_candidates = 0;

voter_t voters[MAX_VOTERS];
int num_voters = 0;

void add_candidate() {
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void list_candidates() {
    printf("Candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void add_voter() {
    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    voters[num_voters].id = num_voters + 1;
    voters[num_voters].voted = 0;
    voters[num_voters].voted_for = -1;
    num_voters++;
}

void cast_vote(int voter_id, int candidate_num) {
    if (voters[voter_id].voted) {
        printf("Error: Voter has already cast a vote\n");
        return;
    }

    if (candidate_num < 1 || candidate_num > num_candidates) {
        printf("Error: Invalid candidate number\n");
        return;
    }

    candidates[candidate_num-1].votes++;
    voters[voter_id].voted = 1;
    voters[voter_id].voted_for = candidate_num-1;
    printf("Voter %s has cast a vote for %s\n", voters[voter_id].name, candidates[candidate_num-1].name);
}

void list_results() {
    printf("Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int choice, voter_id, candidate_num;

    while (1) {
        printf("\n1. Add candidate\n");
        printf("2. List candidates\n");
        printf("3. Add voter\n");
        printf("4. Cast vote\n");
        printf("5. List results\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;

            case 2:
                list_candidates();
                break;

            case 3:
                add_voter();
                break;

            case 4:
                printf("Enter voter id: ");
                scanf("%d", &voter_id);
                printf("Enter candidate number: ");
                scanf("%d", &candidate_num);
                cast_vote(voter_id-1, candidate_num);
                break;

            case 5:
                list_results();
                break;

            case 6:
                exit(0);
                break;

            default:
                printf("Error: Invalid choice\n");
                break;
        }
    }

    return 0;
}