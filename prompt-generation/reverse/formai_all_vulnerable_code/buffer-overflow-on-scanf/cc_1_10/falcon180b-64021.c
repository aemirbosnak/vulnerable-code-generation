//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>

// Function to convert meter to feet
void meterToFeet(double meter) {
    double feet = meter * 3.28084;
    printf("%.2f meters is equal to %.2f feet.\n", meter, feet);
}

// Function to convert kilometer to mile
void kilometerToMile(double kilometer) {
    double mile = kilometer * 0.621371;
    printf("%.2f kilometers is equal to %.2f miles.\n", kilometer, mile);
}

// Function to convert liter to gallon
void literToGallon(double liter) {
    double gallon = liter * 0.264172;
    printf("%.2f liters is equal to %.2f gallons.\n", liter, gallon);
}

// Function to convert kilogram to pound
void kilogramToPound(double kilogram) {
    double pound = kilogram * 2.20462;
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilogram, pound);
}

// Function to convert Celsius to Fahrenheit
void celsiusToFahrenheit(double celsius) {
    double fahrenheit = celsius * 1.8 + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    double meter, kilometer, liter, kilogram, celsius;
    char choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Enter the value you want to convert and the unit of measurement:\n");
    printf("1. Meter to Feet\n2. Kilometer to Mile\n3. Liter to Gallon\n4. Kilogram to Pound\n5. Celsius to Fahrenheit\n");

    scanf("%c", &choice);

    switch(choice) {
        case '1':
            printf("Enter the value in meter: ");
            scanf("%lf", &meter);
            meterToFeet(meter);
            break;

        case '2':
            printf("Enter the value in kilometer: ");
            scanf("%lf", &kilometer);
            kilometerToMile(kilometer);
            break;

        case '3':
            printf("Enter the value in liter: ");
            scanf("%lf", &liter);
            literToGallon(liter);
            break;

        case '4':
            printf("Enter the value in kilogram: ");
            scanf("%lf", &kilogram);
            kilogramToPound(kilogram);
            break;

        case '5':
            printf("Enter the value in Celsius: ");
            scanf("%lf", &celsius);
            celsiusToFahrenheit(celsius);
            break;

        default:
            printf("Invalid choice! Please enter a valid choice.\n");
            break;
    }

    return 0;
}