//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

int main() {

    int option;
    float value, convertedValue;

    printf("Select the conversion you want to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Option: ");

    scanf("%d", &option);

    printf("Enter value to be converted: ");
    scanf("%f", &value);

    switch (option) {
        case 1:
            convertedValue = (value * 9/5) + 32;
            printf("%.2f Celsius is %.2f Fahrenheit", value, convertedValue);
            break;
        case 2:
            convertedValue = value + 273.15;
            printf("%.2f Celsius is %.2f Kelvin", value, convertedValue);
            break;
        case 3:
            convertedValue = (value - 32) * 5/9;
            printf("%.2f Fahrenheit is %.2f Celsius", value, convertedValue);
            break;
        case 4:
            convertedValue = (value + 459.67) * 5/9;
            printf("%.2f Fahrenheit is %.2f Kelvin", value, convertedValue);
            break;
        case 5:
            convertedValue = value - 273.15;
            printf("%.2f Kelvin is %.2f Celsius", value, convertedValue);
            break;
        case 6:
            convertedValue = (value * 9/5) - 459.67;
            printf("%.2f Kelvin is %.2f Fahrenheit", value, convertedValue);
            break;
        default:
            printf("Invalid option selected");
    }

    return 0;
}