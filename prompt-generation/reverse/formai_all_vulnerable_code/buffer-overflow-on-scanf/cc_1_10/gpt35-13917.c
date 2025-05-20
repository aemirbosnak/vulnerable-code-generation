//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 10

typedef struct Candidate
{
    char name[20];
    int votes;
} Candidate;

typedef struct Voter
{
    int voter_id;
    int has_voted;
    Candidate voted_for;
} Voter;

void display_candidates(Candidate candidates[], int num_candidates)
{
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++)
    {
        printf("%s\n", candidates[i].name);
    }
}

void vote(Candidate candidates[], int num_candidates, Voter voters[], int num_voters)
{
    int voter_id;
    printf("Enter your voter ID: ");
    scanf("%d", &voter_id);

    for (int i = 0; i < num_voters; i++)
    {
        if (voters[i].voter_id == voter_id)
        {
            if (voters[i].has_voted)
            {
                printf("You have already voted.\n");
                return;
            }

            char candidate_name[20];
            printf("Enter the name of the candidate you want to vote for: ");
            scanf("%s", candidate_name);

            for (int j = 0; j < num_candidates; j++)
            {
                if (strcmp(candidates[j].name, candidate_name) == 0)
                {
                    candidates[j].votes++;
                    voters[i].has_voted = 1;
                    strcpy(voters[i].voted_for.name, candidate_name);
                    printf("Thank you for voting.\n");
                    return;
                }
            }

            printf("Invalid candidate name.\n");
            return;
        }
    }

    printf("Invalid voter ID.\n");
}

void display_results(Candidate candidates[], int num_candidates)
{
    printf("Election Results:\n");
    for (int i = 0; i < num_candidates; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

int main()
{
    Candidate candidates[MAX_CANDIDATES];
    int num_candidates = 0;

    Voter voters[MAX_CANDIDATES];
    int num_voters = 0;

    while (1)
    {
        printf("\n1. Add Candidate\n2. Display Candidates\n3. Vote\n4. Display Results\n5. Exit\nEnter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            char candidate_name[20];
            printf("Enter the name of the candidate: ");
            scanf("%s", candidate_name);

            candidates[num_candidates].votes = 0;
            strcpy(candidates[num_candidates].name, candidate_name);
            num_candidates++;

            printf("Candidate added successfully.\n");
            break;
        }

        case 2:
        {
            display_candidates(candidates, num_candidates);
            break;
        }

        case 3:
        {
            vote(candidates, num_candidates, voters, num_voters);
            num_voters++;
            break;
        }

        case 4:
        {
            display_results(candidates, num_candidates);
            break;
        }

        case 5:
        {
            printf("Exiting program...\n");
            return 0;
        }

        default:
        {
            printf("Invalid choice.\n");
            break;
        }
        }
    }
}