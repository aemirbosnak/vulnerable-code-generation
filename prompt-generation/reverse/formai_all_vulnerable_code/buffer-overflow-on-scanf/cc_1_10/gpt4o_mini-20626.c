//GPT-4o-mini DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 3
#define NAME_LENGTH 50

typedef struct{
    char name[NAME_LENGTH];
    int votes;
} Candidate;

typedef struct{
    char name[NAME_LENGTH];
    int hasVoted;
} Voter;

void initializeCandidates(Candidate candidates[]){
    strcpy(candidates[0].name, "Romeo");
    candidates[0].votes = 0;
    
    strcpy(candidates[1].name, "Juliet");
    candidates[1].votes = 0;
    
    strcpy(candidates[2].name, "Mercutio");
    candidates[2].votes = 0;
}

void initializeVoters(Voter voters[], int num_voters){
    for(int i = 0; i < num_voters; i++){
        sprintf(voters[i].name, "Voter_%d", i + 1);
        voters[i].hasVoted = 0;
    }
}

void castVote(Voter *voter, Candidate candidates[]){
    if(voter->hasVoted){
        printf("Dear %s, you have already cast your vote.\n", voter->name);
        return;
    }
    
    int choice = 0;
    
    printf("Enter your choice for voting:\n");
    for(int i = 0; i < MAX_CANDIDATES; i++){
        printf("%d. %s\n", i + 1, candidates[i].name);
    }

    printf("Enter candidate number (1-%d): ", MAX_CANDIDATES);
    scanf("%d", &choice);
    
    if(choice < 1 || choice > MAX_CANDIDATES){
        printf("Invalid choice, dear voter. Your vote is lost!\n");
        return; 
    }
    
    candidates[choice - 1].votes++;
    voter->hasVoted = 1;
    printf("Thank you, %s. Your vote for %s has been counted!\n", voter->name, candidates[choice - 1].name);
}

void displayResults(Candidate candidates[]){
    printf("\n***** Election Results *****\n");
    for(int i = 0; i < MAX_CANDIDATES; i++){
        printf("%s received %d votes.\n", candidates[i].name, candidates[i].votes);
    }
}

int main(){
    Candidate candidates[MAX_CANDIDATES];
    Voter voters[MAX_VOTERS];
    int number_of_voters;

    initializeCandidates(candidates);
    
    printf("How many voters will cast their fates? (Max %d): ", MAX_VOTERS);
    scanf("%d", &number_of_voters);

    if(number_of_voters > MAX_VOTERS){
        printf("Too many voters! Let it be %d instead.\n", MAX_VOTERS);
        number_of_voters = MAX_VOTERS;
    }

    initializeVoters(voters, number_of_voters);

    for(int i = 0; i < number_of_voters; i++){
        castVote(&voters[i], candidates);
    }

    displayResults(candidates);
    
    return 0;
}