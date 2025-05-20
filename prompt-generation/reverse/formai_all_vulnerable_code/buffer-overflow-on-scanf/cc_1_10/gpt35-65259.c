//FormAI DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>

// Constants for paranoid conversion
#define INCHES_LIMIT 1000.0
#define FEET_LIMIT 1000.0
#define MILES_LIMIT 10.0
#define KILOMETERS_LIMIT 10.0
#define POUNDS_LIMIT 1000.0
#define KILOGRAMS_LIMIT 1000.0

// Function prototypes
double convertInchesToCentimeters(double inches);
double convertFeetToMeters(double feet);
double convertMilesToKilometers(double miles);
double convertPoundsToKilograms(double pounds);

// Prevents the user from inputting absurd values for conversion
int paranoidInput(char* unit, double limit) {
    double value;
    printf("Enter the value of %s: ", unit);
    scanf("%lf", &value);
    while(value <= 0 || value > limit) {
        printf("Invalid input. Enter a value between 0 and %.2lf: ", limit);
        scanf("%lf", &value);
    }
    return value;
}

int main() {
    int choice;
    do {
        printf("*** UNIT CONVERSION ***\n");
        printf("What do you want to convert?\n");
        printf("1. Inches to Centimeters\n");
        printf("2. Feet to Meters\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Pounds to Kilograms\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("** INCHES TO CENTIMETERS **\n");
                double inches = paranoidInput("inches", INCHES_LIMIT);
                double centimeters = convertInchesToCentimeters(inches);
                printf("%.2lf inches is equivalent to %.2lf centimeters.\n\n", inches, centimeters);
                break;
            case 2:
                printf("** FEET TO METERS **\n");
                double feet = paranoidInput("feet", FEET_LIMIT);
                double meters = convertFeetToMeters(feet);
                printf("%.2lf feet is equivalent to %.2lf meters.\n\n", feet, meters);
                break;
            case 3:
                printf("** MILES TO KILOMETERS **\n");
                double miles = paranoidInput("miles", MILES_LIMIT);
                double kilometers = convertMilesToKilometers(miles);
                printf("%.2lf miles is equivalent to %.2lf kilometers.\n\n", miles, kilometers);
                break;
            case 4:
                printf("** POUNDS TO KILOGRAMS **\n");
                double pounds = paranoidInput("pounds", POUNDS_LIMIT);
                double kilograms = convertPoundsToKilograms(pounds);
                printf("%.2lf pounds is equivalent to %.2lf kilograms.\n\n", pounds, kilograms);
                break;
            case 5:
                printf("** QUITTING PROGRAM **\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n\n");
                break;
        }
    } while(choice != 5);
    return 0;
}

// Conversion functions
double convertInchesToCentimeters(double inches) {
    return inches * 2.54;
}

double convertFeetToMeters(double feet) {
    return feet * 0.3048;
}

double convertMilesToKilometers(double miles) {
    return miles * 1.60934;
}

double convertPoundsToKilograms(double pounds) {
    return pounds * 0.453592;
}