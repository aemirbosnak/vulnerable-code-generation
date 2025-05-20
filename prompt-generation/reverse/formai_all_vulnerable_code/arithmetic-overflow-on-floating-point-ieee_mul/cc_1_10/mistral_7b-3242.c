//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TempData {
    char unit;
    double value;
} TempData;

void fahrenheit_to_celsius(TempData* temp) {
    temp->value = (temp->value - 32.0) * 5.0 / 9.0;
}

void celsius_to_fahrenheit(TempData* temp) {
    temp->value = temp->value * 9.0 / 5.0 + 32.0;
}

void print_menu() {
    printf("\n***** UNIT CONVERTER *****\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

int main() {
    TempData temp;
    char choice;

    do {
        print_menu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temp.value);
                temp.unit = 'F';
                fahrenheit_to_celsius(&temp);
                printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", temp.value, temp.value);
                break;

            case '2':
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temp.value);
                temp.unit = 'C';
                celsius_to_fahrenheit(&temp);
                printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", temp.value, temp.value);
                break;

            case '3':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != '3');

    return 0;
}