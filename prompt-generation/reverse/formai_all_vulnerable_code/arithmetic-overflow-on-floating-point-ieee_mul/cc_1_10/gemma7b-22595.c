//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: satisfied
#include <stdio.h>
#include <math.h>

#define PI 3.14159

int main()
{
    int choice;
    float value;
    float convertedValue;

    // Display menu options
    printf("Choose an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert meters to miles\n");
    printf("4. Convert miles to meters\n");

    // Get user input
    scanf("Enter your choice: ", &choice);

    // Validate user input
    if (choice < 1 || choice > 4)
    {
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    // Get the value to be converted
    printf("Enter the value: ");
    scanf("%f", &value);

    // Convert the value
    switch (choice)
    {
        case 1:
            convertedValue = (value * 1.8) + 32;
            break;
        case 2:
            convertedValue = (value - 32) * 5 / 9;
            break;
        case 3:
            convertedValue = value * 1.613;
            break;
        case 4:
            convertedValue = value * 0.62137;
            break;
    }

    // Display the converted value
    printf("The converted value is: %.2f\n", convertedValue);

    return 0;
}