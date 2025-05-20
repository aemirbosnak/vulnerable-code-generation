//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Voter {
    char name[50];
    int age;
    bool voted;
} voters[100];

struct Candidate {
    char name[50];
    int votes;
} candidates[10];

int num_voters, num_candidates, votes_cast = 0;

void add_voter(){
    printf("Enter name: ");
    scanf("%s", &voters[num_voters].name);
    printf("Enter age: ");
    scanf("%d", &voters[num_voters].age);
    voters[num_voters].voted = false;
    num_voters++;
}

void add_candidate(){
    printf("Enter candidate name: ");
    scanf("%s", &candidates[num_candidates].name);
    candidates[num_candidates].votes = 0;
    num_candidates++;
}

void cast_vote(){
    bool voted = false;
    printf("Enter your name: ");
    char name[50];
    scanf("%s", &name);
    for(int i=0; i<num_voters; i++){
        if(strcmp(voters[i].name, name) == 0){
            if(voters[i].voted){
                printf("You have already voted!\n");
            } else {
                printf("Enter candidate name: ");
                char cname[50];
                scanf("%s", &cname);
                for(int j=0; j<num_candidates; j++){
                    if(strcmp(candidates[j].name, cname) == 0){
                        candidates[j].votes++;
                        votes_cast++;
                        printf("Thank you for voting!\n");
                        voters[i].voted = true;
                        voted = true;
                        break;
                    }
                }
                if(!voted){
                    printf("Invalid candidate name!\n");
                }
            }
            break;
        }
    }
    if(!voted){
        printf("You are not registered to vote!\n");
    }
}

void get_results(){
    printf("Total votes cast: %d\n", votes_cast);
    for(int i=0; i<num_candidates; i++){
        float percent = ((float)candidates[i].votes / (float)votes_cast) * 100;
        printf("%s: %d votes (%.2f%% of total)\n", candidates[i].name, candidates[i].votes, percent);
    }
}

int main(){
    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter number of candidates: ");
    scanf("%d", &num_candidates);
    for(int i=0; i<num_candidates; i++){
        add_candidate();
    }

    printf("Enter number of voters: ");
    scanf("%d", &num_voters);
    for(int i=0; i<num_voters; i++){
        add_voter();
    }

    while(true){
        printf("\nWhat would you like to do?");
        printf("\n1. Cast your vote.");
        printf("\n2. See the results.");
        printf("\n3. Quit.");
        printf("\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: cast_vote(); break;
            case 2: get_results(); break;
            case 3: exit(0); break;
            default: printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}