//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 100
#define MAX_NAME_LENGTH 50

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int votes;
} candidate_t;

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int voted;
    int choice;
} voter_t;

void read_candidates(candidate_t* candidates)
{
    int i;
    for (i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("Enter candidate name: ");
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }
}

void read_voters(voter_t* voters)
{
    int i;
    for (i = 0; i < MAX_VOTERS; i++)
    {
        printf("Enter voter name: ");
        scanf("%s", voters[i].name);
        voters[i].voted = 0;
    }
}

int main()
{
    candidate_t candidates[MAX_CANDIDATES];
    voter_t voters[MAX_VOTERS];

    read_candidates(candidates);
    read_voters(voters);

    int choice;
    char name[MAX_NAME_LENGTH];
    while (1)
    {
        printf("\nEnter your name: ");
        scanf("%s", name);

        int found = 0;
        int index;
        for (index = 0; index < MAX_VOTERS; index++)
        {
            if (strcmp(name, voters[index].name) == 0 &&!voters[index].voted)
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("You have already voted or you are not registered to vote.\n");
            continue;
        }

        printf("\nSelect a candidate:\n");
        int i;
        for (i = 0; i < MAX_CANDIDATES; i++)
        {
            printf("%d. %s\n", i+1, candidates[i].name);
        }

        if (scanf("%d", &choice)!= 1 || choice < 1 || choice > MAX_CANDIDATES)
        {
            printf("Invalid choice.\n");
            continue;
        }

        candidates[choice-1].votes++;
        voters[index].voted = 1;
        voters[index].choice = choice;
    }

    printf("\nElection results:\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }

    return 0;
}