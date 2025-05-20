//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>

// Defining Structures
struct candidate{
    int id;
    char name[50];
    int vote_count;
};

struct voter{
    int id;
    char voterid[10];
    int has_voted;
};

// Main function
int main(){
    int candidate_count, voter_count, i, j, flag;
    printf("\nEnter the number of candidates: ");
    scanf("%d", &candidate_count);
    printf("\nEnter the number of voters: ");
    scanf("%d", &voter_count);

    // Creating arrays of structures
    struct candidate candidates[candidate_count];
    struct voter voters[voter_count];

    // Taking inputs of candidates
    printf("\nEnter the candidate details:\n");
    for(i=0;i<candidate_count;i++){
        printf("\nCandidate ID: ");
        scanf("%d", &candidates[i].id);
        printf("\nCandidate Name: ");
        scanf("%s", candidates[i].name);
        candidates[i].vote_count=0;
    }

    // Taking inputs of voters
    printf("\nEnter the voter details:\n");
    for(i=0;i<voter_count;i++){
        printf("\nVoter ID: ");
        scanf("%d", &voters[i].id);
        printf("\nVoter Aadhar Number: ");
        scanf("%s", voters[i].voterid);
        voters[i].has_voted=0;
    }

    while(1){
        flag=0;
        int choice, candidate_id, voter_id;
        printf("\nPress 1 to cast vote\nPress 2 to view results\nPress 3 to exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter your voter id: ");
                scanf("%d", &voter_id);

                // Checking if the voter has already voted
                for(i=0;i<voter_count;i++){
                    if(voters[i].id==voter_id){
                        if(voters[i].has_voted==1){
                            printf("\nYou have already voted!");
                            flag=1;
                            break;
                        }
                        else{
                            flag=2;
                            break;
                        }
                    }
                }
                if(flag==1){
                    break;
                }
                else if(flag==0){
                    printf("\nInvalid Voter ID");
                    break;
                }
                printf("\nEnter the candidate ID of your choice: ");
                scanf("%d", &candidate_id);
                for(i=0;i<candidate_count;i++){
                    if(candidates[i].id==candidate_id){
                        candidates[i].vote_count++;
                        printf("\nVote successfully casted!!");
                        flag=1;
                        break;
                    }
                }
                if(flag==1){
                    for(i=0;i<voter_count;i++){
                        if(voters[i].id==voter_id){
                            voters[i].has_voted=1;
                            break;
                        }
                    }
                }
                break;
            case 2:
                printf("\n=======================================");
                printf("\n             ELECTION RESULT:          ");
                printf("\n=======================================");
                printf("\nCandidate ID        Candidate name      Number of Votes");
                for(i=0;i<candidate_count;i++){
                    printf("\n%d                  %s                  %d", candidates[i].id, candidates[i].name, candidates[i].vote_count);
                }
                flag=1;
                break;
            case 3:
                printf("\nTHANK YOU FOR USING OUR SYSTEM!");
                flag=1;
                break;
            default:
                printf("\nInvalid Choice!!");
                break;
        }
        if(flag==1){
            break;
        }
    }

    return 0;
}