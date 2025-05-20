//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int votes;
} Candidate;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int voterID;
    int voted;
} Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

void readCandidates() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void readVoters() {
    FILE *fp;
    char filename[100];
    sprintf(filename, "voters.txt");
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: voters.txt not found.\n");
        exit(1);
    }
    int i;
    while (fscanf(fp, "%s %d", voters[i].name, &voters[i].voterID)!= EOF) {
        i++;
        if (i >= MAX_VOTERS) {
            printf("Error: too many voters.\n");
            exit(1);
        }
    }
    fclose(fp);
}

void vote() {
    int i, j;
    for (i = 0; i < MAX_VOTERS; i++) {
        if (!voters[i].voted) {
            printf("%s, please enter your voter ID: ", voters[i].name);
            scanf("%d", &j);
            if (j!= voters[i].voterID) {
                printf("Error: voter ID does not match.\n");
                exit(1);
            }
            printf("Enter candidate name: ");
            scanf("%s", candidates[j].name);
            candidates[j].votes++;
            voters[i].voted = 1;
        }
    }
}

void countVotes() {
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    readCandidates();
    readVoters();
    vote();
    countVotes();
    return 0;
}