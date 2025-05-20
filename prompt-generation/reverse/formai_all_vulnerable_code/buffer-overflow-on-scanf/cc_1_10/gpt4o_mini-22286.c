//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: retro
#include <stdio.h>

// Function prototypes for conversion
void displayMenu();
float convertLength(float value, int choice);
float convertWeight(float value, int choice);
float convertTemperature(float value, int choice);

int main() {
    int option, unitType;
    float value;

    printf("--------------------------------------------------\n");
    printf("               Retro Unit Converter               \n");
    printf("--------------------------------------------------\n");
    printf("Welcome to the Retro Unit Converter! Let's get started.\n");

    while (1) {
        displayMenu();
        printf("Choose an option (1-4): ");
        scanf("%d", &option);

        if (option == 5) {
            printf("Thank you for using the Retro Unit Converter! Goodbye!\n");
            break;
        } else if (option < 1 || option > 5) {
            printf("Invalid option. Please try again.\n");
            continue;
        }

        printf("Enter the value for conversion: ");
        scanf("%f", &value);

        switch (option) {
            case 1: // Length conversion
                printf("Select Length Type:\n1. Meters to Feet\n2. Feet to Meters\n");
                printf("Choose an option (1-2): ");
                scanf("%d", &unitType);
                float lengthResult = convertLength(value, unitType);
                printf("Converted Value: %.2f\n", lengthResult);
                break;

            case 2: // Weight conversion
                printf("Select Weight Type:\n1. Kilograms to Pounds\n2. Pounds to Kilograms\n");
                printf("Choose an option (1-2): ");
                scanf("%d", &unitType);
                float weightResult = convertWeight(value, unitType);
                printf("Converted Value: %.2f\n", weightResult);
                break;

            case 3: // Temperature conversion
                printf("Select Temperature Type:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
                printf("Choose an option (1-2): ");
                scanf("%d", &unitType);
                float temperatureResult = convertTemperature(value, unitType);
                printf("Converted Value: %.2f\n", temperatureResult);
                break;

            case 4: // Length and Weight together
                printf("Get Ready for Length & Weight Conversion!\n");
                printf("1. Convert length, then weight\n2. Convert weight, then length\n");
                printf("Choose an option (1-2): ");
                scanf("%d", &unitType);
            
                if (unitType == 1) {
                    printf("Seamlessly converting length now...\n");
                    float lenResult = convertLength(value, 1);
                    printf("Now converting weight...\n");
                    printf("Enter weight for conversion (in kilograms): ");
                    scanf("%f", &value);
                    float weightResult = convertWeight(value, 1);
                    printf("Converted Length: %.2f Feet\nConverted Weight: %.2f Pounds\n", lenResult, weightResult);
                } else if (unitType == 2) {
                    printf("Seamlessly converting weight now...\n");
                    float weightResult = convertWeight(value, 1);
                    printf("Now converting length...\n");
                    printf("Enter length for conversion (in meters): ");
                    scanf("%f", &value);
                    float lenResult = convertLength(value, 1);
                    printf("Converted Weight: %.2f Pounds\nConverted Length: %.2f Feet\n", weightResult, lenResult);
                }
                break;

            default:
                printf("Invalid option selected, please try again.\n");
        }
    }
    return 0;
}

// Function definitions
void displayMenu() {
    printf("--------------------------------------------------\n");
    printf("Select Conversion Type:\n");
    printf("1. Length\n");
    printf("2. Weight\n");
    printf("3. Temperature\n");
    printf("4. Length & Weight\n");
    printf("5. Exit\n");
}

float convertLength(float value, int choice) {
    switch (choice) {
        case 1: // Meters to Feet
            return value * 3.28084f;
        case 2: // Feet to Meters
            return value / 3.28084f;
        default:
            return 0.0f;
    }
}

float convertWeight(float value, int choice) {
    switch (choice) {
        case 1: // Kilograms to Pounds
            return value * 2.20462f;
        case 2: // Pounds to Kilograms
            return value / 2.20462f;
        default:
            return 0.0f;
    }
}

float convertTemperature(float value, int choice) {
    switch (choice) {
        case 1: // Celsius to Fahrenheit
            return (value * 9.0f / 5.0f) + 32.0f;
        case 2: // Fahrenheit to Celsius
            return (value - 32.0f) * 5.0f / 9.0f;
        default:
            return 0.0f;
    }
}