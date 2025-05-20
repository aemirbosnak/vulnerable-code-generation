//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate{
    int candidateID;
    char name[50];
    int votes;
};

struct voter{
    int voterID;
    int hasVoted;
};

int totalVotes = 0;

void displayCandidates(struct candidate* candidates, int numCandidates){
    printf("------------ Candidates ------------\n");
    for(int i=0; i<numCandidates; i++){
        printf("%d | %s | %d\n", candidates[i].candidateID, candidates[i].name, candidates[i].votes);
    }
    printf("------------------------------------\n");
}

void displayVoterDetails(int currentVoter, int numVoters, struct voter* voters){
    printf("\n------------- Voter Information ------------\n");
    printf("Voter ID: %d\n", voters[currentVoter].voterID);
    if(voters[currentVoter].hasVoted == 0){
        printf("Has voted: No\n");
    }else{
        printf("Has voted: Yes\n");
    }
    printf("--------------------------------------------\n");
}

int main(){

    // Initialize candidates
    struct candidate candidates[3];
    candidates[0].candidateID = 1;
    strcpy(candidates[0].name, "John Smith");
    candidates[0].votes = 0;

    candidates[1].candidateID = 2;
    strcpy(candidates[1].name, "Jane Doe");
    candidates[1].votes = 0;

    candidates[2].candidateID = 3;
    strcpy(candidates[2].name, "Michael Johnson");
    candidates[2].votes = 0;

    // Initialize voters
    struct voter voters[5];
    for(int i=0; i<5; i++){
        voters[i].voterID = i+1;
        voters[i].hasVoted = 0;
    }

    printf("Welcome to the Electronic Voting System!\n\n");

    // Loop through voters
    for(int i=0; i<5; i++){

        // Display Voter Details
        displayVoterDetails(i, 5, voters);

        // Check if voter has already voted
        if(voters[i].hasVoted == 0){

            // Display Candidates
            displayCandidates(candidates, 3);

            // Get Candidate Vote
            int candidateVote;
            printf("Enter candidate ID to vote for: ");
            scanf("%d", &candidateVote);

            // Increment Candidate Vote
            for(int j=0; j<3; j++){
                if(candidates[j].candidateID == candidateVote){
                    candidates[j].votes++;
                    totalVotes++;
                    break;
                }
            }

            // Update Voter Status
            voters[i].hasVoted = 1;

            printf("\nThank you for voting!\n\n");

        }else{
            printf("You have already voted!\n\n");
        }
    }

    printf("------------ Final Election Results ------------\n");
    for(int i=0; i<3; i++){
        printf("%d | %s | %d | %.2f %%\n", candidates[i].candidateID, candidates[i].name, candidates[i].votes, ((float)candidates[i].votes / (float)totalVotes)*100);
    }
    printf("------------------------------------------------\n");
    return 0;
}