//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char input[20];
    int choice;
    float fahrenheit, celsius;

    // Display menu
    printf("Temperature Converter\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Validate input
    if (choice < 1 || choice > 3) {
        printf("Invalid choice!\n");
        exit(0);
    }

    // Get input temperature
    printf("Enter temperature: ");
    scanf("%s", input);

    // Validate input
    if (strlen(input) == 0) {
        printf("Invalid temperature!\n");
        exit(0);
    }

    // Convert input to float
    if (sscanf(input, "%f", &fahrenheit)!= 1) {
        printf("Invalid temperature!\n");
        exit(0);
    }

    // Convert temperature
    switch (choice) {
        case 1:
            celsius = (fahrenheit - 32) * 5 / 9;
            printf("%.2f F = %.2f C\n", fahrenheit, celsius);
            break;
        case 2:
            fahrenheit = celsius * 9 / 5 + 32;
            printf("%.2f C = %.2f F\n", celsius, fahrenheit);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
            exit(0);
    }

    return 0;
}