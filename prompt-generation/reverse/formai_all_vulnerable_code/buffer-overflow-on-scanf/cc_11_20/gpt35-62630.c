//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    int votes;
};

struct Voter {
    char name[50];
    int has_voted;
};

int main() {
    int num_candidates, num_voters, num_votes = 0;
    struct Candidate *candidates = NULL;
    struct Voter *voters = NULL;

    // read input data
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);

    candidates = (struct Candidate *) malloc(num_candidates * sizeof(struct Candidate));

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nEnter number of voters: ");
    scanf("%d", &num_voters);

    voters = (struct Voter *) malloc(num_voters * sizeof(struct Voter));

    for (int i = 0; i < num_voters; i++) {
        printf("Enter name of voter %d: ", i + 1);
        scanf("%s", voters[i].name);
        voters[i].has_voted = 0;
    }

    // voting process
    while (1) {
        int vote_counted = 0;

        for (int i = 0; i < num_voters; i++) {
            if (voters[i].has_voted) {
                continue;
            }

            printf("\n%s, please select a candidate:\n", voters[i].name);

            for (int j = 0; j < num_candidates; j++) {
                printf("%d. %s\n", j + 1, candidates[j].name);
            }

            int candidate_idx;
            scanf("%d", &candidate_idx);

            if (candidate_idx < 1 || candidate_idx > num_candidates) {
                printf("Invalid choice. Try again.\n");
            } else {
                candidates[candidate_idx - 1].votes++;
                voters[i].has_voted = 1;
                vote_counted = 1;
                num_votes++;
            }
        }

        if (!vote_counted) {
            break;
        }
    }

    // display results
    printf("\nVoting results:\n\n");

    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes (%.1f%%)\n", candidates[i].name, candidates[i].votes, (float) candidates[i].votes / num_votes * 100);
    }

    // free memory
    free(candidates);
    free(voters);

    return 0;
}