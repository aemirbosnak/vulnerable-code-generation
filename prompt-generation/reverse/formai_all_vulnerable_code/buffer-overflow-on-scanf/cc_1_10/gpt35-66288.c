//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: light-weight
#include<stdio.h>
#include<string.h>

// define the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

// define the candidate structure
struct candidate{
    char name[50];
    int votes;
};

// define the main function
int main(){

    // initialize the candidates and voters
    struct candidate candidates[MAX_CANDIDATES];
    int voters[MAX_VOTERS];
    int candidate_count = 0;
    int voter_count = 0;

    // read the number of candidates from the user
    printf("Enter the number of candidates: ");
    scanf("%d", &candidate_count);

    // read the candidate names from the user
    for(int i = 0; i < candidate_count; i++){
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidates[i].name);
    }

    //initialize the votes to zero
    for(int i = 0; i < candidate_count; i++){
        candidates[i].votes = 0;
    }

    // read the number of voters from the user
    printf("Enter the number of voters: ");
    scanf("%d", &voter_count);

    // read the votes from the voters
    for(int i = 0; i < voter_count; i++){
        int vote = 0;
        printf("Enter the vote for voter %d (1-%d): ", i+1, candidate_count);
        scanf("%d", &vote);

        // validate the vote
        if(vote >= 1 && vote <= candidate_count){
            voters[i] = vote-1;
            candidates[vote-1].votes++;
        }
        else{
            printf("Invalid vote!\n");
            i--;
        }

    }

    // display the results
    printf("Election Results:\n");
    for(int i = 0; i < candidate_count; i++){
        printf("%d. %s: %d\n", i+1, candidates[i].name, candidates[i].votes);
    }

    return 0;
}