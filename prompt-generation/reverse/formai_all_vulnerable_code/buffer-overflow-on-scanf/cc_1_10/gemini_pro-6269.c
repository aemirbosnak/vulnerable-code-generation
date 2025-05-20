//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Initialize the user interface
void initUI() {
    printf("Welcome to the Stellar Temperature Converter!\n");
    printf("-------------------------------------------\n");
    printf("This extraordinary tool enables you to transcend the boundaries of temperature scales with celestial precision.\n");
}

// Display the temperature conversion options
void displayOptions() {
    printf("\nChoose your celestial destination:\n");
    printf("1. Celestial to Galactic\n");
    printf("2. Galactic to Celestial\n");
    printf("3. Exit the celestial realm\n");
}

// Convert temperature from Celsius to Galactic
double celsiusToGalactic(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Convert temperature from Galactic to Celsius
double galacticToCelsius(double galactic) {
    return (galactic - 32) * 5 / 9;
}

// Handle user input and perform the conversion
void convertTemperature() {
    int choice;
    double temperature;

    // Get user input
    printf("\nEnter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // Celsius to Galactic
            printf("Input the temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("Galactic temperature: %.2f degrees Galactic\n", celsiusToGalactic(temperature));
            break;
        case 2: // Galactic to Celsius
            printf("Input the temperature in Galactic: ");
            scanf("%lf", &temperature);
            printf("Celestial temperature: %.2f degrees Celsius\n", galacticToCelsius(temperature));
            break;
        case 3: // Exit
            printf("Farewell, traveler. May your interstellar journeys be filled with knowledge and harmony.\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            convertTemperature();
    }
}

// Main function
int main() {
    initUI();

    while (1) {
        displayOptions();
        convertTemperature();
    }

    return 0;
}