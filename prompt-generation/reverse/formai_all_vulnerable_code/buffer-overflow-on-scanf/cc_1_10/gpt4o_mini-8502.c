//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

// Function prototypes
void display_options();
void convert_length();
void convert_weight();
void convert_temperature();
void convert_volume();
void welcome_message();

int main() {
    welcome_message();
    int choice;

    while (1) {
        display_options();
        printf("Enter your choice (0 to exit): ");
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
                convert_volume();
                break;
            case 0:
                printf("Exiting the program. Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 0 and 4.\n");
                break;
        }
    }
}

void welcome_message() {
    printf("=================================================\n");
    printf("         Welcome to the Amazing Unit Converter!  \n");
    printf("=================================================\n");
    printf("You can convert lengths, weights, temperatures, and volumes easily.\n");
    printf("Let's make conversions fun and simple!\n");
}

void display_options() {
    printf("\nChoose a conversion type:\n");
    printf("1. Length (Meters, Kilometers, Miles)\n");
    printf("2. Weight (Grams, Kilograms, Pounds)\n");
    printf("3. Temperature (Celsius, Fahrenheit, Kelvin)\n");
    printf("4. Volume (Liters, Milliliters, Gallons)\n");
    printf("0. Exit\n");
}

void convert_length() {
    printf("\n=== Length Converter ===\n");
    double meters, kilometers, miles;

    printf("Enter length in meters: ");
    scanf("%lf", &meters);

    kilometers = meters / 1000.0;
    miles = meters / 1609.34;

    printf("Length in kilometers: %.4lf km\n", kilometers);
    printf("Length in miles: %.4lf mi\n", miles);
}

void convert_weight() {
    printf("\n=== Weight Converter ===\n");
    double grams, kilograms, pounds;

    printf("Enter weight in grams: ");
    scanf("%lf", &grams);

    kilograms = grams / 1000.0;
    pounds = grams / 453.592;

    printf("Weight in kilograms: %.4lf kg\n", kilograms);
    printf("Weight in pounds: %.4lf lb\n", pounds);
}

void convert_temperature() {
    printf("\n=== Temperature Converter ===\n");
    double celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    kelvin = celsius + 273.15;

    printf("Temperature in Fahrenheit: %.4lf °F\n", fahrenheit);
    printf("Temperature in Kelvin: %.4lf K\n", kelvin);
}

void convert_volume() {
    printf("\n=== Volume Converter ===\n");
    double liters, milliliters, gallons;

    printf("Enter volume in liters: ");
    scanf("%lf", &liters);

    milliliters = liters * 1000.0;
    gallons = liters / 3.78541;

    printf("Volume in milliliters: %.4lf mL\n", milliliters);
    printf("Volume in gallons: %.4lf gal\n", gallons);
}