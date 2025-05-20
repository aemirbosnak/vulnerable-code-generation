//Falcon2-11B DATASET v1.0 Category: Unit converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a menu for the user to choose the unit to convert from and to
    printf("Welcome to the Unit Converter! Choose a unit to convert from and to: \n");
    printf("1. Length (feet to meters) \n");
    printf("2. Volume (gallons to liters) \n");
    printf("3. Temperature (Fahrenheit to Celsius) \n");
    printf("4. Weight (pounds to kilograms) \n");
    printf("5. Exit \n");
    
    // Take user input
    char choice;
    printf("Enter your choice (1-5): ");
    scanf("%c", &choice);
    
    // Convert the user's choice to an integer
    int choiceInt;
    if (choice == '1') {
        choiceInt = 1;
    } else if (choice == '2') {
        choiceInt = 2;
    } else if (choice == '3') {
        choiceInt = 3;
    } else if (choice == '4') {
        choiceInt = 4;
    } else {
        choiceInt = 5;
    }
    
    // Convert the units based on the user's choice
    double feet, meters;
    double gallons, liters;
    double fahrenheit, celsius;
    double pounds, kilograms;
    
    if (choiceInt == 1) {
        printf("Converting from feet to meters: ");
        scanf("%lf", &feet);
        meters = feet * 0.3048;
        printf("%.2f feet is equal to %.2f meters.\n", feet, meters);
    } else if (choiceInt == 2) {
        printf("Converting from gallons to liters: ");
        scanf("%lf", &gallons);
        liters = gallons * 3.7854;
        printf("%.2f gallons is equal to %.2f liters.\n", gallons, liters);
    } else if (choiceInt == 3) {
        printf("Converting from Fahrenheit to Celsius: ");
        scanf("%lf", &fahrenheit);
        celsius = (fahrenheit - 32) * 5.0 / 9.0;
        printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
    } else if (choiceInt == 4) {
        printf("Converting from pounds to kilograms: ");
        scanf("%lf", &pounds);
        kilograms = pounds * 0.453592;
        printf("%.2f pounds is equal to %.2f kilograms.\n", pounds, kilograms);
    } else {
        printf("Exiting the program...\n");
        return 0;
    }
    
    return 0;
}