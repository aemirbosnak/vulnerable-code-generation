//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct candidate{
    char name[50];
    int votes;
}candidate;

int main(){
    int num_candidates, num_voters, i, j, choice, vote, max_votes=-1, winner=-1;
    printf("Welcome to the Electronic Voting System!\n\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    candidate candidates[num_candidates];

    //Read in the names of candidates
    for(i=0;i<num_candidates;i++){
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);

    printf("\nGet ready to vote!\n");
    printf("--------------------\n");

    //Read in the choice of each voter
    for(i=0;i<num_voters;i++){
        printf("\nVote %d:\n", i+1);
        for(j=0;j<num_candidates;j++){
            printf("%d. %s\n", j+1, candidates[j].name);
        }
        printf("Enter your choice: ");
        scanf("%d", &choice);
        vote = choice-1;
        if(vote<0 || vote>=num_candidates){
            printf("Invalid choice! Please choose a valid candidate.\n");
            i--;
            continue;
        }
        candidates[vote].votes++;
        printf("Thank you for voting!\n");
    }

    //Find the winner
    for(i=0;i<num_candidates;i++){
        if(candidates[i].votes>max_votes){
            max_votes = candidates[i].votes;
            winner = i;
        }
    }

    printf("\nElection Results\n");
    printf("-----------------\n");
    printf("Winner: %s (with %d votes)\n\n", candidates[winner].name, max_votes);

    printf("Thanks for using the Electronic Voting System!\n");

    return 0;
}