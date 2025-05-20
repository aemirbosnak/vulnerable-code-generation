#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#define MAX_INPUT 100

void celsius_to_galactic(double celsius);
void galactic_to_celsius(double galactic);
void print_menu();

int main() {
    double input;
    char choice;

    print_menu();

    scanf("%lf", &input);

    while (getchar() != '\n')
        continue;

    scanf("%c", &choice);

    switch (choice) {
        case 'C':
            celsius_to_galactic(input);
            break;
        case 'G':
            galactic_to_celsius(input);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            main();
    }

    return 0;
}

void celsius_to_galactic(double celsius) {
    if (celsius < -273.15) {
        printf("Error: Temperature below absolute zero is not possible.\n");
        celsius_to_galactic(celsius);
    } else {
        printf("%.2f Celsius is approximately %.2f Galactic.\n", celsius, 1 / (celsius + 273.15));
    }
}

void galactic_to_celsius(double galactic) {
    if (galactic <= 0) {
        printf("Error: Temperature cannot be zero or less in Galactic scale.\n");
        galactic_to_celsius(galactic);
    } else {
        printf("%.2f Galactic is approximately %.2f Celsius.\n", galactic, (1 / galactic) - 273.15);
    }
}

void print_menu() {
    printf("Temperature Converter\n");
    printf("1. Convert Celsius to Galactic\n");
    printf("2. Convert Galactic to Celsius\n");
    printf("Choose conversion type (C/G): ");
}
