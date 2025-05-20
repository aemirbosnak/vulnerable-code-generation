//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>

// Function declarations
void printMenu();
void convertTemperature();
void convertLength();
void convertMass();
void convertSpeed();
void convertVolume();

// Main function
int main() {
    int choice;

    do {
        printMenu();

        // User input for choice
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Switch statement to call respective conversion function based on user's choice
        switch(choice) {
            case 1:
                convertTemperature();
                break;
            case 2:
                convertLength();
                break;
            case 3:
                convertMass();
                break;
            case 4:
                convertSpeed();
                break;
            case 5:
                convertVolume();
                break;
            case 6:
                printf("\nThank you for using this program.\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to display the main menu
void printMenu() {
    printf("\n----- Unit Converter -----\n");
    printf("1. Temperature\n");
    printf("2. Length\n");
    printf("3. Mass\n");
    printf("4. Speed\n");
    printf("5. Volume\n");
    printf("6. Exit\n");
}

// Function to convert temperature units
void convertTemperature() {
    float input, result;
    int choice;

    printf("\n----- Temperature Conversion -----\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%f", &input);

    // conversion based on the user's choice
    switch(choice) {
        case 1:
            result = input * 1.8 + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", input, result);
            break;
        case 2:
            result = input + 273.15;
            printf("%.2f Celsius is equal to %.2f Kelvin.\n", input, result);
            break;
        case 3:
            result = (input - 32) / 1.8;
            printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", input, result);
            break;
        case 4:
            result = (input - 32) / 1.8 + 273.15;
            printf("%.2f Fahrenheit is equal to %.2f Kelvin.\n", input, result);
            break;
        case 5:
            result = input - 273.15;
            printf("%.2f Kelvin is equal to %.2f Celsius.\n", input, result);
            break;
        case 6:
            result = (input - 273.15) * 1.8 + 32;
            printf("%.2f Kelvin is equal to %.2f Fahrenheit.\n", input, result);
            break;
        default:
            printf("\nInvalid choice, please try again.\n");
    }
}

// Function to convert length units
void convertLength() {
    float input, result;
    int choice;

    printf("\n----- Length Conversion -----\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Meters to Miles\n");
    printf("3. Kilometers to Meters\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Miles to Meters\n");
    printf("6. Miles to Kilometers\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%f", &input);

    // conversion based on the user's choice
    switch(choice) {
        case 1:
            result = input / 1000;
            printf("%.2f Meters is equal to %.2f Kilometers.\n", input, result);
            break;
        case 2:
            result = input * 0.00062;
            printf("%.2f Meters is equal to %.2f Miles.\n", input, result);
            break;
        case 3:
            result = input * 1000;
            printf("%.2f Kilometers is equal to %.2f Meters.\n", input, result);
            break;
        case 4:
            result = input * 0.62137;
            printf("%.2f Kilometers is equal to %.2f Miles.\n", input, result);
            break;
        case 5:
            result = input * 1609.34;
            printf("%.2f Miles is equal to %.2f Meters.\n", input, result);
            break;
        case 6:
            result = input * 1.60934;
            printf("%.2f Miles is equal to %.2f Kilometers.\n", input, result);
            break;
        default:
            printf("\nInvalid choice, please try again.\n");
    }
}

// Function to convert mass units
void convertMass() {
    float input, result;
    int choice;

    printf("\n----- Mass Conversion -----\n");
    printf("1. Kilograms to Grams\n");
    printf("2. Kilograms to Pounds\n");
    printf("3. Grams to Kilograms\n");
    printf("4. Grams to Pounds\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Pounds to Grams\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%f", &input);

    // conversion based on the user's choice
    switch(choice) {
        case 1:
            result = input * 1000;
            printf("%.2f Kilograms is equal to %.2f Grams.\n", input, result);
            break;
        case 2:
            result = input * 2.20462;
            printf("%.2f Kilograms is equal to %.2f Pounds.\n", input, result);
            break;
        case 3:
            result = input / 1000;
            printf("%.2f Grams is equal to %.2f Kilograms.\n", input, result);
            break;
        case 4:
            result = input * 0.00220462;
            printf("%.2f Grams is equal to %.2f Pounds.\n", input, result);
            break;
        case 5:
            result = input / 2.20462;
            printf("%.2f Pounds is equal to %.2f Kilograms.\n", input, result);
            break;
        case 6:
            result = input * 453.592;
            printf("%.2f Pounds is equal to %.2f Grams.\n", input, result);
            break;
        default:
            printf("\nInvalid choice, please try again.\n");
    }
}

// Function to convert speed units
void convertSpeed() {
    float input, result;
    int choice;

    printf("\n----- Speed Conversion -----\n");
    printf("1. Meters/second to Kilometers/hour\n");
    printf("2. Meters/second to Miles/hour\n");
    printf("3. Kilometers/hour to Meters/second\n");
    printf("4. Kilometers/hour to Miles/hour\n");
    printf("5. Miles/hour to Meters/second\n");
    printf("6. Miles/hour to Kilometers/hour\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%f", &input);

    // conversion based on the user's choice
    switch(choice) {
        case 1:
            result = input * 3.6;
            printf("%.2f Meters/second is equal to %.2f Kilometers/hour.\n", input, result);
            break;
        case 2:
            result = input * 2.23694;
            printf("%.2f Meters/second is equal to %.2f Miles/hour.\n", input, result);
            break;
        case 3:
            result = input / 3.6;
            printf("%.2f Kilometers/hour is equal to %.2f Meters/second.\n", input, result);
            break;
        case 4:
            result = input * 0.621371;
            printf("%.2f Kilometers/hour is equal to %.2f Miles/hour.\n", input, result);
            break;
        case 5:
            result = input * 0.44704;
            printf("%.2f Miles/hour is equal to %.2f Meters/second.\n", input, result);
            break;
        case 6:
            result = input * 1.60934;
            printf("%.2f Miles/hour is equal to %.2f Kilometers/hour.\n", input, result);
            break;
        default:
            printf("\nInvalid choice, please try again.\n");
    }
}

// Function to convert volume units
void convertVolume() {
    float input, result;
    int choice;

    printf("\n----- Volume Conversion -----\n");
    printf("1. Liters to Milliliters\n");
    printf("2. Liters to Gallons\n");
    printf("3. Milliliters to Liters\n");
    printf("4. Milliliters to Gallons\n");
    printf("5. Gallons to Liters\n");
    printf("6. Gallons to Milliliters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%f", &input);

    // conversion based on the user's choice
    switch(choice) {
        case 1:
            result = input * 1000;
            printf("%.2f Liters is equal to %.2f Milliliters.\n", input, result);
            break;
        case 2:
            result = input * 0.264172;
            printf("%.2f Liters is equal to %.2f Gallons.\n", input, result);
            break;
        case 3:
            result = input / 1000;
            printf("%.2f Milliliters is equal to %.2f Liters.\n", input, result);
            break;
        case 4:
            result = input * 0.000264172;
            printf("%.2f Milliliters is equal to %.2f Gallons.\n", input, result);
            break;
        case 5:
            result = input * 3.78541;
            printf("%.2f Gallons is equal to %.2f Liters.\n", input, result);
            break;
        case 6:
            result = input * 3785.41;
            printf("%.2f Gallons is equal to %.2f Milliliters.\n", input, result);
            break;
        default:
            printf("\nInvalid choice, please try again.\n");
    }
}