//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int voteCount[3] = {0};
    char candidates[3][20] = {"Candidate 1", "Candidate 2", "Candidate 3"};
    int totalVoters = 0;
    char voterName[100];

    printf("Welcome to the Electronic Voting System\n");

    while(1){
        printf("\nEnter your name to start voting (Enter 'exit' to end voting): ");
        fgets(voterName, 100, stdin);
        if(strcmp(voterName, "exit\n") == 0){
            break;
        }else{
            printf("Welcome %s\n", voterName);
            printf("\nSelect the candidate you want to vote for:\n");
            printf("1. %s\n", candidates[0]);
            printf("2. %s\n", candidates[1]);
            printf("3. %s\n", candidates[2]);

            int choice;
            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            if(choice == 1){
                voteCount[0]++;
                printf("Thank you %s for voting to %s\n", voterName, candidates[0]);
            }else if(choice == 2){
                voteCount[1]++;
                printf("Thank you %s for voting to %s\n", voterName, candidates[1]);
            }else if(choice == 3){
                voteCount[2]++;
                printf("Thank you %s for voting to %s\n", voterName, candidates[2]);
            }else{
                printf("Invalid Input, Please try again\n");
            }

            totalVoters++;
            printf("\n\n");
        }
    }

    printf("\n\n*****************************Results*****************************\n");
    printf("%16s%18s\n", "Candidate", "Vote Count");
    for(int i=0;i<3;i++){
        printf("%16s%18d\n", candidates[i], voteCount[i]);
    }
    printf("%16s%18d\n", "Total Voters", totalVoters);

    if(voteCount[0]>voteCount[1] && voteCount[0]>voteCount[2]){
        printf("\n%s won the election with %d votes\n\n", candidates[0], voteCount[0]);
    }else if(voteCount[1]>voteCount[0] && voteCount[1]>voteCount[2]){
        printf("\n%s won the election with %d votes\n\n", candidates[1], voteCount[1]);
    }else if(voteCount[2]>voteCount[0] && voteCount[2]>voteCount[1]){
        printf("\n%s won the election with %d votes\n\n", candidates[2], voteCount[2]);
    }else{
        printf("\nElection was tie, Please conduct the re-election\n\n");
    }

    return 0;
}