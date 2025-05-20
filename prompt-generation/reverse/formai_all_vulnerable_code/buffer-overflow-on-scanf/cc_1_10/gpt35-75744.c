//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include<stdio.h> //Standard Input/Output libraries
#include<string.h> //String libraries

//Number of Candidates
#define num_candidates 4

//Total number of Voters
#define num_voters 20

//Structure for candidate
struct candidate {
    char name[50];
    int votes;
} candidates[num_candidates];

//Structure for voter
struct voter {
    char id[20];
    int voted;
} voters[num_voters];

//Function to add candidates
void addCandidates(){
    for(int i=0;i<num_candidates;i++){
        printf("Enter the name of candidate %d: ",i+1);
        scanf("%s",candidates[i].name);
    }
}

//Function to display candidates
void displayCandidates(){
    printf("\nList of Candidates:\n");
    for(int i=0;i<num_candidates;i++){
        printf("%d. %s\n",i+1,candidates[i].name);
    }
}

//Function to check if the voter has already voted
int hasVoted(char id[]){
    for(int i=0;i<num_voters;i++){
        if(strcmp(voters[i].id,id)==0){
            if(voters[i].voted==1){
                printf("This voter has already voted.\n");
                return 1;
            }else{
                return 0;
            }
        }
    }
    printf("This voter is not registered.\n");
    return 1;
}

//Function to cast vote
void castVote(char id[]){
    char name[50];
    int flag = 0;
    int index;
    printf("\nList of Candidates:\n");
    for(int i=0;i<num_candidates;i++){
        printf("%d. %s\n",i+1,candidates[i].name);
    }
    printf("\nEnter the name of the candidate you want to vote for: ");
    scanf("%s",name);
    for(int i=0;i<num_candidates;i++){
        if(strcmp(candidates[i].name,name)==0){
            index = i;
            flag = 1;
        }
    }
    if(flag == 0){
        printf("Invalid Candidate\n");
    }else{
        for(int i=0;i<num_voters;i++){
            if(strcmp(voters[i].id,id)==0){
                voters[i].voted = 1;
                candidates[index].votes++;
                printf("Your vote has been casted.\n");
                break;
            }
        }
    }
}

//Function to display result
void displayResult(){
    printf("\nVoting Results:\n");
    for(int i=0;i<num_candidates;i++){
        printf("%s - %d vote(s)\n",candidates[i].name,candidates[i].votes);
    }
}

int main(){
    //Add Candidates
    addCandidates();

    //Register Voters
    for(int i=0;i<num_voters;i++){
        printf("Enter the ID of voter %d: ",i+1);
        scanf("%s",voters[i].id);
        voters[i].voted = 0;
    }

    //Display Candidates
    displayCandidates();

    //Cast Vote
    char id[20];
    int flag;
    while(1){
        flag = 0;
        printf("\nEnter your ID to cast your vote (or type 'exit' to stop voting): ");
        scanf("%s",id);
        if(strcmp(id,"exit")==0){
            break;
        }
        flag = hasVoted(id);
        if(flag==1){
            continue;
        }
        castVote(id);
    }

    //Display Result
    displayResult();

    return 0;
}