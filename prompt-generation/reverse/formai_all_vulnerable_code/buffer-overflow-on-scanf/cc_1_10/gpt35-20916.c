//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between lower and upper limit
int generateRandomNumber(int lower, int upper)
{
    int num;
    srand(time(0));
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

// Function to print a star pattern
void printStars(int num)
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

int main()
{
    int energyLevel = 100;
    int shieldLevel = 100;
    int planet = 1;
    int planetEnergy = 50;
    int planetShield = 25;
    int blackHole = 0;
    int resourceFound = 0;
    int numStars = 0;

    printf("Welcome to the Procedural Space Adventure game!\n\n");

    while (energyLevel > 0 && shieldLevel > 0 && planet < 4)
    {
        printf("You are on planet %d.\n", planet);
        printf("Your energy level is %d.\n", energyLevel);
        printf("Your shield level is %d.\n", shieldLevel);
        printf("Planet energy level is %d.\n", planetEnergy);
        printf("Planet shield level is %d.\n", planetShield);

        // Check if black hole is near
        if (blackHole == 1)
        {
            printf("WARNING: A black hole is near!\n");
            energyLevel = energyLevel - 25; // Decrease energy level
            printf("Your energy level decreased by 25.\n");
        }
        // Check if resource is found
        if (resourceFound == 1)
        {
            printf("You found a resource on the planet!\n");
            energyLevel = energyLevel + 25; // Increase energy level
            shieldLevel = shieldLevel + 25; // Increase shield level
            printf("Your energy level increased by 25.\n");
            printf("Your shield level increased by 25.\n");
        }
        // Show star pattern based on planet number
        if (planet == 1)
        {
            numStars = generateRandomNumber(5, 10); // Generate a random number between 5 and 10
            printf("\n");
            printStars(numStars); // Print the star pattern
        }
        else if (planet == 2)
        {
            numStars = generateRandomNumber(15, 20); // Generate a random number between 15 and 20
            printf("\n");
            printStars(numStars); // Print the star pattern
        }
        else if (planet == 3)
        {
            numStars = generateRandomNumber(25, 30); // Generate a random number between 25 and 30
            printf("\n");
            printStars(numStars); // Print the star pattern
        }

        // Ask for user input
        printf("\nWhat do you want to do now?\n");
        printf("1. Explore planet.\n");
        printf("2. Refuel.\n");
        printf("3. Repair shield.\n");
        printf("4. Travel to next planet.\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nExploring planet...\n");
            int randomNum = generateRandomNumber(1, 2); // Generate a random number between 1 and 2
            if (randomNum == 1)
            {
                printf("No resources found on the planet.\n");
            }
            else
            {
                printf("Resources found on the planet!\n");
                resourceFound = 1; // Set resource found flag to 1
            }
            break;

        case 2:
            printf("\nRefueling...\n");
            energyLevel = energyLevel + planetEnergy; // Increase energy level by planet energy level
            printf("Energy level refueled.\n");
            break;

        case 3:
            printf("\nRepairing shield...\n");
            shieldLevel = shieldLevel + planetShield; // Increase shield level by planet shield level
            printf("Shield repaired.\n");
            break;

        case 4:
            printf("\nTraveling to next planet...\n");
            energyLevel = energyLevel - 25; // Decrease energy level by 25
            shieldLevel = shieldLevel - 25; // Decrease shield level by 25
            planet++; // Increase planet number
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }

        // Check if energy level or shield level is less than 0
        if (energyLevel < 0)
        {
            energyLevel = 0;
        }
        if (shieldLevel < 0)
        {
            shieldLevel = 0;
        }

        // Check if black hole is near
        if (planet == 2)
        {
            blackHole = generateRandomNumber(0, 1); // Generate a random number between 0 and 1
        }
        else
        {
            blackHole = 0;
        }

        // Check if resource found
        if (resourceFound == 1)
        {
            planetEnergy = 0; // Set planet energy to 0
            planetShield = 0; // Set planet shield to 0
            resourceFound = 0; // Set resource found flag to 0
        }
        else
        {
            planetEnergy = generateRandomNumber(25, 50); // Generate a random number between 25 and 50
            planetShield = generateRandomNumber(10, 25); // Generate a random number between 10 and 25
        }

        // Check if energy level or shield level is less than 25
        if (energyLevel < 25 && planet == 3)
        {
            printf("\nYou cannot travel to the next planet as your energy level is less than 25.\n");
            printf("Game Over.\n");
            break;
        }
        if (shieldLevel < 25 && planet == 3)
        {
            printf("\nYou cannot travel to the next planet as your shield level is less than 25.\n");
            printf("Game Over.\n");
            break;
        }
    }

    if (planet == 4)
    {
        printf("\nCongratulations! You have successfully completed the Procedural Space Adventure game.\n");
        printf("You are now a space explorer!\n");
    }

    return 0;
}