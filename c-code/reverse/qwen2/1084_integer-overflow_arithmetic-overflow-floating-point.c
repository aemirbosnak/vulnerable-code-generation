#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int choice, quantity;
    float result;

    printf("Unit Converter\n");
    printf("1. Centimeters to Meters\n");
    printf("2. Meters to Kilometers\n");
    printf("3. Inches to Feet\n");
    printf("4. Feet to Miles\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    switch (choice) {
        case 1:
            result = (float)quantity / 100;
            break;
        case 2:
            result = (float)quantity / 1000;
            break;
        case 3:
            result = (float)quantity * 12 / 36;
            break;
        case 4:
            result = (float)quantity * 5280 / 36;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("%.2f\n", result);

    return 0;
}
