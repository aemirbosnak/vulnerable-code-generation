//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char gender;
} Candidate;

Candidate candidates[10];
int numCandidates;

int main() {
    int choice;
    srand(time(NULL));

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please enter the number of candidates:\n");
    scanf("%d", &numCandidates);

    for (int i = 0; i < numCandidates; i++) {
        Candidate candidate;
        candidate.id = i;
        candidate.name[0] = 'A' + rand() % 26;
        candidate.name[1] = 'A' + rand() % 26;
        candidate.name[2] = 'A' + rand() % 26;
        candidate.name[3] = 'A' + rand() % 26;
        candidate.name[4] = 'A' + rand() % 26;
        candidate.name[5] = 'A' + rand() % 26;
        candidate.name[6] = 'A' + rand() % 26;
        candidate.name[7] = 'A' + rand() % 26;
        candidate.name[8] = 'A' + rand() % 26;
        candidate.name[9] = 'A' + rand() % 26;
        candidate.name[10] = 'A' + rand() % 26;
        candidate.name[11] = 'A' + rand() % 26;
        candidate.name[12] = 'A' + rand() % 26;
        candidate.name[13] = 'A' + rand() % 26;
        candidate.name[14] = 'A' + rand() % 26;
        candidate.name[15] = 'A' + rand() % 26;
        candidate.name[16] = 'A' + rand() % 26;
        candidate.name[17] = 'A' + rand() % 26;
        candidate.name[18] = 'A' + rand() % 26;
        candidate.name[19] = 'A' + rand() % 26;
        candidate.name[20] = 'A' + rand() % 26;
        candidate.name[21] = 'A' + rand() % 26;
        candidate.name[22] = 'A' + rand() % 26;
        candidate.name[23] = 'A' + rand() % 26;
        candidate.name[24] = 'A' + rand() % 26;
        candidate.name[25] = 'A' + rand() % 26;
        candidate.age = rand() % 100 + 1;
        candidate.gender = rand() % 2 == 0? 'M' : 'F';

        printf("Candidate %d: %s (%d years old, %c)\n", i, candidate.name, candidate.age, candidate.gender);

        candidates[i] = candidate;
    }

    printf("Please select a candidate to vote for:\n");
    scanf("%d", &choice);

    printf("Thank you for your vote!\n");

    return 0;
}