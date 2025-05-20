//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constant values
#define NUM_CANDIDATES 4
#define VOTER_ID_MAX 9999999

// Declare functions
void cast_vote(int voter_id, int candidate);
void show_results();
void print_menu();

// Define global variables
int candidates[NUM_CANDIDATES] = {0};
int voting_closed = 0;

int main()
{
    int voter_id = 0, choice = 0;

    printf("Welcome to the Puzzling Electronic Voting System!\n");
    printf("Voters, please enter your ID number: ");
    scanf("%d", &voter_id);

    srand(time(NULL));

    while (!voting_closed)
    {
        print_menu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            cast_vote(voter_id, 0);
            printf("Vote for Candidate 1 cast!\n");
            break;
        case 2:
            cast_vote(voter_id, 1);
            printf("Vote for Candidate 2 cast!\n");
            break;
        case 3:
            cast_vote(voter_id, 2);
            printf("Vote for Candidate 3 cast!\n");
            break;
        case 4:
            cast_vote(voter_id, 3);
            printf("Vote for Candidate 4 cast!\n");
            break;
        case 5:
            show_results();
            break;
        case 6:
            voting_closed = 1;
            printf("Voting is now closed. Thank you for participating!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}

void print_menu()
{
    printf("\n--- Menu ---\n");
    printf("1. Vote for Candidate 1\n");
    printf("2. Vote for Candidate 2\n");
    printf("3. Vote for Candidate 3\n");
    printf("4. Vote for Candidate 4\n");
    printf("5. Show current vote results\n");
    printf("6. Close voting and show final results\n");
}

void cast_vote(int voter_id, int candidate)
{
    // Check if voter has already voted
    if (candidates[candidate] == voter_id)
    {
        printf("You have already voted for this candidate.\n");
        return;
    }

    // Check if voter ID is valid
    if (voter_id > VOTER_ID_MAX || voter_id < 0)
    {
        printf("Invalid voter ID. Please try again.\n");
        return;
    }

    // Cast vote
    candidates[candidate] = voter_id;
}

void show_results()
{
    int i;
    int total_votes = 0;

    printf("\n--- Current Vote Results ---\n");

    // Calculate total votes
    for (i = 0; i < NUM_CANDIDATES; i++)
    {
        if (candidates[i] != 0)
        {
            total_votes++;
        }
    }

    // If no votes cast yet, show message and return
    if (total_votes == 0)
    {
        printf("No votes have been cast yet.\n");
        return;
    }

    // Print results
    for (i = 0; i < NUM_CANDIDATES; i++)
    {
        printf("Candidate %d: ", i+1);

        if (candidates[i] != 0)
        {
            printf("%d votes\n", rand() % 100 + 1); // Puzzling code - generates random number of votes
        }
        else
        {
            printf("0 votes\n");
        }
    }
}