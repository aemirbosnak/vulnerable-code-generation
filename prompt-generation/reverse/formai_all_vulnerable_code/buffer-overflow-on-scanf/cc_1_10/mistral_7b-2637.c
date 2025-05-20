//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void fahrenheitToCelsius(float fahrenheit) {
    float celsius;
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius.\n", fahrenheit, celsius);
}

void celsiusToFahrenheit(float celsius) {
    float fahrenheit;
    fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);
}

int main() {
    char choice;
    float temperature;

    system("clear"); // For Linux/macOS
    //system("cls");   // For Windows

    printf("\n\t*************************************************\n");
    printf("\t*                 TempConverterX3000               *\n");
    printf("\t*              Fahrenheit to Celsius and Vice Versa *\n");
    printf("\t*                  Version 3.0.0                   *\n");
    printf("\t*                Created by Cool Coder            *\n");
    printf("\t*                  2022-2030                      *\n");
    printf("\t*************************************************\n\n");

    do {
        printf("\nEnter F for Fahrenheit to Celsius or C for Celsius to Fahrenheit conversion: ");
        scanf(" %c", &choice);

        if (choice != 'F' && choice != 'C') {
            printf("Invalid option! Please try again.\n");
        } else {
            printf("Enter the temperature value: ");
            scanf("%f", &temperature);

            if (choice == 'F') {
                fahrenheitToCelsius(temperature);
            } else {
                celsiusToFahrenheit(temperature);
            }
        }

    } while (choice != 'Q');

    printf("\nPress any key to exit...");
    getchar();

    return 0;
}