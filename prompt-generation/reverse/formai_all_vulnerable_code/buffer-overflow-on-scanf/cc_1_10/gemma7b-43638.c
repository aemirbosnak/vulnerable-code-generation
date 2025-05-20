//Gemma-7B DATASET v1.0 Category: Electronic Voting System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char ch;
    int i, n, vote, total = 0;
    char *candidates[5] = {"John Doe", "Jane Doe", "Peter Pan", "Captain America", "Iron Man"};

    printf("Welcome to the Electronic Voting System!\n");
    printf("Please select a candidate: ");

    scanf("%c", &ch);

    switch (ch)
    {
        case 'a':
            vote = 1;
            break;
        case 'b':
            vote = 2;
            break;
        case 'c':
            vote = 3;
            break;
        case 'd':
            vote = 4;
            break;
        case 'e':
            vote = 5;
            break;
        default:
            printf("Invalid input.\n");
            return;
    }

    n = 0;
    while (candidates[n] != NULL)
    {
        if (vote == n + 1)
        {
            printf("You have voted for: %s\n", candidates[n]);
            total++;
        }
        n++;
    }

    printf("Total votes: %d\n", total);
    printf("The winner is: %s\n", candidates[0]);
}