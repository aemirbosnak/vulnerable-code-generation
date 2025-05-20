//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTE_OPTIONS 4

typedef struct {
    char name[50];
    int vote[MAX_VOTE_OPTIONS];
} Voter;

typedef struct {
    char name[50];
    int vote_count;
} Candidate;

Voter voters[MAX_VOTERS];
Candidate candidates[MAX_CANDIDATES];

int main() {
    int num_candidates, num_voters, i, j, k;
    char input[100];

    // Read in number of candidates and their names
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for (i = 0; i < num_candidates; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
    }

    // Read in number of voters and their names
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    for (i = 0; i < num_voters; i++) {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
    }

    // Read in voting options for each candidate
    for (i = 0; i < num_candidates; i++) {
        printf("Enter voting options for %s (separated by spaces): ", candidates[i].name);
        scanf("%s", input);

        k = 0;
        while (input[k]!= '\0') {
            candidates[i].vote_count++;
            for (j = 0; j < MAX_VOTE_OPTIONS; j++) {
                if (input[k] == '1' && j == 0) {
                    voters[i].vote[j]++;
                } else if (input[k] == '1') {
                    voters[i].vote[j]++;
                }
            }
            k++;
        }
    }

    // Print out the results
    printf("\nElection Results:\n");
    for (i = 0; i < num_candidates; i++) {
        printf("Candidate: %s\n", candidates[i].name);
        printf("Vote Count: %d\n", candidates[i].vote_count);
        printf("Votes:\n");
        for (j = 0; j < MAX_VOTE_OPTIONS; j++) {
            if (candidates[i].vote_count > 0) {
                printf("%d. %d\n", j+1, voters[i].vote[j]);
            } else {
                printf("%d. None\n", j+1);
            }
        }
        printf("\n");
    }

    return 0;
}