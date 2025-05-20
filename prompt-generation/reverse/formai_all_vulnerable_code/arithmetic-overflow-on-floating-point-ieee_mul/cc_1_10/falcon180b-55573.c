//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    char input[50];
    double celsius, fahrenheit, kelvin;
    int choice;

    // Prompt the user to enter a temperature value
    printf("Enter a temperature value: ");
    scanf("%s", input);

    // Convert the input string to a double value
    sscanf(input, "%lf", &celsius);

    // Prompt the user to choose a conversion type
    printf("Choose a conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    scanf("%d", &choice);

    // Perform the conversion based on the user's choice
    switch(choice) {
        case 1:
            fahrenheit = (celsius * 1.8) + 32;
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
            break;
        case 2:
            kelvin = celsius + 273.15;
            printf("%.2lf Celsius is equal to %.2lf Kelvin.\n", celsius, kelvin);
            break;
        case 3:
            fahrenheit = (celsius * 1.8) + 32;
            celsius = (fahrenheit - 32) / 1.8;
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
            break;
        case 4:
            kelvin = (fahrenheit + 459.67) * 5/9;
            printf("%.2lf Fahrenheit is equal to %.2lf Kelvin.\n", fahrenheit, kelvin);
            break;
        case 5:
            celsius = kelvin - 273.15;
            printf("%.2lf Kelvin is equal to %.2lf Celsius.\n", kelvin, celsius);
            break;
        case 6:
            fahrenheit = (kelvin * 1.8) - 459.67;
            printf("%.2lf Kelvin is equal to %.2lf Fahrenheit.\n", kelvin, fahrenheit);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}