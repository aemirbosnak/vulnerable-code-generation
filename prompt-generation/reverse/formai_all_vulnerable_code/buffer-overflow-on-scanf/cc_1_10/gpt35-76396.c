//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
/*
 * C Temperature Converter
 * Written by [YOUR NAME HERE] in Linus Torvalds style
 */

#include <stdio.h>

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    float temp;
    char choice;

    printf("C Temperature Converter\n");
    printf("-----------------------\n");

    do {
        printf("\nEnter temperature: ");
        scanf("%f", &temp);

        printf("Convert to (F)ahrenheit or (C)elsius? ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'F':
            case 'f':
                printf("%.1fC = %.1fF\n", temp, celsius_to_fahrenheit(temp));
                break;
            case 'C':
            case 'c':
                printf("%.1fF = %.1fC\n", temp, fahrenheit_to_celsius(temp));
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

        printf("Convert another temperature? (Y/N) ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    printf("Goodbye!\n");

    return 0;
}