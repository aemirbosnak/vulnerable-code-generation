//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: careful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_VOTERS 1000
#define MAX_CANDIDATES 5

int voter_count = 0;
int candidate_count = 0;
char candidates[MAX_CANDIDATES][20]; //Array to store candidate names
int candidate_votes[MAX_CANDIDATES] = {0}; //Array to store candidate votes

//Method to add candidate to the list of candidates
void add_candidate(char name[20]){
    strcpy(candidates[candidate_count], name);
    candidate_count++;
}

//Method to cast vote
void cast_vote(int candidate_id){
    candidate_votes[candidate_id]++;
}

//Method to print the winner
void print_winner(){
    int max_vote = candidate_votes[0];
    int winner_id = 0;
    //Find the candidate with maximum vote
    for(int i=1; i<candidate_count; i++){
        if(candidate_votes[i] > max_vote){
            max_vote = candidate_votes[i];
            winner_id = i;
        }
    }
    //Print the winner
    printf("The winner is: %s with %d votes!\n", candidates[winner_id], max_vote);
}

int main(){
    char candidate_name[20];
    //Add candidates to the list
    printf("Enter the candidate names:\n");
    while(1){
        printf("Candidate %d: ", candidate_count+1);
        scanf("%s", candidate_name);
        //End the loop if max number of candidates are added or user wants to stop
        if(strcmp(candidate_name, "stop") == 0 || candidate_count == MAX_CANDIDATES){
            break;
        }
        add_candidate(candidate_name);
    }
    //Cast votes
    printf("Voting session started!\n");
    while(1){
        printf("Enter your vote (1-%d) or 0 to exit: ", candidate_count);
        int vote;
        scanf("%d", &vote);
        if(vote == 0){
            break;
        }
        if(vote < 1 || vote > candidate_count){
            printf("Invalid vote!\n");
            continue;
        }
        cast_vote(vote-1);
        printf("Vote casted for %s\n", candidates[vote-1]);
        voter_count++;
    }
    //Print the winner
    printf("\nTotal number of votes casted: %d\n", voter_count);
    print_winner();
    return 0;
}