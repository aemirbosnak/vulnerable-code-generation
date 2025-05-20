//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: future-proof
#include <stdio.h>

int main()
{
    int n, c, vote;
    int candidate[5] = {0}; // Initializing the candidate array

    printf("Enter the number of voters: ");
    scanf("%d", &n);

    printf("Candidates for the election: \n");
    printf("1. Candidate A\n");
    printf("2. Candidate B\n");
    printf("3. Candidate C\n");
    printf("4. Candidate D\n");
    printf("5. Candidate E\n");

    for(c = 1; c <= n; c++) // Loop to collect votes
    {
        printf("\nEnter your vote (1-5): ");
        scanf("%d", &vote);

        if(vote < 1 || vote > 5) // Validating vote
        {
            printf("Invalid vote! Please enter a vote between 1 and 5.\n");
            c--; // Reducing the vote count as this vote is invalid
            continue; // Skipping the rest of the loop
        }

        candidate[vote - 1]++; // Increasing the vote count for the selected candidate
    }

    printf("\n\nVote Details:\n");
    printf("Candidate A: %d votes\n", candidate[0]);
    printf("Candidate B: %d votes\n", candidate[1]);
    printf("Candidate C: %d votes\n", candidate[2]);
    printf("Candidate D: %d votes\n", candidate[3]);
    printf("Candidate E: %d votes\n", candidate[4]);

    // Finding the candidate with maximum votes
    int max_votes = candidate[0];
    int winner = 1;

    for(c = 2; c <= 5; c++)
    {
        if(candidate[c - 1] > max_votes)
        {
            max_votes = candidate[c - 1];
            winner = c;
        }
    }

    printf("\n\nThe winner is Candidate %c with %d votes.\n", winner + 64, max_votes);

    return 0;
}