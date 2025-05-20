//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float milesToKilometers(float miles) {
    return miles * 1.60934;
}

float kilometersToMiles(float kilometers) {
    return kilometers / 1.60934;
}

float poundsToKilograms(float pounds) {
    return pounds * 0.453592;
}

float kilogramsToPounds(float kilograms) {
    return kilograms / 0.453592;
}

void displayMenu() {
    printf("Unit Converter Menu:\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Celsius to Fahrenheit\n");
    printf("3. Miles to Kilometers\n");
    printf("4. Kilometers to Miles\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("7. Exit\n");
    printf("Please select an option (1-7): ");
}

int main() {
    int choice;
    float input, output;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        if (choice < 1 || choice > 7) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the value to convert: ");
        scanf("%f", &input);

        switch (choice) {
            case 1:
                output = fahrenheitToCelsius(input);
                printf("%.2f Fahrenheit is %.2f Celsius.\n", input, output);
                break;
            case 2:
                output = celsiusToFahrenheit(input);
                printf("%.2f Celsius is %.2f Fahrenheit.\n", input, output);
                break;
            case 3:
                output = milesToKilometers(input);
                printf("%.2f Miles is %.2f Kilometers.\n", input, output);
                break;
            case 4:
                output = kilometersToMiles(input);
                printf("%.2f Kilometers is %.2f Miles.\n", input, output);
                break;
            case 5:
                output = poundsToKilograms(input);
                printf("%.2f Pounds is %.2f Kilograms.\n", input, output);
                break;
            case 6:
                output = kilogramsToPounds(input);
                printf("%.2f Kilograms is %.2f Pounds.\n", input, output);
                break;
        }
        printf("\n");
    }

    return 0;
}