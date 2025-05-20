//FormAI DATASET v1.0 Category: Unit converter ; Style: systematic
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

// Function to convert Kilometers to Miles
float kilometersToMiles(float kilometers) {
    return kilometers * 0.621371;
}

// Function to convert Miles to Kilometers
float milesToKilometers(float miles) {
    return miles * 1.60934;
}

// Function to convert Pounds to Kilograms
float poundsToKilograms(float pounds) {
    return pounds * 0.453592;
}

// Function to convert Kilograms to Pounds
float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

int main() {
    int choice;
    float value;

    do {
        printf("Select an option:\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Convert Kilometers to Miles\n");
        printf("4. Convert Miles to Kilometers\n");
        printf("5. Convert Pounds to Kilograms\n");
        printf("6. Convert Kilograms to Pounds\n");
        printf("7. Exit\n");

        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if (choice == 7) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        printf("Enter value to convert: ");
        scanf("%f", &value);

        switch (choice) {
            case 1:
                printf("%.2f Celsius is %.2f Fahrenheit\n", value, celsiusToFahrenheit(value));
                break;
            case 2:
                printf("%.2f Fahrenheit is %.2f Celsius\n", value, fahrenheitToCelsius(value));
                break;
            case 3:
                printf("%.2f Kilometers is %.2f Miles\n", value, kilometersToMiles(value));
                break;
            case 4:
                printf("%.2f Miles is %.2f Kilometers\n", value, milesToKilometers(value));
                break;
            case 5:
                printf("%.2f Pounds is %.2f Kilograms\n", value, poundsToKilograms(value));
                break;
            case 6:
                printf("%.2f Kilograms is %.2f Pounds\n", value, kilogramsToPounds(value));
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}