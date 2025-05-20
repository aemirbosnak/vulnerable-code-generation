//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: sophisticated
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

///Defining the maximum number of candidates and voters
#define MAX_CANDIDATES 10
#define MAX_VOTERS 100

typedef struct Voter
{
    char name[50];
    int age;
}Voter;

typedef struct Candidate
{
    char name[50];
    int vote_count;
}Candidate;

int num_candidates = 0;
Candidate candidates[MAX_CANDIDATES];

int num_voters = 0;
Voter voters[MAX_VOTERS];

int is_valid_candidate(char* name)
{
    for(int i=0;i<num_candidates;i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int vote_for_candidate(char* name)
{
    for(int i = 0; i<num_candidates;i++)
    {
        if(strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].vote_count++;
            return 1;
        }
    }
    return 0;
}

void display_results()
{
    printf("\n\n*********** ELECTION RESULTS *************\n\n");
    for(int i = 0;i<num_candidates;i++)
    {
        printf("%s: %d\n", candidates[i].name, candidates[i].vote_count);
    }
    printf("\n******************************************\n\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n\n*********** WELCOME TO ELECTION SYSTEM *************\n\n");
        printf("Choose an option:\n1. Register as Voter\n2. Register as Candidate\n3. Cast vote\n4. Display Results\n5. Exit\n\n");
        printf("Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:{
                Voter v;
                printf("Enter voter name: ");
                scanf("%s",v.name);
                printf("Enter voter age: ");
                scanf("%d",&v.age);
                voters[num_voters++] = v;
                printf("\nThank you! You have been registered as a Voter\n");
                break;
            }
            case 2:{
                Candidate c;
                printf("Enter candidate name: ");
                scanf("%s",c.name);
                c.vote_count = 0;
                candidates[num_candidates++] = c;
                printf("\nThank you! You have been registered as a Candidate\n");
                break;
            }
            case 3:{
                char candidate_name[50];
                int voter_age;
                printf("Enter your name: ");
                scanf("%s",candidate_name);
                if(!is_valid_candidate(candidate_name))
                {
                    printf("\nError: Invalid candidate name! Please choose from the following:\n");
                    for(int i=0;i<num_candidates;i++)
                    {
                        printf("%s\n",candidates[i].name);
                    }
                    break;
                }
                printf("Enter your age: ");
                scanf("%d",&voter_age);
                int valid_voter = 0;
                for(int i=0;i<num_voters;i++)
                {
                    if(strcmp(voters[i].name, candidate_name) == 0 && voters[i].age == voter_age)
                    {
                        valid_voter = 1;
                        break;
                    }
                }
                if(!valid_voter)
                {
                    printf("\nError: Invalid Voter details!\n");
                    break;
                }
                if(vote_for_candidate(candidate_name))
                {
                    printf("\nThank you! Your vote has been casted.\n");
                }
                else
                {
                    printf("\nError: Invalid candidate name! Please choose from the following:\n");
                    for(int i=0;i<num_candidates;i++)
                    {
                        printf("%s\n",candidates[i].name);
                    }
                }
                break;
            }
            case 4:{
                display_results();
                break;
            }
            case 5:{
                printf("Thank you for using the Election System.\n");
                exit(0);
            }
            default: printf("\nInvalid Option! Please try again.\n");

        }
    }while(choice!=5);
    return 0;
}