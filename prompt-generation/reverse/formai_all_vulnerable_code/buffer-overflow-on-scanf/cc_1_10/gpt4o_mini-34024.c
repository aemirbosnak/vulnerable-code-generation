//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

void lengthConversion() {
    double meters;
    printf("\nEnter length in meters: ");
    scanf("%lf", &meters);
    
    printf("Length in kilometers: %.4f km\n", meters / 1000);
    printf("Length in centimeters: %.4f cm\n", meters * 100);
    printf("Length in feet: %.4f ft\n", meters * 3.28084);
    printf("Length in inches: %.4f in\n", meters * 39.3701);
}

void weightConversion() {
    double kilograms;
    printf("\nEnter weight in kilograms: ");
    scanf("%lf", &kilograms);
    
    printf("Weight in grams: %.4f g\n", kilograms * 1000);
    printf("Weight in pounds: %.4f lbs\n", kilograms * 2.20462);
    printf("Weight in ounces: %.4f oz\n", kilograms * 35.274);
}

void temperatureConversion() {
    double celsius;
    printf("\nEnter temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    printf("Temperature in Fahrenheit: %.4f °F\n", (celsius * 9/5) + 32);
    printf("Temperature in Kelvin: %.4f K\n", celsius + 273.15);
}

void showMenu() {
    printf("\nUnit Converter Menu\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
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
                printf("Exiting the converter. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}