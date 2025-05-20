//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

/* Define a structure to hold the candidate information */
struct candidate{
    char name[30];
    int votes;
};

/* Declare a function to display the candidate list */
void display_candidates(struct candidate candidates[], int num_candidates){
    int i;
    printf("Candidate List:\n");
    for(i = 0; i < num_candidates; i++){
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

/* Declare a function to cast the vote */
void vote(struct candidate candidates[], int num_candidates, int selected_candidate){
    candidates[selected_candidate-1].votes++;
    printf("Your vote has been cast.\n");
}

/* Declare a function to display the election result */
void display_result(struct candidate candidates[], int num_candidates){
    int i, max_votes = 0, winner_index = 0;
    printf("Election Result:\n");
    for(i = 0; i < num_candidates; i++){
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
        if(candidates[i].votes > max_votes){
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    printf("%s is the winner with %d votes.\n", candidates[winner_index].name, max_votes);
}

/* Main function */
int main(){
    int num_candidates, i, selected_candidate;
    printf("Welcome to Electronic Voting System\n");
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    struct candidate candidates[num_candidates];
    /* Accept candidate details - name and initial votes */
    for(i = 0; i < num_candidates; i++){
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
    /* Display the candidate list */
    display_candidates(candidates, num_candidates);
    /* Cast the vote */
    printf("Select your candidate: ");
    scanf("%d", &selected_candidate);
    /* Check if the selected candidate is valid */
    while(selected_candidate < 1 || selected_candidate > num_candidates){
        printf("Invalid input. Select a valid candidate: ");
        scanf("%d", &selected_candidate);
    }
    /* Cast the vote for the selected candidate */
    vote(candidates, num_candidates, selected_candidate);
    /* Display the election result */
    display_result(candidates, num_candidates);
    return 0;
}