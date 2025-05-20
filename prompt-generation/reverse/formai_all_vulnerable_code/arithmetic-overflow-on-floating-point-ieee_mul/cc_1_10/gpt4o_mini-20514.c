//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>

void displayMenu() {
    printf("Welcome to the Unit Conversion Program!\n");
    printf("Please select the conversion you wish to perform:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Area\n");
    printf("5. Volume\n");
    printf("6. Exit\n");
}

void lengthConversion() {
    float value;
    int choice;
    printf("\nLength Conversion:\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("Select conversion type: ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            printf("%.2f Meters is %.2f Feet\n", value, value * 3.28084);
            break;
        case 2:
            printf("%.2f Feet is %.2f Meters\n", value, value / 3.28084);
            break;
        case 3:
            printf("%.2f Miles is %.2f Kilometers\n", value, value * 1.60934);
            break;
        case 4:
            printf("%.2f Kilometers is %.2f Miles\n", value, value / 1.60934);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void weightConversion() {
    float value;
    int choice;
    printf("\nWeight Conversion:\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Grams to Ounces\n");
    printf("4. Ounces to Grams\n");
    printf("Select conversion type: ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            printf("%.2f Kilograms is %.2f Pounds\n", value, value * 2.20462);
            break;
        case 2:
            printf("%.2f Pounds is %.2f Kilograms\n", value, value / 2.20462);
            break;
        case 3:
            printf("%.2f Grams is %.2f Ounces\n", value, value * 0.035274);
            break;
        case 4:
            printf("%.2f Ounces is %.2f Grams\n", value, value / 0.035274);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void temperatureConversion() {
    float value;
    int choice;
    printf("\nTemperature Conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kelvin to Celsius\n");
    printf("4. Celsius to Kelvin\n");
    printf("Select conversion type: ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            printf("%.2f Celsius is %.2f Fahrenheit\n", value, (value * 9/5) + 32);
            break;
        case 2:
            printf("%.2f Fahrenheit is %.2f Celsius\n", value, (value - 32) * 5/9);
            break;
        case 3:
            printf("%.2f Kelvin is %.2f Celsius\n", value, value - 273.15);
            break;
        case 4:
            printf("%.2f Celsius is %.2f Kelvin\n", value, value + 273.15);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void areaConversion() {
    float value;
    int choice;
    printf("\nArea Conversion:\n");
    printf("1. Square Meters to Acres\n");
    printf("2. Acres to Square Meters\n");
    printf("3. Square Feet to Square Meters\n");
    printf("4. Square Meters to Square Feet\n");
    printf("Select conversion type: ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            printf("%.2f Square Meters is %.2f Acres\n", value, value * 0.000247105);
            break;
        case 2:
            printf("%.2f Acres is %.2f Square Meters\n", value, value / 0.000247105);
            break;
        case 3:
            printf("%.2f Square Feet is %.2f Square Meters\n", value, value * 0.092903);
            break;
        case 4:
            printf("%.2f Square Meters is %.2f Square Feet\n", value, value / 0.092903);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

void volumeConversion() {
    float value;
    int choice;
    printf("\nVolume Conversion:\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("3. Cubic Meters to Liters\n");
    printf("4. Liters to Cubic Meters\n");
    printf("Select conversion type: ");
    scanf("%d", &choice);
    
    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice) {
        case 1:
            printf("%.2f Liters is %.2f Gallons\n", value, value * 0.264172);
            break;
        case 2:
            printf("%.2f Gallons is %.2f Liters\n", value, value / 0.264172);
            break;
        case 3:
            printf("%.2f Cubic Meters is %.2f Liters\n", value, value * 1000);
            break;
        case 4:
            printf("%.2f Liters is %.2f Cubic Meters\n", value, value / 1000);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    int option;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
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
                areaConversion();
                break;
            case 5:
                volumeConversion();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (option != 6);

    return 0;
}