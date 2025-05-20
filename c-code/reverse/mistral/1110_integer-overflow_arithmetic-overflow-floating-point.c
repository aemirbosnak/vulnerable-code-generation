#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_TEMP 127 // Maximum temperature limit to avoid integer overflow

void celsius_to_galactic(int celsius);
void galactic_to_celsius(int galactic);

int main() {
    int choice, temp;

    printf("Temperature Converter\n");
    printf("1. Celsius to Galactic\n");
    printf("2. Galactic to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter temperature: ");
    scanf("%d", &temp);

    switch (choice) {
        case 1:
            celsius_to_galactic(temp);
            break;
        case 2:
            galactic_to_celsius(temp);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

void celsius_to_galactic(int celsius) {
    int galactic = celsius * 1000000 + 1000000; // Integer overflow vulnerability
    printf("Galactic: %d\n", galactic);
}

void galactic_to_celsius(int galactic) {
    int celsius = (galactic - 1000000) / 1000000;
    printf("Celsius: %d\n", celsius);
}
