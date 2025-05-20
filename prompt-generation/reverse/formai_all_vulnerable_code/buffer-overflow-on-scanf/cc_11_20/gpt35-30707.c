//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a[3], b[3], c[3] = {0}, i, j, k, count = 0;
    char ch;
    srand((unsigned)time(NULL));

    printf("Welcome to the C Table Game!\n\n");
    printf("Instructions:\n1. Enter three numbers between 1 and 10 inclusive.\n");
    printf("2. The computer will randomly generate three numbers as well.\n");
    printf("3. You will be given points based on the number of matches you have with the computer's numbers.\n");
    printf("4. The player with the most points at the end wins.\n\n");

    while (1)
    {
        printf("Do you want to play a round? (y/n): ");
        scanf(" %c", &ch);
        if (ch == 'n')
            break;
        else if (ch != 'y')
        {
            printf("Invalid input! Please try again.\n");
            continue;
        }
        printf("Please enter three numbers between 1 and 10 inclusive:\n");
        for (i = 0; i < 3; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] < 1 || a[i] > 10)
            {
                printf("Invalid input! Please try again.\n");
                i--;
            }
        }
        printf("You entered: [%d %d %d]\n", a[0], a[1], a[2]);

        for (i = 0; i < 3; i++)
            b[i] = rand() % 10 + 1;
        printf("The computer's numbers are: [%d %d %d]\n", b[0], b[1], b[2]);

        for (i = 0; i < 3; i++)
            for (j = 0; j < 3; j++)
                if (a[i] == b[j] && c[j] == 0)
                {
                    c[j] = 1;
                    count++;
                    break;
                }
        printf("You have %d match(es) with the computer!\n", count);
        printf("Thank you for playing this round!\n\n");
        count = 0;
        for (i = 0; i < 3; i++)
            c[i] = 0;
    }
    printf("Goodbye! Hope you enjoyed the game!\n");

    return 0;
}