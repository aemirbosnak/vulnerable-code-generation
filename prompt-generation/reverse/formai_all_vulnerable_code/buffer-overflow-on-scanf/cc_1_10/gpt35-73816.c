//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include<stdio.h>
#include<string.h>

struct candidate{           // creating structure for candidate details
    char name[30];
    int id;
    int no_of_votes;
};

int main(){
    struct candidate candidates[5];   // creating 5 candidates
    int voter_id[20];    //creating array of voter IDs
    int i,j,votes;
    int candidate_id;
    int n = 5;   // total number of candidates
    
    // initializing candidates
    strcpy(candidates[0].name,"Robert");
    candidates[0].id = 1;
    candidates[0].no_of_votes = 0;
    
    strcpy(candidates[1].name,"Emma");
    candidates[1].id = 2;
    candidates[1].no_of_votes = 0;
    
    strcpy(candidates[2].name,"Michael");
    candidates[2].id = 3;
    candidates[2].no_of_votes = 0;
    
    strcpy(candidates[3].name,"Sophie");
    candidates[3].id = 4;
    candidates[3].no_of_votes = 0;
    
    strcpy(candidates[4].name,"David");
    candidates[4].id = 5;
    candidates[4].no_of_votes = 0;
    
    // taking voter IDs
    printf("Enter voter ID of 20 voters:\n");
    for(i=0;i<20;i++){
        printf("Enter ID of voter %d:",i+1);
        scanf("%d",&voter_id[i]);
    }
    
    // taking votes from voters
    for(i=0;i<20;i++){
        printf("\n\nVoter %d can now cast their vote\n",i+1);
        printf("Enter ID of candidate you want to vote for:");
        scanf("%d",&candidate_id);
        for(j=0;j<n;j++){
            if(candidate_id == candidates[j].id){
                candidates[j].no_of_votes++;
                printf("You have successfully cast your vote to %s\n",candidates[j].name);
                break;
            }
        }
        if(j==n){
            printf("Invalid candidate ID!\n");
            i--;
        }
    }
    
    // displaying results
    printf("\n\nResults:\n");
    for(i=0;i<n;i++){
        printf("%s got %d votes\n",candidates[i].name,candidates[i].no_of_votes);
    }
    
    return 0;
}