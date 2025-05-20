//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VOTES 10
#define CANDIDATES 4

struct candidate {
    char name[20];
    int votes;
};

void tally_votes(struct candidate *candidates, int votes_cast) {
    for (int i = 0; i < votes_cast; i++) {
        candidates[i].votes++;
    }
}

void print_results(struct candidate *candidates, int votes_cast) {
    printf("\nElection Results\n");
    for (int i = 0; i < votes_cast; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    struct candidate candidates[CANDIDATES] = {
        {"Alice", 0},
        {"Bob",   0},
        {"Carol", 0},
        {"Dave",  0},
    };

    int votes_cast = 0;
    char vote;

    printf("\nWelcome to the Electronic Voting System\n");
    printf("-----------------------------------------\n");
    printf("Cast your vote by entering the corresponding letter (A, B, C, or D):\n");

    while (votes_cast < VOTES) {
        printf("\nCast Vote: ");
        scanf(" %c", &vote);

        switch (vote) {
            case 'A':
                tally_votes(candidates, 0);
                votes_cast++;
                break;
            case 'B':
                tally_votes(candidates, 1);
                votes_cast++;
                break;
            case 'C':
                tally_votes(candidates, 2);
                votes_cast++;
                break;
            case 'D':
                tally_votes(candidates, 3);
                votes_cast++;
                break;
            default:
                printf("Invalid vote. Please try again.\n");
                break;
        }
    }

    print_results(candidates, votes_cast);

    return 0;
}