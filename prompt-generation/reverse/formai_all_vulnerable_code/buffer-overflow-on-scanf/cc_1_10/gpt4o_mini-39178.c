//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>

void displayMenu() {
    printf("\n--- Mind-Bending Unit Converter ---\n");
    printf("1. Convert Length (Meters to Kilometers)\n");
    printf("2. Convert Weight (Kilograms to Pounds)\n");
    printf("3. Convert Temperature (Celsius to Fahrenheit)\n");
    printf("4. Convert Volume (Liters to Gallons)\n");
    printf("5. Convert Speed (Kilometers/h to Miles/h)\n");
    printf("6. Exit\n");
    printf("Select an option (1-6): ");
}

float metersToKilometers(float meters) {
    return meters / 1000.0f;
}

float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462f;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0f / 5.0f) + 32.0f;
}

float litersToGallons(float liters) {
    return liters * 0.264172f;
}

float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371f;
}

int main() {
    int choice;
    float inputValue;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter length in meters: ");
                scanf("%f", &inputValue);
                printf("%.2f meters is %.6f kilometers.\n", inputValue, metersToKilometers(inputValue));
                break;
            
            case 2:
                printf("Enter weight in kilograms: ");
                scanf("%f", &inputValue);
                printf("%.2f kilograms is %.2f pounds.\n", inputValue, kilogramsToPounds(inputValue));
                break;
                
            case 3:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &inputValue);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", inputValue, celsiusToFahrenheit(inputValue));
                break;

            case 4:
                printf("Enter volume in liters: ");
                scanf("%f", &inputValue);
                printf("%.2f liters is %.6f gallons.\n", inputValue, litersToGallons(inputValue));
                break;

            case 5:
                printf("Enter speed in kilometers/h: ");
                scanf("%f", &inputValue);
                printf("%.2f kilometers/h is %.6f miles/h.\n", inputValue, kilometersToMiles(inputValue));
                break;

            case 6:
                printf("Exiting the Mind-Bending Unit Converter. Farewell!\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}