//FormAI DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Define function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float degreeC) {
  float degreeF = ((degreeC * 9) / 5) + 32;
  return degreeF;
}

// Define function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float degreeF) {
  float degreeC = (degreeF - 32) * 5 / 9;
  return degreeC;
}

// Define function to convert Kilometers to Miles
float kilometersToMiles(float km) {
  float miles = km / 1.609;
  return miles;
}

// Define function to convert Miles to Kilometers
float milesToKilometers(float miles) {
  float km = miles * 1.609;
  return km;
}

int main() {
    // initialize variables to hold input values
    float degree, measurement;
    // initialize variables for user input prompt values
    char conversion, mode;

    // loop through the main conversion conversion loop until the user exits
    while (1) {
        printf("Enter 'C' to convert Celsius to Fahrenheit, 'F' to convert Fahrenheit to Celsius,\n"
        "'K' to convert Kilometers to Miles, 'M' to convert Miles to Kilometers, or 'X' to exit: ");
        scanf(" %c", &conversion);

        // check if user wants to exit the program
        if (conversion == 'X' || conversion == 'x') {
            printf("Thanks for using our Unit Converter Program!\n");
            break;
        }

        // check which conversion operation the user wants to perform
        switch (conversion) {
            // Celsius to Fahrenheit
            case 'C':
            case 'c':
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &degree);
                // make the conversion and print the result
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", degree, celsiusToFahrenheit(degree));
                break;
            // Fahrenheit to Celsius
            case 'F':
            case 'f':
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &degree);
                // make the conversion and print the result
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", degree, fahrenheitToCelsius(degree));
                break;
            // Kilometers to Miles
            case 'K':
            case 'k':
                printf("Enter the distance in Kilometers: ");
                scanf("%f", &measurement);
                // make the conversion and print the result
                printf("%.2f Kilometers is equal to %.2f Miles\n", measurement, kilometersToMiles(measurement));
                break;
            // Miles to Kilometers
            case 'M':
            case 'm':
                printf("Enter the distance in Miles: ");
                scanf("%f", &measurement);
                // make the conversion and print the result
                printf("%.2f Miles is equal to %.2f Kilometers\n", measurement, milesToKilometers(measurement));
                break;
            default:
                printf("Invalid conversion option, please try again.\n");
                break;
        }

        printf("Do you want to perform another conversion? Enter 'Y' for Yes or 'N' for No: ");
        scanf(" %c", &mode);

        // check if user wants to exit the program
        if (mode == 'N' || mode == 'n') {
            printf("Thanks for using our Unit Converter Program!\n");
            break;
        }
    }

    return 0;
}