//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declaring global variables
int totalVoters;
int totalCandidates;
char candName[50][50];
int candVotes[50];

// Function declaration
void castVote();

int main()
{
    int choice;
    printf("***Welcome to Electronic Voting System***\n");

    printf("Enter the number of candidates:\n");
    scanf("%d",&totalCandidates);

    // Accepting candidate names
    for (int i=0;i<totalCandidates;i++){
        printf("Enter the name of candidate %d:\n",i+1);
        scanf("%s",candName[i]);
        candVotes[i]=0;
    }

    printf("\nEnter the total number of voters:\n");
    scanf("%d",&totalVoters);

    // Simulating voting
    for (int i=0;i<totalVoters;i++){
        castVote();
    }

    // Displaying the results
    printf("\n\nResult of the Election:\n");
    printf("-----------------------\n");
    for (int i=0;i<totalCandidates;i++){
        printf("%s : %d\n",candName[i],candVotes[i]);
    }

    return 0;
}

// Function to cast vote
void castVote(){
    int choice;
    printf("\n\nCandidates List:");
    printf("\n----------------");
    for (int i=0;i<totalCandidates;i++){
        printf("\n%d. %s",i+1,candName[i]);
    }

    printf("\n\nEnter your choice:\n");
    scanf("%d",&choice);

    if (choice>=1 && choice<=totalCandidates){
        candVotes[choice-1]++;
        printf("\nThank you for casting your vote!\n");
    }

    else{
        printf("\nInvalid choice! Please try again.\n");
        castVote();
    }
}