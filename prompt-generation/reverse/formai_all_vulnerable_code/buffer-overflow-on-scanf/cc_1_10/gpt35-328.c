//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct candidate
{
    char name[30];
    int votes;
}candidates[10]; 

int numberOfCandidates = 0;

void setUpCandidates();
void displayCandidates();
void castVote();

int main()
{
    setUpCandidates();

    printf("\nWelcome to the Electronic Voting System!\n");

    int option;
    do
    {
        printf("\nPlease select an option:\n");
        printf("1. Display Candidates\n");
        printf("2. Cast Vote\n");
        printf("3. Exit\n");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                displayCandidates();
                break;
            case 2:
                castVote();
                break;
            case 3:
                printf("\nThank you for using this Electronic Voting System!\n");
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    while(1);

    return 0;
}

void setUpCandidates()
{
    char name[30];
    int candidateCount;

    printf("How many candidates are running for this election? ");
    scanf("%d", &numberOfCandidates);

    for(int i=0; i<numberOfCandidates; i++)
    {
        printf("\nEnter candidate %d's name: ", i+1);
        scanf("%s", name);

        candidateCount = strlen(name);

        if(candidateCount>30)
        {
            printf("\nMaximum of 30 characters for a name\n");
            exit(0);
        }

        for(int j=0; j<candidateCount; j++)
        {
            candidates[i].name[j] = name[j];
        }

        candidates[i].votes = 0;
    }
}

void displayCandidates()
{
    printf("\n---------CANDIDATES----------\n");
    for(int i=0; i<numberOfCandidates; i++)
    {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("-----------------------------\n");
}

void castVote()
{
    int choice;

    printf("\n---------VOTING PAGE----------\n");
    displayCandidates();
    printf("Enter the number of your chosen candidate: ");
    scanf("%d", &choice);

    if(choice<1 || choice>numberOfCandidates)
    {
        printf("\nInvalid candidate number\n");
        return;
    }

    candidates[choice-1].votes++;
    printf("\nThank you for voting for %s!\n", candidates[choice-1].name);
}