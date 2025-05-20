//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_VOTERS 1000 // Maximum number of voters can vote
#define MAX_CANDIDATES 10 // Maximum number of candidates in the election
#define MAX_NAME_LENGTH 20 // Maximum length of candidate's name
#define MAX_ID_LENGTH 6 // Maximum length of voter's ID

typedef struct{
    char name[MAX_NAME_LENGTH];
    int votes;
}Candidate;

Candidate candidates[MAX_CANDIDATES];
char voter_ids[MAX_VOTERS][MAX_ID_LENGTH];
int num_voters = 0, num_candidates = 0;

void add_candidate(char* name){
    if(num_candidates < MAX_CANDIDATES){
        strcpy(candidates[num_candidates].name,name);
        candidates[num_candidates].votes = 0;
        num_candidates++;
    }
}

int is_voter_registered(char* id){
    for(int i=0;i<num_voters;i++){
        if(strcmp(voter_ids[i],id) == 0)
            return 1;
    }
    return 0;
}

void add_voter(char* id){
    if(num_voters < MAX_VOTERS){
        strcpy(voter_ids[num_voters],id);
        num_voters++;
    }
}

void display_candidates(){
    printf("List of candidates:\n");
    for(int i=0;i<num_candidates;i++){
        printf("%d. %s\n",i+1,candidates[i].name);
    }
}

void vote(char* id, int choice){
    if(is_voter_registered(id)){
        candidates[choice-1].votes++;
        printf("Vote successful.\n");
    }
    else{
        printf("You are not registered as a voter.\n");
    }
}

void display_results(){
    printf("Results:\n");
    for(int i=0;i<num_candidates;i++){
        printf("%s: %d vote(s)\n",candidates[i].name,candidates[i].votes);
    }
}

int main(){
    printf("Electronic Voting System\n\n");
    printf("Enter candidates (up to %d, enter 'done' to stop):\n",MAX_CANDIDATES);
    char name[MAX_NAME_LENGTH];
    scanf("%s",name);
    while(strcmp(name,"done") != 0){
        add_candidate(name);
        scanf("%s",name);
    }
    display_candidates();
    printf("Enter voters (up to %d, enter 'done' to stop):\n",MAX_VOTERS);
    char id[MAX_ID_LENGTH];
    scanf("%s",id);
    while(strcmp(id,"done") != 0){
        add_voter(id);
        scanf("%s",id);
    }
    int choice;
    do{
        printf("\nEnter voter ID to vote (or 'done' to finish voting): ");
        scanf("%s",id);
        if(strcmp(id,"done") != 0){
            display_candidates();
            printf("Enter your vote (1-%d): ",num_candidates);
            scanf("%d",&choice);
            if(choice >= 1 && choice <= num_candidates){
                vote(id,choice);
            }
            else{
                printf("Invalid choice.\n");
            }
        }
    }while(strcmp(id,"done") != 0);
    display_results();
    return 0;
}