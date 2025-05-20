//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTE_LENGTH 100

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int votes;
} candidate_t;

typedef struct {
    char name[MAX_VOTE_LENGTH];
    int vote;
} voter_t;

candidate_t candidates[MAX_CANDIDATES];
voter_t voters[MAX_VOTERS];

void print_candidates(int candidate_count) {
    printf("Candidate list:\n");
    for (int i = 0; i < candidate_count; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
}

void print_voters(int voter_count) {
    printf("Voter list:\n");
    for (int i = 0; i < voter_count; i++) {
        printf("%d. %s\n", i + 1, voters[i].name);
    }
}

int main() {
    int candidate_count, voter_count;

    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);

    printf("Enter the candidates' names:\n");
    for (int i = 0; i < candidate_count; i++) {
        scanf("%s", candidates[i].name);
    }

    printf("Enter the number of voters: ");
    scanf("%d", &voter_count);

    printf("Enter the voters' names:\n");
    for (int i = 0; i < voter_count; i++) {
        scanf("%s", voters[i].name);
    }

    printf("Enter the votes:\n");
    for (int i = 0; i < voter_count; i++) {
        scanf("%d", &voters[i].vote);
    }

    int total_votes = 0;
    for (int i = 0; i < voter_count; i++) {
        total_votes += voters[i].vote;
    }

    for (int i = 0; i < candidate_count; i++) {
        candidates[i].votes = 0;
    }

    for (int i = 0; i < voter_count; i++) {
        int vote = voters[i].vote;
        printf("Voter %s voted for:\n", voters[i].name);
        for (int j = 0; j < candidate_count; j++) {
            if (vote > 0) {
                candidates[j].votes++;
                vote--;
            }
        }
    }

    printf("\nTotal votes: %d\n", total_votes);

    print_candidates(candidate_count);

    return 0;
}