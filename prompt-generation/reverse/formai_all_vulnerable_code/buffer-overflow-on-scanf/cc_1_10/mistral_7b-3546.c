//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: medieval
#include <stdio.h>

// Define constants for hand widths
#define FIST 0.15
#define SPAN 6.67

// Function to read a temperature value in hand widths from the user
float read_temperature() {
    float temperature;

    printf("Enter the temperature in hand widths: ");
    scanf("%f", &temperature);

    return temperature;
}

// Function to convert temperature from fist to span
float fist_to_span(float temperature_in_fist) {
    return temperature_in_fist * SPAN;
}

// Function to convert temperature from span to fist
float span_to_fist(float temperature_in_span) {
    return temperature_in_span / SPAN;
}

int main() {
    int choice;
    float temperature, converted_temperature;

    // Display a medieval-style welcome message
    printf("\n----------------------------------------\n");
    printf("|          Welcome to the Temperature  |\n");
    printf("|             Converter!              |\n");
    printf("|             By Your Humble Servant   |\n");
    printf("|                                    |\n");
    printf("----------------------------------------\n");

    // Loop for user to choose temperature conversion
    do {
        printf("\nChoose an option:\n");
        printf("1. Convert from fist to span\n");
        printf("2. Convert from span to fist\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                temperature = read_temperature();
                converted_temperature = fist_to_span(temperature);
                printf("The temperature in spans is: %.2f\n", converted_temperature);
                break;
            case 2:
                temperature = read_temperature();
                converted_temperature = span_to_fist(temperature);
                printf("The temperature in fists is: %.2f\n", converted_temperature);
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}