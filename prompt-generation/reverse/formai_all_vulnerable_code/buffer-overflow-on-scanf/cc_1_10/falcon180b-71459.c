//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_NAME 50

typedef struct {
    char name[MAX_NAME];
    int votes;
} candidate;

typedef struct {
    char name[MAX_NAME];
    int vote;
} voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];
int num_candidates;
int num_voters;

void read_candidates() {
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    printf("Enter the names and details of the candidates:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("Candidate %d:\n", i+1);
        printf("Name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void read_voters() {
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    printf("Enter the names and details of the voters:\n");
    for (int i = 0; i < num_voters; i++) {
        printf("Voter %d:\n", i+1);
        printf("Name: ");
        scanf("%s", voters[i].name);
    }
}

void vote() {
    printf("The candidates are:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }

    printf("Enter your choice: ");
    scanf("%d", &voters[0].vote);

    for (int i = 1; i < num_voters; i++) {
        printf("Voter %d:\n", i+1);
        printf("Name: ");
        scanf("%s", voters[i].name);
        printf("Choice: ");
        scanf("%d", &voters[i].vote);
    }
}

void count_votes() {
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main() {
    read_candidates();
    read_voters();
    vote();
    count_votes();

    return 0;
}