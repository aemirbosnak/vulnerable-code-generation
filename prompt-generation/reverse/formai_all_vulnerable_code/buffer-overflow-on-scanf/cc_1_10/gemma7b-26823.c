//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, x, y, z;
    char ch;
    float f, g, h;

    printf("Welcome to the Crazy Math Party!\n");
    printf("Let's dance with numbers, shall we?\n");

    // Get the number of participants
    printf("How many participants are joining the party? ");
    scanf("%d", &n);

    // Create a circus of integers
    int numbers[n];
    printf("Time to spin the numbers! Enter %d integers: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    // Find the most energetic number
    x = numbers[0];
    for (i = 1; i < n; i++)
    {
        if (numbers[i] > x)
        {
            x = numbers[i];
        }
    }

    // Shout out the champion
    printf("The most energetic number is: %d!\n", x);

    // Play a game of fizz and buzz
    printf("Shall we play fizz and buzz? (Y/N): ");
    scanf(" %c", &ch);

    if (ch == 'Y')
    {
        printf("Enter two numbers: ");
        scanf("%d %d", &m, &l);

        for (i = m; i <= l; i++)
        {
            if (i % 3 == 0 && i % 5 == 0)
            {
                printf("%d is fizzbuzz!\n", i);
            }
            else if (i % 3 == 0)
            {
                printf("%d is fizz.\n", i);
            }
            else if (i % 5 == 0)
            {
                printf("%d is buzz.\n", i);
            }
            else
            {
                printf("%d is a star.\n", i);
            }
        }
    }

    // Have a sip of imaginary juice
    printf("Let's raise a glass to the end of the party!\n");
    printf("Drink some imaginary juice and have a blast!\n");

    return 0;
}