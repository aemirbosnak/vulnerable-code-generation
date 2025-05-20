//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(){

    int option, authentication_code,num_of_votes;
    float candidate_percentage[5],total_valid_votes=0;
    char candidates[5][50] = {"Candidate A","Candidate B","Candidate C","Candidate D","Candidate E"};

    printf("\nWelcome to Electronic Voting System\n\n");

    //Authentication
    printf("Please enter your authentication code:\n");
    scanf("%d",&authentication_code);

    if(authentication_code==12345){
        printf("\nAuthentication Successful !");
    }

    else{
        printf("\nInvalid Authentication Code. Please try again later.");
        exit(0);
    }

    printf("\nEnter the number of votes: ");
    scanf("%d", &num_of_votes);
    float candidate_votes[5];
    for (int i = 0; i < 5; i++){
        candidate_votes[i] = 0;
    }

    //Voting
    for (int i = 0; i < num_of_votes; i++){
        printf("\nVote#%d\n", i+1);
        printf("\nEnter your Candidate (1-5): ");
        scanf("%d", &option);
        if (option <= 5){
            candidate_votes[option-1]++;
            total_valid_votes++;
        }
    }

    //Results
    printf("\n\n*********Results*********\n\n");
    for (int i = 0; i < 5; i++){
        candidate_percentage[i] = (candidate_votes[i] / total_valid_votes) * 100;
        printf("\nCandidate %s - Votes: %.0f, Percentage %.2f%%\n", candidates[i], candidate_votes[i], candidate_percentage[i]);
    }

    printf("\nTotal Valid Votes: %.0f\n", total_valid_votes);

    return 0;
}