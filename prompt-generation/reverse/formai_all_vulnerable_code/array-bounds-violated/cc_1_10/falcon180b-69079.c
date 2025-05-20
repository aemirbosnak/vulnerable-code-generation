//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

//Defining the maximum number of candidates
#define MAX_CANDIDATES 10

//Defining the structure for a candidate
typedef struct {
    char name[50];
    int votes;
} candidate;

//Function to display the candidates
void display_candidates(candidate candidates[], int num_candidates) {
    printf("The candidates are:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

//Function to get the candidate's name from the user
void get_candidate_name(candidate *candidate) {
    printf("Enter the candidate's name: ");
    scanf("%s", candidate->name);
}

//Function to get the number of candidates from the user
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates (maximum %d): ", MAX_CANDIDATES);
    scanf("%d", &num_candidates);
    return num_candidates;
}

//Function to get the votes for each candidate from the user
void get_votes(candidate candidates[], int num_candidates) {
    for(int i=0; i<num_candidates; i++) {
        printf("Enter the number of votes for candidate %s: ", candidates[i].name);
        scanf("%d", &candidates[i].votes);
    }
}

//Function to determine the winner of the election
int determine_winner(candidate candidates[], int num_candidates) {
    int max_votes = 0;
    int winner_index = -1;
    for(int i=0; i<num_candidates; i++) {
        if(candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
            winner_index = i;
        }
    }
    return winner_index;
}

//Main function
int main() {
    int num_candidates;
    candidate candidates[MAX_CANDIDATES];

    //Get the number of candidates from the user
    num_candidates = get_num_candidates();

    //Get the names and votes for each candidate
    for(int i=0; i<num_candidates; i++) {
        get_candidate_name(&candidates[i]);
        get_votes(candidates, num_candidates);
    }

    //Display the candidates and their votes
    printf("The candidates and their votes are:\n");
    display_candidates(candidates, num_candidates);

    //Determine the winner of the election
    int winner_index = determine_winner(candidates, num_candidates);

    //Display the winner
    printf("\nThe winner of the election is candidate %d with %d votes.\n", winner_index+1, candidates[winner_index].votes);

    return 0;
}