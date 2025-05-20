//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: irregular
#include <stdio.h>

void showMenu() {
    printf("\n=========== Unit Converter ===========\n");
    printf("1. Convert Length (Meters to Feet)\n");
    printf("2. Convert Weight (Kilograms to Pounds)\n");
    printf("3. Convert Temperature (Celsius to Fahrenheit)\n");
    printf("4. Convert Area (Square Meters to Acres)\n");
    printf("5. Convert Volume (Liters to Gallons)\n");
    printf("6. Exit\n");
    printf("======================================\n");
    printf("Select an option (1-6): ");
}

float metersToFeet(float meters) {
    return meters * 3.28084;
}

float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float squareMetersToAcres(float squareMeters) {
    return squareMeters * 0.000247105;
}

float litersToGallons(float liters) {
    return liters * 0.264172;
}

void converterLoop() {
    int choice;
    float input, output;
    
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        if (choice == 6) {
            printf("Exiting the converter. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter length in meters: ");
                scanf("%f", &input);
                output = metersToFeet(input);
                printf("%.2f meters is equal to %.2f feet\n", input, output);
                break;
            case 2:
                printf("Enter weight in kilograms: ");
                scanf("%f", &input);
                output = kilogramsToPounds(input);
                printf("%.2f kilograms is equal to %.2f pounds\n", input, output);
                break;
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                output = celsiusToFahrenheit(input);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", input, output);
                break;
            case 4:
                printf("Enter area in square meters: ");
                scanf("%f", &input);
                output = squareMetersToAcres(input);
                printf("%.2f square meters is equal to %.2f acres\n", input, output);
                break;
            case 5:
                printf("Enter volume in liters: ");
                scanf("%f", &input);
                output = litersToGallons(input);
                printf("%.2f liters is equal to %.2f gallons\n", input, output);
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
}

int main() {
    printf("Welcome to the Cool Unit Converter!\n");
    printf("Join the fun of converting units.\n");
    converterLoop();
    
    return 0;
}