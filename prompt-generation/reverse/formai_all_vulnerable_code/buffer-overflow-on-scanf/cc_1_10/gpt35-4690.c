//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_CANDIDATES 5

// Function to display the menu
void display_menu()
{
    printf("\n\n----- Voting System Menu -----\n");
    printf("1. Add Candidate\n");
    printf("2. Display Candidates\n");
    printf("3. Cast Vote\n");
    printf("4. Show Results\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Structure to store candidate details
struct candidate
{
    char name[30];
    int votes;
};

// Global array of candidates
struct candidate candidates[MAX_CANDIDATES];

// Function to add a new candidate
void add_candidate()
{
    int i=0;
    while(i<MAX_CANDIDATES)
    {
        if(candidates[i].name[0]=='\0')
        {
            printf("\nEnter name of candidate %d: ",i+1);
            scanf("%s",candidates[i].name);
            candidates[i].votes=0;
            printf("Candidate %d Added Successfully!\n",i+1);
            return;
        }
        i++;
    }
    printf("\nMaximum Candidates Reached!\n");
}

// Function to display the list of candidates
void display_candidates()
{
    printf("\n\n----- List of Candidates -----\n");
    for(int i=0;i<MAX_CANDIDATES && candidates[i].name[0]!='\0';i++)
    {
        printf("%d. %s\n",i+1,candidates[i].name);
    }
}

// Function to cast a vote
void cast_vote()
{
    int i;
    char name[30];
    printf("\nEnter Name of Candidate You Want to Vote For: ");
    scanf("%s",name);
    for(i=0;i<MAX_CANDIDATES;i++)
    {
        if(strcmp(name,candidates[i].name)==0)
        {
            candidates[i].votes++;
            printf("\nVote Casted!\n");
            return;
        }
    }
    printf("\nInvalid Candidate Name. Please Try Again!\n");
}

// Function to show the results
void show_results()
{
    int max_votes=0,winner=-1,i;
    printf("\n\n----- Results -----\n");
    for(i=0;i<MAX_CANDIDATES && candidates[i].name[0]!='\0';i++)
    {
        printf("%d. %s - %d Votes\n",i+1,candidates[i].name,candidates[i].votes);
        if(candidates[i].votes>max_votes)
        {
            max_votes=candidates[i].votes;
            winner=i;
        }
    }
    printf("\nWinner: %s with %d Votes\n",candidates[winner].name,max_votes);
}

int main()
{
    int choice;
    for(int i=0;i<MAX_CANDIDATES;i++)
    {
        candidates[i].name[0]='\0';
        candidates[i].votes=0;
    }
    do
    {
        display_menu();
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: add_candidate(); break;
            case 2: display_candidates(); break;
            case 3: cast_vote(); break;
            case 4: show_results(); break;
            case 5: printf("\nThank You For Voting!\n"); break;
            default: printf("\nInvalid Choice. Please Try Again!\n"); break;
        }
    }while(choice!=5);
    return 0;
}