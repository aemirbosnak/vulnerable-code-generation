//FormAI DATASET v1.0 Category: Unit converter ; Style: accurate
#include <stdio.h>

int main() {
    int choice;
    float value, convertedValue;

    printf("Welcome to the Unit Converter!\n\n");

    printf("Select the type of conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");

    printf("\nEnter your choice (1-6): ");
    scanf("%d", &choice);

    printf("\nEnter the value to convert: ");
    scanf("%f", &value);

    switch(choice) {
        case 1:
            convertedValue = (value * 1.8) + 32;
            printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.", value, convertedValue);
            break;
        case 2:
            convertedValue = (value - 32) / 1.8;
            printf("\n%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.", value, convertedValue);
            break;
        case 3:
            convertedValue = value * 1.609344;
            printf("\n%.2f miles is equal to %.2f kilometers.", value, convertedValue);
            break;
        case 4:
            convertedValue = value / 1.609344;
            printf("\n%.2f kilometers is equal to %.2f miles.", value, convertedValue);
            break;
        case 5:
            convertedValue = value * 0.453592;
            printf("\n%.2f pounds is equal to %.2f kilograms.", value, convertedValue);
            break;
        case 6:
            convertedValue = value / 0.453592;
            printf("\n%.2f kilograms is equal to %.2f pounds.", value, convertedValue);
            break;
        default:
            printf("\nInvalid choice!");
    }

    return 0;
}