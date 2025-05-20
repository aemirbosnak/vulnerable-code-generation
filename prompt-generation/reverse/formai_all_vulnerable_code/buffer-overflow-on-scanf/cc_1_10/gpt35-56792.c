//FormAI DATASET v1.0 Category: Unit converter ; Style: excited
#include <stdio.h>

int main() {
    int choice;
    float value;

    printf("Welcome to the Ultimate Unit Converter!\n");

    while (1) {
        printf("\nChoose an option below:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Convert Kilometers to Miles\n");
        printf("4. Convert Miles to Kilometers\n");
        printf("5. Convert Pounds to Kilograms\n");
        printf("6. Convert Kilograms to Pounds\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            float result = (value * 9/5) + 32;
            printf("%.2f degrees Fahrenheit\n", result);
        } else if (choice == 2) {
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &value);
            float result = (value - 32) * 5/9;
            printf("%.2f degrees Celsius\n", result);
        } else if (choice == 3) {
            printf("Enter distance in Kilometers: ");
            scanf("%f", &value);
            float result = value / 1.609;
            printf("%.2f Miles\n", result);
        } else if (choice == 4) {
            printf("Enter distance in Miles: ");
            scanf("%f", &value);
            float result = value * 1.609;
            printf("%.2f Kilometers\n", result);
        } else if (choice == 5) {
            printf("Enter weight in Pounds: ");
            scanf("%f", &value);
            float result = value * 0.453592;
            printf("%.2f Kilograms\n", result);
        } else if (choice == 6) {
            printf("Enter weight in Kilograms: ");
            scanf("%f", &value);
            float result = value / 0.453592;
            printf("%.2f Pounds\n", result);
        } else if (choice == 7) {
            printf("Thank you for using the Ultimate Unit Converter!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}