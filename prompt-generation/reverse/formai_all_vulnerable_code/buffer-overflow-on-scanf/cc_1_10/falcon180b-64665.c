//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100
#define MAX_VOTES 3

typedef struct {
    char name[50];
    int votes[MAX_CANDIDATES];
} Voter;

typedef struct {
    char name[50];
    int totalVotes;
} Candidate;

void shuffleArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int compareStrings(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

int main() {
    srand(time(NULL));

    char candidates[MAX_CANDIDATES][50];
    int numCandidates = 0;

    printf("Enter the number of candidates (1-10): ");
    scanf("%d", &numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        printf("Enter candidate name %d: ", i+1);
        scanf("%s", candidates[i]);
    }

    Candidate *candidatesArray = malloc(numCandidates * sizeof(Candidate));

    for (int i = 0; i < numCandidates; i++) {
        strcpy(candidatesArray[i].name, candidates[i]);
        candidatesArray[i].totalVotes = 0;
    }

    Voter *votersArray = malloc(MAX_VOTERS * sizeof(Voter));

    int numVoters = 0;

    while (numVoters < MAX_VOTERS) {
        printf("Enter voter name (or press enter to finish): ");
        char voterName[50];
        scanf("%s", voterName);

        if (strcmp(voterName, "")!= 0) {
            for (int i = 0; i < numCandidates; i++) {
                printf("Enter vote for %s (1-3): ", candidates[i]);
                scanf("%d", &votersArray[numVoters].votes[i]);
            }

            strcpy(votersArray[numVoters].name, voterName);
            numVoters++;
        }
    }

    qsort(candidatesArray, numCandidates, sizeof(Candidate), compareStrings);

    for (int i = 0; i < numCandidates; i++) {
        printf("%s: %d votes\n", candidatesArray[i].name, candidatesArray[i].totalVotes);
    }

    free(candidatesArray);
    free(votersArray);

    return 0;
}