//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTES 1000
#define MAX_CANDIDATES 5

struct candidate {
    char name[20];
    int votes;
};

void print_candidates(struct candidate candidates[MAX_CANDIDATES], int num_candidates) {
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void print_results(struct candidate candidates[MAX_CANDIDATES], int num_candidates) {
    printf("RESULTS\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int get_winner(struct candidate candidates[MAX_CANDIDATES], int num_candidates) {
    int max_votes = 0;
    int winner = 0;
    for (int i = 0; i < num_candidates; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner = i;
        }
    }
    return winner;
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    printf("Enter number of candidates (maximum %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    getchar();

    if (num_candidates > MAX_CANDIDATES) {
        printf("Maximum number of candidates is %d\n", MAX_CANDIDATES);
        return 1;
    }

    for (int i = 0; i < num_candidates; i++) {
        printf("Enter name of candidate %d: ", i+1);
        fgets(candidates[i].name, 20, stdin);
        candidates[i].name[strcspn(candidates[i].name, "\n")] = 0;
        candidates[i].votes = 0;
    }

    int num_votes = 0;
    char vote[20];
    int vote_cast[MAX_VOTES];
    int valid_vote = 0;

    while (1) {
        printf("Vote for a candidate by entering their name (or type 'done' to stop voting): ");
        fgets(vote, 20, stdin);
        vote[strcspn(vote, "\n")] = 0;

        if (strcmp(vote, "done") == 0) {
            break;
        }

        valid_vote = 0;
        for (int i = 0; i < num_candidates; i++) {
            if (strcmp(candidates[i].name, vote) == 0) {
                candidates[i].votes++;
                vote_cast[num_votes] = i;
                num_votes++;
                valid_vote = 1;
                break;
            }
        }

        if (!valid_vote) {
            printf("Invalid vote.\n");
        }
    }

    print_results(candidates, num_candidates);
    int winner = get_winner(candidates, num_candidates);
    printf("Winner: %s\n", candidates[winner].name);

    return 0;
}