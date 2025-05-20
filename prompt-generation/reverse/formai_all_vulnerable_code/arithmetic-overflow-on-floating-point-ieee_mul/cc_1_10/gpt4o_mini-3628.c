//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void showMenu();
void convertLength();
void convertWeight();
void convertTemperature();
void lengthOptions();
void weightOptions();
void temperatureOptions();
void clearInputBuffer(); // To prevent issues from lingering input

int main() {
    int choice = -1;

    while (1) {
        showMenu();
        printf("Please enter a choice (1-4): ");
        int result = scanf("%d", &choice);

        if (result != 1) {
            clearInputBuffer();
            printf("Invalid input! Please enter a number between 1 and 4.\n");
            continue;
        }

        if (choice < 1 || choice > 4) {
            printf("Out of range! Try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                printf("Exiting the program... Stay safe!\n");
                exit(0);
            default:
                printf("This should never happen!\n");
        }
    }

    return 0;
}

void showMenu() {
    printf("\n************ Unit Converter ************\n");
    printf("1. Convert Length\n");
    printf("2. Convert Weight\n");
    printf("3. Convert Temperature\n");
    printf("4. Exit\n");
    printf("*****************************************\n");
}

void convertLength() {
    int choice = -1;
    double value, convertedValue;

    lengthOptions();
    printf("Choose a length conversion (1-6): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 6) {
        printf("Choosing an option outside the limits, are we?\n");
        return;
    }

    printf("Enter the length value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1: // Meters to Feet
            convertedValue = value * 3.28084;
            printf("%.2f meters = %.2f feet\n", value, convertedValue);
            break;
        case 2: // Feet to Meters
            convertedValue = value / 3.28084;
            printf("%.2f feet = %.2f meters\n", value, convertedValue);
            break;
        case 3: // Meters to Yards
            convertedValue = value * 1.09361;
            printf("%.2f meters = %.2f yards\n", value, convertedValue);
            break;
        case 4: // Yards to Meters
            convertedValue = value / 1.09361;
            printf("%.2f yards = %.2f meters\n", value, convertedValue);
            break;
        case 5: // Kilometers to Miles
            convertedValue = value * 0.621371;
            printf("%.2f kilometers = %.2f miles\n", value, convertedValue);
            break;
        case 6: // Miles to Kilometers
            convertedValue = value / 0.621371;
            printf("%.2f miles = %.2f kilometers\n", value, convertedValue);
            break;
        default:
            printf("Invalid conversion choice. The paranoia is creeping in...\n");
    }
}

void convertWeight() {
    int choice = -1;
    double value, convertedValue;

    weightOptions();
    printf("Choose a weight conversion (1-6): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 6) {
        printf("Warning: You seem to be dabbling where you shouldn't!\n");
        return;
    }

    printf("Enter the weight value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1: // Kilograms to Pounds
            convertedValue = value * 2.20462;
            printf("%.2f kilograms = %.2f pounds\n", value, convertedValue);
            break;
        case 2: // Pounds to Kilograms
            convertedValue = value / 2.20462;
            printf("%.2f pounds = %.2f kilograms\n", value, convertedValue);
            break;
        case 3: // Grams to Ounces
            convertedValue = value * 0.035274;
            printf("%.2f grams = %.2f ounces\n", value, convertedValue);
            break;
        case 4: // Ounces to Grams
            convertedValue = value / 0.035274;
            printf("%.2f ounces = %.2f grams\n", value, convertedValue);
            break;
        case 5: // Stones to Pounds
            convertedValue = value * 14.0;
            printf("%.2f stones = %.2f pounds\n", value, convertedValue);
            break;
        case 6: // Pounds to Stones
            convertedValue = value / 14.0;
            printf("%.2f pounds = %.2f stones\n", value, convertedValue);
            break;
        default:
            printf("You have stirred the pot of confusion!\n");
    }
}

void convertTemperature() {
    int choice = -1;
    double value, convertedValue;

    temperatureOptions();
    printf("Choose a temperature conversion (1-3): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Caution! Ignoring the rules can lead to discomfort!\n");
        return;
    }

    printf("Enter the temperature value to convert: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1: // Celsius to Fahrenheit
            convertedValue = (value * 9 / 5) + 32;
            printf("%.2f Celsius = %.2f Fahrenheit\n", value, convertedValue);
            break;
        case 2: // Fahrenheit to Celsius
            convertedValue = (value - 32) * 5 / 9;
            printf("%.2f Fahrenheit = %.2f Celsius\n", value, convertedValue);
            break;
        case 3: // Kelvin to Celsius
            convertedValue = value - 273.15;
            printf("%.2f Kelvin = %.2f Celsius\n", value, convertedValue);
            break;
        default:
            printf("What sorcery is this? Abandon hope...\n");
    }
}

void lengthOptions() {
    printf("\n*** Length Conversion Options ***\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Meters to Yards\n");
    printf("4. Yards to Meters\n");
    printf("5. Kilometers to Miles\n");
    printf("6. Miles to Kilometers\n");
}

void weightOptions() {
    printf("\n*** Weight Conversion Options ***\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("5. Stones to Pounds\n");
    printf("6. Pounds to Stones\n");
}

void temperatureOptions() {
    printf("\n*** Temperature Conversion Options ***\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear buffer until the newline
}