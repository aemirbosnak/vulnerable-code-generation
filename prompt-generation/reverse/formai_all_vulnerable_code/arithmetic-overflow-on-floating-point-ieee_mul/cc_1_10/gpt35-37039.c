//FormAI DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int choice;
    float value, result;

    printf("Choose the conversion you'd like to perform:\n");
    printf("1 - Celcius to Fahrenheit\n");
    printf("2 - Fahrenheit to Celcius\n");
    printf("3 - Kilometers to Miles\n");
    printf("4 - Miles to Kilometers\n");
    printf("5 - Pounds to Kilograms\n");
    printf("6 - Kilograms to Pounds\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    printf("Enter the value you'd like to convert: ");
    scanf("%f", &value);

    switch(choice) {
        case 1:
            result = (value * 9/5) + 32;
            printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", value, result);
            break;
        case 2:
            result = (value - 32) * 5/9;
            printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", value, result);
            break;
        case 3:
            result = value / 1.609;
            printf("%.2f kilometers is equal to %.2f miles.\n", value, result);
            break;
        case 4:
            result = value * 1.609;
            printf("%.2f miles is equal to %.2f kilometers.\n", value, result);
            break;
        case 5:
            result = value / 2.205;
            printf("%.2f pounds is equal to %.2f kilograms.\n", value, result);
            break;
        case 6:
            result = value * 2.205;
            printf("%.2f kilograms is equal to %.2f pounds.\n", value, result);
            break;
        default:
            printf("Invalid choice - please enter a number between 1 and 6.\n");
            break;
    }

    return 0;
}