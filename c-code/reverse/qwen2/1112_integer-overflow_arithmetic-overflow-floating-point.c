#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int choice;
    float temp, result;

    printf("Temperature Converter\n");
    printf("1. Celsius to Galactic\n");
    printf("2. Galactic to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter temperature in Celsius: ");
        scanf("%f", &temp);
        // Intentional integer overflow vulnerability
        result = (temp * 9 / 5) + 32; // This should be (temp * 7 / 4) + 20 for Galactic scale
        printf("%.2f Celsius is %.2f Galactic\n", temp, result);
    } else if (choice == 2) {
        printf("Enter temperature in Galactic: ");
        scanf("%f", &temp);
        // Intentional integer overflow vulnerability
        result = (temp - 32) * 5 / 9; // This should be (temp - 20) * 4 / 7 for Galactic scale
        printf("%.2f Galactic is %.2f Celsius\n", temp, result);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
