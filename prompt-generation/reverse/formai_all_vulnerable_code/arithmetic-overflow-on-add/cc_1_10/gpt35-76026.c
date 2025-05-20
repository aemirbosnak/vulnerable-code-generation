//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>

#define MAX_CANDIDATES 10 //Maximum number of candidates allowed in the election
#define MAX_VOTERS 50 //Maximum number of voters allowed
#define MAX_NAME_LENGTH 20 //Maximum length of a candidate name

int numCandidates = 0; //Number of candidates currently in the election
char candidateNames[MAX_CANDIDATES][MAX_NAME_LENGTH + 1]; //Array to store the names of the candidates
int candidateVotes[MAX_CANDIDATES] = {0}; //Array to store the number of votes each candidate has received

void castVote(int voterID, int candidateID) {
    candidateVotes[candidateID]++;
    printf("Voter %d has cast their vote for %s.\n", voterID, candidateNames[candidateID]);
    sleep(1); //Simulate some delay in the voting process
}

int main() {
    srand(time(NULL)); //Seed the random number generator
    
    int numVoters;
    printf("Enter the number of voters: ");
    scanf("%d", &numVoters);
    
    if(numVoters > MAX_VOTERS) {
        printf("Error: Only %d voters are allowed.\n", MAX_VOTERS);
        exit(0);
    }
    
    printf("Enter the number of candidates (Up to 10): ");
    
    scanf("%d", &numCandidates);
    
    if(numCandidates > MAX_CANDIDATES) {
        printf("Error: Only up to %d candidates are allowed.\n", MAX_CANDIDATES);
        exit(0);
    }
    
    for(int i = 0; i < numCandidates; i++) {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidateNames[i]);
    }
    
    //Simulate the voting process
    for(int i = 0; i < numVoters; i++) {
        int candidateID = rand() % numCandidates; //Pick a random candidate ID
        castVote(i+1, candidateID);
    }
    
    //Display the results
    printf("Election Results:\n");
    printf("-----------------\n");
    for(int i = 0; i < numCandidates; i++) {
        printf("%s:\t%d votes\n", candidateNames[i], candidateVotes[i]);
    }
    
    return 0;
}