//FormAI DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius)
{
    return (celsius * 1.8) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit)
{
    return (fahrenheit - 32) / 1.8;
}

// Function to convert Miles to Kilometers
float miles_to_kilometers(float miles)
{
    return miles * 1.60934;
}

// Function to convert Kilometers to Miles
float kilometers_to_miles(float kilometers)
{
    return kilometers / 1.60934;
}

// Function to convert Pounds to Kilograms
float pounds_to_kilograms(float pounds)
{
    return pounds * 0.453592;
}

// Function to convert Kilograms to Pounds
float kilograms_to_pounds(float kilograms)
{
    return kilograms / 0.453592;
}

int main()
{
    int option;
    float value, result;

    printf("Welcome to the Unit Converter!\n\n");

    while (1)
    {
        printf("Choose an option from the menu below:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Pounds to Kilograms\n");
        printf("6. Kilograms to Pounds\n");
        printf("7. Exit\n");

        scanf("%d", &option);

        if (option == 7)
        {
            printf("\nThank you for using the Unit Converter!\n");
            break;
        }

        printf("\nEnter a value to convert:\n");
        scanf("%f", &value);

        switch (option)
        {
            case 1:
                result = celsius_to_fahrenheit(value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", value, result);
                break;

            case 2:
                result = fahrenheit_to_celsius(value);
                printf("%.2f Fahrenheit = %.2f Celsius\n", value, result);
                break;

            case 3:
                result = miles_to_kilometers(value);
                printf("%.2f Miles = %.2f Kilometers\n", value, result);
                break;

            case 4:
                result = kilometers_to_miles(value);
                printf("%.2f Kilometers = %.2f Miles\n", value, result);
                break;

            case 5:
                result = pounds_to_kilograms(value);
                printf("%.2f Pounds = %.2f Kilograms\n", value, result);
                break;

            case 6:
                result = kilograms_to_pounds(value);
                printf("%.2f Kilograms = %.2f Pounds\n", value, result);
                break;

            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}