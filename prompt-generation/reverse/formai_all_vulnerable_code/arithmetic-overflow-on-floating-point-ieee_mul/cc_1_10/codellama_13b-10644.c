//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>

int main() {
    // Declare variables
    int choice;
    double input_value;
    double result;

    // Display menu
    printf("Welcome to the Unit Converter\n");
    printf("----------------------------\n");
    printf("1. Convert from meters to feet\n");
    printf("2. Convert from feet to meters\n");
    printf("3. Convert from kilometers to miles\n");
    printf("4. Convert from miles to kilometers\n");
    printf("Enter your choice: ");

    // Get user input
    scanf("%d", &choice);

    // Perform conversion
    switch (choice) {
        case 1:
            printf("Enter the value in meters: ");
            scanf("%lf", &input_value);
            result = input_value * 3.28084;
            printf("Value in feet: %.2lf\n", result);
            break;
        case 2:
            printf("Enter the value in feet: ");
            scanf("%lf", &input_value);
            result = input_value / 3.28084;
            printf("Value in meters: %.2lf\n", result);
            break;
        case 3:
            printf("Enter the value in kilometers: ");
            scanf("%lf", &input_value);
            result = input_value * 0.621371;
            printf("Value in miles: %.2lf\n", result);
            break;
        case 4:
            printf("Enter the value in miles: ");
            scanf("%lf", &input_value);
            result = input_value / 0.621371;
            printf("Value in kilometers: %.2lf\n", result);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}