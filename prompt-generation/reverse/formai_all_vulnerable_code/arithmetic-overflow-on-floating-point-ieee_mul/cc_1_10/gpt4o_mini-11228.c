//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>

void displayMenu() {
    printf("Unit Converter\n");
    printf("1. Length Converter (meters to feet)\n");
    printf("2. Weight Converter (kilograms to pounds)\n");
    printf("3. Temperature Converter (Celsius to Fahrenheit)\n");
    printf("4. Exit\n");
}

double metersToFeet(double meters) {
    return meters * 3.28084;
}

double kilogramsToPounds(double kg) {
    return kg * 2.20462;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

int main() {
    int choice;
    double input, result;

    while (1) {
        displayMenu();
        printf("Select conversion type: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear input buffer
            continue;
        }

        if (choice == 4) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter length in meters: ");
                if (scanf("%lf", &input) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                result = metersToFeet(input);
                printf("%.2f meters = %.2f feet\n", input, result);
                break;

            case 2:
                printf("Enter weight in kilograms: ");
                if (scanf("%lf", &input) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                result = kilogramsToPounds(input);
                printf("%.2f kilograms = %.2f pounds\n", input, result);
                break;

            case 3:
                printf("Enter temperature in Celsius: ");
                if (scanf("%lf", &input) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while(getchar() != '\n'); // clear input buffer
                    continue;
                }
                result = celsiusToFahrenheit(input);
                printf("%.2f Celsius = %.2f Fahrenheit\n", input, result);
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    return 0;
}