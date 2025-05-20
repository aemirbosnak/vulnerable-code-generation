//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define the number of candidates
#define NUM_CANDIDATES 3

// Define the candidate names
char *candidate_names[NUM_CANDIDATES] = {"Candidate A", "Candidate B", "Candidate C"};

// Define the number of voters
#define NUM_VOTERS 100

// Define the voter names
char *voter_names[NUM_VOTERS] = {"Voter 1", "Voter 2", "Voter 3", "Voter 4", "Voter 5", "Voter 6", "Voter 7", "Voter 8", "Voter 9", "Voter 10", "Voter 11", "Voter 12", "Voter 13", "Voter 14", "Voter 15", "Voter 16", "Voter 17", "Voter 18", "Voter 19", "Voter 20", "Voter 21", "Voter 22", "Voter 23", "Voter 24", "Voter 25", "Voter 26", "Voter 27", "Voter 28", "Voter 29", "Voter 30", "Voter 31", "Voter 32", "Voter 33", "Voter 34", "Voter 35", "Voter 36", "Voter 37", "Voter 38", "Voter 39", "Voter 40", "Voter 41", "Voter 42", "Voter 43", "Voter 44", "Voter 45", "Voter 46", "Voter 47", "Voter 48", "Voter 49", "Voter 50", "Voter 51", "Voter 52", "Voter 53", "Voter 54", "Voter 55", "Voter 56", "Voter 57", "Voter 58", "Voter 59", "Voter 60", "Voter 61", "Voter 62", "Voter 63", "Voter 64", "Voter 65", "Voter 66", "Voter 67", "Voter 68", "Voter 69", "Voter 70", "Voter 71", "Voter 72", "Voter 73", "Voter 74", "Voter 75", "Voter 76", "Voter 77", "Voter 78", "Voter 79", "Voter 80", "Voter 81", "Voter 82", "Voter 83", "Voter 84", "Voter 85", "Voter 86", "Voter 87", "Voter 88", "Voter 89", "Voter 90", "Voter 91", "Voter 92", "Voter 93", "Voter 94", "Voter 95", "Voter 96", "Voter 97", "Voter 98", "Voter 99", "Voter 100"};

// Define the number of votes for each candidate
int votes[NUM_CANDIDATES][NUM_VOTERS] = {0};

// Define the total number of votes cast
int total_votes = 0;

int main()
{
    // Initialize the random number generator
    srand(time(NULL));

    // Display the candidate names and their corresponding numbers
    printf("ELECTORAL COLLEGE RESULTS\n");
    printf("=========================================================\n");
    printf("Candidate | Number of Votes (%)\n");
    printf("=========================================================\n");

    // Calculate the total number of votes cast
    for (int i = 0; i < NUM_VOTERS; i++)
    {
        total_votes += votes[i][0];
        total_votes += votes[i][1];
        total_votes += votes[i][2];
    }

    // Calculate the percentage of votes for each candidate
    int candidate_percentage[NUM_CANDIDATES];
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        candidate_percentage[i] = 0;
        for (int j = 0; j < NUM_VOTERS; j++)
        {
            candidate_percentage[i] += votes[j][i];
        }
        candidate_percentage[i] /= total_votes;
    }

    // Display the candidate names and their corresponding number of votes
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("%-30s | %d\n", candidate_names[i], votes[0][i]);
    }

    // Sort the candidate names by the number of votes
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        for (int j = 0; j < NUM_CANDIDATES - i - 1; j++)
        {
            if (votes[0][j] > votes[0][j + 1])
            {
                char temp[strlen(candidate_names[j])];
                strcpy(temp, candidate_names[j + 1]);
                strcpy(candidate_names[j + 1], candidate_names[j]);
                strcpy(candidate_names[j], temp);
            }
        }
    }

    // Display the candidate names and their corresponding number of votes
    for (int i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("%-30s | %d\n", candidate_names[i], votes[0][i]);
    }

    // Calculate the winner of the election
    int winner_index = 0;
    int max_votes = votes[0][0];
    for (int i = 1; i < NUM_CANDIDATES; i++)
    {
        if (votes[0][i] > max_votes)
        {
            max_votes = votes[0][i];
            winner_index = i;
        }
    }

    // Display the winner of the election
    printf("\n\nWINNER: %s (%d)\n", candidate_names[winner_index], votes[0][winner_index]);

    return 0;
}