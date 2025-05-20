//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: romantic
#include <stdio.h>
#define MAX_VOTERS 1000

struct Candidate{
    char name[100];
    int votes;
};

int main(){

    struct Candidate candidatelist[10];
    int num_candidates, num_voters;
    int i, j, choice, vote;
    int voterids[MAX_VOTERS] = {0};

    printf("Enter the number of Candidates: ");
    scanf("%d", &num_candidates);

    //Adding the candidates to the candidatelist
    for(i=0; i<num_candidates; i++){
        printf("Enter the name of Candidate %d: ", i+1);
        scanf("%s", candidatelist[i].name);
        candidatelist[i].votes = 0;
    }

    printf("Enter the number of Voters: ");
    scanf("%d", &num_voters);

    //Taking the votes from the voters
    for(i=0; i<num_voters; i++){
        printf("Enter Voter ID: ");
        scanf("%d", &choice);

        //Checking if the voter has voted before
        for(j=0; j<i; j++){
            if(voterids[j] == choice){
                printf("Already Voted!!!\n");
                vote = -1;
                break;
            }
        }

        if(vote != -1){
            printf("Enter your Candidate choice (1-%d): ", num_candidates);
            scanf("%d", &vote);

            if(vote >= 1 && vote <= num_candidates){
                candidatelist[vote-1].votes++;
                voterids[i] = choice;
            }
        }   
    }

    //Displaying the results
    printf("Results:\n");
    for(i=0; i<num_candidates; i++){
        printf("%d. %s - %d votes\n", i+1, candidatelist[i].name, candidatelist[i].votes);
    }

    return 0;
}