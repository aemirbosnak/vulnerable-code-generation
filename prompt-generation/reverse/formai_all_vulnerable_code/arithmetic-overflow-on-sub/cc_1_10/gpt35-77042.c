//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Candidate {
    char name[50];
    int votes;
};

int main() {
    int numCandidates, numVoters;
    printf("Enter the number of candidates: ");
    scanf("%d", &numCandidates);
    struct Candidate candidates[numCandidates];

    for(int i = 0; i < numCandidates; i++){
        printf("Enter candidate %d's name: ", i + 1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);

    for(int i = 0; i < numVoters; i++){
        printf("Voter %d: Choose a candidate by typing their number\n", i + 1);
        for(int j = 0; j < numCandidates; j++){
            printf("%d. %s\n", j + 1, candidates[j].name);
        }

        int vote;
        scanf("%d", &vote);
        candidates[vote-1].votes++;
    }

    printf("Voting results:\n");
    for(int i = 0; i < numCandidates; i++){
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    int maxVotes = 0;
    char *winner;
    for(int i = 0; i < numCandidates; i++){
        if(candidates[i].votes > maxVotes){
            maxVotes = candidates[i].votes;
            winner = candidates[i].name;
        }
    }

    printf("The winner is %s with %d votes!\n", winner, maxVotes);

    return 0;
}