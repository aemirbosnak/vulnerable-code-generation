//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

void convert_temperature();
void convert_length();
void convert_weight();
void convert_volume();

int main() {
    int choice;
    while (1) {
        printf("\n--- Unit Converter ---\n");
        printf("1. Temperature\n");
        printf("2. Length\n");
        printf("3. Weight\n");
        printf("4. Volume\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                convert_temperature();
                break;
            case 2:
                convert_length();
                break;
            case 3:
                convert_weight();
                break;
            case 4:
                convert_volume();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }
    return 0;
}

void convert_temperature() {
    float celsius, fahrenheit, kelvin;
    int temp_choice;

    printf("\n--- Temperature Conversion ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Select conversion (1-6): ");
    scanf("%d", &temp_choice);

    switch (temp_choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("Temperature in Celsius: %.2f\n", celsius);
            break;
        case 3:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            kelvin = celsius + 273.15;
            printf("Temperature in Kelvin: %.2f\n", kelvin);
            break;
        case 4:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &kelvin);
            celsius = kelvin - 273.15;
            printf("Temperature in Celsius: %.2f\n", celsius);
            break;
        case 5:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            kelvin = (fahrenheit - 32) * 5/9 + 273.15;
            printf("Temperature in Kelvin: %.2f\n", kelvin);
            break;
        case 6:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &kelvin);
            fahrenheit = (kelvin - 273.15) * 9/5 + 32;
            printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void convert_length() {
    float meters, feet, inches;
    int length_choice;

    printf("\n--- Length Conversion ---\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("3. Meters to Inches\n");
    printf("4. Inches to Meters\n");
    printf("5. Feet to Inches\n");
    printf("6. Inches to Feet\n");
    printf("Select conversion (1-6): ");
    scanf("%d", &length_choice);

    switch (length_choice) {
        case 1:
            printf("Enter length in meters: ");
            scanf("%f", &meters);
            feet = meters * 3.28084;
            printf("Length in Feet: %.2f\n", feet);
            break;
        case 2:
            printf("Enter length in feet: ");
            scanf("%f", &feet);
            meters = feet / 3.28084;
            printf("Length in Meters: %.2f\n", meters);
            break;
        case 3:
            printf("Enter length in meters: ");
            scanf("%f", &meters);
            inches = meters * 39.3701;
            printf("Length in Inches: %.2f\n", inches);
            break;
        case 4:
            printf("Enter length in inches: ");
            scanf("%f", &inches);
            meters = inches / 39.3701;
            printf("Length in Meters: %.2f\n", meters);
            break;
        case 5:
            printf("Enter length in feet: ");
            scanf("%f", &feet);
            inches = feet * 12;
            printf("Length in Inches: %.2f\n", inches);
            break;
        case 6:
            printf("Enter length in inches: ");
            scanf("%f", &inches);
            feet = inches / 12;
            printf("Length in Feet: %.2f\n", feet);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void convert_weight() {
    float kilograms, pounds, ounces;
    int weight_choice;

    printf("\n--- Weight Conversion ---\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("3. Kilograms to Ounces\n");
    printf("4. Ounces to Kilograms\n");
    printf("5. Pounds to Ounces\n");
    printf("6. Ounces to Pounds\n");
    printf("Select conversion (1-6): ");
    scanf("%d", &weight_choice);

    switch (weight_choice) {
        case 1:
            printf("Enter weight in kilograms: ");
            scanf("%f", &kilograms);
            pounds = kilograms * 2.20462;
            printf("Weight in Pounds: %.2f\n", pounds);
            break;
        case 2:
            printf("Enter weight in pounds: ");
            scanf("%f", &pounds);
            kilograms = pounds / 2.20462;
            printf("Weight in Kilograms: %.2f\n", kilograms);
            break;
        case 3:
            printf("Enter weight in kilograms: ");
            scanf("%f", &kilograms);
            ounces = kilograms * 35.274;
            printf("Weight in Ounces: %.2f\n", ounces);
            break;
        case 4:
            printf("Enter weight in ounces: ");
            scanf("%f", &ounces);
            kilograms = ounces / 35.274;
            printf("Weight in Kilograms: %.2f\n", kilograms);
            break;
        case 5:
            printf("Enter weight in pounds: ");
            scanf("%f", &pounds);
            ounces = pounds * 16;
            printf("Weight in Ounces: %.2f\n", ounces);
            break;
        case 6:
            printf("Enter weight in ounces: ");
            scanf("%f", &ounces);
            pounds = ounces / 16;
            printf("Weight in Pounds: %.2f\n", pounds);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}

void convert_volume() {
    float liters, gallons, milliliters;
    int volume_choice;

    printf("\n--- Volume Conversion ---\n");
    printf("1. Liters to Gallons\n");
    printf("2. Gallons to Liters\n");
    printf("3. Liters to Milliliters\n");
    printf("4. Milliliters to Liters\n");
    printf("5. Gallons to Milliliters\n");
    printf("6. Milliliters to Gallons\n");
    printf("Select conversion (1-6): ");
    scanf("%d", &volume_choice);

    switch (volume_choice) {
        case 1:
            printf("Enter volume in liters: ");
            scanf("%f", &liters);
            gallons = liters * 0.264172;
            printf("Volume in Gallons: %.2f\n", gallons);
            break;
        case 2:
            printf("Enter volume in gallons: ");
            scanf("%f", &gallons);
            liters = gallons / 0.264172;
            printf("Volume in Liters: %.2f\n", liters);
            break;
        case 3:
            printf("Enter volume in liters: ");
            scanf("%f", &liters);
            milliliters = liters * 1000;
            printf("Volume in Milliliters: %.2f\n", milliliters);
            break;
        case 4:
            printf("Enter volume in milliliters: ");
            scanf("%f", &milliliters);
            liters = milliliters / 1000;
            printf("Volume in Liters: %.2f\n", liters);
            break;
        case 5:
            printf("Enter volume in gallons: ");
            scanf("%f", &gallons);
            milliliters = gallons / 0.000264172;
            printf("Volume in Milliliters: %.2f\n", milliliters);
            break;
        case 6:
            printf("Enter volume in milliliters: ");
            scanf("%f", &milliliters);
            gallons = milliliters * 0.000264172;
            printf("Volume in Gallons: %.2f\n", gallons);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
}