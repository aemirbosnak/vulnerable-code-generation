//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void castVote(int candidateNumber);
void displayResults();

struct Candidate
{
    int candidateNumber;
    char name[20];
    int voteCount;
};

struct Candidate candidates[5];

void main()
{
    //initialize candidates
    candidates[0].candidateNumber = 1;
    strcpy(candidates[0].name, "John");
    candidates[0].voteCount = 0;

    candidates[1].candidateNumber = 2;
    strcpy(candidates[1].name, "Sarah");
    candidates[1].voteCount = 0;

    candidates[2].candidateNumber = 3;
    strcpy(candidates[2].name, "David");
    candidates[2].voteCount = 0;

    candidates[3].candidateNumber = 4;
    strcpy(candidates[3].name, "Emily");
    candidates[3].voteCount = 0;

    candidates[4].candidateNumber = 5;
    strcpy(candidates[4].name, "Mark");
    candidates[4].voteCount = 0;

    int cont = 1;
    while (cont==1)
    {
        int choice = 0;
        printf("\nWelcome to the Electronic Voting System.\n\n");
        printf("1) Cast Vote.\n");
        printf("2) Display Results.\n");
        printf("3) Exit Program.\n\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nPlease enter the candidate number you wish to vote for (1-5): ");
            int candidateNumber;
            scanf("%d", &candidateNumber);
            castVote(candidateNumber);
            break;
        case 2:
            displayResults();
            break;
        case 3:
            cont = 0;
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
        }
    }

}

void castVote(int candidateNumber)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (candidates[i].candidateNumber == candidateNumber)
        {
            candidates[i].voteCount++;
            printf("\nThank you for casting your vote for %s.\n", candidates[i].name);
            return;
        }
    }
    printf("\nInvalid candidate number.\n");
    return;
}

void displayResults()
{
    int i;
    printf("\nElection Results:\n");
    printf("Candidate\tVotes\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s\t%d\n", candidates[i].name, candidates[i].voteCount);
    }
    return;
}