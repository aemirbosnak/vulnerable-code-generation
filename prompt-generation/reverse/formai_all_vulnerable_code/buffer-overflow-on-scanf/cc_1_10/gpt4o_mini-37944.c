//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: recursive
#include <stdio.h>

// Function prototypes for unit conversion
void lengthConverter();
void weightConverter();
void temperatureConverter();
void mainMenu();
void repeatConversion();

double metersToFeet(double meters) {
    return meters * 3.28084;
}

double feetToMeters(double feet) {
    return feet / 3.28084;
}

double kilogramsToPounds(double kg) {
    return kg * 2.20462;
}

double poundsToKilograms(double lbs) {
    return lbs / 2.20462;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

void lengthConverter() {
    double value;
    int choice;

    printf("Length Converter:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter value in meters: ");
        scanf("%lf", &value);
        printf("%.2lf meters is %.2lf feet.\n", value, metersToFeet(value));
    } else if (choice == 2) {
        printf("Enter value in feet: ");
        scanf("%lf", &value);
        printf("%.2lf feet is %.2lf meters.\n", value, feetToMeters(value));
    } else {
        printf("Invalid choice. Please try again.\n");
        lengthConverter();
    }
}

void weightConverter() {
    double value;
    int choice;

    printf("Weight Converter:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter value in kilograms: ");
        scanf("%lf", &value);
        printf("%.2lf kilograms is %.2lf pounds.\n", value, kilogramsToPounds(value));
    } else if (choice == 2) {
        printf("Enter value in pounds: ");
        scanf("%lf", &value);
        printf("%.2lf pounds is %.2lf kilograms.\n", value, poundsToKilograms(value));
    } else {
        printf("Invalid choice. Please try again.\n");
        weightConverter();
    }
}

void temperatureConverter() {
    double value;
    int choice;

    printf("Temperature Converter:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter value in Celsius: ");
        scanf("%lf", &value);
        printf("%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", value, celsiusToFahrenheit(value));
    } else if (choice == 2) {
        printf("Enter value in Fahrenheit: ");
        scanf("%lf", &value);
        printf("%.2lf degrees Fahrenheit is %.2lf degrees Celsius.\n", value, fahrenheitToCelsius(value));
    } else {
        printf("Invalid choice. Please try again.\n");
        temperatureConverter();
    }
}

void repeatConversion() {
    char choice;
    printf("Would you like to perform another conversion? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        mainMenu();
    } else if (choice == 'n' || choice == 'N') {
        printf("Thank you for using the unit converter. Goodbye!\n");
    } else {
        printf("Invalid input. Please try again.\n");
        repeatConversion();
    }
}

void mainMenu() {
    int selection;

    printf("\nUnit Converter Menu:\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
    scanf("%d", &selection);

    switch (selection) {
        case 1:
            lengthConverter();
            repeatConversion();
            break;
        case 2:
            weightConverter();
            repeatConversion();
            break;
        case 3:
            temperatureConverter();
            repeatConversion();
            break;
        case 4:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            mainMenu();
            break;
    }
}

int main() {
    mainMenu();
    return 0;
}