//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void print_menu() {
    printf("\n*** Welcome to the Stellar Unit Converter ***\n");
    printf("1. Convert Length (meters to kilometers)\n");
    printf("2. Convert Weight (grams to kilograms)\n");
    printf("3. Convert Temperature (Celsius to Fahrenheit)\n");
    printf("4. Convert Time (seconds to hours)\n");
    printf("5. Convert Volume (liters to gallons)\n");
    printf("6. Exit\n");
    printf("Select an option (1-6): ");
}

double meters_to_kilometers(double meters) {
    return meters / 1000.0;
}

double grams_to_kilograms(double grams) {
    return grams / 1000.0;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double seconds_to_hours(double seconds) {
    return seconds / 3600.0;
}

double liters_to_gallons(double liters) {
    return liters / 3.78541; // 1 gallon = 3.78541 liters
}

int main() {
    int choice;
    char buffer[BUFFER_SIZE];
    double input, output;

    while (1) {
        print_menu();
        
        // Get user input safely
        if (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
            choice = atoi(buffer);
        } else {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter length in meters: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                input = atof(buffer);
                output = meters_to_kilometers(input);
                printf("%.2f meters is equal to %.2f kilometers.\n", input, output);
                break;

            case 2:
                printf("Enter weight in grams: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                input = atof(buffer);
                output = grams_to_kilograms(input);
                printf("%.2f grams is equal to %.2f kilograms.\n", input, output);
                break;

            case 3:
                printf("Enter temperature in Celsius: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                input = atof(buffer);
                output = celsius_to_fahrenheit(input);
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", input, output);
                break;

            case 4:
                printf("Enter time in seconds: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                input = atof(buffer);
                output = seconds_to_hours(input);
                printf("%.2f seconds is equal to %.2f hours.\n", input, output);
                break;

            case 5:
                printf("Enter volume in liters: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                input = atof(buffer);
                output = liters_to_gallons(input);
                printf("%.2f liters is equal to %.2f gallons.\n", input, output);
                break;

            case 6:
                printf("Thank you for using the Stellar Unit Converter! Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
                break;
        }

        printf("Would you like to convert something else? (y/n): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        if (strncmp(buffer, "n", 1) == 0 || strncmp(buffer, "N", 1) == 0) {
            printf("Thank you for using the Stellar Unit Converter! Goodbye!\n");
            break;
        }
    }

    return 0;
}