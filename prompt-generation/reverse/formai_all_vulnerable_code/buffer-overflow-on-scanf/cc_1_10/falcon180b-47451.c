//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100
#define MAX_VOTES 5

typedef struct {
    char name[50];
    int votes;
} Candidate;

typedef struct {
    char voter_id[50];
    int votes[MAX_CANDIDATES];
} Voter;

void read_candidates(Candidate candidates[]) {
    int i, j;
    printf("Enter the number of candidates: ");
    scanf("%d", &j);
    for (i = 0; i < j; i++) {
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void read_voters(Voter voters[]) {
    int i, j;
    printf("Enter the number of voters: ");
    scanf("%d", &j);
    for (i = 0; i < j; i++) {
        printf("Enter the voter ID of voter %d: ", i + 1);
        scanf("%s", voters[i].voter_id);
        for (int k = 0; k < MAX_CANDIDATES; k++) {
            voters[i].votes[k] = 0;
        }
    }
}

void count_votes(Candidate candidates[], Voter voters[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < MAX_CANDIDATES; j++) {
            if (voters[i].votes[j] == 1) {
                candidates[j].votes++;
            }
        }
    }
}

void display_results(Candidate candidates[], int n) {
    int i;
    printf("\nResults:\n");
    printf("Candidate\tVotes\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int n, m;

    printf("Enter the number of candidates: ");
    scanf("%d", &n);
    read_candidates(candidates);

    printf("Enter the number of voters: ");
    scanf("%d", &m);
    read_voters(voters);

    count_votes(candidates, voters, m);

    display_results(candidates, n);

    return 0;
}