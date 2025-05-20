//FormAI DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>

int main() {
    // Displaying welcome message and prompt for input
    printf("Welcome to the Unit Converter!\n\n");
    printf("Please select one of the options below:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Inches to Centimeters\n");
    printf("3. Pounds to Kilograms\n\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    // Fahrenheit to Celsius conversion
    if (choice == 1){
        printf("You have selected Fahrenheit to Celsius conversion!\n\n");
        float fahrenheit;
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);
        float celsius = (fahrenheit - 32) * 5 / 9;
        printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, celsius);
    }

    // Inches to Centimeters conversion
    else if (choice == 2){
        printf("You have selected Inches to Centimeters conversion!\n\n");
        float inches;
        printf("Enter the length in inches: ");
        scanf("%f", &inches);
        float centimeters = inches * 2.54;
        printf("%.2f inches is %.2f centimeters\n", inches, centimeters);
    }

    // Pounds to Kilograms conversion
    else if (choice == 3){
        printf("You have selected Pounds to Kilograms conversion!\n\n");
        float pounds;
        printf("Enter the weight in pounds: ");
        scanf("%f", &pounds);
        float kilograms = pounds / 2.2046;
        printf("%.2f pounds is %.2f kilograms\n", pounds, kilograms);
    }

    // Invalid choice entered
    else{
        printf("Invalid choice selected! Please select options 1, 2 or 3.\n");
    }

    return 0;
}