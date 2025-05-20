//Gemma-7B DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>
#include <math.h>

void main() {
    int choice, num, i, j;
    float conversion_factor, result;

    printf("Please select an option:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            conversion_factor = (5.0 / 9.0) * 100;
            printf("Enter the temperature in Fahrenheit:");
            scanf("%d", &num);
            result = (num - 32) * conversion_factor;
            printf("The temperature in Celsius is: %.2f", result);
            break;

        case 2:
            conversion_factor = (9.0 / 5.0) * 100 + 32;
            printf("Enter the temperature in Celsius:");
            scanf("%d", &num);
            result = (num * conversion_factor) + 32;
            printf("The temperature in Fahrenheit is: %.2f", result);
            break;

        case 3:
            conversion_factor = 1.613;
            printf("Enter the distance in miles:");
            scanf("%d", &num);
            result = num * conversion_factor;
            printf("The distance in kilometers is: %.2f", result);
            break;

        case 4:
            conversion_factor = 0.621371;
            printf("Enter the distance in kilometers:");
            scanf("%d", &num);
            result = num * conversion_factor;
            printf("The distance in miles is: %.2f", result);
            break;

        default:
            printf("Invalid choice");
    }

    return;
}