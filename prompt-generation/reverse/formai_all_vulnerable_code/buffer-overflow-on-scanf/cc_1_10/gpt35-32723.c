//FormAI DATASET v1.0 Category: Unit converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float value;
    float result;

    printf("Welcome to the futuristic Unit Converter!\n\n");

    while(1) // Loop until user exits
    {
        printf("\nPlease choose a conversion option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Light Years to Kilometers\n");
        printf("4. Kilometers to Light Years\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the temperature in Celsius: ");
                scanf("%f", &value);
                result = (value * 9 / 5) + 32;
                printf("%.2f degrees Fahrenheit\n", result);
                break;

            case 2:
                printf("\nEnter the temperature in Fahrenheit: ");
                scanf("%f", &value);
                result = (value - 32) * 5 / 9;
                printf("%.2f degrees Celsius\n", result);
                break;

            case 3:
                printf("\nEnter the distance in Light Years: ");
                scanf("%f", &value);
                result = value * 9.461e+12;
                printf("%.2f kilometers\n", result);
                break;

            case 4:
                printf("\nEnter the distance in Kilometers: ");
                scanf("%f", &value);
                result = value / 9.461e+12;
                printf("%.2f Light Years\n", result);
                break;

            case 5:
                printf("Thank you for using the futuristic Unit Converter! Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}