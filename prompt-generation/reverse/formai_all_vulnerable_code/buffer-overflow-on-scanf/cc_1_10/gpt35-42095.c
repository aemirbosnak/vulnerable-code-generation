//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate{
    char name[30];
    int vote_count;
};

struct candidate candidates[5]; // Maximum 5 candidates can participate

int main(){

    int num_candidates, num_voters, vote;
    char voter[30];
    int i,j;

    printf("Welcome to the Electronic Voting System!\n");

    // Retrieving input from user
    printf("Enter the number of candidates: ");
    scanf("%d",&num_candidates);

    for(i=0;i<num_candidates;i++){
        printf("Enter name of candidate %d: ",i+1);
        scanf("%s",candidates[i].name);
        candidates[i].vote_count = 0;
    }

    printf("Enter the number of voters: ");
    scanf("%d",&num_voters);

    // Casting votes
    for(i=0;i<num_voters;i++){
        printf("\nEnter the name of voter %d: ",i+1);
        scanf("%s",voter);

        printf("Candidates available for voting:\n");
        for(j=0;j<num_candidates;j++){
            printf("%d. %s\n",j+1,candidates[j].name);
        }

        printf("%s, Please enter your vote by the candidate number: ",voter);
        scanf("%d",&vote);

        if(vote>0 && vote<=num_candidates){
            candidates[vote-1].vote_count++;
            printf("Congratulations! Your vote has been casted for %s.\n",candidates[vote-1].name);
        }
        else{
            printf("Invalid vote! Please enter the correct candidate number.\n");
            i--;
        }
    }

    // Displaying results
    printf("\nResults:\n");

    for(i=0;i<num_candidates;i++){
        printf("%d. %s - %d votes\n",i+1,candidates[i].name,candidates[i].vote_count);
    }

    return 0;
}