//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];
int num_candidates;

void add_candidate() {
    printf("Enter candidate name: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void vote() {
    int voter_id;
    printf("Enter voter ID: ");
    scanf("%d", &voter_id);

    if (voter_id <= 0 || voter_id > MAX_VOTERS) {
        printf("Invalid voter ID.\n");
        return;
    }

    int candidate_id;
    printf("Enter candidate ID: ");
    scanf("%d", &candidate_id);

    if (candidate_id <= 0 || candidate_id > num_candidates) {
        printf("Invalid candidate ID.\n");
        return;
    }

    candidates[candidate_id - 1].votes++;
}

void display_results() {
    printf("\nResults:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("\nElectronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. Vote\n");
        printf("3. Display results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_candidate();
                break;
            case 2:
                vote();
                break;
            case 3:
                display_results();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}