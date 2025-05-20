//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: protected
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CANDIDATES 5
#define MAX_VOTERS 1000

int candidate_votes[MAX_CANDIDATES]; // Array to store votes for each candidate

// Function to display the list of candidates
void display_candidates(char candidates[][20], int num_candidates)
{
    printf("List of candidates:\n");
    for (int i = 0; i < num_candidates; i++)
    {
        printf("%d. %s\n", i + 1, candidates[i]);
    }
}

// Function to cast a vote for a candidate
void cast_vote(int candidate_num)
{
    candidate_votes[candidate_num - 1]++;
    printf("Your vote has been cast for candidate %d.\n", candidate_num);
}

// Function to display the voting results
void display_results(char candidates[][20], int num_candidates)
{
    int max_votes = 0;
    int winners[MAX_CANDIDATES];
    int num_winners = 0;

    printf("Voting Results:\n");

    // Find the candidate with the most votes
    for (int i = 0; i < num_candidates; i++)
    {
        if (candidate_votes[i] > max_votes)
        {
            max_votes = candidate_votes[i];
        }
    }

    // Find all candidates with the most votes
    for (int i = 0; i < num_candidates; i++)
    {
        if (candidate_votes[i] == max_votes)
        {
            winners[num_winners++] = i;
        }
    }

    // Display the winners
    printf("Winner(s):\n");
    for (int i = 0; i < num_winners; i++)
    {
        printf("%s\n", candidates[winners[i]]);
    }

    // Display voting statistics
    printf("Voting Statistics:\n\n");
    for (int i = 0; i < num_candidates; i++)
    {
        printf("%s: %d votes\n", candidates[i], candidate_votes[i]);
    }
}

int main()
{
    char candidates[MAX_CANDIDATES][20] = {"Candidate 1", "Candidate 2", "Candidate 3", "Candidate 4", "Candidate 5"};
    int num_candidates = MAX_CANDIDATES;

    // Display the list of candidates
    display_candidates(candidates, num_candidates);

    // Get the number of voters
    printf("Enter the number of voters: ");
    int num_voters;
    scanf("%d", &num_voters);

    // Cast votes for each voter
    for (int i = 0; i < num_voters; i++)
    {
        int vote;
        printf("Enter your vote (1-%d): ", num_candidates);
        scanf("%d", &vote);
        while (vote < 1 || vote > num_candidates)
        {
            printf("Invalid vote. Please enter a number between 1 and %d: ", num_candidates);
            scanf("%d", &vote);
        }
        cast_vote(vote);
    }

    // Display the voting results
    display_results(candidates, num_candidates);

    return 0;
}