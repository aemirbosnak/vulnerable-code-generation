//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate
{
    char name[30];
    int vote_count;
};

struct voter
{
    char name[30];
    int voted;
};

int main()
{
    int num_candidates, num_voters, vote_count = 0;
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);
    struct candidate candidates[num_candidates];

    for(int i=0; i<num_candidates; i++)
    {
        printf("Enter candidate %d name: ", (i+1));
        scanf("%s", candidates[i].name);
        candidates[i].vote_count = 0;
    }

    printf("\nEnter the number of voters: ");
    scanf("%d", &num_voters);
    struct voter voters[num_voters];

    for(int i=0; i<num_voters; i++)
    {
        printf("Enter voter %d name: ", (i+1));
        scanf("%s", voters[i].name);
        voters[i].voted = -1;
    }

    int vote, voter_id;
    char confirm;

    do
    {
        printf("\nCandidate list:\n");
        for(int i=0; i<num_candidates; i++)
        {
            printf("%d. %s\n", (i+1), candidates[i].name);
        }

        printf("\nEnter the candidate number you want to vote for: ");
        scanf("%d", &vote);

        if(vote <= 0 || vote > num_candidates)
        {
            printf("Invalid vote. Please try again.\n");
        }
        else
        {
            printf("\nVoter list:\n");
            for(int i=0; i<num_voters; i++)
            {
                printf("%d. %s\n", (i+1), voters[i].name);
            }

            printf("\nEnter the voter number: ");
            scanf("%d", &voter_id);

            if(voter_id <= 0 || voter_id > num_voters)
            {
                printf("Invalid voter. Please try again.\n");
            }
            else if(voters[voter_id-1].voted != -1)
            {
                printf("This voter has already voted.\n");
            }
            else
            {
                candidates[vote-1].vote_count++;
                voters[voter_id-1].voted = vote;
                printf("\nVote confirmed for candidate %d.\n", vote);
                vote_count++;

                printf("\nDo you want to continue voting? (y/n) ");
                scanf(" %c", &confirm);
            }
        }
    } while(confirm == 'y' || confirm == 'Y');

    printf("\nThe voting results are as follows:\n");
    for(int i=0; i<num_candidates; i++)
    {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].vote_count);
    }

    printf("\nTotal votes cast: %d\n", vote_count);

    return 0;
}