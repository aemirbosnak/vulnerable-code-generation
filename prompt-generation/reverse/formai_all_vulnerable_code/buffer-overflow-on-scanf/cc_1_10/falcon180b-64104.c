//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define NUM_CANDIDATES 5
#define NUM_VOTERS 100

typedef struct {
    char name[50];
    int age;
    int voterID;
} Voter;

typedef struct {
    char name[50];
    int votes;
} Candidate;

void createVoters(Voter voters[]) {
    int i;
    for (i = 0; i < NUM_VOTERS; i++) {
        printf("Enter the name of voter %d:\n", i + 1);
        scanf("%s", voters[i].name);
        printf("Enter the age of voter %s:\n", voters[i].name);
        scanf("%d", &voters[i].age);
        voters[i].voterID = i + 1;
    }
}

void createCandidates(Candidate candidates[]) {
    int i;
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("Enter the name of candidate %d:\n", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void vote(Voter voters[], Candidate candidates[]) {
    int i, j, choice;
    printf("\n");
    for (i = 0; i < NUM_VOTERS; i++) {
        printf("Voter %d, please enter your choice:\n", voters[i].voterID);
        for (j = 0; j < NUM_CANDIDATES; j++) {
            printf("%d. %s\n", j + 1, candidates[j].name);
        }
        scanf("%d", &choice);
        if (choice >= 1 && choice <= NUM_CANDIDATES) {
            candidates[choice - 1].votes++;
        } else {
            printf("Invalid choice!\n");
        }
    }
}

void displayResults(Candidate candidates[]) {
    int i;
    printf("\n");
    for (i = 0; i < NUM_CANDIDATES; i++) {
        printf("%s got %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    Voter voters[NUM_VOTERS];
    Candidate candidates[NUM_CANDIDATES];

    createVoters(voters);
    createCandidates(candidates);

    vote(voters, candidates);

    displayResults(candidates);

    return 0;
}