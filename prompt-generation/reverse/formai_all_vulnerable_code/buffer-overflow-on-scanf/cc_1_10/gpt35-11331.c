//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate{
    char name[50];
    int vote_count;
}candidates[5];

int main(){
    int i,j,n,vote;
    char str[50];
    
    //initialize candidates
    strcpy(candidates[0].name,"John");
    candidates[0].vote_count = 0;
    strcpy(candidates[1].name,"Mary");
    candidates[1].vote_count = 0;
    strcpy(candidates[2].name,"David");
    candidates[2].vote_count = 0;
    strcpy(candidates[3].name,"Jane");
    candidates[3].vote_count = 0;
    strcpy(candidates[4].name,"Sam");
    candidates[4].vote_count = 0;
    
    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the number of voters: ");
    scanf("%d",&n);
    
    //loop to get votes
    for(i=0;i<n;i++){
        printf("\nVoter %d, enter your vote:\n",i+1);
        printf("1. John\n2. Mary\n3. David\n4. Jane\n5. Sam\n");
        scanf("%d",&vote);
        candidates[vote-1].vote_count++; //increment vote count for selected candidate
    }
    
    //display results
    printf("\nRESULTS\n");
    for(i=0;i<5;i++){
        printf("%d. %s - %d votes\n",i+1,candidates[i].name,candidates[i].vote_count);
    }
    
    //determine winner
    int max_vote = candidates[0].vote_count;
    int winner = 0;
    for(i=1;i<5;i++){
        if(candidates[i].vote_count > max_vote){
            max_vote = candidates[i].vote_count;
            winner = i;
        }
    }
    printf("\nThe winner is %s with %d votes!\n",candidates[winner].name,max_vote);
    
    return 0;
}