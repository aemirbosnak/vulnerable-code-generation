//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    char input[100];
    char unit[10];
    int choice;
    float temperature, converted;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature value and its unit (e.g. 20 C): ");
    scanf("%s %s", input, unit);

    while (1) {
        printf("\nPlease choose a conversion:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Celsius to Kelvin\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Fahrenheit to Kelvin\n");
        printf("5. Kelvin to Celsius\n");
        printf("6. Kelvin to Fahrenheit\n");
        printf("7. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temperature = atof(input);
                converted = (temperature * 9/5) + 32;
                printf("%.2f C = %.2f F\n", temperature, converted);
                break;
            case 2:
                temperature = atof(input);
                converted = temperature + 273.15;
                printf("%.2f C = %.2f K\n", temperature, converted);
                break;
            case 3:
                temperature = atof(input);
                converted = (temperature - 32) * 5/9;
                printf("%.2f F = %.2f C\n", temperature, converted);
                break;
            case 4:
                temperature = atof(input);
                converted = (temperature - 32) * 5/9;
                printf("%.2f F = %.2f K\n", temperature, converted);
                break;
            case 5:
                temperature = atof(input);
                converted = temperature - 273.15;
                printf("%.2f K = %.2f C\n", temperature, converted);
                break;
            case 6:
                temperature = atof(input);
                converted = (temperature * 9/5) - 459.67;
                printf("%.2f K = %.2f F\n", temperature, converted);
                break;
            case 7:
                printf("Thank you for using the Temperature Converter!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}