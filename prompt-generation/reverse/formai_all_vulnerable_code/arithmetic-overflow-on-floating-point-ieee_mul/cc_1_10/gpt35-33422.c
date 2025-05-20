//FormAI DATASET v1.0 Category: Unit converter ; Style: expert-level
#include <stdio.h>

// Function prototypes
void printMenu(); 
float convertLength(float, int, int); 
float convertArea(float, int, int); 
float convertTemperature(float, int, int); 

// Main function
int main() {
    int choice;
    float value;
    int fromUnit, toUnit;
    char ans = 'Y';
    while (ans == 'Y' || ans == 'y') {
        printMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("Enter the value to be converted: ");
        scanf("%f", &value);
        printf("Enter the unit of from which you want to convert: ");
        scanf("%d", &fromUnit);
        printf("Enter the unit of to which you want to convert: ");
        scanf("%d", &toUnit);
        switch (choice) {
            case 1:
                printf("\n====== Length Conversion ======\n");
                printf("%.2f %d = %.2f %d\n", value, fromUnit, convertLength(value, fromUnit, toUnit), toUnit);
                break;
            case 2:
                printf("\n====== Area Conversion ======\n");
                printf("%.2f %d = %.2f %d\n", value, fromUnit, convertArea(value, fromUnit, toUnit), toUnit);
                break;
            case 3:
                printf("\n====== Temperature Conversion ======\n");
                printf("%.2f %d = %.2f %d\n", value, fromUnit, convertTemperature(value, fromUnit, toUnit), toUnit);
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");               
        }
        printf("\nDo you want to convert again? [Y|N]: ");
        scanf(" %c", &ans);
    }
    return 0;
}

// Utility function to display the menu
void printMenu() {
    printf("\n====== Unit Converter ======\n");
    printf("1. Length\n");
    printf("2. Area\n");
    printf("3. Temperature\n");
    printf("===========================\n");    
}

// Utility function to convert length
float convertLength(float value, int fromUnit, int toUnit) {
    if (fromUnit == 1 && toUnit == 2) {
        // convert feet to meters
        return value * 0.3048;
    } else if (fromUnit == 2 && toUnit == 1) {
        // convert meters to feet
        return value / 0.3048;
    } else if (fromUnit == 1 && toUnit == 3) {
        // convert feet to miles
        return value / 5280;
    } else if (fromUnit == 3 && toUnit == 1) {
        // convert miles to feet
        return value * 5280;
    } else if (fromUnit == 2 && toUnit == 3) {
        // convert meters to miles
        return value / 1609.34;
    } else if (fromUnit == 3 && toUnit == 2) {
        // convert miles to meters
        return value * 1609.34;
    } else {
        // conversion not supported
        return 0.0;
    }
}

// Utility function to convert area
float convertArea(float value, int fromUnit, int toUnit) {
    if (fromUnit == 1 && toUnit == 2) {
        // convert square feet to square meters
        return value * 0.092903;
    } else if (fromUnit == 2 && toUnit == 1) {
        // convert square meters to square feet
        return value / 0.092903;
    } else if (fromUnit == 1 && toUnit == 3) {
        // convert square feet to acres
        return value / 43560;
    } else if (fromUnit == 3 && toUnit == 1) {
        // convert acres to square feet
        return value * 43560;
    } else if (fromUnit == 2 && toUnit == 3) {
        // convert square meters to acres
        return value / 4046.86;
    } else if (fromUnit == 3 && toUnit == 2) {
        // convert acres to square meters
        return value * 4046.86;
    } else {
        // conversion not supported
        return 0.0;
    }
}

// Utility function to convert temperature
float convertTemperature(float value, int fromUnit, int toUnit) {
    if (fromUnit == 1 && toUnit == 2) {
        // convert Celsius to Fahrenheit
        return (value * 9 / 5) + 32;
    } else if (fromUnit == 2 && toUnit == 1) {
        // convert Fahrenheit to Celsius
        return (value - 32) * 5 / 9;
    } else {
        // conversion not supported
        return 0.0;
    }
}