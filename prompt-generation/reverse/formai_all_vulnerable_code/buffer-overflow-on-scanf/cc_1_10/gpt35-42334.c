//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Candidate{
    char Name[30];
    char Party[30];
    int Votes;
}candidate[10];

void initialize(){
    for(int i=0;i<10;++i){
        candidate[i].Name[0] = '\0';
        candidate[i].Party[0] = '\0';
        candidate[i].Votes = 0;
    }
}

void vote(){
    int n;
    printf("Enter the number of candidates: ");
    scanf("%d",&n);
    printf("Enter the Details of each candidate:\n");
    for(int i=0;i<n;++i){
        printf("Candidate %d:\n",i+1);
        printf("\tName: ");
        scanf("%s",candidate[i].Name);
        printf("\tParty: ");
        scanf("%s",candidate[i].Party);
        candidate[i].Votes = 0;
    }
    int vote;
    printf("Enter the number of voters: ");
    scanf("%d",&vote);
    char choice[30];
    for(int i=0;i<vote;++i){
        printf("Voter %d\n",i+1);
        printf("\tEnter the name of your candidate: ");
        scanf("%s",choice);
        for(int j=0;j<n;++j){
            if(strcmp(candidate[j].Name,choice)==0){
                candidate[j].Votes++;
                printf("Thank you for voting!\n");
                break;
            }
            if(j==n-1){
                printf("Invalid candidate name!\n");
            }
        }
    }
}

void display_results(){
    int n = 10;
    for(int i=0;i<n;++i){
        if(candidate[i].Name[0] == '\0')
            break;
        printf("Candidate %d:\n",i+1);
        printf("\tName: %s\n",candidate[i].Name);
        printf("\tParty: %s\n",candidate[i].Party);
        printf("\tNumber of Votes: %d\n",candidate[i].Votes);
    }
}

void sort_candidates(){
    int i, j;
    struct Candidate temp;
    int n = 10;
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(candidate[i].Votes<candidate[j].Votes) {
                temp=candidate[i];
                candidate[i]=candidate[j];
                candidate[j]=temp;
            }
        }
    }
}

int main(){
    printf("Welcome to the Electronic Voting System\n");
    printf("Please Choose a Task:\n");
    printf("\t1. Vote\n");
    printf("\t2. Display Results\n");
    printf("\t3. Sort Candidates by Votes\n");
    printf("\t4. Exit\n");
    int task;
    do {
        printf("\nEnter your choice: ");
        scanf("%d",&task);
        switch(task){
            case 1: 
                initialize();
                vote(); 
                break;
            case 2: 
                display_results(); 
                break;
            case 3: 
                sort_candidates(); 
                display_results(); 
                break;
            case 4: 
                printf("Thank you for using the Electronic Voting System!\n"); 
                break;
            default: 
                printf("Invalid Choice! Please Try again.\n"); 
                break;
        }
    }while(task!=4);
    return 0;
}