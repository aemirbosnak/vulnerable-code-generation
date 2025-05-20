//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, count, max_votes, winner_index;
    printf("Enter the number of candidates: ");
    scanf("%d", &n);

    char candidateNames[n][50];
    int votes[n];

    // Taking candidate names and initializing votes to 0
    for(i=0; i<n; i++) 
    {
        printf("Enter the name of candidate %d: ", i+1);
        scanf("%s", candidateNames[i]);
        votes[i] = 0;
    }

    int voters;
    printf("Enter the number of voters: ");
    scanf("%d", &voters);

    // Taking votes from the voters
    for(i=0; i<voters; i++) 
    {
        printf("\nVoter %d\n", i+1);
        printf("Enter the candidate number you want to vote for: ");
        scanf("%d", &j);
        if(j>n || j<1) {
            printf("Invalid candidate number. Try again.\n");
            i--;
            continue;
        }
        votes[j-1]++;
        printf("Your vote has been recorded.\n");
    }

    printf("\nVotes Details:\n");
    printf("Candidate\tVotes\n");
    for(i=0; i<n; i++)
    {
        printf("%s\t\t%d\n", candidateNames[i], votes[i]);
    }

    // Finding the winner
    max_votes = votes[0];
    winner_index = 0;
    for(i=1; i<n; i++) {
        if(votes[i]>max_votes) {
            max_votes = votes[i];
            winner_index = i;
        }
    }

    printf("\nResult: Winner is %s with %d votes.", candidateNames[winner_index], max_votes);
    
    return 0;
}