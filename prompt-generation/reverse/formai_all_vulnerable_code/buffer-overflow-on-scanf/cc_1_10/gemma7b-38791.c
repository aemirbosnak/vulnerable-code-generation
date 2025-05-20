//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int votes[5] = {0, 0, 0, 0, 0};
    char choices[5] = {'a', 'b', 'c', 'd', 'e'};
    int i, choice, valid = 0;

    system("clear");
    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select your choice:\n");

    for (i = 0; i < 5; i++)
    {
        printf("%c) %s\n", choices[i], votes[i]);
    }

    printf("Enter your choice (a-e): ");
    scanf("%c", &choice);

    system("clear");

    for (i = 0; i < 5; i++)
    {
        if (choices[i] == choice)
        {
            votes[i]++;
            valid = 1;
            break;
        }
    }

    if (valid)
    {
        printf("Your vote has been cast.\n");
        printf("The results are:\n");

        for (i = 0; i < 5; i++)
        {
            printf("%c) %s\n", choices[i], votes[i]);
        }
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
    }

    return;
}