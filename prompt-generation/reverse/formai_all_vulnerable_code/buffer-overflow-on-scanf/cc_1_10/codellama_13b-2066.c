//Code Llama-13B DATASET v1.0 Category: Temperature monitor ; Style: Alan Turing
// A unique C Temperature monitor example program in an Alan Turing style

#include <stdio.h>

int main() {
    float temperature;
    char input;
    int i = 0;

    // Welcome message
    printf("Welcome to the Temperature Monitoring System.\n");

    // Loop to get temperature inputs
    while (i < 3) {
        // Get temperature input
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temperature);

        // Check if temperature is in range
        if (temperature < 0 || temperature > 100) {
            printf("Temperature out of range. Try again.\n");
            continue;
        }

        // Print temperature status
        if (temperature < 25) {
            printf("Temperature is below normal. Take action.\n");
        } else if (temperature > 25 && temperature < 30) {
            printf("Temperature is normal.\n");
        } else if (temperature > 30) {
            printf("Temperature is above normal. Take action.\n");
        }

        // Get input to continue
        printf("Enter 'y' to continue, any other key to exit: ");
        scanf("%c", &input);

        // Check input
        if (input == 'y') {
            i++;
        } else {
            break;
        }
    }

    // Goodbye message
    printf("Thank you for using the Temperature Monitoring System.\n");

    return 0;
}