//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 50
#define FAHRENHEIT 'F'
#define CELSIUS 'C'

typedef struct {
    char unit;
    float value;
} Temperature;

void print_menu() {
    printf("*********************************\n");
    printf("* Temperature Conversion Program *\n");
    printf("*********************************\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

void convert_fahrenheit_to_celsius(Temperature *temp) {
    temp->value = (temp->value - 32) * 5.0 / 9.0;
}

void convert_celsius_to_fahrenheit(Temperature *temp) {
    temp->value = (temp->value * 9.0 / 5.0) + 32;
}

void read_input(Temperature *temp) {
    char unit;
    float value;

    printf("Enter temperature value: ");
    scanf("%f", &value);

    printf("Enter temperature unit (F/C): ");
    scanf(" %c", &unit);

    strcpy(temp->unit, &unit);
    temp->value = value;
}

void print_result(Temperature temp) {
    if (temp.unit == FAHRENHEIT) {
        if (temp.value >= 32) {
            convert_fahrenheit_to_celsius(&temp);
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", temp.value, temp.value);
        } else {
            printf("%.2f degrees Fahrenheit is below freezing point and cannot be converted to Celsius.\n", temp.value);
        }
    } else if (temp.unit == CELSIUS) {
        convert_celsius_to_fahrenheit(&temp);
        printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", temp.value, temp.value);
    }
}

int main() {
    Temperature temp;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        read_input(&temp);

        switch (choice) {
            case 1:
                if (temp.value >= 32) {
                    convert_fahrenheit_to_celsius(&temp);
                } else {
                    printf("Temperature value below freezing point. Please enter valid temperature.\n");
                    break;
                }
                break;
            case 2:
                convert_celsius_to_fahrenheit(&temp);
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please choose valid option.\n");
        }

        print_result(temp);
    } while (1);

    return 0;
}