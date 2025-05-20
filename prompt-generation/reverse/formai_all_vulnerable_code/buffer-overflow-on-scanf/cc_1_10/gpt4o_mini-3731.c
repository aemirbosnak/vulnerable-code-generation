//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: energetic
#include <stdio.h>

void displayMenu() {
    printf("\n==============================\n");
    printf("      UNIT CONVERTER\n");
    printf("==============================\n");
    printf("1. Convert Miles to Kilometers\n");
    printf("2. Convert Kilograms to Pounds\n");
    printf("3. Convert Celsius to Fahrenheit\n");
    printf("4. Convert Liters to Gallons\n");
    printf("5. Convert Meters to Feet\n");
    printf("6. Exit\n");
    printf("==============================\n");
    printf("Choose an option (1-6): ");
}

double milesToKilometers(double miles) {
    return miles * 1.60934;
}

double kilogramsToPounds(double kilograms) {
    return kilograms * 2.20462;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double litersToGallons(double liters) {
    return liters * 0.264172;
}

double metersToFeet(double meters) {
    return meters * 3.28084;
}

int main() {
    int choice;
    double inputValue, result;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting the program. Thank you for using the Unit Converter!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter miles: ");
                scanf("%lf", &inputValue);
                result = milesToKilometers(inputValue);
                printf("%.2f miles is equal to %.2f kilometers.\n", inputValue, result);
                break;

            case 2:
                printf("Enter kilograms: ");
                scanf("%lf", &inputValue);
                result = kilogramsToPounds(inputValue);
                printf("%.2f kilograms is equal to %.2f pounds.\n", inputValue, result);
                break;

            case 3:
                printf("Enter Celsius: ");
                scanf("%lf", &inputValue);
                result = celsiusToFahrenheit(inputValue);
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", inputValue, result);
                break;

            case 4:
                printf("Enter liters: ");
                scanf("%lf", &inputValue);
                result = litersToGallons(inputValue);
                printf("%.2f liters is equal to %.2f gallons.\n", inputValue, result);
                break;

            case 5:
                printf("Enter meters: ");
                scanf("%lf", &inputValue);
                result = metersToFeet(inputValue);
                printf("%.2f meters is equal to %.2f feet.\n", inputValue, result);
                break;

            default:
                printf("Invalid choice! Please select a valid option (1-6).\n");
                break;
        }
    }

    return 0;
}