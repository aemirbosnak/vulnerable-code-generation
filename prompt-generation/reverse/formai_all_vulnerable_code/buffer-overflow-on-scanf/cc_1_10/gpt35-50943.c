//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: configurable
//Header files
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Function Declaration
void displayVoters();
void casteVote();
void countVotes();
void getResult();
//Structure Definition
struct candidate{
    int candidateID;
    char name[20];
    char party[10];
    int voteCount;
};
struct voter{
    int voterID;
    char name[20];
    int voted;
};
//Global Declarations
struct candidate candidates[3];
struct voter voters[5];
int totalVotes;
//Main function
int main(){
    int choice;
    for(int i=0; i<3; i++){
        printf("Enter ID, Name, Party of Candidate %d:\n",(i+1));
        scanf("%d %s %s",&candidates[i].candidateID,&candidates[i].name,&candidates[i].party);
        candidates[i].voteCount = 0;
    }
    for(int i=0; i<5; i++){
        printf("Enter ID, Name of Voter %d:\n",(i+1));
        scanf("%d %s",&voters[i].voterID,&voters[i].name);
        voters[i].voted = 0;
    }
    while(1){
        printf("1: Display Voters\n2. Cast Vote\n3. Count Votes\n4. Get Result\n5. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:displayVoters(); break;
            case 2:casteVote(); break;
            case 3:countVotes(); break;
            case 4:getResult(); break;
            case 5:exit(0); break;
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
//Function Definition for Display Voters
void displayVoters(){
    printf("Voters List:\n");
    printf("Voter ID\t Name\t Voted\n");
    for(int i=0; i<5; i++){
        printf("%d\t%s\t",voters[i].voterID,voters[i].name);
        if(voters[i].voted==1){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}
//Function Definition for Cast Vote
void casteVote(){
    int voterId, candidateId;
    printf("Enter Voter ID:\n");
    scanf("%d",&voterId);
    int flag = 0;
    for(int i=0; i<5; i++){
        if(voters[i].voterID==voterId){
            if(voters[i].voted==0){
                flag =1;
                voters[i].voted=1;
                printf("Enter Candidate ID:\n");
                scanf("%d",&candidateId);
                for(int j=0; j<3; j++){
                    if(candidates[j].candidateID==candidateId){
                        candidates[j].voteCount++;
                        totalVotes++;
                        printf("Thank you for Voting\n");
                    }
                }
            }
            else{
                printf("Voter already voted!\n");
            }
            break;
        }
    }
    if(flag==0){
        printf("Invalid Voter ID\n");
    }
}
//Function Definition for Count Votes
void countVotes(){
    printf("Total Votes:%d\n",totalVotes);
    printf("Candidate Votes:\n");
    for(int i=0; i<3; i++){
        printf("%d\t%s\t%d\n",candidates[i].candidateID,candidates[i].name,candidates[i].voteCount);
    }
}
//Function Definition for Get Result
void getResult(){
    int maxIndex = 0;
    for(int i=1; i<3; i++){
        if(candidates[i].voteCount > candidates[maxIndex].voteCount){
            maxIndex = i;
        }
    }
    printf("Winner is %s with %d votes\n",candidates[maxIndex].name,candidates[maxIndex].voteCount);
}