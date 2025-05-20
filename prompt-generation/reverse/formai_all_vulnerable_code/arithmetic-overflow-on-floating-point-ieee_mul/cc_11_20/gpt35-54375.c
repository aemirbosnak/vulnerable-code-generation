//FormAI DATASET v1.0 Category: Unit converter ; Style: realistic
#include <stdio.h>

int main() {
    int choice1, choice2;
    float value, convertedValue;

    printf("Select the type of unit to convert from:\n");
    printf("1. Length\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");
    scanf("%d", &choice1);

    printf("Select the type of unit to convert to:\n");
    printf("1. Length\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");
    scanf("%d", &choice2);

    printf("Enter the value to convert:\n");
    scanf("%f", &value);

    if(choice1 == 1 && choice2 == 1) {
        // Convert from meters to centimeters
        convertedValue = value * 100;
        printf("%.2f meters is equal to %.2f centimeters.\n", value, convertedValue);
    } else if(choice1 == 1 && choice2 == 2) {
        // Convert from meters to feet
        convertedValue = value * 3.28084;
        printf("%.2f meters is equal to %.2f feet.\n", value, convertedValue);
    } else if(choice1 == 1 && choice2 == 3) {
        // Contert from meters to yards
        convertedValue = value * 1.09361;
        printf("%.2f meters is equal to %.2f yards.\n", value, convertedValue);
    } else if(choice1 == 2 && choice2 == 2) {
        // Convert from Celsius to Fahrenheit
        convertedValue = (value * (9/5)) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", value, convertedValue);
    } else if(choice1 == 2 && choice2 == 1) {
       // Conver from Celsius to Kelvin
       convertedValue = value + 273.15;
       printf("%.2f Celsius is equal to %.2f Kelvin.\n", value, convertedValue);
    } else if(choice1 == 2 && choice2 == 3) {
        // Convert from Celsius to Rankine
        convertedValue = (value + 273.15) * (9/5);
        printf("%.2f Celsius is equal to %.2f Rankine.\n", value, convertedValue);
    } else if(choice1 == 3 && choice2 == 1) {
        // Convert from kg to pounds
        convertedValue = value * 2.20462;
        printf("%.2f kilograms is equal to %.2f pounds.\n", value, convertedValue);
    } else if(choice1 == 3 && choice2 == 2) {
        // Convert from kg to ounces
        convertedValue = value * 35.274;
        printf("%.2f kilograms is equal to %.2f ounces.\n", value, convertedValue);
    } else if(choice1 == 3 && choice2 == 3) {
        // Convert from kg to grams
        convertedValue = value * 1000;
        printf("%.2f kilograms is equal to %.2f grams.\n", value, convertedValue);
    } else {
        printf("Invalid input! Please try again.\n");
    }

    return 0;
}