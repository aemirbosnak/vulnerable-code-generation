//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LEN 50
#define MAX_VOTE_LEN 10

struct candidate {
    char name[MAX_NAME_LEN];
    int votes;
};

struct voter {
    char name[MAX_NAME_LEN];
    int vote[MAX_CANDIDATES];
};

void read_candidates(struct candidate *candidates) {
    int i;
    printf("Enter the number of candidates (max %d): ", MAX_CANDIDATES);
    scanf("%d", &i);
    for (int j = 0; j < i; j++) {
        printf("Enter candidate name %d: ", j+1);
        scanf("%s", candidates[j].name);
    }
}

void read_voters(struct voter *voters, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter voter name %d: ", i+1);
        scanf("%s", voters[i].name);
        printf("Enter the number of votes (max %d): ", MAX_VOTE_LEN);
        scanf("%d", &voters[i].vote[0]);
        int j;
        for (j = 1; j < MAX_CANDIDATES; j++) {
            voters[i].vote[j] = 0;
        }
    }
}

void count_votes(struct candidate *candidates, struct voter *voters, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_CANDIDATES; j++) {
            if (voters[i].vote[j] > 0) {
                candidates[j].votes++;
            }
        }
    }
}

void print_results(struct candidate *candidates) {
    int i;
    printf("Results:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    struct candidate candidates[MAX_CANDIDATES];
    struct voter voters[MAX_VOTERS];
    int n;

    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of voters (max %d): ", MAX_VOTERS);
    scanf("%d", &n);

    read_candidates(candidates);
    read_voters(voters, n);

    count_votes(candidates, voters, n);

    print_results(candidates);

    return 0;
}