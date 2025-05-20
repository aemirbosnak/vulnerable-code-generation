//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: multivariable
#include <stdio.h>

void lengthConversion();
void weightConversion();
void temperatureConversion();

void lengthConversion() {
    float meters, feet, yards, inches;

    printf("\nLength Conversion:\n");
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    feet = meters * 3.28084;
    yards = meters * 1.09361;
    inches = meters * 39.3701;

    printf("Length in feet: %.2f ft\n", feet);
    printf("Length in yards: %.2f yd\n", yards);
    printf("Length in inches: %.2f in\n", inches);
}

void weightConversion() {
    float kilograms, pounds, ounces;

    printf("\nWeight Conversion:\n");
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilograms);

    pounds = kilograms * 2.20462;
    ounces = kilograms * 35.274;

    printf("Weight in pounds: %.2f lbs\n", pounds);
    printf("Weight in ounces: %.2f oz\n", ounces);
}

void temperatureConversion() {
    float celsius, fahrenheit, kelvin;

    printf("\nTemperature Conversion:\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;

    printf("Temperature in Fahrenheit: %.2f °F\n", fahrenheit);
    printf("Temperature in Kelvin: %.2f K\n", kelvin);
}

int main() {
    int choice;

    do {
        printf("\nUnit Converter Menu:\n");
        printf("1. Length Conversion (Meters to Feet/Yards/Inches)\n");
        printf("2. Weight Conversion (Kilograms to Pounds/Ounces)\n");
        printf("3. Temperature Conversion (Celsius to Fahrenheit/Kelvin)\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                temperatureConversion();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}