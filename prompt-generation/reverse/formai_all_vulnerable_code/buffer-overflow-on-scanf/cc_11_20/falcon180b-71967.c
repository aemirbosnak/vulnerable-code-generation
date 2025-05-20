//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voter_id;
} Voter;

int main() {
    int num_candidates, num_voters;
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int i, j, k, choice;
    char input[100];

    srand(time(NULL));

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Enter the name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].voter_id = i + 1;
    }

    printf("Voting has begun!\n");

    while (1) {
        printf("Enter your voter ID: ");
        scanf("%d", &k);

        if (k < 1 || k > num_voters) {
            printf("Invalid voter ID.\n");
            continue;
        }

        printf("Enter your choice (candidate number): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > num_candidates) {
            printf("Invalid choice.\n");
            continue;
        }

        for (i = 0; i < num_candidates; i++) {
            if (strcmp(candidates[i].name, "Ada Lovelace") == 0) {
                candidates[i].votes++;
                break;
            }
        }

        printf("Thank you for voting!\n");
    }

    printf("Voting has ended.\n");

    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}