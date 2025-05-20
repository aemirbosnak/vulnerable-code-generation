//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MIN_TEMP -327.5 // Minimum temperature in Fahrenheit
#define MAX_TEMP 300.0 // Maximum temperature in Fahrenheit
#define MIN_CEL -270.0 // Minimum temperature in Celsius
#define MAX_CEL 1000.0 // Maximum temperature in Celsius

void convertFtoC(double fahrenheit) {
    double celsius;
    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2lf degrees Fahrenheit is equal to %.2lf degrees Celsius.\n", fahrenheit, celsius);
}

void convertCtoF(double celsius) {
    double fahrenheit;
    fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    printf("%.2lf degrees Celsius is equal to %.2lf degrees Fahrenheit.\n", celsius, fahrenheit);
}

void displayMenu() {
    int choice;
    double temperature;

    printf("-------------------------------------------------\n");
    printf("| Temperature Converter Menu                    |\n");
    printf("-------------------------------------------------\n");
    printf("| 1. Convert Fahrenheit to Celsius              |\n");
    printf("| 2. Convert Celsius to Fahrenheit              |\n");
    printf("| 3. Exit                                      |\n");
    printf("-------------------------------------------------\n");
    printf("| Enter your choice:                            |\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            if (temperature < MIN_TEMP || temperature > MAX_TEMP) {
                printf("Invalid temperature value. Please enter a temperature between %lf and %lf degrees Fahrenheit.\n", MIN_TEMP, MAX_TEMP);
                return;
            }
            convertFtoC(temperature);
            break;
        case 2:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            if (temperature < MIN_CEL || temperature > MAX_CEL) {
                printf("Invalid temperature value. Please enter a temperature between %lf and %lf degrees Celsius.\n", MIN_CEL, MAX_CEL);
                return;
            }
            convertCtoF(temperature);
            break;
        case 3:
            printf("Exiting program...\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
    }

    displayMenu();
}

int main() {
    displayMenu();
    return 0;
}