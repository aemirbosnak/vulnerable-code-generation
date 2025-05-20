//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>

void display_menu() {
    printf("Welcome to the Unit Converter!\n");
    printf("Please choose a conversion option:\n");
    printf("1. Length (meters to kilometers and vice versa)\n");
    printf("2. Temperature (Celsius to Fahrenheit and vice versa)\n");
    printf("3. Weight (grams to kilograms and vice versa)\n");
    printf("4. Volume (liters to gallons and vice versa)\n");
    printf("5. Exit\n");
}

float meters_to_kilometers(float meters) {
    return meters / 1000.0;
}

float kilometers_to_meters(float kilometers) {
    return kilometers * 1000.0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float grams_to_kilograms(float grams) {
    return grams / 1000.0;
}

float kilograms_to_grams(float kilograms) {
    return kilograms * 1000.0;
}

float liters_to_gallons(float liters) {
    return liters / 3.78541;
}

float gallons_to_liters(float gallons) {
    return gallons * 3.78541;
}

int main() {
    int choice;
    float input, output;

    do {
        display_menu();
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Length Conversion:\n");
                printf("Enter value in meters: ");
                scanf("%f", &input);
                output = meters_to_kilometers(input);
                printf("%.2f meters is %.2f kilometers\n", input, output);
                printf("Enter value in kilometers: ");
                scanf("%f", &input);
                output = kilometers_to_meters(input);
                printf("%.2f kilometers is %.2f meters\n", input, output);
                break;

            case 2:
                printf("Temperature Conversion:\n");
                printf("Enter value in Celsius: ");
                scanf("%f", &input);
                output = celsius_to_fahrenheit(input);
                printf("%.2f Celsius is %.2f Fahrenheit\n", input, output);
                printf("Enter value in Fahrenheit: ");
                scanf("%f", &input);
                output = fahrenheit_to_celsius(input);
                printf("%.2f Fahrenheit is %.2f Celsius\n", input, output);
                break;

            case 3:
                printf("Weight Conversion:\n");
                printf("Enter value in grams: ");
                scanf("%f", &input);
                output = grams_to_kilograms(input);
                printf("%.2f grams is %.2f kilograms\n", input, output);
                printf("Enter value in kilograms: ");
                scanf("%f", &input);
                output = kilograms_to_grams(input);
                printf("%.2f kilograms is %.2f grams\n", input, output);
                break;

            case 4:
                printf("Volume Conversion:\n");
                printf("Enter value in liters: ");
                scanf("%f", &input);
                output = liters_to_gallons(input);
                printf("%.2f liters is %.2f gallons\n", input, output);
                printf("Enter value in gallons: ");
                scanf("%f", &input);
                output = gallons_to_liters(input);
                printf("%.2f gallons is %.2f liters\n", input, output);
                break;

            case 5:
                printf("Exiting the program. Thank you!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    } while (choice != 5);

    return 0;
}