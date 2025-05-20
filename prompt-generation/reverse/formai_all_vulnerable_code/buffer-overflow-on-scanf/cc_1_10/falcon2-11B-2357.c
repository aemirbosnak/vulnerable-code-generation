//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

int main()
{
    int numVotes;
    char candidates[5][20];
    char voterName[20];
    int voteIndex;
    int i;

    printf("Number of candidates: ");
    scanf("%d", &numVotes);

    printf("Enter candidate names: ");
    for (i = 0; i < numVotes; i++)
    {
        scanf("%s", candidates[i]);
    }

    printf("Enter number of votes: ");
    scanf("%d", &numVotes);

    for (i = 0; i < numVotes; i++)
    {
        printf("Enter voter name: ");
        scanf("%s", voterName);

        printf("Select candidate: ");
        for (voteIndex = 0; voteIndex < numVotes; voteIndex++)
        {
            if (strcmp(candidates[voteIndex], voterName) == 0)
            {
                break;
            }
        }

        printf("Vote for %s? (y/n): ", candidates[voteIndex]);
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y')
        {
            printf("Voted for %s!\n", candidates[voteIndex]);
        }
        else
        {
            printf("Invalid vote.\n");
        }
    }

    return 0;
}