//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Candidate {
    char name[50];
    int votes;
};

int main() {
    srand(time(0));
    int num_candidates, num_voters, i, j, choice;
    printf("Welcome to the wacky electronic voting system!\n");
    printf("How many candidates are there? ");
    scanf("%d", &num_candidates);

    if (num_candidates < 2) {
        printf("Seriously? You need at least 2 candidates!\n");
        return 0;
    }

    struct Candidate candidates[num_candidates];
    for (i = 0; i < num_candidates; i++) {
        printf("Enter the name of candidate #%d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("How many voters are there? ");
    scanf("%d", &num_voters);

    if (num_voters < num_candidates) {
        printf("Well, this isn't gonna be a fair election!\n");
    }

    for (i = 0; i < num_voters; i++) {
        printf("Voter #%d, please enter your choice:\n", i+1);
        for (j = 0; j < num_candidates; j++) {
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        scanf("%d", &choice);
        candidates[choice-1].votes++;
    }

    printf("And the winner is... ");
    int max_votes = candidates[0].votes;
    for (i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }
    int winners[num_candidates], num_winners = 0;
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes == max_votes) {
            winners[num_winners] = i;
            num_winners++;
        }
    }
    if (num_winners == 1) {
        printf("%s!\n", candidates[winners[0]].name);
    } else {
        printf("a tie between ");
        for (i = 0; i < num_winners; i++) {
            printf("%s", candidates[winners[i]].name);
            if (i < num_winners-1) {
                printf(" and ");
            }
        }
        printf("!\n");
    }

    printf("And here's a breakdown of the votes:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    printf("\nBonus round: let's randomly add some extra votes!\n");
    for (i = 0; i < num_candidates; i++) {
        int extra_votes = rand() % 10;
        printf("%d extra votes go to %s!\n", extra_votes, candidates[i].name);
        candidates[i].votes += extra_votes;
    }

    printf("\nAnd the winner of the bonus round is... ");
    max_votes = candidates[0].votes;
    for (i = 1; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
    }
    num_winners = 0;
    for (i = 0; i < num_candidates; i++) {
        if (candidates[i].votes == max_votes) {
            winners[num_winners] = i;
            num_winners++;
        }
    }
    if (num_winners == 1) {
        printf("%s! Congratulations on your extra votes!\n", candidates[winners[0]].name);
    } else {
        printf("a tie between ");
        for (i = 0; i < num_winners; i++) {
            printf("%s", candidates[winners[i]].name);
            if (i < num_winners-1) {
                printf(" and ");
            }
        }
        printf("! Everyone gets extra votes!\n");
    }

    return 0;
}