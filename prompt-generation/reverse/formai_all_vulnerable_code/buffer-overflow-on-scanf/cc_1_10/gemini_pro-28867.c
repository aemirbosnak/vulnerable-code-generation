//GEMINI-pro DATASET v1.0 Category: Electronic Voting System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of candidates
#define NUM_CANDIDATES 5

// Define the names of the candidates and their positions on the ballot
char *candidates[NUM_CANDIDATES] = {"Alice", "Bob", "Carol", "Dave", "Eve"};

// Define the array to store the number of votes for each candidate
int votes[NUM_CANDIDATES];

// Define the function to get the index of the candidate with the most votes
int get_winner_index()
{
    int max_votes = 0;
    int winner_index = -1;

    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        if (votes[i] > max_votes)
        {
            max_votes = votes[i];
            winner_index = i;
        }
    }

    return winner_index;
}

// Define the function to print the results of the election
void print_results()
{
    printf("Election Results:\n");

    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("%s: %d votes\n", candidates[i], votes[i]);
    }

    int winner_index = get_winner_index();
    printf("The winner is: %s\n", candidates[winner_index]);
}

// Define the main function
int main()
{
    // Initialize the array of votes to 0
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        votes[i] = 0;
    }

    // Get the votes from the user
    printf("Enter the number of votes for each candidate:\n");
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        scanf("%d", &votes[i]);
    }

    // Print the results of the election
    print_results();

    return 0;
}