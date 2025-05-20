//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("#################################################################\n");
    printf("Welcome to the Electronic Voting System!\n");
    printf("#################################################################\n");

    // Create a list of voters
    char **voters = NULL;
    int num_voters = 0;

    // Get the number of voters
    printf("Enter the number of voters: ");
    scanf("%d", &num_voters);

    // Allocate memory for the voters
    voters = (char **)malloc(num_voters * sizeof(char *));

    // Get the voters' information
    for (int i = 0; i < num_voters; i++)
    {
        printf("Enter the voter's name: ");
        scanf("%s", voters[i]);
    }

    // Create a list of candidates
    char **candidates = NULL;
    int num_candidates = 0;

    // Get the number of candidates
    printf("Enter the number of candidates: ");
    scanf("%d", &num_candidates);

    // Allocate memory for the candidates
    candidates = (char **)malloc(num_candidates * sizeof(char *));

    // Get the candidates' information
    for (int i = 0; i < num_candidates; i++)
    {
        printf("Enter the candidate's name: ");
        scanf("%s", candidates[i]);
    }

    // Create a ballot
    char **ballot = NULL;
    int num_ballots = 0;

    // Get the number of ballots
    printf("Enter the number of ballots: ");
    scanf("%d", &num_ballots);

    // Allocate memory for the ballots
    ballot = (char **)malloc(num_ballots * sizeof(char *));

    // Get the ballots
    for (int i = 0; i < num_ballots; i++)
    {
        printf("Enter the voter's name: ");
        scanf("%s", ballot[i]);

        printf("Enter the candidate's name: ");
        scanf("%s", ballot[i]);
    }

    // Count the votes
    int **vote_counts = NULL;
    int num_votes = 0;

    // Allocate memory for the vote counts
    vote_counts = (int **)malloc(num_candidates * sizeof(int *));

    // Initialize the vote counts
    for (int i = 0; i < num_candidates; i++)
    {
        vote_counts[i] = 0;
    }

    // Count the votes
    for (int i = 0; i < num_ballots; i++)
    {
        for (int j = 0; j < num_candidates; j++)
        {
            if (strcmp(ballot[i], voters[j]) == 0)
            {
                vote_counts[j]++;
            }
        }
    }

    // Print the vote counts
    printf("#################################################################\n");
    printf("Vote Counts:\n");
    printf("#################################################################\n");

    for (int i = 0; i < num_candidates; i++)
    {
        printf("Candidate: %s, Votes: %d\n", candidates[i], vote_counts[i]);
    }

    // Print the winner
    int winner = 0;
    for (int i = 0; i < num_candidates; i++)
    {
        if (vote_counts[i] > vote_counts[winner])
        {
            winner = i;
        }
    }

    printf("#################################################################\n");
    printf("The winner is: %s!\n", candidates[winner]);
    printf("#################################################################\n");

    return 0;
}