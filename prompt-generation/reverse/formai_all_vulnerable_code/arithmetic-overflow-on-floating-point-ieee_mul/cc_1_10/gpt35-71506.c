//FormAI DATASET v1.0 Category: Unit converter ; Style: distributed
#include <stdio.h>

// Function prototypes
void printMainMenu();
void printLengthMenu();
void printMassMenu();
void printTemperatureMenu();
void convertLength();
void convertMass();
void convertTemperature();
float convertToCM(float val, int unitIndex);
float convertToGram(float val, int unitIndex);
float convertToFahrenheit(float val);
float convertToCelsius(float val);

int main() {
    int menuChoice;

    // Loop indefinitely until user decides to quit
    while (1) {
        printMainMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertMass();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                printf("\nThank you for using the unit converter. Have a nice day!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Print main menu
void printMainMenu() {
    printf("\n-------------UNIT CONVERTER-------------");
    printf("\n1. Length");
    printf("\n2. Mass");
    printf("\n3. Temperature");
    printf("\n4. Quit");
}

// Print length conversion menu
void printLengthMenu() {
    printf("\n----------LENGTH CONVERSION----------");
    printf("\n1. Millimeters");
    printf("\n2. Centimeters");
    printf("\n3. Meters");
    printf("\n4. Kilometers");
}

// Print mass conversion menu
void printMassMenu() {
    printf("\n----------MASS CONVERSION----------");
    printf("\n1. Milligrams");
    printf("\n2. Grams");
    printf("\n3. Kilograms");
}

// Print temperature conversion menu
void printTemperatureMenu() {
    printf("\n----------TEMPERATURE CONVERSION----------");
    printf("\n1. Fahrenheit");
    printf("\n2. Celsius");
}

// Convert length
void convertLength() {
    float val;
    int unitIndex, choice;

    printLengthMenu();
    printf("\nEnter value to be converted: ");
    scanf("%f", &val);

    printf("\nConvert from: ");
    scanf("%d", &unitIndex);

    printf("\nConvert to: ");
    scanf("%d", &choice);

    float cmVal = convertToCM(val, unitIndex);
    float finalVal = cmVal;

    switch (choice) {
        case 1:
            finalVal = cmVal * 0.1;
            printf("\n%.2f mm", finalVal);
            break;
        case 2:
            printf("\n%.2f cm", finalVal);
            break;
        case 3:
            finalVal = cmVal * 0.01;
            printf("\n%.2f m", finalVal);
            break;
        case 4:
            finalVal = cmVal * 0.00001;
            printf("\n%.2f km", finalVal);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}

// Convert mass
void convertMass() {
    float val;
    int unitIndex, choice;

    printMassMenu();
    printf("\nEnter value to be converted: ");
    scanf("%f", &val);

    printf("\nConvert from: ");
    scanf("%d", &unitIndex);

    printf("\nConvert to: ");
    scanf("%d", &choice);

    float gramVal = convertToGram(val, unitIndex);
    float finalVal = gramVal;

    switch (choice) {
        case 1:
            finalVal = gramVal * 1000;
            printf("\n%.2f mg", finalVal);
            break;
        case 2:
            printf("\n%.2f g", finalVal);
            break;
        case 3:
            finalVal = gramVal * 0.001;
            printf("\n%.2f kg", finalVal);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}

// Convert temperature
void convertTemperature() {
    float val;
    int choice;

    printTemperatureMenu();
    printf("\nEnter value to be converted: ");
    scanf("%f", &val);

    printf("\nConvert to: ");
    scanf("%d", &choice);

    float finalVal = val;

    switch (choice) {
        case 1:
            finalVal = convertToFahrenheit(val);
            printf("\n%.2f F", finalVal);
            break;
        case 2:
            finalVal = convertToCelsius(val);
            printf("\n%.2f C", finalVal);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }
}

// Convert length to centimeters
float convertToCM(float val, int unitIndex) {
    switch (unitIndex) {
        case 1:
            return val * 0.1;
        case 2:
            return val;
        case 3:
            return val * 100;
        case 4:
            return val * 100000;
        default:
            printf("\nInvalid unit index. Defaulting to centimeters.\n");
            return val;
    }
}

// Convert mass to grams
float convertToGram(float val, int unitIndex) {
    switch (unitIndex) {
        case 1:
            return val * 0.001;
        case 2:
            return val;
        case 3:
            return val * 1000;
        default:
            printf("\nInvalid unit index. Defaulting to grams.\n");
            return val;
    }
}

// Convert Fahrenheit to Celsius
float convertToCelsius(float val) {
    return (val - 32) * (5.0 / 9.0);
}

// Convert Celsius to Fahrenheit
float convertToFahrenheit(float val) {
    return (val * (9.0 / 5.0)) + 32;
}