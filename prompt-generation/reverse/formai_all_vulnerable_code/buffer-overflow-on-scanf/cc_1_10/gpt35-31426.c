//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct candidate {
    int id;
    char name[100];
    int votes;
} Candidate;

int main() {
    int num_candidates, num_voters, i, j, v, max_votes = 0, winner_id = -1;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    Candidate candidates[num_candidates];

    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d ID: ", i + 1);
        scanf("%d", &candidates[i].id);

        printf("Enter candidate %d name: ", i + 1);
        scanf("%s", candidates[i].name);

        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    int* voter_ids;
    voter_ids = (int*)malloc(num_voters * sizeof(int));

    for (i = 0; i < num_voters; i++) {
        printf("Enter voter %d ID: ", i + 1);
        scanf("%d", &voter_ids[i]);

        printf("Who would you like to vote for? (Enter candidate ID): ");
        scanf("%d", &v);

        for (j = 0; j < num_candidates; j++) {
            if (candidates[j].id == v) {
                candidates[j].votes++;
            }
        }
    }

    printf("Results:\n");

    for (i = 0; i < num_candidates; i++) {
        printf("%s got %d votes.\n", candidates[i].name, candidates[i].votes);

        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_id = candidates[i].id;
        }
    }

    printf("The winner is candidate %d\n", winner_id);

    free(voter_ids);

    return 0;
}