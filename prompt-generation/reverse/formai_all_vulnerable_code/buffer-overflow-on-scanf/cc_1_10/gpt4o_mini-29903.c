//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("Welcome to the Unit Converter!\n");
    printf("Choose the conversion you want to perform:\n");
    printf("1. Length Conversion (meters to feet)\n");
    printf("2. Weight Conversion (kilograms to pounds)\n");
    printf("3. Temperature Conversion (Celsius to Fahrenheit)\n");
    printf("4. Volume Conversion (liters to gallons)\n");
    printf("5. Exit the program\n");
}

double meters_to_feet(double meters) {
    return meters * 3.28084;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

double liters_to_gallons(double liters) {
    return liters * 0.264172;
}

void perform_conversion(int choice) {
    double value, result;

    switch(choice) {
        case 1:
            printf("Enter value in meters: ");
            scanf("%lf", &value);
            result = meters_to_feet(value);
            printf("%.2lf meters is equal to %.2lf feet.\n", value, result);
            break;

        case 2:
            printf("Enter value in kilograms: ");
            scanf("%lf", &value);
            result = kilograms_to_pounds(value);
            printf("%.2lf kilograms is equal to %.2lf pounds.\n", value, result);
            break;

        case 3:
            printf("Enter value in Celsius: ");
            scanf("%lf", &value);
            result = celsius_to_fahrenheit(value);
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", value, result);
            break;

        case 4:
            printf("Enter value in liters: ");
            scanf("%lf", &value);
            result = liters_to_gallons(value);
            printf("%.2lf liters is equal to %.2lf gallons.\n", value, result);
            break;

        case 5:
            printf("Exiting the program. Goodbye!\n");
            exit(0);

        default:
            printf("Invalid choice. Please select a valid option.\n");
            break;
    }
}

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        perform_conversion(choice);
        printf("\n");
    }

    return 0;
}