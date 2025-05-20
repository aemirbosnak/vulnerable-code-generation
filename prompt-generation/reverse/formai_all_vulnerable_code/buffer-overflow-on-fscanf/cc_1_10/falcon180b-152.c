//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define VOTE_VALUE 1

typedef struct {
    char name[50];
    int vote;
} candidate_t;

typedef struct {
    char name[50];
    int vote[MAX_CANDIDATES];
} voter_t;

int main() {
    int num_candidates, num_voters;
    char filename[50];
    FILE *fp;
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Read candidate names from file
    sprintf(filename, "candidates.txt");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < num_candidates; i++) {
        fscanf(fp, "%s", candidates[i].name);
        candidates[i].vote = 0;
    }
    fclose(fp);

    // Read voter names and votes from file
    sprintf(filename, "votes.txt");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    num_voters = 0;
    while (fscanf(fp, "%s", voters[num_voters].name)!= EOF) {
        for (int i = 0; i < num_candidates; i++) {
            fscanf(fp, "%d", &voters[num_voters].vote[i]);
        }
        num_voters++;
    }
    fclose(fp);

    // Count votes
    for (int i = 0; i < num_candidates; i++) {
        for (int j = 0; j < num_voters; j++) {
            if (voters[j].vote[i] == VOTE_VALUE) {
                candidates[i].vote++;
            }
        }
    }

    // Print results
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote);
    }

    return 0;
}