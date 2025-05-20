//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: medieval
#include <stdio.h>
#include <math.h>

void main()
{
    int choice;
    float num, result;

    printf("Welcome to the Enchanted Calculator of Old!\n");
    printf("Please select an option:\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Convert miles to kilometers\n");
    printf("4. Convert kilometers to miles\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter the Fahrenheit temperature:");
            scanf("%f", &num);
            result = (num - 32) * 5 / 9;
            printf("The Celsius temperature is: %.2f", result);
            break;

        case 2:
            printf("Enter the Celsius temperature:");
            scanf("%f", &num);
            result = (num * 9 / 5) + 32;
            printf("The Fahrenheit temperature is: %.2f", result);
            break;

        case 3:
            printf("Enter the number of miles:");
            scanf("%f", &num);
            result = num * 1.613;
            printf("The number of kilometers is: %.2f", result);
            break;

        case 4:
            printf("Enter the number of kilometers:");
            scanf("%f", &num);
            result = num * 0.62137;
            printf("The number of miles is: %.2f", result);
            break;

        default:
            printf("Invalid choice. Please try again.");
    }

    printf("\nThank you for using the Enchanted Calculator of Old. May your conversions be precise and your imagination soar.");

    return;
}