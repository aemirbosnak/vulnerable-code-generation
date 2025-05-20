#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate {
    char name[100];
    int votes;
};

int main() {
    int num_candidates, num_voters, i, j, candidate_index;
    struct candidate *candidates;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    candidates = (struct candidate *)malloc(num_candidates * sizeof(struct candidate));

    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Enter voter %d's choice (1-%d): ", i + 1, num_candidates);
        scanf("%d", &candidate_index);
        if (candidate_index > 0 && candidate_index <= num_candidates)
            candidates[candidate_index - 1].votes++;
        else
            printf("Invalid choice. Please enter a valid candidate index.\n");
    }

    int max_votes = 0;
    int winner_index = -1;

    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }

    printf("The winner is %s with %d votes.\n", candidates[winner_index].name, candidates[winner_index].votes);

    free(candidates);
    return 0;
}
