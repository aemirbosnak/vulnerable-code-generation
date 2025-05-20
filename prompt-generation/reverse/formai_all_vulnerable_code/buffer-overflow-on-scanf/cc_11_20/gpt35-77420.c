//FormAI DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>

int main() {
    printf("====================================\n");
    printf("Welcome to the Unit Converter Program\n");
    printf("====================================\n");

    // Variables to store user input values
    double input_value;
    int from_unit_choice, to_unit_choice;

    // Flag to check if the program should continue
    int continue_program = 1;

    while (continue_program) {
        // Prompt user to enter input value
        printf("Enter the value to be converted: ");
        scanf("%lf", &input_value);

        // Prompt user to select unit to convert from
        printf("\nEnter the unit to convert from:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        scanf("%d", &from_unit_choice);

        // Prompt user to select unit to convert to
        printf("\nEnter the unit to convert to:\n");
        printf("1. Celsius\n");
        printf("2. Fahrenheit\n");
        printf("3. Kelvin\n");
        scanf("%d", &to_unit_choice);

        double output_value;

        // Perform conversion based on user input
        switch (from_unit_choice) {
            case 1:
                // Convert from Celsius
                if (to_unit_choice == 2) {
                    // Convert to Fahrenheit
                    output_value = (input_value * 1.8) + 32;
                } else if (to_unit_choice == 3) {
                    // Convert to Kelvin
                    output_value = input_value + 273.15;
                } else {
                    output_value = input_value;
                }
                break;
            case 2:
                // Convert from Fahrenheit
                if (to_unit_choice == 1) {
                    // Convert to Celsius
                    output_value = (input_value - 32) * 0.5556;
                } else if (to_unit_choice == 3) {
                    // Convert to Kelvin
                    output_value = (input_value - 32) * 0.5556 + 273.15;
                } else {
                    output_value = input_value;
                }
                break;
            case 3:
                // Convert from Kelvin
                if (to_unit_choice == 1) {
                    // Convert to Celsius
                    output_value = input_value - 273.15;
                } else if (to_unit_choice == 2) {
                    // Convert to Fahrenheit
                    output_value = (input_value - 273.15) * 1.8 + 32;
                } else {
                    output_value = input_value;
                }
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                continue;
        }

        // Display conversion result
        printf("\nThe converted value is: %.2lf\n", output_value);

        // Prompt user to continue or exit program
        printf("\nDo you want to continue?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        int continue_choice;
        scanf("%d", &continue_choice);

        if (continue_choice != 1) {
            continue_program = 0;
        }
    }
    printf("Thank you for using the Unit Converter Program.\n");
    return 0;
}