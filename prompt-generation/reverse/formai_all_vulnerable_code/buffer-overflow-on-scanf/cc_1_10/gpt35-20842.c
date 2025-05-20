//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>

int menu(); // function for displaying menu and getting user input
void celsius_to_fahrenheit(); // function for converting Celsius to Fahrenheit
void fahrenheit_to_celsius(); // function for converting Fahrenheit to Celsius
void kilometers_to_miles(); // function for converting kilometers to miles
void miles_to_kilometers(); // function for converting miles to kilometers

int main()
{
    int choice;

    do {
        choice = menu();

        switch(choice) {
            case 1:
                celsius_to_fahrenheit();
                break;
            case 2:
                fahrenheit_to_celsius();
                break;
            case 3:
                kilometers_to_miles();
                break;
            case 4:
                miles_to_kilometers();
                break;
            case 5:
                printf("\nThank you for using the unit converter.\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

int menu()
{
    int choice;

    printf("Unit Converter\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void celsius_to_fahrenheit()
{
    float celsius, fahrenheit;

    printf("Celsius to Fahrenheit\n\n");
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

void fahrenheit_to_celsius()
{
    float celsius, fahrenheit;

    printf("Fahrenheit to Celsius\n\n");
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - 32) * 5 / 9;

    printf("%.2f degrees Fahrenheit is %.2f degrees Celsius.\n", fahrenheit, celsius);
}

void kilometers_to_miles()
{
    float kilometers, miles;

    printf("Kilometers to Miles\n\n");
    printf("Enter the distance in kilometers: ");
    scanf("%f", &kilometers);

    miles = kilometers / 1.609;

    printf("%.2f kilometers is %.2f miles.\n", kilometers, miles);
}

void miles_to_kilometers()
{
    float kilometers, miles;

    printf("Miles to Kilometers\n\n");
    printf("Enter the distance in miles: ");
    scanf("%f", &miles);

    kilometers = miles * 1.609;

    printf("%.2f miles is %.2f kilometers.\n", miles, kilometers);
}