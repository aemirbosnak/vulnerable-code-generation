//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 5
#define MAX_NAME_LENGTH 20

// structure definition for candidate
typedef struct Candidate{
    char name[MAX_NAME_LENGTH];
    int vote_count;
}Candidate;

// function to display main menu and receive user input
int display_main_menu();

// function to display result of voting
void display_result(Candidate candidates[], int num_candidates);

int main(){
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates;
    int total_votes = 0;
    int num_voters;
    int i,j;
    int vote; // variable to store user's vote
    int voter_ids[MAX_VOTERS]; // array to store voter ID of each voter
    int is_voted[MAX_VOTERS] = {0}; // array to keep track of whether a particular voter has already voted or not
    
    printf("Welcome to Electronic Voting System\n");

    // get number of candidates
    printf("Enter number of candidates (maximum 5): ");
    scanf("%d",&num_candidates);

    // get candidate name and initialize vote count to 0
    for(i=0;i<num_candidates;i++){
        printf("Enter name of candidate %d: ",i+1);
        scanf("%s",candidates[i].name);
        candidates[i].vote_count = 0;
    }

    // get number of voters
    printf("Enter number of voters (maximum 100): ");
    scanf("%d",&num_voters);

    // get voter ID and check if the voter has already voted or not
    for(i=0;i<num_voters;i++){
        printf("Enter voter ID: ");
        scanf("%d",&voter_ids[i]);
        
        if(is_voted[voter_ids[i]] == 1){
            printf("This voter has already voted.\n");
            i--; // decrement i so that the same voter is asked again for his/her ID
        }else{
            is_voted[voter_ids[i]] = 1;
        }
    }

    printf("Voting has started.\n");
    printf("--------------------\n");

    // loop through each voter and ask for vote
    for(i=0;i<num_voters;i++){
        printf("Voter %d, select your candidate:\n",voter_ids[i]);
        for(j=0;j<num_candidates;j++){
            printf("%d. %s\n",j+1,candidates[j].name);
        }
        printf("Enter your choice: ");
        scanf("%d",&vote);

        if(vote < 1 || vote > num_candidates){
            printf("Invalid choice, please vote again.\n");
            i--; // decrement i so that the same voter is asked again for his/her vote
        }else{
            candidates[vote-1].vote_count++;
            total_votes++;
        }
    }

    // display result of voting
    display_result(candidates, num_candidates);

    return 0;
}

int display_main_menu(){
    int choice;
    
    printf("Electronic Voting System\n");
    printf("------------------------\n");
    printf("1. Start voting\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    return choice;
}

void display_result(Candidate candidates[], int num_candidates){
    int i;
    int winner_index = 0;
    int highest_vote_count = 0;

    printf("Result of Voting:\n");
    printf("------------------\n");

    for(i=0;i<num_candidates;i++){
        printf("%s: %d votes\n",candidates[i].name,candidates[i].vote_count);

        if(candidates[i].vote_count > highest_vote_count){
            highest_vote_count = candidates[i].vote_count;
            winner_index = i;
        }
    }

    printf("------------------\n");
    printf("Winner: %s\n",candidates[winner_index].name);
}