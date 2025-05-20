//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>

// Function prototypes
void display_menu();
void convert_length();
void convert_weight();
void convert_temperature();
void convert_area();
void convert_volume();

int main() {
    int choice;
    printf("Welcome to the Ultimate Unit Converter!\n");
    printf("Let's convert some units!\n");

    while (1) {
        display_menu();
        printf("Please enter your choice (1-5), or 0 to exit: ");
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
                convert_area();
                break;
            case 5:
                convert_volume();
                break;
            case 0:
                printf("Thank you for using the Ultimate Unit Converter! Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to display the menu
void display_menu() {
    printf("\n***** Unit Conversion Menu *****\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Area\n");
    printf("5. Volume\n");
    printf("0. Exit\n");
}

// Function to convert length
void convert_length() {
    double meters, feet;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084; // 1 meter = 3.28084 feet
    printf("%.2f meters is equal to %.2f feet.\n", meters, feet);
}

// Function to convert weight
void convert_weight() {
    double kilograms, pounds;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kilograms);
    pounds = kilograms * 2.20462; // 1 kilogram = 2.20462 pounds
    printf("%.2f kilograms is equal to %.2f pounds.\n", kilograms, pounds);
}

// Function to convert temperature
void convert_temperature() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = celsius * 9.0/5.0 + 32.0; // Celsius to Fahrenheit
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert area
void convert_area() {
    double squareMeters, squareFeet;
    printf("Enter area in square meters: ");
    scanf("%lf", &squareMeters);
    squareFeet = squareMeters * 10.7639; // 1 square meter = 10.7639 square feet
    printf("%.2f square meters is equal to %.2f square feet.\n", squareMeters, squareFeet);
}

// Function to convert volume
void convert_volume() {
    double liters, gallons;
    printf("Enter volume in liters: ");
    scanf("%lf", &liters);
    gallons = liters * 0.264172; // 1 liter = 0.264172 gallons
    printf("%.2f liters is equal to %.2f gallons.\n", liters, gallons);
}

// Note: Always ensure to review the conversions for precision and context!