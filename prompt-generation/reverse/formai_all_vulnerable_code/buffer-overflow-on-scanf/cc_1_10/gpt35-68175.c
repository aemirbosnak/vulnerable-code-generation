//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int candidates;
    printf("Enter the number of candidates: ");
    scanf("%d", &candidates);

    char** candidate_names = (char**)malloc(candidates * sizeof(char*));
    for(int i=0; i<candidates; i++)
    {
        candidate_names[i] = (char*)malloc(20 * sizeof(char));
        printf("Enter name of candidate %d: ", i+1);
        scanf("%s", candidate_names[i]);
    }

    int* votes = (int*)calloc(candidates, sizeof(int));
    int total_votes = 0;

    printf("\nVoting Starts Now!\n");
    printf("Enter candidate number to cast your vote (Press 0 to finish): \n");

    int choice;
    do
    {
        scanf("%d", &choice);
        if(choice>=1 && choice<=candidates)
        {
            votes[choice-1]++;
            total_votes++;
        }
        else if(choice!=0)
        {
            printf("Invalid Candidate Number! Try Again.\n");
        }
    }while(choice!=0);

    printf("Voting Completed!\n\n");
    printf("Result: \n");

    for(int i=0; i<candidates; i++)
    {
        printf("%s - %d votes\n", candidate_names[i], votes[i]);
    }

    printf("Total Votes: %d\n", total_votes);

    int winner = 0;
    for(int i=0; i<candidates; i++)
    {
        if(votes[i]>votes[winner])
        {
            winner = i;
        }
    }

    printf("\nWinner of the Election: %s with %d votes\n", candidate_names[winner], votes[winner]);

    for(int i=0; i<candidates; i++)
    {
        free(candidate_names[i]);
    }
    free(candidate_names);
    free(votes);

    return 0;
}