//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define VOTER_ID_SIZE 10

/* defining candidate struct */
typedef struct Candidate{
    char name[50];
    int votes;
}Candidate;

/* function to cast votes */
void cast_vote(Candidate candidates[MAX_CANDIDATES], char voter_id[VOTER_ID_SIZE]){
    int i, choice;
    printf("----------------------------------------------\n");
    printf("Candidate List:\n");
    for(i = 0; i < MAX_CANDIDATES; i++){
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("----------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    if(choice > MAX_CANDIDATES || choice < 1){
        printf("Invalid choice!\n");
        return;
    }
    printf("Thank you for voting!\n");
    candidates[choice-1].votes++;
}

/* function to display results */
void display_results(Candidate candidates[MAX_CANDIDATES]){
    int i;
    printf("----------------------------------------------\n");
    printf("Results:\n");
    for(i = 0; i < MAX_CANDIDATES; i++){
        printf("%s - %d\n", candidates[i].name, candidates[i].votes);
    }
    printf("----------------------------------------------\n");
}

/* main function */
int main(){
    Candidate candidates[MAX_CANDIDATES];
    char voter_id[VOTER_ID_SIZE];
    int i;

    /* initializing candidate names and votes */
    strcpy(candidates[0].name, "Candidate 1");
    strcpy(candidates[1].name, "Candidate 2");
    strcpy(candidates[2].name, "Candidate 3");
    strcpy(candidates[3].name, "Candidate 4");
    strcpy(candidates[4].name, "Candidate 5");
    for(i = 0; i < MAX_CANDIDATES; i++){
        candidates[i].votes = 0;
    }

    /* taking input voter id and casting votes */
    printf("Enter your Voter ID: ");
    scanf("%s",voter_id);
    cast_vote(candidates, voter_id);

    /* displaying results */
    display_results(candidates);

    return 0;
}