//Falcon-180B DATASET v1.0 Category: Electronic Voting System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num_candidates, num_votes, i, j, max_votes=0, vote;
    char name[20][50];
    float percentage;

    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    for(i=0; i<num_candidates; i++)
    {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", name[i]);
    }

    printf("Enter the number of votes: ");
    scanf("%d", &num_votes);

    for(i=0; i<num_votes; i++)
    {
        printf("Enter your vote (%d): ", i+1);
        scanf("%d", &vote);

        if(vote >= 1 && vote <= num_candidates)
        {
            max_votes = (max_votes > vote)? max_votes : vote;
        }
        else
        {
            printf("Invalid vote!\n");
            exit(0);
        }
    }

    for(i=0; i<num_candidates; i++)
    {
        printf("%s: %d vote(s)\n", name[i], 0);
    }

    srand(time(0));

    for(i=0; i<num_votes; i++)
    {
        j = rand() % num_candidates;
        printf("%s: %d vote(s)\n", name[j], 1);
    }

    for(i=0; i<num_candidates; i++)
    {
        percentage = ((float)max_votes / num_votes) * 100;
        printf("%s: %.2f%%\n", name[i], percentage);
    }

    return 0;
}