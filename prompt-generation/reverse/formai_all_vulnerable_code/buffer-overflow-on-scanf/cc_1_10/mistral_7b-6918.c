//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP -327.67 // Minimum temperature in Fahrenheit
#define MAX_TEMP 125.0   // Maximum temperature in Fahrenheit

void convertFtoC(float fahrenheit) {
    printf("\nConverting %.2f°F to Celsius:\n", fahrenheit);
    float celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2f°F is equal to %.2f°C\n\n", fahrenheit, celsius);
}

void convertCtoF(float celsius) {
    printf("\nConverting %.2f°C to Fahrenheit:\n", celsius);
    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2f°C is equal to %.2f°F\n\n", celsius, fahrenheit);
}

void printMenu() {
    printf("\n******************************************\n");
    printf("*          Temperature Converter           *\n");
    printf("*1. Convert Fahrenheit to Celsius         *\n");
    printf("*2. Convert Celsius to Fahrenheit         *\n");
    printf("*3. Exit                                 *\n");
    printf("******************************************\n");
}

int main() {
    int choice;
    float temperature;

    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temperature);

                if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                    printf("Invalid temperature value.\n");
                    break;
                }

                convertFtoC(temperature);
                break;

            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);

                convertCtoF(temperature);
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}