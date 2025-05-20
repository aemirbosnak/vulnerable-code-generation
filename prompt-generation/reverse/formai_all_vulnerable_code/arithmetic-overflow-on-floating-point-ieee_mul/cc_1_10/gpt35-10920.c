//FormAI DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>

int main()
{
    //conversion factors
    double meter_to_feet = 3.28084;
    double feet_to_meter = 0.3048;
    double kilometer_to_mile = 0.621371;
    double mile_to_kilometer = 1.60934;
    double celsius_to_fahrenheit = 1.8;
    double fahrenheit_to_celsius = 0.555556;
    int option;
    double value;

    printf("Welcome to the Unit Converter Program\n");

    do {
        printf("\n_______________________________________\n");
        printf("Please select an option:\n");
        printf("1. Convert Meters to Feet\n");
        printf("2. Convert Feet to Meters\n");
        printf("3. Convert Kilometers to Miles\n");
        printf("4. Convert Miles to Kilometers\n");
        printf("5. Convert Celsius to Fahrenheit\n");
        printf("6. Convert Fahrenheit to Celsius\n");
        printf("7. Exit Program\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("Please enter the value in meters: ");
                scanf("%lf", &value);
                printf("%.2lf meters = %.2lf feet\n", value, value * meter_to_feet);
                break;
            case 2:
                printf("Please enter the value in feet: ");
                scanf("%lf", &value);
                printf("%.2lf feet = %.2lf meters\n", value, value * feet_to_meter);
                break;
            case 3:
                printf("Please enter the value in kilometers: ");
                scanf("%lf", &value);
                printf("%.2lf kilometers = %.2lf miles\n", value, value * kilometer_to_mile);
                break;
            case 4:
                printf("Please enter the value in miles: ");
                scanf("%lf", &value);
                printf("%.2lf miles = %.2lf kilometers\n", value, value * mile_to_kilometer);
                break;
            case 5:
                printf("Please enter the value in Celsius: ");
                scanf("%lf", &value);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, (value * celsius_to_fahrenheit) + 32);
                break;
            case 6:
                printf("Please enter the value in Fahrenheit: ");
                scanf("%lf", &value);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, (value - 32) * fahrenheit_to_celsius);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option. Please enter a valid option.\n");
                break;
        }
    } while(option != 7);

    return 0;
}