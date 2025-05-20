//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice;
    float num, result, value1, value2;

    // Welcome to the Ruins of Old New York
    printf("Welcome to the Ruins of Old New York. You are in the ruins of a once great city.\n");

    // Main Menu
    printf("Please select an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert Miles to Kilometers\n");
    printf("4. Convert Kilometers to Miles\n");

    // Get the user's choice
    scanf("%d", &choice);

    // Switch statement to handle the user's choice
    switch (choice)
    {
        case 1:
            // Convert Fahrenheit to Celsius
            printf("Enter the temperature in Fahrenheit:");
            scanf("%f", &num);
            value1 = (num - 32) * 5 / 9;
            result = value1;
            printf("The temperature in Celsius is: %.2f\n", result);
            break;

        case 2:
            // Convert Celsius to Fahrenheit
            printf("Enter the temperature in Celsius:");
            scanf("%f", &num);
            value2 = (num * 9 / 5) + 32;
            result = value2;
            printf("The temperature in Fahrenheit is: %.2f\n", result);
            break;

        case 3:
            // Convert Miles to Kilometers
            printf("Enter the distance in miles:");
            scanf("%f", &num);
            value1 = num * 1.613;
            result = value1;
            printf("The distance in kilometers is: %.2f\n", result);
            break;

        case 4:
            // Convert Kilometers to Miles
            printf("Enter the distance in kilometers:");
            scanf("%f", &num);
            value2 = num * 0.621371;
            result = value2;
            printf("The distance in miles is: %.2f\n", result);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    // Thank you for visiting the Ruins of Old New York
    printf("Thank you for visiting the Ruins of Old New York. May your journey be safe.\n");

    return;
}