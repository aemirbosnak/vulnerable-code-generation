//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float value;
    char unit[10];
} Unit;

void print_unit(Unit unit) {
    printf("%.2f %s\n", unit.value, unit.unit);
}

Unit convert_fahrenheit_to_celsius(Unit unit) {
    Unit celsius;
    celsius.value = (unit.value - 32) * 5.0/9.0;
    strcpy(celsius.unit, "°C");
    return celsius;
}

Unit convert_celsius_to_fahrenheit(Unit unit) {
    Unit fahrenheit;
    fahrenheit.value = unit.value * 9.0/5.0 + 32;
    strcpy(fahrenheit.unit, "°F");
    return fahrenheit;
}

int main() {
    int choice;
    Unit input;
    Unit output;

    printf("Welcome to the Unit Converter!\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
    scanf("%d", &choice);

    printf("Enter temperature value and unit: ");
    scanf("%f %s", &input.value, input.unit);

    switch (choice) {
        case 1:
            output = convert_fahrenheit_to_celsius(input);
            print_unit(output);
            break;
        case 2:
            output = convert_celsius_to_fahrenheit(input);
            print_unit(output);
            break;
        case 3:
            printf("Exiting the program...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            main();
    }

    return 0;
}