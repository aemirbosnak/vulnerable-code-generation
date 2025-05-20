//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct{
    char name[20];
    int votes;
}Candidate;

typedef struct{
    char name[20];
    int voted;
}Voter;

Candidate candidates[MAX_CANDIDATES];
Voter voters[MAX_VOTERS];
int num_candidates=0, num_voters=0;

void add_candidate(){
    if(num_candidates==MAX_CANDIDATES){
        printf("Error: Maximum number of candidates reached!\n");
        return;
    }
    printf("Enter name of candidate: ");
    scanf("%s", candidates[num_candidates].name);
    candidates[num_candidates].votes=0;
    num_candidates++;
}

void list_candidates(){
    printf("List of Candidates:\n");
    for(int i=0; i<num_candidates; i++){
        printf("%s %d\n", candidates[i].name, candidates[i].votes);
    }
}

void vote(){
    if(num_voters==MAX_VOTERS){
        printf("Error: Maximum number of voters reached!\n");
        return;
    }
    printf("Enter voter name: ");
    char name[20];
    scanf("%s", name);
    for(int i=0; i<num_voters; i++){
        if(strcmp(voters[i].name, name)==0){
            printf("Error: Voter already voted!\n");
            return;
        }
    }
    int index=-1;
    printf("List of Candidates:\n");
    for(int i=0; i<num_candidates; i++){
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("Enter candidate number to vote for: ");
    scanf("%d", &index);
    if(index<1 || index>num_candidates){
        printf("Error: Invalid candidate number!\n");
        return;
    }
    candidates[index-1].votes++;
    strcpy(voters[num_voters].name, name);
    voters[num_voters].voted=1;
    num_voters++;
}

void results(){
    printf("Voting Results:\n");
    printf("Total votes: %d\n", num_voters);
    for(int i=0; i<num_candidates; i++){
        printf("%s: %d\n", candidates[i].name, candidates[i].votes);
    }
}

int main(){
    srand(time(0));
    printf("Welcome to the Cyberpunk Electronic Voting System!\n");
    printf("==============================================\n");

    int option=-1;
    while(option!=0){
        printf("Menu:\n");
        printf("1. Add Candidate\n");
        printf("2. List Candidates\n");
        printf("3. Vote\n");
        printf("4. Results\n");
        printf("0. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                add_candidate();
                break;
            case 2:
                list_candidates();
                break;
            case 3:
                vote();
                break;
            case 4:
                results();
                break;
            case 0:
                printf("Thanks for using the Cyberpunk Electronic Voting System!\n");
                break;
            default:
                printf("Error: Invalid option!\n");
                break;
        }
    }
    return 0;
}