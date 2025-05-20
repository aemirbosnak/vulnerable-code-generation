//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 1000
#define MAX_VOTER_NAME_LENGTH 50

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int voterID;
} Voter;

typedef struct {
    char name[MAX_VOTER_NAME_LENGTH];
    int votes;
} Candidate;

int main() {
    FILE *fp;
    char filename[50] = "voter_list.txt";
    Voter voters[MAX_VOTERS];
    int numVoters = 0;
    Candidate candidates[MAX_CANDIDATES];
    int numCandidates = 0;
    char filename2[50] = "candidate_list.txt";
    char choice;
    int voterID;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening voter list file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", voters[numVoters].name, &voters[numVoters].voterID)!= EOF) {
        numVoters++;
    }

    fclose(fp);

    fp = fopen(filename2, "r");
    if (fp == NULL) {
        printf("Error opening candidate list file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s", candidates[numCandidates].name)!= EOF) {
        numCandidates++;
    }

    fclose(fp);

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter your voter ID:\n");
    scanf("%d", &voterID);

    for (i = 0; i < numVoters; i++) {
        if (voters[i].voterID == voterID) {
            printf("Welcome, %s!\n", voters[i].name);
            break;
        }
    }

    if (i == numVoters) {
        printf("Invalid voter ID.\n");
        exit(1);
    }

    printf("Please select a candidate to vote for:\n");
    for (j = 0; j < numCandidates; j++) {
        printf("%d. %s\n", j+1, candidates[j].name);
    }

    scanf("%c", &choice);

    if (choice < '1' || choice > '5') {
        printf("Invalid choice.\n");
        exit(1);
    }

    candidates[choice - '1'].votes++;

    printf("Thank you for voting!\n");

    return 0;
}