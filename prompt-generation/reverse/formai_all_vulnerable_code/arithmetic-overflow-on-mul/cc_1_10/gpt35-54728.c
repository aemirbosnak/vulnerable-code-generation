//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int convertUnit(int choice, int value);

int main()
{
    int choice, value, result;

    printf("Welcome to Unit Converter!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Miles to Kilometers\n");
        printf("3. Convert Inches to Centimeters\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        if(choice < 1 || choice > 4){
            printf("Invalid option. Please enter a number between 1 and 4.\n");
            continue;
        }

        if(choice == 4){
            printf("Goodbye!\n");
            break;
        }

        printf("Enter a value to convert:\n");
        scanf("%d", &value);

        result = convertUnit(choice, value);

        printf("Converted value: %d\n\n", result);

    } while(choice != 4);

    return 0;
}

int convertUnit(int choice, int value)
{
    int result;

    switch(choice){
        case 1: //Convert Celsius to Fahrenheit
            result = (value * 9 / 5) + 32;
            break;
        case 2: //Convert Miles to Kilometers
            result = value * 1.60934;
            break;
        case 3: //Convert Inches to Centimeters
            result = value * 2.54;
            break;
        default:
            printf("Invalid option. Please enter a number between 1 and 4.\n");
            break;
    }

    return result;
}