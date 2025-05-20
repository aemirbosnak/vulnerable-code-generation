//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct{
    char name[50];
    int votes;
}candidate;

typedef struct{
    char name[50];
    int voter_id;
}voter;

candidate candidates[MAX_CANDIDATES];
voter voters[MAX_VOTERS];

void add_candidate(){
    int i;
    for(i=0;i<MAX_CANDIDATES;i++){
        if(candidates[i].name[0]=='\0'){
            break;
        }
    }
    printf("Enter the name of the candidate: ");
    scanf("%s",candidates[i].name);
    candidates[i].votes=0;
}

void add_voter(){
    int i;
    for(i=0;i<MAX_VOTERS;i++){
        if(voters[i].name[0]=='\0'){
            break;
        }
    }
    printf("Enter the name of the voter: ");
    scanf("%s",voters[i].name);
    voters[i].voter_id=i+1;
}

void vote(){
    int i,j;
    char name[50];
    for(i=0;i<MAX_VOTERS;i++){
        if(voters[i].name[0]!='\0'){
            printf("Voter %d's turn to vote.\n",i+1);
            printf("Enter the name of the candidate you want to vote for: ");
            scanf("%s",name);
            for(j=0;j<MAX_CANDIDATES;j++){
                if(strcmp(name,candidates[j].name)==0){
                    candidates[j].votes++;
                    printf("Your vote has been counted.\n");
                    break;
                }
            }
        }
    }
}

void display_results(){
    int i;
    printf("\nResults:\n");
    for(i=0;i<MAX_CANDIDATES;i++){
        if(candidates[i].name[0]!='\0'){
            printf("%s: %d votes\n",candidates[i].name,candidates[i].votes);
        }
    }
}

int main(){
    int choice;
    while(true){
        printf("\nElectronic Voting System\n");
        printf("1. Add candidate\n");
        printf("2. Add voter\n");
        printf("3. Vote\n");
        printf("4. Display results\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_candidate();
                break;
            case 2:
                add_voter();
                break;
            case 3:
                vote();
                break;
            case 4:
                display_results();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}