//FormAI DATASET v1.0 Category: Unit converter ; Style: random
#include <stdio.h>

int main()
{
    int choice;
    float inputVal, outputVal;

    // Displaying the menu
    printf("Welcome to our Unit Converter!\n");
    printf("Which conversion you want to perform:\n");
    printf("1. Feet to Meters\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Gallons to Liters\n");
    printf("5. Inches to Centimeters\n");
    printf("6. Celsius to Fahrenheit\n");
    printf("7. Grams to Ounces\n");
    printf("Enter your choice: ");

    // Getting the user's choice
    scanf("%d", &choice);

    // Prompting user to enter the value to be converted
    printf("Enter the value you want to convert: ");

    // Getting the user input
    scanf("%f", &inputVal);

    // Checking user's choice and performing the conversion
    switch (choice)
    {
        case 1: // Feet to Meters
            outputVal = inputVal / 3.281;
            printf("%f feet = %f meters\n", inputVal, outputVal);
            break;
        case 2: // Miles to Kilometers
            outputVal = inputVal * 1.609;
            printf("%f miles = %f kms\n", inputVal, outputVal);
            break;
        case 3: // Pounds to Kilograms
            outputVal = inputVal * 0.453592;
            printf("%f lbs = %f kgs\n", inputVal, outputVal);
            break;
        case 4: // Gallons to Liters
            outputVal = inputVal * 3.78541;
            printf("%f gallons = %f liters\n", inputVal, outputVal);
            break;
        case 5: // Inches to Centimeters
            outputVal = inputVal * 2.54;
            printf("%f inches = %f cms\n", inputVal, outputVal);
            break;
        case 6: // Celsius to Fahrenheit
            outputVal = (inputVal * 9.0 / 5.0) + 32.0;
            printf("%f degrees Celsius = %f degrees Fahrenheit\n", inputVal, outputVal);
            break;
        case 7: // Grams to Ounces
            outputVal = inputVal * 0.035274;
            printf("%f grams = %f ounces\n", inputVal, outputVal);
            break;
        default:
            printf("Invalid input!\n");
            break;
    }

    return 0;
}