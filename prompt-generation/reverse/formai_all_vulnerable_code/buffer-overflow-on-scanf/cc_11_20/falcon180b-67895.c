//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100
#define MAX_VOTER_NAME_LEN 50

typedef struct {
    char name[MAX_VOTER_NAME_LEN];
    int voter_id;
} Voter;

typedef struct {
    char name[MAX_VOTER_NAME_LEN];
    int votes;
} Candidate;

int main() {
    FILE *fp;
    char filename[100];
    int choice, i, j, k, n, max_votes, total_votes = 0;
    char ch;
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];

    // Initialize candidates
    for (i = 0; i < MAX_CANDIDATES; i++) {
        candidates[i].name[0] = '\0';
        candidates[i].votes = 0;
    }

    // Initialize voters
    for (i = 0; i < MAX_VOTERS; i++) {
        voters[i].name[0] = '\0';
        voters[i].voter_id = i + 1;
    }

    // Read voter data from file
    printf("Enter the name of the voter data file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while ((fscanf(fp, "%s", voters[total_votes].name))!= EOF) {
        total_votes++;
        if (total_votes >= MAX_VOTERS) {
            printf("Maximum number of voters exceeded.\n");
            exit(1);
        }
    }
    fclose(fp);

    // Display list of candidates
    printf("\nList of Candidates:\n");
    for (i = 0; i < MAX_CANDIDATES; i++) {
        if (candidates[i].name[0]!= '\0') {
            printf("%d. %s\n", i + 1, candidates[i].name);
        }
    }

    // Get number of candidates from user
    printf("\nEnter the number of candidates (1-%d): ", MAX_CANDIDATES);
    scanf("%d", &n);

    // Get candidate names from user
    for (i = 0; i < n; i++) {
        printf("\nEnter the name of candidate %d: ", i + 1);
        scanf("%s", candidates[i].name);
    }

    // Display list of voters
    printf("\nList of Voters:\n");
    for (i = 0; i < total_votes; i++) {
        printf("%d. %s\n", voters[i].voter_id, voters[i].name);
    }

    // Allow voters to cast their votes
    for (i = 0; i < total_votes; i++) {
        printf("\nVoter %d, please enter your vote (1-%d): ", voters[i].voter_id, n);
        scanf("%d", &choice);
        for (j = 0; j < n; j++) {
            if (choice == j + 1) {
                candidates[j].votes++;
                break;
            }
        }
    }

    // Display election results
    printf("\nElection Results:\n");
    for (i = 0; i < n; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}