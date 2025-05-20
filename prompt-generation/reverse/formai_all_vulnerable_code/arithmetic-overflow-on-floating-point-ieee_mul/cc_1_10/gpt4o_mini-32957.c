//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void show_menu();
void convert_length();
void convert_temperature();
void convert_weight();
void convert_area();
void clear_input_buffer();

int main() {
    int choice;

    while (1) {
        show_menu();
        printf("Select an option (0 to exit): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                convert_length();
                break;
            case 2:
                convert_temperature();
                break;
            case 3:
                convert_weight();
                break;
            case 4:
                convert_area();
                break;
            case 0:
                printf("Exiting the converter. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void show_menu() {
    printf("\n--- Unit Converter ---\n");
    printf("1. Length\n");
    printf("2. Temperature\n");
    printf("3. Weight\n");
    printf("4. Area\n");
    printf("0. Exit\n");
}

void convert_length() {
    double meters, feet;

    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

void convert_temperature() {
    double celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

void convert_weight() {
    double kilograms, pounds;

    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462;
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
}

void convert_area() {
    double square_meters, acres;

    printf("Enter area in square meters: ");
    scanf("%lf", &square_meters);
    acres = square_meters * 0.000247105;
    printf("%.2f square meters is equal to %.5f acres.\n", square_meters, acres);
}

void clear_input_buffer() {
    // Clear the input buffer to handle extra input
    while (getchar() != '\n');
}