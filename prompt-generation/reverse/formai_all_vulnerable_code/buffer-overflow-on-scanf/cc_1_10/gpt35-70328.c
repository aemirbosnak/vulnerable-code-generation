//FormAI DATASET v1.0 Category: Unit converter ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    float input, output;
    int choice;

    printf("Please select the unit to convert from:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");

    scanf("%d", &choice);

    switch(choice) {

        // Celsius to Fahrenheit
        case 1:
            printf("Enter degrees Celsius to convert: ");
            scanf("%f", &input);
            output = (input * 9.0 / 5.0) + 32.0;
            printf("Degrees Fahrenheit: %.2f\n", output);
            break;

        // Fahrenheit to Celsius
        case 2:
            printf("Enter degrees Fahrenheit to convert: ");
            scanf("%f", &input);
            output = (input - 32.0) * 5.0 / 9.0;
            printf("Degrees Celsius: %.2f\n", output);
            break;

        // Miles to Kilometers
        case 3:
            printf("Enter miles to convert: ");
            scanf("%f", &input);
            output = input / 0.62137;
            printf("Kilometers: %.2f\n", output);
            break;

        // Kilometers to Miles
        case 4:
            printf("Enter kilometers to convert: ");
            scanf("%f", &input);
            output = input * 0.62137;
            printf("Miles: %.2f\n", output);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}