//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

void display_menu() {
    printf("=======================================\n");
    printf("        Welcome to Unit Converter      \n");
    printf("=======================================\n");
    printf("Please choose the type of conversion:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Exit\n");
    printf("=======================================\n");
}

void length_conversion() {
    double meters, feet, inches;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    feet = meters * 3.28084;
    inches = feet * 12;
    printf("%.2f meters is equal to %.2f feet and %.2f inches.\n", meters, feet, inches);
}

void weight_conversion() {
    double kg, lbs;
    printf("Enter weight in kilograms: ");
    scanf("%lf", &kg);
    lbs = kg * 2.20462;
    printf("%.2f kg is equal to %.2f lbs.\n", kg, lbs);
}

void temperature_conversion() {
    double celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You chose Length Conversion!\n");
                length_conversion();
                break;
            case 2:
                printf("You chose Weight Conversion!\n");
                weight_conversion();
                break;
            case 3:
                printf("You chose Temperature Conversion!\n");
                temperature_conversion();
                break;
            case 4:
                printf("Exiting... Thank you for using the Unit Converter!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }

        printf("\n");
    } while (choice != 4);

    return 0;
}