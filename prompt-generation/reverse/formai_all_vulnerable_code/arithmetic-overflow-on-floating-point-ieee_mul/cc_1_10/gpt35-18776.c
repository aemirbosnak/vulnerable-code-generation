//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
/* This is a unique C Unit Converter program that uses a combination of ephemeral and practical code styles. It is designed to convert various units of measurement from one system to another. Enjoy! */

#include <stdio.h>
#include <stdlib.h>

void main_menu();
void length_menu();
void weight_menu();
void temperature_menu();

int main() {
    system("clear"); // clear screen
    printf("\t\t\tWELCOME TO THE UNIT CONVERTER PROGRAM\n\n");
    printf("This program can convert several units of measure between various systems.\n");
    main_menu(); // call main menu function
    return 0;
}

void main_menu() {
    int choice;
    printf("\nSelect the type of unit to convert:\n\n");
    printf("\t1. Length\n");
    printf("\t2. Weight\n");
    printf("\t3. Temperature\n");
    printf("\t4. Exit\n\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            length_menu(); // call length menu function
            break;
        case 2:
            weight_menu(); // call weight menu function
            break;
        case 3:
            temperature_menu(); // call temperature menu function
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            main_menu(); // go back to main menu
    }
}

void length_menu() {
    int choice;
    float inches, centimeters, result;
    printf("\nSelect the unit to convert:\n\n");
    printf("\t1. Inches to Centimeters\n");
    printf("\t2. Centimeters to Inches\n");
    printf("\t3. Feet to Meters\n");
    printf("\t4. Meters to Feet\n");
    printf("\t5. Yards to Meters\n");
    printf("\t6. Meters to Yards\n");
    printf("\t7. Miles to Kilometers\n");
    printf("\t8. Kilometers to Miles\n");
    printf("\t9. Back to Main Menu\n\n");
    printf("Enter your choice (1-9): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the length in inches: ");
            scanf("%f", &inches);
            result = inches * 2.54;
            printf("%.2f inches equals %.2f centimeters.\n", inches, result);
            length_menu(); // go back to length menu
            break;
        case 2:
            printf("Enter the length in centimeters: ");
            scanf("%f", &centimeters);
            result = centimeters / 2.54;
            printf("%.2f centimeters equals %.2f inches.\n", centimeters, result);
            length_menu(); // go back to length menu
            break;
        case 3:
            printf("Enter the length in feet: ");
            scanf("%f", &inches);
            result = inches / 3.281;
            printf("%.2f feet equals %.2f meters.\n", inches, result);
            length_menu(); // go back to length menu
            break;
        case 4:
            printf("Enter the length in meters: ");
            scanf("%f", &centimeters);
            result = centimeters * 3.281;
            printf("%.2f meters equals %.2f feet.\n", centimeters, result);
            length_menu(); // go back to length menu
            break;
        case 5:
            printf("Enter the length in yards: ");
            scanf("%f", &inches);
            result = inches / 1.094;
            printf("%.2f yards equals %.2f meters.\n", inches, result);
            length_menu(); // go back to length menu
            break;
        case 6:
            printf("Enter the length in meters: ");
            scanf("%f", &centimeters);
            result = centimeters * 1.094;
            printf("%.2f meters equals %.2f yards.\n", centimeters, result);
            length_menu(); // go back to length menu
            break;
        case 7:
            printf("Enter the length in miles: ");
            scanf("%f", &inches);
            result = inches * 1.609;
            printf("%.2f miles equals %.2f kilometers.\n", inches, result);
            length_menu(); // go back to length menu
            break;
        case 8:
            printf("Enter the length in kilometers: ");
            scanf("%f", &centimeters);
            result = centimeters / 1.609;
            printf("%.2f kilometers equals %.2f miles.\n", centimeters, result);
            length_menu(); // go back to length menu
            break;
        case 9:
            main_menu(); // go back to main menu
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            length_menu(); // go back to length menu
    }
}

void weight_menu() {
    int choice;
    float pounds, kilograms, result;
    printf("\nSelect the unit to convert:\n\n");
    printf("\t1. Pounds to Kilograms\n");
    printf("\t2. Kilograms to Pounds\n");
    printf("\t3. Ounces to Grams\n");
    printf("\t4. Grams to Ounces\n");
    printf("\t5. Back to Main Menu\n\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the weight in pounds: ");
            scanf("%f", &pounds);
            result = pounds / 2.205;
            printf("%.2f pounds equals %.2f kilograms.\n", pounds, result);
            weight_menu(); // go back to weight menu
            break;
        case 2:
            printf("Enter the weight in kilograms: ");
            scanf("%f", &kilograms);
            result = kilograms * 2.205;
            printf("%.2f kilograms equals %.2f pounds.\n", kilograms, result);
            weight_menu(); // go back to weight menu
            break;
        case 3:
            printf("Enter the weight in ounces: ");
            scanf("%f", &pounds);
            result = pounds * 28.35;
            printf("%.2f ounces equals %.2f grams.\n", pounds, result);
            weight_menu(); // go back to weight menu
            break;
        case 4:
            printf("Enter the weight in grams: ");
            scanf("%f", &kilograms);
            result = kilograms / 28.35;
            printf("%.2f grams equals %.2f ounces.\n", kilograms, result);
            weight_menu(); // go back to weight menu
            break;
        case 5:
            main_menu(); // go back to main menu
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            weight_menu(); // go back to weight menu
    }
}

void temperature_menu() {
    int choice;
    float fahrenheit, celsius, result;
    printf("\nSelect the unit to convert:\n\n");
    printf("\t1. Fahrenheit to Celsius\n");
    printf("\t2. Celsius to Fahrenheit\n");
    printf("\t3. Kelvin to Celsius\n");
    printf("\t4. Celsius to Kelvin\n");
    printf("\t5. Back to Main Menu\n\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            result = (fahrenheit - 32) * 5 / 9;
            printf("%.2f Fahrenheit equals %.2f Celsius.\n", fahrenheit, result);
            temperature_menu(); // go back to temperature menu
            break;
        case 2:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            result = (celsius * 9 / 5) + 32;
            printf("%.2f Celsius equals %.2f Fahrenheit.\n", celsius, result);
            temperature_menu(); // go back to temperature menu
            break;
        case 3:
            printf("Enter the temperature in Kelvin: ");
            scanf("%f", &celsius);
            result = celsius - 273.15;
            printf("%.2f Kelvin equals %.2f Celsius.\n", celsius, result);
            temperature_menu(); // go back to temperature menu
            break;
        case 4:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);
            result = celsius + 273.15;
            printf("%.2f Celsius equals %.2f Kelvin.\n", celsius, result);
            temperature_menu(); // go back to temperature menu
            break;
        case 5:
            main_menu(); // go back to main menu
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            temperature_menu(); // go back to temperature menu
    }
}