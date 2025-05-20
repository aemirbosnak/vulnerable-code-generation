//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize the electronic voting system
    int votes[5] = {0, 0, 0, 0, 0};
    char candidates[5][20] = {
        "John Doe",
        "Jane Doe",
        "Bill Smith",
        "Mary Johnson",
        "Bob Brown"
    };

    // Welcome the voter
    printf("Welcome to the Electronic Voting System!\n");

    // Get the voter's choice
    printf("Please select a candidate: ");
    char choice;

    // Validate the voter's choice
    while (1)
    {
        scanf("%c", &choice);

        if (choice >= 'a' && choice <= 'e')
        {
            break;
        }

        printf("Invalid choice. Please try again: ");
    }

    // Record the voter's vote
    votes[choice - 'a']++;

    // Display the results
    printf("The results of the election are:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s has received %d votes.\n", candidates[i], votes[i]);
    }

    // Thank the voter
    printf("Thank you for voting!\n");

    return 0;
}