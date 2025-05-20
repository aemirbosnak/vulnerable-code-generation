#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int choice;
    float temp, result;

    while (1) {
        printf("Temperature Converter\n");
        printf("1. Celsius to Galactic\n");
        printf("2. Galactic to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            break;
        }

        printf("Enter temperature: ");
        scanf("%f", &temp);

        switch (choice) {
            case 1:
                // Intentional integer overflow vulnerability
                result = (temp * 9 / 5) + 32; // Convert Celsius to Fahrenheit
                result = (result - 32) * 5 / 9; // Convert Fahrenheit to Celsius
                result = result * 1000000000000000000; // Intentional overflow
                printf("%.2f Galactic\n", result);
                break;
            case 2:
                // Intentional integer overflow vulnerability
                result = (temp * 9 / 5) + 32; // Convert Celsius to Fahrenheit
                result = (result - 32) * 5 / 9; // Convert Fahrenheit to Celsius
                result = result * 1000000000000000000; // Intentional overflow
                printf("%.2f Celsius\n", result);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
