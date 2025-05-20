//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice;
    float num;

    // Display menu options
    printf("\nPlease select an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert meters to kilometers\n");
    printf("4. Convert kilometers to meters\n");

    // Get user input
    scanf("Enter your choice: ", &choice);

    // Process user choice
    switch (choice)
    {
        case 1:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &num);
            float celsius = (num - 32) * 5 / 9;
            printf("The temperature in Celsius is: %.2f\n", celsius);
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &num);
            float fahrenheit = (num * 9 / 5) + 32;
            printf("The temperature in Fahrenheit is: %.2f\n", fahrenheit);
            break;
        case 3:
            printf("Enter the distance in meters: ");
            scanf("%f", &num);
            float kilometers = num * 1000 / 1609.34;
            printf("The distance in kilometers is: %.2f\n", kilometers);
            break;
        case 4:
            printf("Enter the distance in kilometers: ");
            scanf("%f", &num);
            float meters = num * 1609.34 / 1000;
            printf("The distance in meters is: %.2f\n", meters);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    return;
}