//FormAI DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen() {
    system("CLS");
}

void print_title() {
    printf("  _____     _             _     \n");
    printf(" / ____|   | |           | |    \n");
    printf("| |  __  __| |_ __ __ _  | |__  \n");
    printf("| | |_ |/ _` | '__/ _` | | '_ \\ \n");
    printf("| |__| | (_| | | | (_| | | |_) |\n");
    printf(" \\_____|\\__,_|_|  \\__, | |_.__/ \n");
    printf("                    __/ |       \n");
    printf("                   |___/        \n\n");
}

void print_menu() {
    printf("1. Length\n");
    printf("2. Mass\n");
    printf("3. Temperature\n");
    printf("4. Volume\n");
    printf("5. Speed\n");
    printf("6. Quit\n\n");
}

void convert_length() {
    float meters;
    char unit[10];
    clear_screen();
    printf("Enter Length in Meters: ");
    scanf("%f", &meters);
    printf("Enter Output Unit (cm, mm, km): ");
    scanf("%s", unit);
    if (strcmp(unit, "cm") == 0) {
        printf("%.2f meters is equivalent to %.2f centimeters\n", meters, meters * 100);
    } else if (strcmp(unit, "mm") == 0) {
        printf("%.2f meters is equivalent to %.2f millimeters\n", meters, meters * 1000);
    } else if (strcmp(unit, "km") == 0) {
        printf("%.2f meters is equivalent to %.2f kilometers\n", meters, meters / 1000);
    } else {
        printf("Invalid unit entered\n");
    }
}

void convert_mass() {
    float kilogram;
    char unit[10];
    clear_screen();
    printf("Enter Mass in Kilograms: ");
    scanf("%f", &kilogram);
    printf("Enter Output Unit (g, mg, lb): ");
    scanf("%s", unit);
    if (strcmp(unit, "g") == 0) {
        printf("%.2f kilograms is equivalent to %.2f grams\n", kilogram, kilogram * 1000);
    } else if (strcmp(unit, "mg") == 0) {
        printf("%.2f kilograms is equivalent to %.2f milligrams\n", kilogram, kilogram * 1000000);
    } else if (strcmp(unit, "lb") == 0) {
        printf("%.2f kilograms is equivalent to %.2f pounds\n", kilogram, kilogram * 2.20462);
    } else {
        printf("Invalid unit entered\n");
    }
}

void convert_temperature() {
    float celsius;
    clear_screen();
    printf("Enter Temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("The Temperature in Fahrenheit is %.2f\n", (celsius * 1.8) + 32);
}

void convert_volume() {
    float liters;
    char unit[10];
    clear_screen();
    printf("Enter Volume in Liters: ");
    scanf("%f", &liters);
    printf("Enter Output Unit (ml, gal): ");
    scanf("%s", unit);
    if (strcmp(unit, "ml") == 0) {
        printf("%.2f liters is equivalent to %.2f milliliters\n", liters, liters * 1000);
    } else if (strcmp(unit, "gal") == 0) {
        printf("%.2f liters is equivalent to %.2f gallons\n", liters, liters / 3.78541);
    } else {
        printf("Invalid unit entered\n");
    }
}

void convert_speed() {
    float kmph;
    clear_screen();
    printf("Enter Speed in Kilometers per Hour: ");
    scanf("%f", &kmph);
    printf("The Speed in Miles per Hour is %.2f\n", kmph / 1.60934);
}

int main() {
    char choice;
    do {
        clear_screen();
        print_title();
        print_menu();
        printf("Enter your choice: ");
        choice = getchar();
        switch (choice) {
            case '1':
                convert_length();
                break;
            case '2':
                convert_mass();
                break;
            case '3':
                convert_temperature();
                break;
            case '4':
                convert_volume();
                break;
            case '5':
                convert_speed();
                break;
            case '6':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        getchar();
    } while (choice != '6');
    return 0;
}