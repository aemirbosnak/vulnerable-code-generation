//FormAI DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int array[10][10], checked[10][10] = { 0 };
    int i, j, k, m, n, found, count = 0;

    srand(time(NULL));

    // Fill the array with random numbers between 1 and 5
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            array[i][j] = rand() % 5 + 1;
        }
    }

    // Print the array
    printf("\nMemory Game\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Loop through the array twice to check for matching pairs
    for (k = 0; k < 2; k++)
    {
        printf("\nEnter the row and column of the first card: ");
        scanf("%d %d", &m, &n);

        // Check if the card has already been checked
        if (checked[m][n] == 1)
        {
            printf("\nThis card has already been matched. Please try again.\n");
            k--;
            continue;
        }

        printf("%d \n", array[m][n]);

        printf("Enter the row and column of the second card: ");
        scanf("%d %d", &i, &j);

        // Check if the card has already been checked
        if (checked[i][j] == 1)
        {
            printf("\nThis card has already been matched. Please try again.\n");
            k--;
            continue;
        }

        printf("%d \n", array[i][j]);

        // Check if the two cards match
        if (array[m][n] == array[i][j])
        {
            printf("\nMatch found!\n\n");
            
            // Set both cards as checked
            checked[m][n] = 1;
            checked[i][j] = 1;

            // Increase the count of matched pairs
            count++;

            // Check if all pairs have been matched
            if (count == 25)
            {
                printf("Congratulations! You have completed the game!\n");
                exit(0);
            }

            // Ask the player if they want to continue or quit
            printf("Would you like to continue playing? (1 - Yes, 0 - No): ");
            scanf("%d", &found);

            if (found == 0)
            {
                printf("Thank you for playing!\n");
                exit(0);
            }
        }
        else
        {
            printf("\nNo match found.\n\n");
        }

    }

    printf("You have used all your tries. Game Over.\n");

    return 0;
}