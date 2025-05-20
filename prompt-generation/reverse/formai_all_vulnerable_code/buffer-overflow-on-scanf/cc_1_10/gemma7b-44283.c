//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define variables
    int numRolls = 0, totalSum = 0, rollValue = 0, currentRoll = 0, isRolling = 1;

    // Loop until the user enters a non-negative integer
    while (1)
    {
        printf("Enter the number of rolls: ");
        scanf("%d", &numRolls);

        if (numRolls >= 0)
            break;

        printf("Invalid input. Please enter a non-negative integer: ");
    }

    // Roll the dice as specified by the user
    for (int i = 0; i < numRolls; i++)
    {
        // Generate a random number between 1 and 6
        rollValue = rand() % 6 + 1;

        // Add the roll value to the current roll
        currentRoll += rollValue;

        // Increment the total sum
        totalSum += rollValue;

        // Print the roll value
        printf("Roll: %d\n", rollValue);
    }

    // Display the total sum and average roll
    printf("Total sum: %d\n", totalSum);
    printf("Average roll: %.2f\n", (double)totalSum / numRolls);

    // Check if the user wants to roll again
    if (isRolling)
    {
        printf("Do you want to roll again? (Y/N): ");
        char answer = getchar();

        // If the user wants to roll again, start the loop again
        if (answer == 'Y' || answer == 'y')
            main();
    }

    return 0;
}