//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} candidate;

typedef struct {
    int id;
    char name[50];
    int candidate_id;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates = 0, num_voters = 0;
int candidate_id;

void register_candidate() {
    if (num_candidates >= MAX_CANDIDATES) {
        printf("Maximum number of candidates reached.\n");
        return;
    }

    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes[0] = 0;
    num_candidates++;
}

void register_voter() {
    if (num_voters >= MAX_VOTERS) {
        printf("Maximum number of voters reached.\n");
        return;
    }

    printf("Enter voter ID: ");
    scanf("%d", &voters[num_voters].id);
    printf("Enter voter name: ");
    scanf("%s", voters[num_voters].name);
    num_voters++;
}

void vote() {
    int voter_id;

    printf("Enter voter ID: ");
    scanf("%d", &voter_id);

    int voter_index = -1;
    for (int i = 0; i < num_voters; i++) {
        if (voters[i].id == voter_id) {
            voter_index = i;
            break;
        }
    }

    if (voter_index == -1) {
        printf("Invalid voter ID.\n");
        return;
    }

    printf("Enter candidate ID: ");
    scanf("%d", &candidate_id);

    if (candidate_id < 0 || candidate_id >= num_candidates) {
        printf("Invalid candidate ID.\n");
        return;
    }

    voters[voter_index].candidate_id = candidate_id;
    candidates[candidate_id].votes[voter_id]++;
}

void display_results() {
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes[0]);
        for (int j = 1; j < num_voters; j++) {
            candidates[i].votes[j] += candidates[i].votes[j - 1];
        }
    }
}

void main() {
    srand(time(NULL));

    int choice;

    while (1) {
        printf("\nElectronic Voting System\n");
        printf("1. Register candidate\n");
        printf("2. Register voter\n");
        printf("3. Vote\n");
        printf("4. Display results\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                register_candidate();
                break;
            case 2:
                register_voter();
                break;
            case 3:
                vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}