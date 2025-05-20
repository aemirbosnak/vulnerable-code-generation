//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

// Function prototypes
void displayMenu();
void convertTemperature();
void convertLength();
void convertWeight();

int main()
{
    // Display welcome message
    printf("--- Welcome to the Unit Converter ---\n\n");

    // Display the menu
    displayMenu();

    return 0;
}

void displayMenu()
{
    int choice;

    // Display the menu options
    printf("Select an option to convert:\n");
    printf("1. Temperature\n");
    printf("2. Length\n");
    printf("3. Weight\n");
    printf("4. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Convert the units based on the user's choice
    switch(choice)
    {
        case 1:
            convertTemperature();
            break;
        case 2:
            convertLength();
            break;
        case 3:
            convertWeight();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            displayMenu();
    }
}

void convertTemperature()
{
    int choice;
    double input, output;

    // Display the temperature conversion options
    printf("\nSelect a conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("5. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the temperature conversion based on the user's choice
    switch(choice)
    {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &input);
            output = input * 1.8 + 32;
            printf("The temperature in Fahrenheit is: %.2lf\n", output);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &input);
            output = (input - 32) / 1.8;
            printf("The temperature in Celsius is: %.2lf\n", output);
            break;
        case 3:
            printf("Enter the temperature in Kelvin: ");
            scanf("%lf", &input);
            output = input - 273.15;
            printf("The temperature in Celsius is: %.2lf\n", output);
            break;
        case 4:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &input);
            output = input + 273.15;
            printf("The temperature in Kelvin is: %.2lf\n", output);
            break;
        case 5:
            displayMenu();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            convertTemperature();
    }

    // Prompt the user to convert another value or return to the main menu
    printf("\nDo you want to convert another temperature value? (y/n): ");
    char ans;
    scanf(" %c", &ans);
    if(ans == 'y' || ans == 'Y')
    {
        convertTemperature();
    }
    else
    {
        displayMenu();
    }
}

void convertLength()
{
    int choice;
    double input, output;

    // Display the length conversion options
    printf("\nSelect a conversion option:\n");
    printf("1. Inches to Centimeters\n");
    printf("2. Centimeters to Inches\n");
    printf("3. Feet to Meters\n");
    printf("4. Meters to Feet\n");
    printf("5. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the length conversion based on the user's choice
    switch(choice)
    {
        case 1:
            printf("Enter the length in inches: ");
            scanf("%lf", &input);
            output = input * 2.54;
            printf("The length in centimeters is: %.2lf\n", output);
            break;
        case 2:
            printf("Enter the length in centimeters: ");
            scanf("%lf", &input);
            output = input / 2.54;
            printf("The length in inches is: %.2lf\n", output);
            break;
        case 3:
            printf("Enter the length in feet: ");
            scanf("%lf", &input);
            output = input / 3.281;
            printf("The length in meters is: %.2lf\n", output);
            break;
        case 4:
            printf("Enter the length in meters: ");
            scanf("%lf", &input);
            output = input * 3.281;
            printf("The length in feet is: %.2lf\n", output);
            break;
        case 5:
            displayMenu();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            convertLength();
    }

    // Prompt the user to convert another value or return to the main menu
    printf("\nDo you want to convert another length value? (y/n): ");
    char ans;
    scanf(" %c", &ans);
    if(ans == 'y' || ans == 'Y')
    {
        convertLength();
    }
    else
    {
        displayMenu();
    }
}

void convertWeight()
{
    int choice;
    double input, output;

    // Display the weight conversion options
    printf("\nSelect a conversion option:\n");
    printf("1. Pounds to Kilograms\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Ounces to Grams\n");
    printf("4. Grams to Ounces\n");
    printf("5. Exit\n");

    // Get the user's choice
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Perform the weight conversion based on the user's choice
    switch(choice)
    {
        case 1:
            printf("Enter the weight in pounds: ");
            scanf("%lf", &input);
            output = input * 0.4536;
            printf("The weight in kilograms is: %.2lf\n", output);
            break;
        case 2:
            printf("Enter the weight in kilograms: ");
            scanf("%lf", &input);
            output = input / 0.4536;
            printf("The weight in pounds is: %.2lf\n", output);
            break;
        case 3:
            printf("Enter the weight in ounces: ");
            scanf("%lf", &input);
            output = input * 28.35;
            printf("The weight in grams is: %.2lf\n", output);
            break;
        case 4:
            printf("Enter the weight in grams: ");
            scanf("%lf", &input);
            output = input / 28.35;
            printf("The weight in ounces is: %.2lf\n", output);
            break;
        case 5:
            displayMenu();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            convertWeight();
    }

    // Prompt the user to convert another value or return to the main menu
    printf("\nDo you want to convert another weight value? (y/n): ");
    char ans;
    scanf(" %c", &ans);
    if(ans == 'y' || ans == 'Y')
    {
        convertWeight();
    }
    else
    {
        displayMenu();
    }
}