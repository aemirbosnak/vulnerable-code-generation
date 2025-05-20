//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
/* Unique C Unit Converter Example Program */
/* By: [Your Name] */

#include <stdio.h>
#include <stdlib.h>

/* Function Declarations */
double meters_to_feet(double meters);
double feet_to_meters(double feet);
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);

/* Main Function */
int main()
{
    int choice;
    double input, result;
    
    printf("Welcome to the Ultra-Precise Unit Converter!\n");
    printf("--------------------------------------------\n\n");
    
    do {
        printf("What unit conversion would you like to perform?\n");
        printf("1. Meters to Feet\n");
        printf("2. Feet to Meters\n");
        printf("3. Celsius to Fahrenheit\n");
        printf("4. Fahrenheit to Celsius\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1:
                printf("Enter the length in meters: ");
                scanf("%lf", &input);
                result = meters_to_feet(input);
                printf("%.2lf meters is equal to %.2lf feet.\n\n", input, result);
                break;
                
            case 2:
                printf("Enter the length in feet: ");
                scanf("%lf", &input);
                result = feet_to_meters(input);
                printf("%.2lf feet is equal to %.2lf meters.\n\n", input, result);
                break;
                
            case 3:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &input);
                result = celsius_to_fahrenheit(input);
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n\n", input, result);
                break;
                
            case 4:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &input);
                result = fahrenheit_to_celsius(input);
                printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n\n", input, result);
                break;
                
            case 5:
                break;
                
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n\n");
                break;
        }
    } while(choice != 5);
    
    printf("Thank you for using the Ultra-Precise Unit Converter!\n\n");
    
    return 0;
}

/* Function Definitions */
double meters_to_feet(double meters) {
    return meters * 3.28084;
}

double feet_to_meters(double feet) {
    return feet * 0.3048;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 1.8) + 32.0;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32.0) / 1.8;
}