//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void display_welcome_message() {
    printf("=====================================================\n");
    printf("Welcome to Neo-Tokyo Unit Converter v0.8 Revamp\n");
    printf("Embrace the future, convert the past.\n");
    printf("=====================================================\n");
}

void display_menu() {
    printf("Select the conversion you want to perform:\n");
    printf("1. Length (Meters to Feet)\n");
    printf("2. Temperature (Celsius to Fahrenheit)\n");
    printf("3. Weight (Kilograms to Pounds)\n");
    printf("4. Data (Megabytes to Gigabytes)\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");
}

double meters_to_feet(double meters) {
    return meters * 3.28084;
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

double kilograms_to_pounds(double kilograms) {
    return kilograms * 2.20462;
}

double megabytes_to_gigabytes(double megabytes) {
    return megabytes / 1024.0;
}

void handle_choice(int choice) {
    double input_value, output_value;
    switch (choice) {
        case 1:
            printf("Enter the length in meters: ");
            scanf("%lf", &input_value);
            output_value = meters_to_feet(input_value);
            printf("%.2lf meters = %.2lf feet\n", input_value, output_value);
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &input_value);
            output_value = celsius_to_fahrenheit(input_value);
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", input_value, output_value);
            break;
        case 3:
            printf("Enter the weight in kilograms: ");
            scanf("%lf", &input_value);
            output_value = kilograms_to_pounds(input_value);
            printf("%.2lf kilograms = %.2lf pounds\n", input_value, output_value);
            break;
        case 4:
            printf("Enter the data size in megabytes: ");
            scanf("%lf", &input_value);
            output_value = megabytes_to_gigabytes(input_value);
            printf("%.2lf megabytes = %.2lf gigabytes\n", input_value, output_value);
            break;
        case 5:
            printf("Thanks for using Neo-Tokyo Unit Converter. Stay safe in the shadows!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
}

int main() {
    char buffer[MAX_LENGTH];
    int choice;

    display_welcome_message();

    while (1) {
        display_menu();
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &choice);
        handle_choice(choice);
        printf("\n");
    }

    return 0;
}