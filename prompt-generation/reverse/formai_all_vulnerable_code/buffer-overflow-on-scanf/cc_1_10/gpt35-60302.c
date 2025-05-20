//FormAI DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    char c;

    printf("Welcome to the Dice Roller!\n");
    printf("Press \'r\' to roll the dice and \'q\' to quit.\n");

    // Repeat until user quits
    while (1)
    {
        // Wait for user input
        scanf("%c", &c);

        if (c == 'q')
        {
            printf("Thanks for playing! Goodbye.\n");
            break;
        }
        else if (c != 'r')
        {
            printf("Please enter \'r\' to roll the dice or \'q\' to quit.\n");
            continue;
        }

        // Generate random number between 1-6
        srand(time(NULL));
        n = (rand() % 6) + 1;

        // Display dice roll result
        printf("You rolled a:");

        switch (n)
        {
            case 1:
                printf("         O\n");
                printf("       / | \\ \n");
                printf("         |   \n");
                printf("       /   \\ \n");
                printf("      |     |\n");
                printf("      |_____|");
                break;
            case 2:
                printf("         O\n");
                printf("       / | \\ \n");
                printf("         |   \n");
                printf("         |   \n");
                printf("       /   \\ \n");
                printf("      |_____|");
                break;
            case 3:
                printf("         O\n");
                printf("       / | \\ \n");
                printf("         |   \n");
                printf("         |   \n");
                printf("         |   \n");
                printf("      |_____|");
                break;
            case 4:
                printf("         O\n");
                printf("       / | \\ \n");
                printf("         |   \n");
                printf("         |   \n");
                printf("       / | \\ \n");
                printf("      |_____|");
                break;
            case 5:
                printf("         O\n");
                printf("       / | \\ \n");
                printf("         |   \n");
                printf("       / | \\ \n");
                printf("         |   \n");
                printf("      |_____|");
                break;
            case 6:
                printf("         O\n");
                printf("       / | \\ \n");
                printf("         |   \n");
                printf("       / | \\ \n");
                printf("       /   \\ \n");
                printf("      |_____|");
                break;
        }

        printf("\n");
    }

    return 0;
}