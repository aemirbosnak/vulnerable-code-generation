//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

void display_menu() {
    printf("Welcome to the Unit Converter!\n");
    printf("Choose a conversion type:\n");
    printf("1. Length (meters to feet)\n");
    printf("2. Weight (kilograms to pounds)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    printf("4. Area (square meters to acres)\n");
    printf("5. Volume (liters to gallons)\n");
    printf("6. Exit\n");
}

double meters_to_feet(double meters) {
    return meters * 3.28084;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32;
}

double square_meters_to_acres(double sqm) {
    return sqm * 0.000247105;
}

double liters_to_gallons(double liters) {
    return liters * 0.264172;
}

int main() {
    int choice;
    double input;

    while (1) {
        display_menu();
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("Exiting the program. Thank you for using the Unit Converter!\n");
            break;
        }

        printf("Enter the value to convert: ");
        scanf("%lf", &input);

        switch (choice) {
            case 1:
                printf("%.2lf meters is equal to %.2lf feet.\n", input, meters_to_feet(input));
                break;
            case 2:
                printf("%.2lf kilograms is equal to %.2lf pounds.\n", input, kilograms_to_pounds(input));
                break;
            case 3:
                printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", input, celsius_to_fahrenheit(input));
                break;
            case 4:
                printf("%.2lf square meters is equal to %.2lf acres.\n", input, square_meters_to_acres(input));
                break;
            case 5:
                printf("%.2lf liters is equal to %.2lf gallons.\n", input, liters_to_gallons(input));
                break;
            default:
                printf("Invalid choice. Please select from the menu.\n");
                break;
        }
        
        printf("\n");
    }
    return 0;
}