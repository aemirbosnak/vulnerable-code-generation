//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP (-32.0)
#define MAX_TEMP (373.15)

void convertFtoC(double fahrenheit) {
    double celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2f Fahrenheit is equal to %.2f Celsius\n", fahrenheit, celsius);
}

void convertCtoF(double celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
}

void printMenu() {
    printf("\nTemperature Converter Menu:\n");
    printf("-------------------------------\n");
    printf("1. Convert Fahrenheit to Celsius\n");
    printf("2. Convert Celsius to Fahrenheit\n");
    printf("3. Exit\n");
}

int main() {
    double temperature;
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                    printf("Invalid temperature value! Temperature must be between %-.2f and %-.2f degrees.\n", MIN_TEMP, MAX_TEMP);
                    continue;
                }
                convertFtoC(temperature);
                break;

            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%lf", &temperature);
                if (temperature < -273.15 || temperature > MAX_TEMP) {
                    printf("Invalid temperature value! Temperature must be less than absolute zero or between %-.2f and %-.2f degrees.\n", MIN_TEMP, MAX_TEMP);
                    continue;
                }
                convertCtoF(temperature);
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}