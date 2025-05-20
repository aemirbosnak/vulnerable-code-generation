//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Define the number of candidates
#define CANDIDATES 5

//Define the structure for a candidate
typedef struct{
    char name[50];
    int votes;
}candidate;

//Function to display the menu
void displayMenu(){
    printf("\n");
    printf("=================================================\n");
    printf("Welcome to the Electronic Voting System\n");
    printf("=================================================\n");
    printf("1. Vote\n");
    printf("2. View Results\n");
    printf("3. Exit\n");
    printf("=================================================\n");
}

//Function to get the choice from the user
int getChoice(){
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d",&choice);
    return choice;
}

//Function to initialize the candidates
void initCandidates(){
    int i;
    candidate candidates[CANDIDATES];
    for(i=0;i<CANDIDATES;i++){
        candidates[i].name[0]='\0';
        candidates[i].votes=0;
    }
}

//Function to vote
void vote(){
    int choice,i;
    char name[50];
    candidate candidates[CANDIDATES];
    initCandidates();
    printf("\nEnter the name of the candidate you want to vote for: ");
    scanf("%s",name);
    for(i=0;i<CANDIDATES;i++){
        if(strcmp(name,candidates[i].name)==0){
            printf("\n%s is already a candidate.\n",name);
            return;
        }
    }
    strcpy(candidates[0].name,name);
    candidates[0].votes++;
    printf("\n%s has been added as a candidate.\n",name);
    printf("\n=================================================\n");
    printf("Please vote for one of the following candidates:\n");
    for(i=0;i<CANDIDATES;i++){
        printf("%d. %s (%d votes)\n",i+1,candidates[i].name,candidates[i].votes);
    }
    printf("=================================================\n");
    do{
        printf("\nEnter the number of the candidate you want to vote for: ");
        scanf("%d",&choice);
        if(choice<1 || choice>CANDIDATES){
            printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice<1 || choice>CANDIDATES);
    candidates[choice-1].votes++;
    printf("\nThank you for voting for %s.\n",candidates[choice-1].name);
}

//Function to view results
void viewResults(){
    int i;
    candidate candidates[CANDIDATES];
    initCandidates();
    printf("\n=================================================\n");
    printf("The results of the election are:\n");
    for(i=0;i<CANDIDATES;i++){
        printf("%d. %s (%d votes)\n",i+1,candidates[i].name,candidates[i].votes);
    }
    printf("=================================================\n");
}

//Main function
int main(){
    int choice;
    do{
        displayMenu();
        choice=getChoice();
        switch(choice){
            case 1:
                vote();
                break;
            case 2:
                viewResults();
                break;
            case 3:
                printf("\nThank you for using the Electronic Voting System.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }while(choice!=3);
    return 0;
}