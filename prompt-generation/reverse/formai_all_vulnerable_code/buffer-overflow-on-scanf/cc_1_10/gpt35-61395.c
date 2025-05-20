//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct candidate 
{
    char name[50];
    int votes;
};

int main()
{
    int choice, num_candidates, i, vote;
    int total_votes = 0;
    struct candidate *candidates;

    printf("Welcome to the electronic voting system.\n");

    printf("Enter number of candidates : ");
    scanf("%d", &num_candidates);

    candidates = (struct candidate*) malloc(num_candidates * sizeof(struct candidate));

    for(i=0; i<num_candidates; i++)
    {
        printf("Enter name of candidate %d : ", i+1);
        scanf("%s", candidates[i].name);
        candidates[i].votes = 0;
    }

    while(1)
    {
        printf("\n");
        printf("1. Cast vote\n");
        printf("2. View results\n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n");
                printf("Candidates\n");
                printf("----------\n");
                for(i=0; i<num_candidates; i++)
                {
                    printf("%d. %s\n", i+1, candidates[i].name);
                }
                printf("\n");

                printf("Enter candidate number to vote for : ");
                scanf("%d", &vote);

                if(vote>0 && vote<=num_candidates)
                {
                    candidates[vote-1].votes++;
                    total_votes++;
                    printf("Vote cast successfully.\n");
                }
                else
                {
                    printf("Invalid candidate number.\n");
                }
                break;

            case 2:
                printf("\n");
                printf("Results\n");
                printf("-------\n");
                for(i=0; i<num_candidates; i++)
                {
                    printf("%s : %d votes\n", candidates[i].name, candidates[i].votes);
                }
                printf("Total votes cast : %d\n", total_votes);
                printf("\n");
                break;

            case 3:
                printf("Thank you for using the electronic voting system.\n");
                free(candidates);
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}