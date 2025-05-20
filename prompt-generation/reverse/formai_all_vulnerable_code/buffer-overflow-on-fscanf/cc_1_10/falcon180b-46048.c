//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME_LEN 100
#define MAX_VOTE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    int vote[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[MAX_NAME_LEN];
    int total_votes;
} Candidate;

void read_candidates(FILE *fp, Candidate candidates[MAX_CANDIDATES]) {
    int i = 0;
    while (fscanf(fp, "%s %d", candidates[i].name, &candidates[i].total_votes)!= EOF) {
        i++;
        if (i >= MAX_CANDIDATES) {
            printf("Error: Too many candidates.\n");
            exit(1);
        }
    }
}

void read_voters(FILE *fp, Voter voters[MAX_VOTERS]) {
    int i = 0;
    while (fscanf(fp, "%s %s", voters[i].name, voters[i].vote)!= EOF) {
        i++;
        if (i >= MAX_VOTERS) {
            printf("Error: Too many voters.\n");
            exit(1);
        }
    }
}

int count_votes(Voter voters[MAX_VOTERS], Candidate candidates[MAX_CANDIDATES]) {
    int i, j;
    for (i = 0; i < MAX_VOTERS; i++) {
        for (j = 0; j < MAX_CANDIDATES; j++) {
            if (strcasecmp(voters[i].vote[j], candidates[j].name) == 0) {
                candidates[j].total_votes++;
                break;
            }
        }
    }
    return 0;
}

void print_results(Candidate candidates[MAX_CANDIDATES]) {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].total_votes);
    }
}

int main() {
    FILE *fp;
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];

    fp = fopen("votes.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open votes.txt.\n");
        exit(1);
    }

    read_candidates(fp, candidates);
    read_voters(fp, voters);

    count_votes(voters, candidates);

    print_results(candidates);

    fclose(fp);
    return 0;
}