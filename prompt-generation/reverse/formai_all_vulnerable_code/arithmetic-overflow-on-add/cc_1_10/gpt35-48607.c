//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: introspective
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Structure to store the candidate information*/
typedef struct {
    char name[50];
    int votes_count;
} Candidate;

/*Function to retrieve the number of candidates from the user*/
int get_num_candidates() {
    int num_candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    return num_candidates;
}

/*Function to retrieve the candidate information from the user*/
void get_candidate_info(Candidate candidates[], int num_candidates) {
    for(int i=0; i<num_candidates; i++) {
        printf("Enter the name of candidate no. %d: ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes_count = 0;
    }
}

/*Function to display the list of candidates*/
void display_candidates(Candidate candidates[], int num_candidates) {
    printf("List of candidates:\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
}

/*Function to retrieve the voter's choice*/
int get_vote_choice() {
    int vote_choice;
    printf("Enter your choice: ");
    scanf("%d", &vote_choice);
    return vote_choice;
}

/*Function to record the vote*/
void record_vote(Candidate candidates[], int vote_choice) {
    candidates[vote_choice-1].votes_count++;
    printf("You have voted for %s\n", candidates[vote_choice-1].name);
}

/*Function to display the election result*/
void display_election_result(Candidate candidates[], int num_candidates) {
    printf("\nElection Results:\n");
    printf("====================\n");
    for(int i=0; i<num_candidates; i++) {
        printf("%s: %d vote(s)\n", candidates[i].name, candidates[i].votes_count);
    }
    printf("====================\n");
}

/*Main function*/
int main() {
    int num_candidates, num_voters;
    Candidate candidates[50];

    //Get inputs from user
    num_candidates = get_num_candidates();
    get_candidate_info(candidates, num_candidates);
    display_candidates(candidates, num_candidates);

    //Voting process
    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);
    for(int i=0; i<num_voters; i++) {
        printf("\nVoter no. %d\n", i+1);
        display_candidates(candidates, num_candidates);
        int vote_choice = get_vote_choice();
        record_vote(candidates, vote_choice);
    }

    //Result
    display_election_result(candidates, num_candidates);

    return 0;
}