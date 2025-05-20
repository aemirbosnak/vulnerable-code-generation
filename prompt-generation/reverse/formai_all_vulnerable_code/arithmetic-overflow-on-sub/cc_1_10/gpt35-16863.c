//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: futuristic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Candidate //Defining candidate structure
{
    int id;
    char name[50];
    int votes;
};

struct Voter //Defining voter structure
{
    char name[50];
    int voted;
};

void castVote(struct Candidate *c, struct Voter *v, int totalCandidates, int totalVoters) //Function to cast vote
{
    int candidateID, voterID;
    
    printf("Enter your voter ID: ");
    scanf("%d", &voterID);
    printf("Welcome %s. Please enter your candidate ID to cast your vote:\n", v[voterID].name);
    
    for(int i=0; i<totalCandidates; i++)
    {
        printf("Candidate ID: %d | Candidate Name: %s\n", c[i].id, c[i].name);
    }
    scanf("%d", &candidateID);
    c[candidateID-1].votes++;
    v[voterID].voted = 1;
    printf("Thank you for voting!\n");
}

void printResults(struct Candidate *c, int totalCandidates) //Function to print results
{
    printf("Vote Count:\n");
    for(int i=0; i<totalCandidates; i++)
    {
        printf("%s: %d votes\n", c[i].name, c[i].votes);
    }
}

int main()
{
    int totalCandidates, totalVoters, choice;
    
    printf("Welcome to the Electronic Voting System!\n");
    printf("Enter the total number of candidates: ");
    scanf("%d", &totalCandidates);
    
    struct Candidate c[totalCandidates]; //Array of candidates
    
    for(int i=0; i<totalCandidates; i++) //Taking input of candidate details
    {
        printf("Enter details for candidate %d:\n", i+1);
        printf("Candidate ID: ");
        scanf("%d", &c[i].id);
        printf("Candidate Name: ");
        scanf("%s", c[i].name);
        c[i].votes = 0;
    }
    
    printf("Enter the total number of voters: ");
    scanf("%d", &totalVoters);
    
    struct Voter v[totalVoters];       //Array of voters
    
    for(int i=0; i<totalVoters; i++)   //Taking input of voter details
    {
        printf("Enter details for voter %d:\n", i+1);
        printf("Voter Name: ");
        scanf("%s", v[i].name);
        v[i].voted = 0;
    }
    
    do{                                //Menu-driven program
        printf("\nMenu:\n");
        printf("1. Cast Vote\n");
        printf("2. Print Results\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: castVote(c, v, totalCandidates, totalVoters);
                    break;
            case 2: printResults(c, totalCandidates);
                    break;
            case 3: printf("Thank you for using the Electronic Voting System!\n");
                    exit(0);
            default: printf("Invalid Choice. Please try again.\n");
        }
    }while(1);
    
    return 0;
}