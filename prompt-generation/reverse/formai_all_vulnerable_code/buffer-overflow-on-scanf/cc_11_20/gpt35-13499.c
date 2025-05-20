//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: random
#include<stdio.h>
#include<string.h>

//Election structure to store candidate names and votes
struct Election{
    char candidateName[20];
    int votes;
};

int main(){
    printf("Welcome to the Electronic Voting System\n");

    //Creating an array of Election structure to store maximum of 10 candidates and their votes
    struct Election candidateList[10];
    int totalCandidates;

    //Taking input for total number of candidates
    printf("Enter the total number of candidates: ");
    scanf("%d", &totalCandidates);

    //Taking input for candidate names and initializing votes to 0
    for(int i=0; i<totalCandidates; i++){
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidateList[i].candidateName);
        candidateList[i].votes = 0;
    }

    //Taking input for total number of voters
    int totalVoters;
    printf("Enter the total number of voters: ");
    scanf("%d", &totalVoters);

    //Looping through each voter to cast their vote
    for(int i=0; i<totalVoters; i++){
        printf("Voter %d, cast your vote\n", i+1);

        //Printing the list of candidates to choose from
        for(int j=0; j<totalCandidates; j++){
            printf("%d. %s\n", j+1, candidateList[j].candidateName);
        }

        //Taking input for voter's choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        //Validating the input choice
        if(choice<1 || choice>totalCandidates){
            printf("Invalid choice. Please try again\n");
            i--;
            continue;
        }

        //Incrementing the voted candidate's votes
        candidateList[choice-1].votes++;
        printf("Thank you for casting your vote\n");
    }

    //Printing the final result of the election
    printf("Final Result:\n");
    for(int i=0; i<totalCandidates; i++){
        printf("%s: %d votes\n", candidateList[i].candidateName, candidateList[i].votes);
    }

    //Finding the winner
    int maxVotes = -1;
    int winnerIndex;
    for(int i=0; i<totalCandidates; i++){
        if(candidateList[i].votes > maxVotes){
            maxVotes = candidateList[i].votes;
            winnerIndex = i;
        }
    }

    //Printing the winner or in case of tie, printing both candidates with maximum votes
    printf("Winner(s):\n");
    for(int i=0; i<totalCandidates; i++){
        if(candidateList[i].votes == maxVotes){
            printf("%s\n", candidateList[i].candidateName);
        }
    }

    return 0;
}