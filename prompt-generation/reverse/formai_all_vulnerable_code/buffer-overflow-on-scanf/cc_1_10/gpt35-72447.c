//FormAI DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice;
    float tempInC, tempInF, tempInK;

    printf("Welcome to the Temperature Converter Program\n");

    do
    {
        printf("Please select an option from the menu below:\n");
        printf("1. Convert Celsius to Fahrenheit and Kelvin\n");
        printf("2. Convert Fahrenheit to Celsius and Kelvin\n");
        printf("3. Convert Kelvin to Celsius and Fahrenheit\n");
        printf("4. Exit the program\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &tempInC);
                tempInF = (tempInC * 1.8) + 32;
                tempInK = tempInC + 273.15;
                printf("%.2f Celsius is equal to %.2f Fahrenheit and %.2f Kelvin\n", tempInC, tempInF, tempInK);
                break;

            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &tempInF);
                tempInC = (tempInF - 32) / 1.8;
                tempInK = ((tempInF - 32) / 1.8) + 273.15;
                printf("%.2f Fahrenheit is equal to %.2f Celsius and %.2f Kelvin\n", tempInF, tempInC, tempInK);
                break;

            case 3:
                printf("Enter temperature in Kelvin: ");
                scanf("%f", &tempInK);
                tempInC = tempInK - 273.15;
                tempInF = ((tempInK - 273.15) * 1.8) + 32;
                printf("%.2f Kelvin is equal to %.2f Celsius and %.2f Fahrenheit\n", tempInK, tempInC, tempInF);
                break;

            case 4:
                printf("Thank you for using the Temperature Converter Program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option selected. Please try again.\n");
        }

    }while(choice != 4);

    return 0;
}