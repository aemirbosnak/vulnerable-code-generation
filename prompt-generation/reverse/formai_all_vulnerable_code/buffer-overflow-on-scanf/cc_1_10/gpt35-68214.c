//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: accurate
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int candidateID;
    char name[20];
    int age;
    int votes;
}candidate;

candidate list[10];

void initialize_candidates(){
    int i;
    for(i=0;i<10;i++){
        list[i].candidateID = i+1;
        sprintf(list[i].name,"Candidate_%d",i+1);
        list[i].age = 18 + rand()%30; //to generate age between 18 and 48
        list[i].votes = 0;
    }
}

void display_candidates(){
    int i;
    printf("Candidate ID   Name            Age\n");
    printf("==================================\n");
    for(i=0;i<10;i++){
        printf("%-15d%-16s%d\n",list[i].candidateID,list[i].name,list[i].age);
    }
}

void vote(){
    int candidateID,i;
    printf("Enter the Candidate ID you want to vote for: ");
    scanf("%d",&candidateID);
    for(i=0;i<10;i++){
        if(list[i].candidateID == candidateID){
            list[i].votes++;
            printf("You have successfully cast your vote to %s\n",list[i].name);
            break;
        }
    }
    if(i == 10){
        printf("Invalid Candidate ID! Please try again.\n");
    }
}

void display_results(){
    int i,maxVotes=0;
    printf("Candidate ID   Name            Votes\n");
    printf("===================================\n");
    for(i=0;i<10;i++){
        printf("%-15d%-16s%d\n",list[i].candidateID,list[i].name,list[i].votes);
        if(list[i].votes > maxVotes){
            maxVotes = list[i].votes;
        }
    }
    printf("===================================\n");
    printf("Winner: \n");
    for(i=0;i<10;i++){
        if(list[i].votes == maxVotes){
            printf("Candidate %d - %s\n",list[i].candidateID,list[i].name);
        }
    }
}

int main(){
    int choice,i;
    initialize_candidates();
    printf("Welcome to Electronic Voting System!\n");
    do{
        printf("\nMenu:\n");
        printf("1. Display Candidates\n");
        printf("2. Vote\n");
        printf("3. Display Results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nCandidates:\n");
                display_candidates();
                break;
            case 2:
                printf("\nVote:\n");
                vote();
                break;
            case 3:
                printf("\nResults:\n");
                display_results();
                break;
            case 4:
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
                break;
        }
    }while(choice != 4);

    printf("\nThank You for using Electronic Voting System!\n");

    return 0;
}