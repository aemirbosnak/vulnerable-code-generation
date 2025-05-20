//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate{
    int id;
    char name[30];
    int votes;
};

int main()
{
    int numCand, i, j;
    char temp[30];
    printf("Enter number of candidates: ");
    scanf("%d", &numCand);

    struct candidate *c = (struct candidate*) malloc(numCand*sizeof(struct candidate));

    //Input candidate details
    for(i=0;i<numCand;i++){
        printf("\nEnter candidate %d ID: ", i+1);
        scanf("%d", &(c+i)->id);
        printf("Enter candidate %d name: ", i+1);
        fflush(stdin);
        gets((c+i)->name);
        (c+i)->votes = 0;
    }

    //Display candidate details
    printf("\n\n-----Candidate Details-----\n\n");
    printf("ID\tName\n");
    for(i=0;i<numCand;i++){
        printf("%d\t%s\n", (c+i)->id, (c+i)->name);
    }

    //Voting system
    int choice, voterID, flag=0;
    while(!flag){
        printf("\nEnter your voter ID: ");
        scanf("%d", &voterID);
        for(i=0;i<numCand;i++){
            printf("%d\t%s\n", (c+i)->id, (c+i)->name);
        }
        printf("\nEnter your vote (ID of candidate): ");
        scanf("%d", &choice);
        for(i=0;i<numCand;i++){
            if(choice == (c+i)->id){
                (c+i)->votes++;
                printf("Thank you for your vote!\n");
                flag = 1;
                break;
            }
        }
        if(flag==0) printf("Invalid candidate ID. Please try again.\n");
    }

    //Display voting results
    printf("\n\n-----Voting Results-----\n\n");
    printf("ID\tName\tVotes Received\n");
    for(i=0;i<numCand;i++){
        printf("%d\t%s\t%d\n", (c+i)->id, (c+i)->name, (c+i)->votes);
    }

    //Sort candidate based on number of votes received (Descending Order)
    struct candidate tempCandidate;
    for(i=0;i<numCand-1;i++){
        for(j=0;j<numCand-i-1;j++){
            if((c+j)->votes<(c+j+1)->votes){
                tempCandidate = *(c+j);
                *(c+j) = *(c+j+1);
                *(c+j+1) = tempCandidate;
            }
        }
    }

    //Display winner
    int maxVotes = (c+0)->votes, maxIndex = 0;
    for(i=0;i<numCand;i++){
        if((c+i)->votes > maxVotes){
            maxIndex = i;
            maxVotes = (c+i)->votes;
        }
    }
    printf("\n\nWinner: %s\n", (c+maxIndex)->name);

    free(c);
    return 0;
}