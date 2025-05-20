//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: creative
#include <stdio.h>

void displayMenu() {
    printf("===================================\n");
    printf("        Unit Converter Menu        \n");
    printf("===================================\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
    printf("===================================\n");
    printf("Please choose an option (1-4): ");
}

void lengthConversion() {
    float meters, feet;
    printf("Enter length in meters: ");
    scanf("%f", &meters);
    feet = meters * 3.28084; // Conversion factor
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

void weightConversion() {
    float kilos, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%f", &kilos);
    pounds = kilos * 2.20462; // Conversion factor
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilos, pounds);
}

void temperatureConversion() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32; // Conversion formula
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
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
                return 0;
            default:
                printf("Invalid option! Please choose again.\n");
        }
        printf("\n");
    }
    return 0;
}