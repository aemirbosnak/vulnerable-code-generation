//FormAI DATASET v1.0 Category: Electronic Voting System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Global variables
int yes_total = 0;
int no_total = 0;
int invalid_total = 0;

// Function prototypes
void print_results();
int voting_menu();

int main()
{
    int vote_option;
    printf("\nWelcome to the Electronic Voting System!\n");

    do {
        // Display voting menu and get user input
        vote_option = voting_menu();

        // Determine which option the user selected
        switch (vote_option)
        {
            case 1:
                printf("\nYou've selected YES!\n");
                yes_total ++;
                break;
            case 2:
                printf("\nYou've selected NO!\n");
                no_total ++;
                break;
            default:
                printf("\nYour vote is invalid!\n");
                invalid_total ++;
        }
    } while (vote_option != 0);

    // Print the final results of the vote
    print_results();

    return 0;
}

// Function to display voting menu and get user input
int voting_menu()
{
    int vote_option;

    printf("\nPlease enter your vote selection:\n");
    printf("1. YES\n");
    printf("2. NO\n");
    printf("0. Exit voting system\n");
    scanf("%d", &vote_option);

    return vote_option;
}

// Function to print the final results of the vote
void print_results()
{
    printf("\nResults of the Electronic Voting System:\n");
    printf("YES votes: %d\n", yes_total);
    printf("NO votes: %d\n", no_total);
    printf("Invalid votes: %d\n", invalid_total);

    if (yes_total > no_total)
        printf("\nThe YES vote wins!\n");
    else if (no_total > yes_total)
        printf("\nThe NO vote wins!\n");
    else
        printf("\nIt's a tie!\n");
}