//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct
{
    char name[20];
    int age;
}Voter;

typedef struct
{
    char candidate[20];
    int votes;
}Candidate;

void printVoter(Voter v)
{
    printf("Voter Name: %s, Age: %d\n", v.name, v.age);
}

void printCandidate(Candidate c)
{
    printf("Candidate Name: %s, Votes: %d\n", c.candidate, c.votes);
}

int main()
{
    Voter voter[100];
    Candidate candidate[10];
    
    for(int i = 0; i < 100; i++)
    {
        printf("Enter Voter Name: ");
        scanf("%s", voter[i].name);
        printf("Enter Voter Age: ");
        scanf("%d", &voter[i].age);
    }
    
    for(int i = 0; i < 10; i++)
    {
        printf("Enter Candidate Name: ");
        scanf("%s", candidate[i].candidate);
    }
    
    for(int i = 0; i < 100; i++)
    {
        printf("Enter your vote: ");
        scanf("%d", &voter[i].age);
        
        for(int j = 0; j < 10; j++)
        {
            if(voter[i].age == candidate[j].votes)
            {
                printf("Your vote is added to %s's vote count!\n", candidate[j].candidate);
                candidate[j].votes++;
                break;
            }
        }
    }
    
    for(int i = 0; i < 10; i++)
    {
        if(candidate[i].votes > 0)
        {
            printf("Candidate %s has %d votes.\n", candidate[i].candidate, candidate[i].votes);
        }
    }
    
    return 0;
}