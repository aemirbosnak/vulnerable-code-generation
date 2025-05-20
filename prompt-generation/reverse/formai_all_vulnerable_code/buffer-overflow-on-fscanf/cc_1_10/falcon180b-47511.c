//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct {
    char name[50];
    int age;
    int voterID;
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

int main() {
    FILE *fp;
    Voter voters[MAX_VOTERS];
    Candidate candidates[MAX_CANDIDATES];
    int numVoters = 0, numCandidates = 0, i, j, choice;
    char filename[20];

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the name of the candidate list file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    while (fscanf(fp, "%s %d", candidates[numCandidates].name, &candidates[numCandidates].votes)!= EOF) {
        numCandidates++;
    }

    fclose(fp);

    printf("Please enter the number of voters: ");
    scanf("%d", &numVoters);

    for (i = 0; i < numVoters; i++) {
        printf("Enter voter %d's name: ", i + 1);
        scanf("%s", voters[i].name);
        printf("Enter voter %d's age: ", i + 1);
        scanf("%d", &voters[i].age);
        voters[i].voterID = i + 1;
    }

    printf("Please enter your voter ID: ");
    scanf("%d", &choice);

    for (i = 0; i < numCandidates; i++) {
        if (choice == i + 1) {
            candidates[i].votes++;
            break;
        }
    }

    printf("Thank you for voting!\n");

    return 0;
}