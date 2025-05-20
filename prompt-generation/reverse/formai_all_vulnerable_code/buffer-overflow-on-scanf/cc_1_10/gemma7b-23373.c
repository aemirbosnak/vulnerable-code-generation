//Gemma-7B DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, l, m, n, x, y, z;
    char ch;

    // Create a 2D array of integers
    int arr[5][5] = {{1, 2, 3, 4, 5},
                           {6, 7, 8, 9, 10},
                           {11, 12, 13, 14, 15},
                           {16, 17, 18, 19, 20},
                           {21, 22, 23, 24, 25}};

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between 0 and 9
    x = rand() % 10;

    // Print the weather forecast for the day
    printf("Today's weather forecast:**\n");

    // Iterate over the 2D array
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            // Check if the temperature at the current location is greater than the random number
            if (arr[i][j] > x)
            {
                // Print a sunny emoji
                printf("☀️");
            }
            else
            {
                // Print a cloudy emoji
                printf("☁️");
            }
        }
        printf("\n");
    }

    // Get the user's input
    printf("What is your name? ");
    scanf("%c", &ch);

    // Print a personalized message
    printf("Hello, %c! Have a nice day!", ch);

    return 0;
}