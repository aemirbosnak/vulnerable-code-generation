//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INFO "Welcome to the Temperature Converter!\n"
#define F_TO_C "Converting from Fahrenheit to Celsius...\n"
#define C_TO_F "Converting from Celsius to Fahrenheit...\n"
#define INVALID_TEMP "Invalid temperature value!\n"

typedef struct {
    char operation;
    double temperature;
    char unit;
} temperature_operation;

void print_menu() {
    printf("\nTemperature Converter Menu:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Quit\n");
}

void fahrenheit_to_celsius(temperature_operation *temp_op) {
    temp_op->temperature = (temp_op->temperature - 32) * 5.0 / 9.0;
    temp_op->unit = 'C';
    printf("%s", F_TO_C);
}

void celsius_to_fahrenheit(temperature_operation *temp_op) {
    temp_op->temperature = (temp_op->temperature * 9.0 / 5.0) + 32;
    temp_op->unit = 'F';
    printf("%s", C_TO_F);
}

void convert_temperature(temperature_operation *temp_op) {
    switch (temp_op->operation) {
        case '1':
            fahrenheit_to_celsius(temp_op);
            break;
        case '2':
            celsius_to_fahrenheit(temp_op);
            break;
        case '3':
            exit(0);
            break;
        default:
            printf("%s", INVALID_TEMP);
            temp_op->operation = '1';
            break;
    }
}

int main() {
    temperature_operation temp_op;
    char choice;

    printf("%s\n\n", INFO);
    print_menu();

    while (1) {
        scanf("%c", &choice);
        temp_op.operation = choice;

        if (choice != '1' && choice != '2' && choice != '3') {
            printf("%s", INVALID_TEMP);
            continue;
        }

        if (choice == '1') {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temp_op.temperature);
        } else {
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temp_op.temperature);
        }

        convert_temperature(&temp_op);
        printf("Result: %.2lf%c\n", temp_op.temperature, temp_op.unit);
        print_menu();
    }

    return 0;
}