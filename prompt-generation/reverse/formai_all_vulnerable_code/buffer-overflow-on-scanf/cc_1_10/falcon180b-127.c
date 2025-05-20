//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 1000

typedef struct{
    char name[50];
    int votes;
}Candidate;

typedef struct{
    char name[50];
    int voter_id;
}Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];

int num_candidates=0;
int num_voters=0;

void add_candidate(){
    int i;
    printf("Enter candidate name: ");
    scanf("%s",candidates[num_candidates].name);
    printf("Candidate %s added.\n",candidates[num_candidates].name);
    num_candidates++;
}

void vote(){
    int i,j;
    printf("Enter voter ID: ");
    scanf("%d",&voters[num_voters].voter_id);
    printf("Enter candidate name: ");
    scanf("%s",voters[num_voters].name);
    for(i=0;i<num_candidates;i++){
        if(strcmp(candidates[i].name,voters[num_voters].name)==0){
            candidates[i].votes++;
            break;
        }
    }
    printf("Vote casted.\n");
    num_voters++;
}

void display_results(){
    int i;
    printf("\n");
    for(i=0;i<num_candidates;i++){
        printf("%s: %d votes\n",candidates[i].name,candidates[i].votes);
    }
}

int main(){
    int choice;
    do{
        printf("\n");
        printf("1. Add candidate\n");
        printf("2. Vote\n");
        printf("3. Display results\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add_candidate();
                break;
            case 2:
                vote();
                break;
            case 3:
                display_results();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice!=4);
    return 0;
}