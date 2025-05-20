//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: surprised
#include <stdio.h>

void displayMenu() {
    printf("Welcome to the Amazing C Unit Converter!\n");
    printf("---------------------------------------\n");
    printf("1. Convert Length (m to km)\n");
    printf("2. Convert Temperature (C to F)\n");
    printf("3. Convert Weight (kg to lbs)\n");
    printf("4. Convert Volume (liters to gallons)\n");
    printf("5. Convert Area (sq meters to sq feet)\n");
    printf("6. Exit\n");
    printf("Please select an option (1-6): ");
}

double convertLength(double meters) {
    return meters / 1000.0; // Convert meters to kilometers
}

double convertTemperature(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0; // Convert Celsius to Fahrenheit
}

double convertWeight(double kilograms) {
    return kilograms * 2.20462; // Convert kilograms to pounds
}

double convertVolume(double liters) {
    return liters * 0.264172; // Convert liters to gallons
}

double convertArea(double squareMeters) {
    return squareMeters * 10.7639; // Convert square meters to square feet
}

int main() {
    int choice;
    double input, result;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1 || choice < 1 || choice > 6) {
            printf("Invalid option. Please choose a number between 1 and 6.\n");
            while(getchar() != '\n'); // Clear the buffer
            continue;
        }

        if (choice == 6) {
            printf("Thank you for using the Amazing C Unit Converter! Goodbye!\n");
            break;
        }

        printf("Enter the value to convert: ");
        if (scanf("%lf", &input) != 1) {
            printf("Invalid input! Please enter a numerical value.\n");
            while(getchar() != '\n'); // Clear the buffer
            continue;
        }
        
        switch (choice) {
            case 1:
                result = convertLength(input);
                printf("%.2lf meters is equal to %.2lf kilometers.\n\n", input, result);
                break;
            case 2:
                result = convertTemperature(input);
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n\n", input, result);
                break;
            case 3:
                result = convertWeight(input);
                printf("%.2lf kilograms is equal to %.2lf pounds.\n\n", input, result);
                break;
            case 4:
                result = convertVolume(input);
                printf("%.2lf liters is equal to %.2lf gallons.\n\n", input, result);
                break;
            case 5:
                result = convertArea(input);
                printf("%.2lf square meters is equal to %.2lf square feet.\n\n", input, result);
                break;
            default:
                printf("Unexpected error!\n\n");
                break;
        }
    }

    return 0;
}