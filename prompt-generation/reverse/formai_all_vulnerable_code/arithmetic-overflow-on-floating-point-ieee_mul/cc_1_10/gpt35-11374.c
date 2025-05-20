//FormAI DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void showMenu();
void temperature();
void length();
void weight();
void speed();

int main() {
    printf("\t\tWelcome to the Unit Converter!\n");

    while(1) {
        showMenu();

        int option;
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                temperature();
                break;
            case 2:
                length();
                break;
            case 3:
                weight();
                break;
            case 4:
                speed();
                break;
            case 5:
                printf("\nThank you for using the Unit Converter. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please enter a valid option.\n");
                break;
        }
    }

    return 0;
}

void showMenu() {
    printf("\n---- Conversion Options ----\n");
    printf("1. Temperature\n");
    printf("2. Length\n");
    printf("3. Weight\n");
    printf("4. Speed\n");
    printf("5. Exit\n");
}

void temperature() {
    printf("\n--- Temperature Conversion ---\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your option: ");

    int option;
    scanf("%d", &option);

    float value;
    printf("Enter the value to convert: ");
    scanf("%f", &value);

    switch(option) {
        case 1:
            printf("%.2f Celsius is %.2f Fahrenheit.\n", value, (value * 9/5) + 32);
            break;
        case 2:
            printf("%.2f Fahrenheit is %.2f Celsius.\n", value, (value - 32) * 5/9);
            break;
        default:
            printf("\nInvalid option! Please enter a valid option.\n");
            break;
    }
}

void length() {
    printf("\n--- Length Conversion ---\n");
    printf("1. Meters to Feet\n");
    printf("2. Feet to Meters\n");
    printf("Enter your option: ");

    int option;
    scanf("%d", &option);

    float value;
    printf("Enter the value to convert: ");
    scanf("%f", &value);

    switch(option) {
        case 1:
            printf("%.2f Meters is %.2f Feet.\n", value, value * 3.281);
            break;
        case 2:
            printf("%.2f Feet is %.2f Meters.\n", value, value / 3.281);
            break;
        default:
            printf("\nInvalid option! Please enter a valid option.\n");
            break;
    }
}

void weight() {
    printf("\n--- Weight Conversion ---\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter your option: ");

    int option;
    scanf("%d", &option);

    float value;
    printf("Enter the value to convert: ");
    scanf("%f", &value);

    switch(option) {
        case 1:
            printf("%.2f Kilograms is %.2f Pounds.\n", value, value * 2.205);
            break;
        case 2:
            printf("%.2f Pounds is %.2f Kilograms.\n", value, value / 2.205);
            break;
        default:
            printf("\nInvalid option! Please enter a valid option.\n");
            break;
    }
}

void speed() {
    printf("\n--- Speed Conversion ---\n");
    printf("1. Kilometers per hour to Miles per hour\n");
    printf("2. Miles per hour to Kilometers per hour\n");
    printf("Enter your option: ");

    int option;
    scanf("%d", &option);

    float value;
    printf("Enter the value to convert: ");
    scanf("%f", &value);

    switch(option) {
        case 1:
            printf("%.2f Kilometers per hour is %.2f Miles per hour.\n", value, value / 1.609);
            break;
        case 2:
            printf("%.2f Miles per hour is %.2f Kilometers per hour.\n", value, value * 1.609);
            break;
        default:
            printf("\nInvalid option! Please enter a valid option.\n");
            break;
    }
}