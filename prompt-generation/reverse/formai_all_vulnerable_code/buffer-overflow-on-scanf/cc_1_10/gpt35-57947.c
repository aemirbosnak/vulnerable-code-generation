//FormAI DATASET v1.0 Category: Unit converter ; Style: invasive
#include <stdio.h>

void menu()
{
    printf("\n--- UNIT CONVERTER ---\n");
    printf("1. Feet to meters\n");
    printf("2. Miles to kilometers\n");
    printf("3. Pounds to kilograms\n");
    printf("4. Gallons to liters\n");
    printf("5. Fahrenheit to Celsius\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void feet_to_meters()
{
    float feet, meters;
    printf("Enter measurement in feet: ");
    scanf("%f", &feet);
    meters = feet * 0.3048;
    printf("%.2f feet = %.2f meters\n", feet, meters);
}

void miles_to_kilometers()
{
    float miles, kilometers;
    printf("Enter measurement in miles: ");
    scanf("%f", &miles);
    kilometers = miles * 1.60934;
    printf("%.2f miles = %.2f kilometers\n", miles, kilometers);
}

void pounds_to_kilograms()
{
    float pounds, kilograms;
    printf("Enter weight in pounds: ");
    scanf("%f", &pounds);
    kilograms = pounds * 0.453592;
    printf("%.2f pounds = %.2f kilograms\n", pounds, kilograms);
}

void gallons_to_liters()
{
    float gallons, liters;
    printf("Enter volume in gallons: ");
    scanf("%f", &gallons);
    liters = gallons * 3.78541;
    printf("%.2f gallons = %.2f liters\n", gallons, liters);
}

void fahrenheit_to_celsius()
{
    float fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2f degrees Fahrenheit = %.2f degrees Celsius\n", fahrenheit, celsius);
}

int main()
{
    int choice;
    do
    {
        menu();
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                feet_to_meters();
                break;
            case 2:
                miles_to_kilometers();
                break;
            case 3:
                pounds_to_kilograms();
                break;
            case 4:
                gallons_to_liters();
                break;
            case 5:
                fahrenheit_to_celsius();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}