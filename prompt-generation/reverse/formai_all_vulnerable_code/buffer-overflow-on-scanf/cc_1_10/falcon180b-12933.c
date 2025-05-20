//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct candidate {
    char name[50];
    int votes;
};

void addCandidate(struct candidate *candidates, int *numCandidates) {
    char name[50];
    printf("Enter candidate name: ");
    scanf("%s", name);

    int i;
    for(i=0; i<*numCandidates; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            printf("Candidate already exists.\n");
            return;
        }
    }

    strcpy(candidates[*numCandidates].name, name);
    candidates[*numCandidates].votes = 0;
    (*numCandidates)++;
}

void displayCandidates(struct candidate *candidates, int numCandidates) {
    printf("\nCandidates:\n");
    int i;
    for(i=0; i<numCandidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

void castVote(struct candidate *candidates, int numCandidates, int voterNum) {
    char name[50];
    int choice;

    printf("\nEnter candidate name: ");
    scanf("%s", name);

    choice = -1;
    int i;
    for(i=0; i<numCandidates; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            choice = i;
            break;
        }
    }

    if(choice == -1) {
        printf("Invalid candidate name.\n");
        return;
    }

    candidates[choice].votes++;
    printf("\nVote cast for %s.\n", candidates[choice].name);
}

void displayResults(struct candidate *candidates, int numCandidates) {
    int i;
    for(i=0; i<numCandidates; i++) {
        printf("%d. %s - %d votes\n", i+1, candidates[i].name, candidates[i].votes);
    }
}

int main() {
    int numCandidates = 0;
    struct candidate candidates[100];

    addCandidate(candidates, &numCandidates);

    int voterNum = 1;
    while(voterNum <= 100) {
        castVote(candidates, numCandidates, voterNum);
        voterNum++;
    }

    displayResults(candidates, numCandidates);

    return 0;
}