#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double value, result;

    printf("Unit Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 6) {
        printf("Invalid choice!\n");
        return 1;
    }

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            result = (value * 9 / 5) + 32;
            break;
        case 2:
            result = (value - 32) * 5 / 9;
            break;
        case 3:
            result = value * 0.621371;
            break;
        case 4:
            result = value / 0.621371;
            break;
        case 5:
            result = value * 0.453592;
            break;
        case 6:
            result = value / 0.453592;
            break;
    }

    printf("%.2f converted is %.2f\n", value, result);

    return 0;
}
