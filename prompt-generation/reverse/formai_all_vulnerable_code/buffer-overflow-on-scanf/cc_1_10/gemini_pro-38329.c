//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare the variables needed for the program.
    float input_value;
    int input_type;
    int output_type;
    float output_value;

    // Display a welcome message to the user.
    printf("Welcome to the Unit Converter program!\n");

    // Get the input value from the user.
    printf("Enter the input value: ");
    scanf("%f", &input_value);

    // Get the input type from the user.
    printf("Enter the input type (1 for kilometers, 2 for miles, 3 for pounds, 4 for kilograms): ");
    scanf("%d", &input_type);

    // Get the output type from the user.
    printf("Enter the output type (1 for kilometers, 2 for miles, 3 for pounds, 4 for kilograms): ");
    scanf("%d", &output_type);

    // Convert the input value to the output type.
    switch (input_type) {
        case 1:
            // Convert kilometers to miles.
            output_value = input_value * 0.621371;
            break;
        case 2:
            // Convert miles to kilometers.
            output_value = input_value * 1.60934;
            break;
        case 3:
            // Convert pounds to kilograms.
            output_value = input_value * 0.453592;
            break;
        case 4:
            // Convert kilograms to pounds.
            output_value = input_value * 2.20462;
            break;
        default:
            // Handle invalid input types.
            printf("Invalid input type.\n");
            return 1;
    }

    // Display the output value to the user.
    printf("The output value is: %f\n", output_value);

    // Exit the program.
    return 0;
}