//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: minimalist
#include <stdio.h>

void display_menu() {
    printf("Welcome to the Unit Converter\n");
    printf("1. Length (meters to feet)\n");
    printf("2. Weight (kilograms to pounds)\n");
    printf("3. Temperature (Celsius to Fahrenheit)\n");
    printf("4. Exit\n");
}

void convert_length() {
    double meters;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    double feet = meters * 3.28084;
    printf("%.2f meters is %.2f feet\n", meters, feet);
}

void convert_weight() {
    double kilograms;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    double pounds = kilograms * 2.20462;
    printf("%.2f kilograms is %.2f pounds\n", kilograms, pounds);
}

void convert_temperature() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    double fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
}

int main() {
    int choice;
    while (1) {
        display_menu();
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_weight();
                break;
            case 3:
                convert_temperature();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option, please try again.\n");
        }
        printf("\n");
    }
    return 0;
}