//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

// function that returns the converted temperature from Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// function that returns the converted distance from Meters to Miles
float metersToMiles(float meters) {
    return meters * 0.000621371;
}

// function that returns the converted weight from Kilograms to Pounds
float kilogramsToPounds(float kilograms) {
    return kilograms * 2.20462;
}

int main() {
    int choice;
    float value;
    printf("Hey there! Welcome to the Happy Converter!\n");
    do {
        // menu
        printf("\nWhat would you like to convert today?\n");
        printf("1. Temperature from Celsius to Fahrenheit\n");
        printf("2. Distance from Meters to Miles\n");
        printf("3. Weight from Kilograms to Pounds\n");
        printf("4. Exit the converter\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the temperature in Celsius: ");
                scanf("%f", &value);
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", value, celsiusToFahrenheit(value));
                break;
            case 2:
                printf("\nEnter the distance in Meters: ");
                scanf("%f", &value);
                printf("%.2f Meters is equal to %.2f Miles\n", value, metersToMiles(value));
                break;
            case 3:
                printf("\nEnter the weight in Kilograms: ");
                scanf("%f", &value);
                printf("%.2f Kilograms is equal to %.2f Pounds\n", value, kilogramsToPounds(value));
                break;
            case 4:
                printf("\nThank you for using the Happy Converter! Have a great day!\n");
                break;
            default:
                printf("\nOops! Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}