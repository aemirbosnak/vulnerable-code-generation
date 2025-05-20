//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

// Function prototypes
float celsiusToFahrenheit(float celsius);
float fahrenheitToCelsius(float fahrenheit);
void printMenu();
void introspectiveMessage(int choice);

int main() {
    float temperature;
    int choice;
    bool keepRunning = true;

    // Introspection: Why do we measure temperature?
    printf("Welcome to the Temperature Converter!\n");
    printf("Temperature is not just a number; it reflects our environment, emotions, and more.\n");

    while (keepRunning) {
        printMenu();
        
        // Getting user choice
        printf("Please select an option (1 or 2, or 0 to exit): ");
        scanf("%d", &choice);

        // Making sense of choices
        switch (choice) {
            case 1:
                printf("You chose to convert Celsius to Fahrenheit.\n");
                introspectiveMessage(choice);
                printf("Enter the temperature in Celsius: ");
                scanf("%f", &temperature);
                printf("The temperature in Fahrenheit is: %.2f°F\n", celsiusToFahrenheit(temperature));
                break;

            case 2:
                printf("You chose to convert Fahrenheit to Celsius.\n");
                introspectiveMessage(choice);
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%f", &temperature);
                printf("The temperature in Celsius is: %.2f°C\n", fahrenheitToCelsius(temperature));
                break;

            case 0:
                keepRunning = false;
                printf("Exiting the program. May your temperatures remain balanced!\n");
                break;

            default:
                printf("Invalid choice. The heat is on, but you can't just pick any number!\n");
                break;
        }
        printf("\n"); // Adding a new line for better readability
    }
    
    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

// Function to print the main menu
void printMenu() {
    printf("----- Temperature Conversion Menu -----\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("0. Exit the program\n");
}

// Function that reflects on the choice made by the user
void introspectiveMessage(int choice) {
    if (choice == 1) {
        printf("Converting Celsius to Fahrenheit... a new perspective on warmth and chill.\n");
    } else if (choice == 2) {
        printf("Transforming Fahrenheit to Celsius... a dance of numbers amidst heated exchanges.\n");
    } else {
        printf("Every choice counts; even in temperature, each degree tells a story.\n");
    }
}